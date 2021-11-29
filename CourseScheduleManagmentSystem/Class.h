#pragma once
#include <string>

using namespace std;

class Class {
private:
	int id;
	string grade;

public:

	Class(int id, string grade) {
		this->id = id;
		this->grade = grade;
	}

	void setId(int id) {
		this->id = id;
	}

	int getId() {
		return this->id;
	}
	void setGrade(string grade) {
		this->grade = grade;
	}

	string getGrade() {
		return this->grade;
	}
};