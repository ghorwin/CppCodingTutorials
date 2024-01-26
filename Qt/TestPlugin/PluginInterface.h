#ifndef PluginInterfaceH
#define PluginInterfaceH

#include "AbstractPluginInterface.h"

#include <QString>

/*! Interface for a plugin. */
class TESTPLUGIN_EXPORT PluginInterface : public AbstractPluginInterface {
public:

	/*! Test function. */
	virtual QString doSomething(const QString& testData) = 0;
};

/*! Identifies our plugin import interface with a unique-string. The formation is free text, but we use
	the Java package naming convention for lack of a better idea :-) The appended version number in increased
	when we later change the interface.
*/
#define PluginInterface_iid "xyz.Plugin.PluginInterface/1.0"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)


#endif // PluginInterfaceH
