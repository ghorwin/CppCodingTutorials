#ifndef TestPluginH
#define TestPluginH

#include "PluginInterface.h"

class TestPlugin : public QObject, public PluginInterface {
public:
	Q_OBJECT
	Q_INTERFACES(PluginInterface)
	Q_PLUGIN_METADATA(IID "xyz.Plugin.PluginInterface")
public:

	/*! Implementation of the abstract PluginInterface functions .*/
	QString doSomething(const QString& testData);
};



#endif // TestPluginH

