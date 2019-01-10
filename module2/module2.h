#pragma once
#define jApi
#include "..\AbstractDLL\AbstractDLL.h"
namespace core {
	class jApi module2 :
		public iModule {
	public:
		module2();
		virtual ~module2();

		double execute(const double a, const double b);
		string name();
	};
};