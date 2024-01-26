#ifndef PluginLoaderH
#define PluginLoaderH

#include <QMap>
#include <QPluginLoader>

#include <memory>

class PluginLoader {
public:

	struct PluginData {
		/*! Standard constructor. Create the pluginLoader.*/
		PluginData() :
			m_loader(new QPluginLoader) // shared pointer
		{}

		/*! Source-path, where Plugin-Shared-Lib was read from.
			May be of format "repository:<plugin-name>", in which case the plugin
			is retrieved upon installing from the webpage repository.
		*/
		QString m_pluginPath;

		/*! The pluginloader (library wrapper) of this library.
			Only set to an object if library was successfully loaded.
		*/
		std::shared_ptr<QPluginLoader>	m_loader;
	};

	PluginLoader();

	void loadPlugins(const QString & pluginDir);

	/*! Stores data about all collected plugins.
		Key is unique plugin file path (of binary file) or url-prefix.
	*/
	QMap<QString, PluginData>	m_plugins;

private:

	/*! Attempts to load a plugin in the given path. */
	void loadPlugin(const QString & pluginPath, PluginData & pd);
};

#endif // PluginLoaderH
