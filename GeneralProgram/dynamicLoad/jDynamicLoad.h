#pragma once
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <list>
using namespace std;

class jDll {
public:
	string name;
	const HINSTANCE instance;
	jDll(string name, const HINSTANCE instance) :
		name(name),
		instance(instance) {
	}
	template<class T> T getFunc(string data) {
		T p = nullptr;
		p = (T)GetProcAddress(instance,(LPCSTR)data.c_str());
		return p;
	}
};
class dynamicLoad {
public:
	static list<jDll*> DynamicLibraries;
	static void load(wstring path, wstring name);
	static jDll* at(string name);
};