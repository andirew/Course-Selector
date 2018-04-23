#ifndef SCMAPPTESTER_H
#define SCMAPPTESTER_H

#include "ScmApp.h"
namespace sict {

	class ScmAppTester {
		ScmApp* s;

	public:
		ScmAppTester() { s = new sict::ScmApp("oms4.txt"); }
		~ScmAppTester() { delete s; }

		void load();

		bool saveAndLoadCourses();

		void runAllTests();
	};
}
#endif
