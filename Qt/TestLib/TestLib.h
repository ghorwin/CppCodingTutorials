#ifndef TESTLIB_H
#define TESTLIB_H

#ifdef _MSC_VER

#include <windows.h>

// Unter Windows BUILD_LIB beim Erstellen der Library setzen, aber nicht im importierenden Projekt
// Nur für Visual Studio Compiler notwendig.
#if defined (BUILD_LIB)
#define TESTLIB_EXPORT Q_DECL_EXPORT
#else
#define TESTLIB_EXPORT Q_DECL_IMPORT
#endif

#else
#define TESTLIB_EXPORT
#endif // _MSC_VER


class TESTLIB_EXPORT TestLib {
public:

	bool doNix();
};

#endif // TESTLIB_H
