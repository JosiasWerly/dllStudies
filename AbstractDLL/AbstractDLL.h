#pragma once
#ifndef abstractDll
#define abstractDll

#ifdef jCoding
	#define jApi __declspec(dllexport)
	#include "Activator.h"
	static Global::Activator *ptr = nullptr;
#else
	#define jApi __declspec(dllimport)
#endif

#include <string>
#include <vector>

using namespace std;
namespace core {
	class jApi Persistence {
	public:
		Persistence();
		~Persistence();

		void init();
		void shutdown();
		void tick(Global::Activator *ptr);
	};
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
		typedef void(*jInit)(Global::Activator *activator);
		//extern "C" jApi void init(Global::Activator *activator);
	};
};
#endif // !abstractDll