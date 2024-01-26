#ifndef AbstractPluginInterfaceH
#define AbstractPluginInterfaceH

#include <QtPlugin>

#ifdef _MSC_VER

#include <windows.h>

// Unter Windows BUILD_PLUGIN beim Erstellen der Library setzen, aber nicht im importierenden Projekt
// Nur für Visual Studio Compiler notwendig.
#if defined (BUILD_PLUGIN)
#define TESTPLUGIN_EXPORT Q_DECL_EXPORT
#else
#define TESTPLUGIN_EXPORT Q_DECL_IMPORT
#endif

#else
#define TESTPLUGIN_EXPORT
#endif // _MSC_VER

/*! This class declares common plugin interface functions.
	This header should be included by all plugin interface classes.
*/
class TESTPLUGIN_EXPORT AbstractPluginInterface {
public:

	/*! Virtual D'tor. */
	virtual ~AbstractPluginInterface() = default;


	// ... common functions ...
};


Q_DECLARE_METATYPE(AbstractPluginInterface*)

#endif // AbstractPluginInterfaceH
