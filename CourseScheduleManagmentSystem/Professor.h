#pragma once
#include <string>

using namespace std;

class Professor
{
private:
	 int id;
	 string name;
	 string lastName;

public:

	

	Professor(int id,string name,string lastName) {
		this->id = id;
		this->name = name;
		this->lastName = lastName;

	}

	void setId(int id) {
		this->id = id;
	}

	int getId() {
		return this->id;
	}

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return this->name;
	}

	void setLastName(string lastName) {
		this->lastName = lastName;
	}

	string getLastName() {
		return this->lastName;
	}

};








