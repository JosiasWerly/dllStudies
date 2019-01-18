#pragma once
#include <vector>
using namespace std;
namespace Global{
	class Activator {
	public:
		vector<float> *values;

		Activator(){}
		~Activator(){}
	};
	static Activator *activator = nullptr;
};
