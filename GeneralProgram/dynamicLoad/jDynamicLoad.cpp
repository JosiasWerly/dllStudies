#include "jDynamicLoad.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
using namespace std;
list<jDll*> dynamicLoad::DynamicLibraries = list<jDll*>();

bool dynamicLoad::load(wstring path, wstring name) {	
	wstring strg;
	strg = path;
	strg += name;
	HINSTANCE instance = LoadLibrary((LPCWSTR)strg.c_str());
	if (!instance)
		throw 1;

	auto converter = [=](wstring &from)->string{
		string stgName;
		for (size_t i = 0; i < from.length(); i++){
			stgName += from.at(i);
		}
		return stgName;
	};
	dynamicLoad::DynamicLibraries.emplace_back(new jDll(converter(name), instance));
	return true;
}
jDll* dynamicLoad::at(string name) {
	for (list<jDll*>::iterator i = DynamicLibraries.begin(); i != DynamicLibraries.end(); i++){
		if (name == (*i)->name)
			return (*i);
	}
	return nullptr;
}