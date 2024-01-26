#include "PluginLoader.h"

#include <QCoreApplication>
#include <QDebug>

#include <memory>

#include <QPluginLoader>
#include <QDir>

#if defined(_WIN32)
#include <windows.h>
#endif

#include <PluginInterface.h>

PluginLoader::PluginLoader()
{

}


void PluginLoader::loadPlugins(const QString & pluginDir) {
	// first load built-in (installed) plugins
	QDir pluginsDir(pluginDir);

	QStringList entryList = pluginsDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);
	for (const QString &dirName : entryList) {
		// attempt to load a plugin in this directory
		PluginData pd;
		loadPlugin(pluginsDir.filePath(dirName), pd);
	}
}


void PluginLoader::loadPlugin(const QString & pluginPath, PluginData & pd) {
	QDir pluginDir(pluginPath);
	const auto entryList = pluginDir.entryList(QDir::Files);
	QStringList libFiles;
	int count = 0;
	QString pluginFile;
	for (const QString &fileName : entryList) {
		QString ext = QFileInfo(fileName).suffix();
		// skip files that do not have a valid file extensions
		if (ext != "so" && ext != "dll" && ext != "dylib")
			continue;

		// one of the dll/so-files (NOTE: there may be several!) might be a plugin; try to load them all until we succeed.
		libFiles.append(fileName);
		// do we have a plugin file?
		if (fileName.contains("plugin", Qt::CaseInsensitive)) {
			if (count == 0)
				pluginFile = fileName;
			++count;
		}
	}

	if (libFiles.count() == 0)
		return; // no shared lib files in directory

	// only one libFile? must be the plugin
	if (libFiles.count() == 1) {
		pluginFile = libFiles[0];
	}
	else {
		// if we have several lib files in directory, we must have one exactly one with "plugin" in the filename
		if (count > 1) {
			return; // multiple plugin files in directory, cannot decide which
		}
		else if (count == 0) {
			return; // no library is marked "plugin"
		}
		// pluginFile already holds filename to shared 'plugin' library
	}

	// try to load plugin
	QString pluginFilePath = pluginDir.absoluteFilePath(pluginFile);
	pd.m_loader->setFileName(pluginFilePath);
	pd.m_loader->setLoadHints(QLibrary::DeepBindHint);  // when loading plugins with IBK library support (yet other versions), this ensures that libraries use their own statically linked code

	QObject * plugin = nullptr;
	// add path to plugin to library search paths
	qApp->addLibraryPath(pluginDir.absolutePath());
	qDebug() << qApp->libraryPaths();
	bool success = pd.m_loader->load(); // load the plugin
	// and remove the path again, so that subsequent libs won't load wrong dll/so-files
	qApp->removeLibraryPath(pluginDir.absolutePath());
	if (success) {
		plugin = pd.m_loader->instance(); // access the library
		qDebug() << "Successfully loaded";

		PluginInterface * pluginInterface = qobject_cast<PluginInterface*>(plugin);
		if (pluginInterface != nullptr) {
			QString testData;
			QString result = pluginInterface->doSomething(testData);
			qDebug() << "Function execution works";
		}
	}
	else {
		qDebug() << pd.m_loader->errorString();
	}
}

