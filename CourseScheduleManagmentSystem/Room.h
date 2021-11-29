#pragma once
#include <string>

using namespace std;

class Room
{
private:

	int id;
	string name;

public:

	Room(int id,string name) {
		this->id = id;
		this->name = name;
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

};