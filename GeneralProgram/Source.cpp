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
	
	
	
	//core::allocators::newModule nMod1 = d->getFunc<core::allocators::newModule>("newModule1");
	//core::iModule *mod = nMod1();
	//cout << mod->name() << endl;
	//core::allocators::newModule a = dynamicLoad::getProc<core::allocators::newModule>("createModule1");
	//core::iModule *q = a();
	//q->name();
	
	return 0;
}




////////////Simple Test////////////////
//#include "dynamicLoad/jDynamicLoad.h"
//#include "simpleDLL.h"
////#include "AbstractDLL.h"
////#include "module1.h"
////#include "module2.h"
//
//#include <windows.h>
//#include <tchar.h>
//
//#include <iostream>
//using namespace std;
//
//typedef class simple::iClass*(*newIClass)(void);
//typedef double(*fnx)(double, double);
//int main() {
//	if (!dynamicLoad::load(L"C:\\Users\\UltraDevUser\\source\\repos\\joeWerly\\dllStudies\\BuildOutput\\Debug\\AbstractDLL.dll"))
//		throw 1;
//	{
//		fnx f = dynamicLoad::getProc<fnx>("add");
//		if (f(10, 5) != 15)
//			throw 1;
//	}
//	newIClass newiClass = dynamicLoad::getProc<newIClass>("create");
//	simple::iClass *j = newiClass();
//	cout << j->value();
//	return 0;
//}