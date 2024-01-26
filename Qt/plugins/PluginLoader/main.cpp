#include <QCoreApplication>

#include "PluginLoader.h"

#include "TestPlugin.h"

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);

	PluginLoader loader;
	loader.loadPlugins(".."); // parent path to plugin base dir, subdirs are expected to contain plugins

#ifdef TEST_DIRECT_LINKING
	TestPlugin p;
	QString dummy;
	p.doSomething(dummy);
#endif // TEST_DIRECT_LINKING

	return a.exec();
}
