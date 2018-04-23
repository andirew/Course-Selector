#ifndef SICT_POSAPP_H__
#define SICT_POSAPP_H__

#include <fstream>

#include "general.h"
#include "Course.h"
#include "ICTCourse.h"
#include "GenEdCourse.h"
namespace sict {
	class ScmAppTester;
	class ScmApp: public ICTCourse, GenEdCourse {
		Course* courseList_[MAX_NO_RECS];
		int noOfCourses_;
		char _filename[128];
		std::fstream datafile_;


		void pause() const;
		int menu();
		void listCourses()const;
		int searchForACourse(const char* courseCode)const;
		void changeStudyLoad(const char* courseCode)const;
		void addACourse(char a);
		
		
		void saveRecs();
		void loadRecs();
	public:
		ScmApp(const char* filename);
		int run();
		friend class ScmAppTester;


	};
}
#endif
