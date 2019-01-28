#pragma once
#ifndef abstractDll
#define abstractDll

#ifdef jCoding
	#define jApi __declspec(dllexport)
	#include "Activator.h"
#else
	#define jApi __declspec(dllimport)
#endif

#include <string>
#include <vector>

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
		typedef iModule*(*jFactoryModule)(void);
		typedef void(*jFnxActivator)(Global::Activator *activator);
		extern "C" __declspec(dllexport) void tick(Global::Activator *activator) {
			Global::activator = activator;
		}
	};
};
#endif // !abstractDll