
#ifndef SICT_GenEdCourse_H__
#define SICT_GenEdCourse_H__
#include "general.h"
#include "Course.h"
#include <iostream>
namespace sict {
	class GenEdCourse :public Course {
		int langLevel_;
	public:
		GenEdCourse(int lang);
		GenEdCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, int langLevel = 0);
		GenEdCourse();

		int getLangLevel() const;
		
		void setLangLevel(int value);

		std::ostream& write(std::ostream& os) const;
		std::fstream& store(std::fstream& file, bool addNewLine = true)const;
		std::fstream& load(std::fstream& file);
		std::istream& read(std::istream& is);
	};
	std::ostream & operator<<(std::ostream&, GenEdCourse &);
}

#endif