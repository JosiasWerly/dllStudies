#include "packagedModule.h"
using namespace core;
packagedModule::packagedModule(){
}
packagedModule::~packagedModule(){
}
string packagedModule::name(){
	string result = "add";
	return result;
}
double packagedModule::execute(const double a, const double b){
	return a + b;
}