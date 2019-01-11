#pragma once
#ifndef abstractDll
#define abstractDll

#ifdef jApi
#define jApi __declspec(dllexport)
#else
#define jApi __declspec(dllimport)
#endif
#include <string>
using namespace std;
namespace core {
	class jApi iModule {
	public:
		iModule();
		virtual ~iModule();
		virtual void Destroy();
		virtual string name() = 0;
		virtual double execute(const double a, const double b) = 0;
	};
	namespace allocators {
		typedef iModule*(*factoryModule)(void);
	};
};
#endif // !abstractDll