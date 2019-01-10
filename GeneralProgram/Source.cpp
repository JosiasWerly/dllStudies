#include "dynamicLoad/jDynamicLoad.h"
#include "AbstractDLL.h"
#include "module1.h"
//#include "module2.h"

#include <windows.h>
#include <tchar.h>

#include <iostream>
using namespace std;
int main() {
	dynamicLoad::load(L"C:\\Users\\UltraDevUser\\source\\repos\\joeWerly\\dllStudies\\BuildOutput\\Debug\\", L"module1.dll");	
	//core::allocators::newModule a = dynamicLoad::getProc<core::allocators::newModule>("createModule1");
	//core::iModule *q = a();
	q->name();
	
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