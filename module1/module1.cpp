#include "module1.h"
namespace core{
	module1::module1() {
}
	module1::~module1() {
}
	string module1::name() {
	string result = "module1";
	return result;
}
	double module1::execute() {
		vector<float> *v = activator->values;
		if(v) {
			for(size_t i = 0; i < v->size(); i++) {
				v->at(i) += 1;
			}
			return 1;
		}
		return 0;
	}

	namespace allocators {
		extern "C" jMod core::iModule* newModule1() {
			return new module1();
		}
	};	
};