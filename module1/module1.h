#pragma once
#ifdef codingModule
	#include "..\AbstractDLL\AbstractDLL.h"
	#define jMod __declspec(dllexport)
#else
	#define jMod __declspec(dllimport)
#endif // !codingModule
namespace core {
	class jMod module1 :
		public iModule {
	public:
		module1();
		virtual ~module1();

		double execute();
		string name();
	};
	namespace allocators{		
		extern "C" jMod core::iModule* newModule1();
	};
};