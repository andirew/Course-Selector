#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Course.h"
#include "ICTCourse.h"
#include "GenEdCourse.h"
#include "general.h"
#include "ScmApp.h"


using namespace std;
namespace sict {
	bool one = true;

	ScmApp::ScmApp(const char* filename) {

		strncpy(_filename, filename, 128);

		*courseList_ = nullptr;
		noOfCourses_ = 0;
		loadRecs();
	}
	void ScmApp::pause() const {
		cout << "Press Enter to continue...";
		cin.ignore().get();
	}

	void ScmApp::saveRecs() {

		datafile_.open(_filename, ios::out);

		for (int i = 0; i < noOfCourses_; i++) {
		
				courseList_[i]->store(datafile_);
			
		}

		datafile_.close();
		loadRecs();

	}
	void ScmApp::loadRecs() {
		//courseList_ = 0;

		datafile_.open(_filename, ios::in);
		if (!datafile_.is_open()) { //not sure if this is right!!

			datafile_.clear();
			datafile_.close();
			datafile_.open(_filename, ios::out);
			datafile_.close();

		}
		else if (datafile_.is_open()) {
			while (!datafile_.eof()) {


				char id = 0;

				datafile_ >> id;
				datafile_.ignore(1);
				if (id == 'G') {
					//	delete _items[_noOfItems];
					courseList_[noOfCourses_] = new GenEdCourse;


					courseList_[noOfCourses_]->load(datafile_);
					noOfCourses_ += 1;

				}
				else if (id == 'I') {
					//	delete _items[_noOfItems];
					courseList_[noOfCourses_] = new ICTCourse;


					courseList_[noOfCourses_]->load(datafile_);
					
					noOfCourses_ += 1;

				}


			}

			datafile_.close();
		}

	}


	int ScmApp::menu() {
		char choice;

		cout << "Seneca Course Managment Tool" << endl;
		cout << "1- List courses" << endl;
		cout << "2- Display the details of the course." << endl;
		cout << "3- Add a courset" << endl;
		cout << "4- Change the study load of a course" << endl;
		cout << "5- Load courses from a file." << endl;
		cout << "6- Save courses to a file." << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		//cin.ignore();
		cin >> choice;

		if (choice == '1') {
			cout << endl;
			return 1;
		}
		else if (choice == '2') {
			cout << endl;
			cin.clear();
			return 2;
		}
		else if (choice == '3') {
			cout << endl;
			cin.clear();
			return 3;
		}
		else if (choice == '4') {
			cout << endl;
			return 4;
		}
		else if (choice == '5') {
			cout << endl;
			return 5;
		}
		else if (choice == '6') {
			cout << endl;
			return 6;
		}
		else if (choice == '0') {
			cout << endl;
			return 0;
		}
		else {
			cout << endl;
			choice = -1;
			return -1;
		}
	}
	void ScmApp::listCourses()const {


		cout << "Row | Code | Course Title | Credits | Study Load |" << endl;
		cout << "----|------|--------------|---------|------------|" << endl;

		int x = 0;

		for (int i = 0; i < noOfCourses_; i++) {
			if (i <= 10) {
				x = i + 1;
				cout << "   " << x << " | " << courseList_[i] << endl;;
				x++;
			}
			else {
				break;

			}




		}

	}

	int ScmApp::searchForACourse(const char* courseCode)const {
		for (int i = 0; i < noOfCourses_; i++) {
			int result = strcmp(courseList_[i]->getCourseCode(), courseCode);
			if (result == 0) {
				return i;
			}
		}
		return -1;
	}
	void ScmApp::changeStudyLoad(const char* courseCode) const {

		int oldCourse;;
		int newCourse;
		bool fail = false;
		if (cin.fail()) {
			cout << "Invalid value!" << endl;
			fail = true;
		}

		int value = searchForACourse(courseCode);


		if (value >= 0 && fail == false) {
			cout << courseList_[value] << endl;

			cout << endl;
			cout << endl;
			cout << "Please enter the number of purchased items: ";
			int upd;

			cin >> upd;

			if (value < (courseList_[value]->getCredits() - courseList_[value]->getStudyLoad())) {
				oldCourse = courseList_[value]->getStudyLoad();
				newCourse = oldCourse + upd;
				courseList_[value]->setStudyLoad(newCourse);

			}

			cout << endl;
			cout << "Updated!" << endl << endl;


		}
		else if (value == -1 && fail == false) {
			cout << "Not found!" << endl << endl;
		}

	}

	void ScmApp::addACourse(char a) {
		if (a == TYPE_ICT) {

			char tempcourseCode_[MAX_COURSECODE_LEN + 1];
			int tempcredits_;
			int tempstudyLoad_;
			char* tempcourseTitle_ = nullptr;
			char tempcompsys_[41];
			cout << "Course Code: ";
			cin >> tempcourseCode_;
			cout << "Course Title: ";
			cin >> tempcourseTitle_;
			cout << "Credits: ";
			cin >> tempcredits_;
			cout << "Study Load: ";
			cin >> tempstudyLoad_;
			cout << "Computer System: ";
			cin >> tempcompsys_;
			ICTCourse* add;
			add = new ICTCourse(tempcourseCode_, tempcourseTitle_, tempcredits_, tempstudyLoad_,tempcompsys_);
			courseList_[noOfCourses_ + 1] = add;
			noOfCourses_++;
		}
		else if (a == TYPE_GEN) {
			char tempcourseCode_[MAX_COURSECODE_LEN + 1];
			int tempcredits_;
			int tempstudyLoad_;
			char* tempcourseTitle_ = nullptr;
			int tempcompsys_;
			cout << "Course Code: ";
			cin >> tempcourseCode_;
			cout << "Course Title: ";
			cin >> tempcourseTitle_;
			cout << "Credits: ";
			cin >> tempcredits_;
			cout << "Study Load: ";
			cin >> tempstudyLoad_;
			cout << "Language Requirment: ";
			cin >> tempcompsys_;
			GenEdCourse* add2 = new GenEdCourse(tempcourseCode_, tempcourseTitle_, tempcredits_, tempstudyLoad_,tempcompsys_);

			courseList_[noOfCourses_ + 1] = add2;
			noOfCourses_++;
		}

	}

	int ScmApp::run() {
	
		//_noOfItems = 0;
		bool run = true;
		int currsele;
		char courseCode_[MAX_COURSECODE_LEN + 1];

		while (run == true) {

			currsele = menu();
			if (currsele == 1) {
				listCourses();

			}
			else if (currsele == 2) {
				cout << "Please enter the course code: ";
				cin >> courseCode_;
				int value = searchForACourse(courseCode_);

				if (value >= 0) {
					cout << "v-----------------------------------v" << endl;
					courseList_[value]->display(cout);
					cout << "^-----------------------------------^" << endl << endl;
				}
				else if (value == -1) {
					cout << "Not found!" << endl;
				}


			}
			else if (currsele == 3) {
				cout << "Pleasde Enter the course Type(I-ICT or G-GenEd):";
				int in;
				cin >> in;

				addACourse(in);


			}
			else if (currsele == 4) {
				cout << "Please enter the course code: ";
				cin >> courseCode_;
				changeStudyLoad(courseCode_);

			}
			else if (currsele == 5) {

			}
			else if (currsele == 6) {

			}
		
			else if (currsele == 0) {

				cout << "Goodbye!" << endl;
				//	_pause();
				exit(0);

			}
			else {
				cout << "=== Invalid Selection, try again ===" << endl;
			}

		}
		return 0;
	}

}