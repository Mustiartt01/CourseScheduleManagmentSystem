#pragma once
#include <string>
using namespace std;

class Course {

private:
	int id;
	string courseName;

public:
	Course(int id,string name) {
		this->id = id;
		this->courseName = name;
	}


	void setId(int id) {
		this->id = id;
	}

	int getId() {
		return this->id;
	}

	void setCourseName(string courseName) {
		this->courseName = courseName;
	}

	string getCourseName() {
		return this->courseName;
	}

};