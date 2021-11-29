#include "Syllabus.h"
#include "SyllabusService.h"
#include "sqlite/sqlite3.h"
#include "DbService.h"
#include <iostream>
#include "SyllabusDetailDto.h"

using namespace std;

extern sqlite3* DB;

extern DbContext DbCon;

extern char* ERROR_MESSAGE;




void SyllabusService::Add(Syllabus syllabus) {

	int result = sqlite3_open("CourseSchedule.db",&DB);

	const string sql = "INSERT INTO Syllabus(professorId,courseId,roomId,classId,lessonRange) VALUES ('" + DbCon.IntToString(syllabus.getProfessorId()) + "','"
		+ DbCon.IntToString(syllabus.getCourseId()) + "','"
		+ DbCon.IntToString(syllabus.getRoomId()) + "','"
		+ DbCon.IntToString(syllabus.getClassId())+ "','"
		+ DbCon.IntToString(syllabus.getLessonRange()) + 
 "');";

	sqlite3_exec(DB,sql.c_str(),DbCon.callback,0,&ERROR_MESSAGE);


	if (result != SQLITE_OK) {

		cout << "Error !!!" << endl;
	}
	else
		cout << "Syllabus Successfuly Added" << endl;

	sqlite3_close(DB);



}

void SyllabusService::Update(Syllabus syllabus) {

	int result = sqlite3_open("CourseSchedule.db", &DB);

	const string sql = "UPDATE Syllabus SET (professorId,courseId,roomId,classId,lessonRange) = ('" + DbCon.IntToString(syllabus.getProfessorId()) + "','"
		+ DbCon.IntToString(syllabus.getCourseId()) + "','"
		+ DbCon.IntToString(syllabus.getRoomId()) + "','"
		+ DbCon.IntToString(syllabus.getClassId()) + "','"
		+ DbCon.IntToString(syllabus.getLessonRange()) +
		"') where id = (" + DbCon.IntToString(syllabus.getId())+"); ";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, 0, &ERROR_MESSAGE);


	if (result != SQLITE_OK) {

		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}
	else
		cout << "Syllabus Successfuly Updated" << endl;

	sqlite3_close(DB);

}

void SyllabusService::Delete(int syllabusId) {

	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string sql = "DELETE from syllabus where id = " + DbCon.IntToString(syllabusId);

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, NULL, &ERROR_MESSAGE);

	if (result != SQLITE_OK) {
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}
	else
		std::cout << "Syllabus Successfully Deleted" << std::endl;

	sqlite3_close(DB);
}

void SyllabusService::Get(int id) {

	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string data = "Data \n";
	string sql = "SELECT * from syllabus where id =" + DbCon.IntToString(id);

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, (void*)data.c_str(), &ERROR_MESSAGE);

	if (result != SQLITE_OK) {
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}
	else
		std::cout << "Listed by id" << std::endl;
	sqlite3_close(DB);

}

void SyllabusService::GetAll() {

	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string data = "Data \n";
	string sql = "SELECT * from syllabus";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, (void*)data.c_str(), &ERROR_MESSAGE);

	if (result != SQLITE_OK) {
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}
	else
		cout << "All Syllabus Listed " << endl;
	sqlite3_close(DB);


}