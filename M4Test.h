#ifndef TEST_H
#define TEST_H
#include <cstring>
#include <new>
#include <iomanip>

#define _CRT_SECURE_NO_WARNINGS
#define NUM_OF_COURSE_TESTS (6)


struct Test {
	bool testResult;
	char testName[100];
	bool (*testFunc)(void);
public:
	void run(); 
	void setName(const char* n); 
};


class CourseTestList {
	Test testlist[NUM_OF_COURSE_TESTS];
public:
	CourseTestList();
	void runAllTests() {
		for (int i = 0; i < NUM_OF_COURSE_TESTS; i++)
			testlist[i].run();
	}
};

#endif
