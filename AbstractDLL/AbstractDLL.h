#pragma once
#ifdef jApi
#define jApi __declspec(dllexport)
#else
#define jApi __declspec(dllimport)
#endif
#include <string>

using namespace std;

namespace core {
	class jApi iModule {
	public:
		virtual void Destroy() {
			delete this;
		}
		virtual string name(string& s) = 0;
		virtual double execute(const double a, const double b) = 0;
	};
};