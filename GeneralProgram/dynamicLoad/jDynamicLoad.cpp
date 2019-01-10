#include "jDynamicLoad.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
using namespace std;
HINSTANCE dynamicLoad::instance = nullptr;
bool dynamicLoad::load(const wchar_t *path, const wchar_t *name) {
	dynamicLoad::instance = LoadLibrary((LPCWSTR)path);
	if (!instance)
		throw 1;
	return dynamicLoad::instance;
}