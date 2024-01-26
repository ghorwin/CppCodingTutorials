#include "TestPlugin.h"

#include <TestLib.h>

QString TestPlugin::doSomething(const QString &) {
	TestLib l;
	bool res = l.doNix();
	if (res)
		return "works";
	else
		return "failed";
}
