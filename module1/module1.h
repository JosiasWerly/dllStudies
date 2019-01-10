#pragma once
#ifdef jApi
#include "..\AbstractDLL\AbstractDLL.h"
#endif // !jApi
namespace core {
	class jApi module1 :
		public iModule {
	public:
		module1();
		virtual ~module1();

		double execute(const double a, const double b);
		string name();
	};
};