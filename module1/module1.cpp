#include "module1.h"
using namespace core;
module1::module1() {
}
module1::~module1() {
}
string module1::name() {
	string result = "module1";
	return result;
}
double module1::execute(const double a, const double b) {
	return a-b;
}