#include "module2.h"
using namespace core;
module2::module2() {
}
module2::~module2() {
}
string module2::name() {
	string result = "module2";
	return result;
}
double module2::execute(const double a, const double b) {
	return (a*a) + b;
}