#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "M4Test.h"

void Test::run() {
 	testResult = (*testFunc)();
	std::cout << "Test: " << testName << " - " 
		  << (testResult ? "Passed" : "Failed") << std::endl; 
}

void Test::setName(const char* n){ strcpy(testName, n);}
