#ifndef SICT_Course_H__
#define SICT_Course_H__
#include "general.h"
#include "Streamable.h"
namespace sict {
	class Course : public Streamable {
		char courseCode_[MAX_COURSECODE_LEN + 1]; //sku_ = courseCode_;
		int credits_; //qty = credits;
		int studyLoad_;//quantity
		char* courseTitle_ ;//name_ = coursTitle_
		



	public:

		Course(const Course & B);
		Course();
		Course(const char* courseCode, const char* courseTitle, int credits = 0, int studyLoad = 0);
	


	
		void setCourseCode(const char* value);
	
		void setCourseTitle(const char* n);
		
		void setStudyLoad(int p);
		void setCredits(int q);

		
		
		const char* getCourseCode()const;
		const char*  getCourseTitle() const;
		int  getCredits() const;
		int  getStudyLoad() const;
		const bool isEmpty() const;

		std::ostream& display(std::ostream& os) const;
		bool operator==(const char* coursecode) const;

		int operator+=(int);

		


	};


	std::ostream & operator<<(std::ostream&, Course &);


}

#endif