#include "jDynamicLoad.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
using namespace std;
HINSTANCE dynamicLoad::instance = nullptr;
bool dynamicLoad::load(const wchar_t *path) {
	dynamicLoad::instance = LoadLibrary((LPCWSTR)path);
	return dynamicLoad::instance;
}