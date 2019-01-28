#include "module2.h"
namespace core {
	module2::module2() {
	}
	module2::~module2() {
	}
	string module2::name() {
		string result = "sum";
		return result;
	}
	double module2::execute() {		
		vector<float> *v = Global::activator->values;
		if(v) {
			for(size_t i = 0; i < v->size(); i++) {
				v->emplace_back(v->at(i));
			}
			return 1;
		}		
		return 0;
	}

	namespace allocators {
		extern "C" jMod core::iModule* newModule2() {
			return new module2();
		}
	};
};