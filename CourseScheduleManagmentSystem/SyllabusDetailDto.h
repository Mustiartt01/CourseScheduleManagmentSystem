#pragma once
#include <string>

using namespace std;

class SyllabusDetailDto
{
private:
	string professorName;
	string courseName;
	string roomName;
	string className;
	int lessonRange;

public:

	 SyllabusDetailDto(string profName,string courseName,string roomName,string className,int lessonRange) {
		this->professorName = profName;
		this->roomName = roomName;
		this->courseName = courseName;
		this->className = className;
		this->lessonRange = lessonRange;
		
	}

	 void setProfessorName(string profName) {
		 this->professorName = profName;
	 }

	 string getProfessorName() {
		 return this->professorName;
	 }

	 void setCourseName(string courseName) {
		 this->courseName = courseName;
	 }

	 string getCourseName() {
		 return this->courseName;
	 }

	 void setRoomName(string roomName) {
		 this->roomName = roomName;
	 }

	 string getRoomName() {
		 return this->roomName;
	 }

	 void setClassName(string className) {
		 this->className = className;
	 }

	 string getClassName() {
		 return this->className;
	 }

	 void setLessonRange(int lessonRange) {
		 this->lessonRange = lessonRange;
	 }

	 int getLessonRange() {
		 return this->lessonRange;
	 }



};