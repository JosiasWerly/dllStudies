#include "AbstractDLL.h"
namespace core {
	iModule::iModule() {
	}
	iModule::~iModule() {
	}
	void iModule::Destroy() {
		delete this;
	}
};
