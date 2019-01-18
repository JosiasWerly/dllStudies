#pragma once
#ifndef abstractDll
#define abstractDll

#ifdef jApi
#define jApi __declspec(dllexport)
#else
#define jApi __declspec(dllimport)
#endif
#include <string>
#include <vector>
#include "Activator.h"
using namespace std;
namespace core {
	class jApi iModule {
	public:
		iModule();
		virtual ~iModule();
		virtual void Destroy();
		virtual string name() = 0;
		virtual double execute() = 0;
	};
	namespace allocators {
		extern "C" jApi void init(Global::Activator *activator);
		typedef iModule*(*factoryModule)(void);
	};
};
#endif // !abstractDll