#pragma once
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <list>
using namespace std;

class dynamicLoad {
public:
	class dynamicLibrary {
	public:
		const char *name;
		const HINSTANCE instance;
		dynamicLibrary(const char *name, const HINSTANCE instance):
			name(name),
			instance(instance){
		}
		template<class T> static T getProc(const char* data) {
			T p = nullptr;
			p = (T)GetProcAddress(dynamicLoad::instance, data);
			return p;
		}
	};
public:
	static list<dynamicLibrary*>* DynamicLibraries;
	static bool load(const wchar_t *path, const wchar_t *name);
};