#include "AbstractDLL.h"
namespace core {
	


	iModule::iModule() {
	}
	iModule::~iModule() {
	}
	void iModule::Destroy() {
		delete this;
	}

	Persistence::Persistence() {}
	Persistence::~Persistence() {}

	void Persistence::init() {}
	void Persistence::shutdown() {
		::ptr = nullptr;
	}
	void Persistence::tick(Global::Activator *ptr) {
		::ptr = ptr;
	}


	namespace allocators {


		/*extern "C" jApi void init(Global::Activator *activator) {
			Global::activator = activator;
		}*/
	};

	//jApi vector<float>* globalVariable::valuesRef = nullptr;
	//globalVariable::globalVariable() {}
	//globalVariable::~globalVariable() {}
	/*globalVariable& globalVariable::getInstance() {
		static globalVariable inst;
		return inst;
	}*/
};
