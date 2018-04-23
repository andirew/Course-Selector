#pragma once
#ifndef SICT_ICTCourse_H__
#define SICT_ICTCourse_H__
#include "general.h"
#include "Course.h"


namespace sict {
	class ICTCourse:public Course{
		char computerSystem_[6 + 1];
	public:
		ICTCourse();
		ICTCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, const char* computerSystem = "matrix");

	
		const char* getComputerSystem() const;
		void setComputerSystem(const char* value);
		std::ostream& write(std::ostream& os) const;
		std::fstream& store(std::fstream& file, bool addNewLine = true)const;
		std::fstream& load(std::fstream& file);
		std::istream& read(std::istream& is);
	};
	std::ostream & operator<<(std::ostream&, ICTCourse &);
}

#endif