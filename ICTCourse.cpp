#include <cstring>
#include "ScmApp.h"
#include "Course.h"
#include "ICTCourse.h"
#include <iomanip>
#include "GenEdCourse.h"
#include "Streamable.h"
using namespace std;
namespace sict{
	ICTCourse::ICTCourse() {
			
		setCourseCode("");
		setCourseTitle("");
		setCredits(0);
		setStudyLoad(0);
		setComputerSystem("");


	}
	ICTCourse::ICTCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, const char* computerSystem) {
		int result = strcmp(courseCode, "");
		int result2 = strcmp(courseTitle, "");
		
	
		if ((result != 0) && (result2 != 0) && (credits > 0) && (studyLoad > 0)) {
			computerSystem_[6] = '\0';
			strncpy(computerSystem_, computerSystem, 6);
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
			setComputerSystem("");

		}

	}


	const char* ICTCourse::getComputerSystem() const {
		return computerSystem_;
	}
	void ICTCourse::setComputerSystem(const char* value) {
		
		strncpy(computerSystem_, value, 6);
	}

	ostream& ICTCourse::write(std::ostream& os) const {
		char title[21];
		
		strncpy(title, getCourseTitle(),20);
		title[20] = '\0';
		os << std::left << std::setw(MAX_COURSECODE_LEN) << getCourseCode() << "  |  "
			<<std::left << std::setw(20)<< title << "  |  " <<
			std::right <<std::setw(6)<<getCredits() << "  |  " <<
			std::right <<std::setw(4) << getStudyLoad() << "  |  " 
			<< computerSystem_ <<"  |        |";
		return os;
	}

	std::ostream & operator<<(std::ostream & Q, ICTCourse & item)
	{
		if (item.isEmpty() == false) {
			item.display(Q);

			return Q;
		}
		return Q;
	}

	fstream& ICTCourse::store(fstream& fileStream, bool addNewLine) const{
		if (addNewLine == true) {
			fileStream << TYPE_ICT<<"," << getCourseCode() << "," << getCourseTitle() << "," << getCredits() << "," << getStudyLoad() << "," << getComputerSystem()<< endl;

			return fileStream;
		}
		else {
			fileStream <<TYPE_ICT<<","<< getCourseCode() << "," << getCourseTitle() << "," << getCredits() << "," << getStudyLoad() << "," << getComputerSystem();
			return fileStream;
		}

	}

	fstream& ICTCourse::load(fstream& file) {
		char code[25];
		char title[100];
		int credits;
		int load;
		char system[25];

		file.getline(code, 25, ',');
		setCourseCode(code);

		// -----------------------------
		file.getline(title, 100, ',');
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
		file.getline(system, 41 , ',');
		
		setComputerSystem(system);

		// -----------------------------

		return file;


	}
	istream& ICTCourse::read(std::istream& is) {
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

		cout << "Computer System: ";
		is >> buf;
		setComputerSystem(buf);

		return is;
	}




}