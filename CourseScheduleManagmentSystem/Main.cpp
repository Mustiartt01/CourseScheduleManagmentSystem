#include <iostream>
#include "DbService.h"
#include "ClassService.h"
#include "CourseService.h"
#include "Professor.h"
#include "ProfessorService.h"
#include "RoomService.h"
#include "SyllabusService.h"
#include "SyllabusDetailDto.h"
#include <list>
using namespace std;

DbContext DbCon;
sqlite3* DB;
char* ERROR_MESSAGE;

vector<string> v1;
vector<SyllabusDetailDto> baseDto;

static int callback2(void* data, int argc, char** argv, char** azColName)
{
	int i;

	for (i = 0; i < argc; i++) {

		v1.push_back(argv[i]);
	}

	return 0;
}


void SyllabusDetailService(int syllabusId) {



	sqlite3_open("CourseSchedule.db", &DB);

	string sql = "SELECT Professor.name, Class.grade, Course.courseName, Room.roomName FROM Professor, Room, Class, Course WHERE Professor.id = 1 AND Class.id = 1 AND Room.id = 1 AND Course.id = 1";

	sqlite3_exec(DB, sql.c_str(),callback2,0,&ERROR_MESSAGE);


}

void GetSyllabusDetail(vector<SyllabusDetailDto>& baseVector) {


	string professorName;
	string className;
	string courseName;
	string roomName;
	int lessonRange = 2;


	for (int i = 0; i < v1.size(); i++) {

		professorName = v1[i];
		i++;

		className = v1[i];
		i++;

		courseName = v1[i];
		i++;

		roomName = v1[i];
		i++;

		SyllabusDetailDto dto(professorName,courseName,roomName,className,lessonRange);

		baseVector.push_back(dto);

	}

}


int main() {
	
	Syllabus s1(1,1,1,1,1,2);

	SyllabusDetailService(1);

	GetSyllabusDetail(baseDto);

	

	

	for (int i = 0; i < baseDto.size();i++) {

		cout << "Profesor Name: " << baseDto[i].getProfessorName() << endl;
		cout << "Class Name: " << baseDto[i].getClassName() << endl;
		cout << "Room Name: " << baseDto[i].getRoomName() << endl;
		cout << "Course Name: " << baseDto[i].getCourseName() << endl;
	}
	
}
 