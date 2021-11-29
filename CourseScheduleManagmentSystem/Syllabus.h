#pragma once
#include <string>
using namespace std;

class Syllabus
{
private:
	int id;
	int professorId;
	int courseId;
	int roomId;
	int classId;
	int lessonRange;

public:



	Syllabus(int id, int pName, int cName, int room,int classId,int lRange) {

		this->id = id;
		this->professorId = pName;
		this->courseId = cName;
		this->roomId = room;
		this->classId = classId;
		this->lessonRange = lRange;
	}
	

	void setId(int id) {
		this->id = id;
	}

	int getId() {
		return this->id;
	}

	void setProfessorId(int profName) {
		this->professorId = profName;
	}

	int getProfessorId() {
		return this->professorId;
	}
	void setCourseId(int courseName) {
		this->courseId = courseName;
	}

	int getCourseId() {
		return this->courseId;
	}

	void setRoomId(int roomName) {
		this->roomId = roomName;
	}

	int getRoomId() {
		return this->roomId;
	}

	void setClassId(int classId) {
		this->classId = classId;
	}

	int getClassId() {
		return this->classId;
	}

	void setLessonRange(int lessonRange) {
		this->lessonRange = lessonRange;
	}

	int getLessonRange() {
		return this->lessonRange;
	}


};

