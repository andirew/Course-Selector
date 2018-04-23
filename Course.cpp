#include "Course.h"
#include <iomanip>
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>


using namespace std;
namespace sict {
	Course::Course() {
		courseTitle_ = new char[21]; // name
		courseTitle_ = '\0';
		credits_ = 0;//qtyNeeded
		studyLoad_ = 0;//quantity


		strcpy(courseCode_, "");//sku

	}
	Course::Course(const char* courseCode, const char* courseTitle, int credits, int studyLoad) {
		int result = strcmp(courseCode, "");
		int result2 = strcmp(courseTitle, "");
		if ((result != 0) && (result2 != 0) && (credits > 0) && (studyLoad > 0)) {
			strncpy(courseCode_, courseCode, MAX_COURSECODE_LEN);
			int size;
			size = strlen(courseTitle);
			courseTitle_ = new char[size + 1];
			strcpy(courseTitle_, courseTitle);
			courseTitle_[size] = '\0';
			credits_ = credits;
			studyLoad_ = studyLoad;
			
		}
		else {
			strcpy(courseCode_, "");
			courseTitle_ = '\0';
			credits_ = 0;//qtyNeeded
			studyLoad_ = 0;//quantity
			strcpy(courseCode_, "");//sku

		}
	}
	Course::Course(const Course& B) {
		*this = B;
	}

	void Course::setCourseCode(const char* value) {
		strcpy(courseCode_, value);
	}
	void Course::setCourseTitle(const char* n) {
		int size;
		size = strlen(n);
		courseTitle_ = new char[size + 1];
		strcpy(courseTitle_, n);
	}
	void Course::setStudyLoad(int p) {
		studyLoad_ = p;
	}
	void Course::setCredits(int q) {
		credits_ = q;
	}
	const char* Course::getCourseCode()const {
		return courseCode_;
	}
	const char*  Course::getCourseTitle() const {
		return courseTitle_;
	}
	int  Course::getCredits() const {
		return credits_;
	}
	int  Course::getStudyLoad() const {
		return studyLoad_;
	}
	const bool Course::isEmpty() const {

		if (getStudyLoad() == 0 && getCredits() == 0) {
			
			return true;
		}
		else {
			
			return false;
		}

	}
	bool Course::operator==(const char* coursecode) const
	{

		int result = strcmp(courseCode_, coursecode);
		if (result == 0) {

			return true;


		}
		else {

			return false;
		}

	}
	int Course::operator+=(int sumAdd)
	{
		int sum;
		sum = this->studyLoad_ + sumAdd;
		setStudyLoad(sum);
		return sum;


	}

	ostream& Course::display(std::ostream& os) const {
		os << std::left << std::setw(MAX_COURSECODE_LEN) << getCourseCode() << "|"
			<< std::left << std::setw(20) << getCourseTitle() << "|" <<
			std::right << std::setw(6) << getCredits() << "|" <<
			std::right << std::setw(4) << getStudyLoad() << "|";
		return os;
	}
	

}