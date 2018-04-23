#include <iostream>
#include <cstring>
#include "ScmApp.h"
#include "M4ScmAppTester.h"
#include "M4Test.h"
#include "ICTCourse.h"
#include "GenEdCourse.h"


using namespace sict;



void ScmAppTester::load() {

	s->courseList_[0] = new sict::ICTCourse("OOP244", "Object-Oriented Programming in C++", 1, 4, "edwin");
	s->courseList_[1] = new sict::ICTCourse("BTP200", "The Object-Oriented Paradigm Using C++", 1, 1);
	s->courseList_[2] = new sict::GenEdCourse("HIS201", "World War II", 1, 3);
	s->courseList_[3] = new sict::GenEdCourse("SOC600", "Introduction to Sociology", 1, 3, 1);

	s->noOfCourses_ = 4;
}



bool ScmAppTester::saveAndLoadCourses() {
	load();
	s->saveRecs();
	for (int i = 0; i < s->noOfCourses_; i++) {
		delete s->courseList_[i]; s->courseList_[i] = 0;
	}

	s->loadRecs();

	sict::ICTCourse* i1 = dynamic_cast<sict::ICTCourse *>(s->courseList_[0]);
	sict::ICTCourse* i2 = dynamic_cast<sict::ICTCourse *>(s->courseList_[1]);
	sict::GenEdCourse* g1 = dynamic_cast<sict::GenEdCourse *>(s->courseList_[2]);
	sict::GenEdCourse* g2 = dynamic_cast<sict::GenEdCourse *>(s->courseList_[3]);

	return  (
		!i1->isEmpty()
		&& (!strcmp("OOP244", i1->getCourseCode()))
		&& (!strcmp("Object-Oriented Programming in C++", i1->getCourseTitle()))
		&& (i1->getCredits() == 1)
		&& (i1->getStudyLoad() == 4)
		&& (!strcmp(i1->getComputerSystem(), "edwin"))
		
		&& !i2->isEmpty()
		&& (!strcmp("BTP200", i2->getCourseCode()))
		&& (!strcmp("The Object-Oriented Paradigm Using C++", i2->getCourseTitle()))
		&& (i2->getCredits() == 1)
		&& (i2->getStudyLoad() == 1)
		&& (!strcmp(i2->getComputerSystem(), "matrix"))
		
		&& !g1->isEmpty()
		&& (!strcmp("HIS201", g1->getCourseCode()))
		&& (!strcmp("World War II", g1->getCourseTitle()))
		&& (g1->getCredits() == 1)
		&& (g1->getStudyLoad() == 3)
		&& (g1->getLangLevel() == 0)

		&& !g2->isEmpty()
		&& (!strcmp("SOC600", g2->getCourseCode()))
		&& (!strcmp("Introduction to Sociology", g2->getCourseTitle()))
		&& (g2->getCredits() == 1)
		&& (g2->getStudyLoad() == 3)
		&& (g2->getLangLevel() == 1)
		

		);


}


void ScmAppTester::runAllTests() {

	std::cout << "Test: ScmApp::saveRec/loadRec () - " << (saveAndLoadCourses() ? "Passed" : "Failed") << std::endl;

};
