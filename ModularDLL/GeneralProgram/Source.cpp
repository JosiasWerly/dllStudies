


#define PlayingDynamicLoad
#ifdef PlayingDynamicLoad
#include "Activator.h"
#include "dynamicLoad/jDynamicLoad.h"
#include "AbstractDLL.h"
//#include "module1.h"
//#include "module2.h"
#include <windows.h>
#include <tchar.h>
#include <iostream>




using namespace std;
using namespace core;
using namespace core::allocators;

int main() {
	Global::activator = new Global::Activator();
	Global::activator->values = new vector<float>();
	for(size_t i = 0; i < 10; i++){
		Global::activator->values->emplace_back(i);
	}
	
	dynamicLoad::load(L"C:\\Users\\UltraDevUser\\source\\repos\\joeWerly\\dllStudies\\BuildOutput\\Debug\\Win32\\", L"AbstractDLL.dll");
	dynamicLoad::load(L"C:\\Users\\UltraDevUser\\source\\repos\\joeWerly\\dllStudies\\BuildOutput\\Debug\\Win32\\", L"module1.dll");
	dynamicLoad::load(L"C:\\Users\\UltraDevUser\\source\\repos\\joeWerly\\dllStudies\\BuildOutput\\Debug\\Win32\\", L"module2.dll");
	jDll
		*jDllAbstract = dynamicLoad::at("AbstractDLL.dll"),
		*jDllNewMod1 = dynamicLoad::at("module1.dll"),
		*jDllNewMod2 = dynamicLoad::at("module2.dll");
	
	core::allocators::jFactoryModule
		m1 = jDllNewMod1->getFunc<jFactoryModule>("newModule1"),
		m2 = jDllNewMod2->getFunc<jFactoryModule>("newModule2");

	core::allocators::jFnxActivator
		dllAbs = jDllAbstract->getFunc<jFnxActivator>("tick"),
		initm1 = jDllNewMod1->getFunc<jFnxActivator>("tick"),
		initm2 = jDllNewMod2->getFunc<jFnxActivator>("tick");

	dllAbs(Global::activator);
	initm1(Global::activator);
	initm2(Global::activator);


	iModule
		*mod1 = m1(),
		*mod2 = m2();
	double r;
	r = mod1->execute();
	r = mod2->execute();
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








