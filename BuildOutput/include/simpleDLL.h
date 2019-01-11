#pragma once
#ifdef jApiSimple
#define jApiSimple __declspec(dllexport)
#else
#define jApiSimple __declspec(dllimport)
#endif
namespace simple{
	class jApiSimple iClass{
	public:
		iClass();
		virtual ~iClass();
		virtual int value();
	};
	extern "C" jApiSimple double add(double a, double b);
	extern "C" jApiSimple simple::iClass* createiClass();
};