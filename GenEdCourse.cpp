#include <cstring>
#include "ScmApp.h"
#include "Course.h"
#include "GenEdCourse.h"
#include <iomanip>

using namespace std;
namespace sict {
	

	GenEdCourse::GenEdCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, int langLevel ) {
		int result = strcmp(courseCode, "");
		int result2 = strcmp(courseTitle, "");
		if (langLevel < 0 || langLevel >= 6) {
			langLevel = 0;
			setLangLevel(0);
		}
		
		if ((result != 0) && (result2 != 0) && (credits > 0) && (studyLoad > 0) && (langLevel >= 0)){
			
				setLangLevel(langLevel);
				setCourseCode(courseCode);
				setCourseTitle(courseTitle);
				setCredits(credits);
				setStudyLoad(studyLoad);
			

		}
		else {
			setCourseCode("");
			setCourseTitle("");
			setCredits(0);
			setStudyLoad(0);
			setLangLevel(0);

		}
	}
	GenEdCourse::GenEdCourse() {

		langLevel_ = 0;
	}

	int GenEdCourse::getLangLevel() const {

		return langLevel_;
	}

	void GenEdCourse::setLangLevel(int value) {
		if (value < 0 || value >= 6) {
			langLevel_ = 0;
			
		}
		else {
			langLevel_ = value;
		}
	}

	ostream& GenEdCourse::write(std::ostream& os) const {
		char title[21];

		strncpy(title, getCourseTitle(), 20);
		title[20] = '\0';
		os << std::left << std::setw(MAX_COURSECODE_LEN) << getCourseCode() << "  |  "
			<< std::left << std::setw(20) << title << "  |  " <<
			std::right << std::setw(6) << getCredits() << "  |  " <<
			std::right << std::setw(4) << getStudyLoad() << "  |      " 
			<<std::setw(6) << "    |     "
			<< langLevel_ <<"  |";
		return os;
	}

	std::ostream & operator<<(std::ostream & Q, GenEdCourse & item)
	{
		if (item.isEmpty() == false) {
			item.display(Q);

			return Q;
		}
		return Q;
	}

	fstream& GenEdCourse::store(fstream& fileStream, bool addNewLine) const {
		if (addNewLine == true) {
			fileStream << TYPE_GEN <<","<< getCourseCode() << "," << getCourseTitle() << "," << getCredits() << "," << getStudyLoad() << "," << getLangLevel() << endl;

			return fileStream;
		}
		else {
			fileStream <<TYPE_GEN <<","<< getCourseCode() << "," << getCourseTitle() << "," << getCredits() << "," << getStudyLoad() << "," << getLangLevel();
			return fileStream;
		}

	}

	fstream& GenEdCourse::load(fstream& file) {
		char code[25];
		char title[25];
		int credits;
		int load;
		int lang;

		file.getline(code, 25, ',');
		setCourseCode(code);

		// -----------------------------
		file.getline(title, 25, ',');
		
		setCourseTitle(title);
		// -----------------------------
		file << fixed;
		file << setprecision(2);
		file >> credits;
		setCredits(credits);
		file.ignore(1);


		file >> load;
		setStudyLoad(load);
		file.ignore(1);
		// -----------------------------
		
		file >> lang;
		setLangLevel(lang);
		
		// -----------------------------

		return file;


	}
	istream& GenEdCourse::read(std::istream& is) {
		char buf[2000];
		int ibuf;

		cout << "Course Code: ";
		is >> buf;
		setCourseCode(buf);

		cout << "Course Title: ";
		is >> buf;
		setCourseTitle(buf);

		cout << "Credits: ";
		is >> ibuf;
		setCredits(ibuf);

		cout << "Study Load: ";
		is >> ibuf;
		setStudyLoad(ibuf);

		cout << "Language Requirement: ";
		is >> ibuf;
		setLangLevel(ibuf);

		return is;
	}
}