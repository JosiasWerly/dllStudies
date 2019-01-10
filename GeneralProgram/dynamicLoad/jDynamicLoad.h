#pragma once
#include <windows.h>
#include <iostream>
#include <tchar.h>
using namespace std;
class dynamicLoad {
public:
	static HINSTANCE instance;
	static bool load(const wchar_t *path);
	template<class T> static bool getProc(const char* data, T &fnx) {
		T p = nullptr;
		p = (T)GetProcAddress(dynamicLoad::instance, data);
		if (p) {
			fnx = p;
			return true;
		}
		return false;
	}
};