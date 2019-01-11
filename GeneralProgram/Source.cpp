

//Select what type you would test
//#define dynamicLoad
#ifdef dynamicLoad
#include "dynamicLoad/jDynamicLoad.h"
#include "AbstractDLL.h"
#include "module1.h"
#include "module2.h"
#include <windows.h>
#include <tchar.h>
#include <iostream>



using namespace std;
using namespace core;
using namespace core::allocators;
int main() {
	dynamicLoad::load(L"C:\\Users\\UltraDevUser\\source\\repos\\joeWerly\\dllStudies\\BuildOutput\\Debug\\", L"module1.dll");
	dynamicLoad::load(L"C:\\Users\\UltraDevUser\\source\\repos\\joeWerly\\dllStudies\\BuildOutput\\Debug\\", L"module2.dll");
	jDll
		*jDllNewMod1 = dynamicLoad::at("module1.dll"),
		*jDllNewMod2 = dynamicLoad::at("module2.dll");
	core::allocators::factoryModule
		m1 = jDllNewMod1->getFunc<factoryModule>("newModule1"),
		m2 = jDllNewMod2->getFunc<factoryModule>("newModule2");
	iModule
		*mod1 = m1(),
		*mod2 = m2();

	cout << mod1->name() << endl;
	cout << mod2->name() << endl;
	return 0;
}
#else
#include "dynamicLoad/jDynamicLoad.h"
#include "simpleDLL.h"
#include <windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

typedef class simple::iClass*(*newIClassFnx)(void);
typedef double(*fnx)(double, double);
int main() {
	dynamicLoad::load(L"C:\\Users\\UltraDevUser\\source\\repos\\joeWerly\\dllStudies\\BuildOutput\\Debug\\", L"simpleDLL.dll");
	jDll *dl = dynamicLoad::at("simpleDLL.dll");

	fnx addFnx = dl->getFunc<fnx>("add");
	newIClassFnx newIClass = dl->getFunc<newIClassFnx>("createiClass");	
	simple::iClass *j = newIClass();
	
	cout << j->value() << endl;
	cout << addFnx(10, 20);
	return 0;
}
#endif // dynamicLoad







