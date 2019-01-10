#pragma once
#include "AbstractDLL.h"
//internal implementation just for package with the dll
namespace core {
	class jApi packagedModule :
		public iModule {
	public:
		packagedModule();
		virtual ~packagedModule();

		double execute(const double a, const double b);
		string name();
	};
};