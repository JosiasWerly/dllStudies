#include "simpleDLL.h"

namespace simple {
	extern "C" jApiSimple double add(double a, double b) {
		return a + b;
	}
	extern "C" jApiSimple simple::iClass* create() {
		return new simple::iClass();
	}
	iClass::iClass() {}
	iClass::~iClass() {}
	int iClass::value() {
		return 123;
	}
};