#include "Course.h"
#include "CourseService.h"
#include "DbService.h"
#include <iostream>
#include "sqlite/sqlite3.h"

using namespace std;

extern DbContext DbCon;
extern sqlite3* DB;
extern char* ERROR_MESSAGE;

void CourseService::Add(Course course) {


	int result = sqlite3_open("CourseSchedule.db", &DB);

	const string sql = "INSERT INTO Course(courseName) VALUES ('" + course.getCourseName() + "');";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, 0, &ERROR_MESSAGE);

	if (result != SQLITE_OK)
	{
		cout << "Error !!!";
		sqlite3_errmsg(DB);
	}
	else
	{
		cout << "Course Succesfully Added";
	}

	sqlite3_close(DB);
}

void CourseService::Update(Course course) {

	int result = sqlite3_open("CourseSchedule.db", &DB);

	const string sql = "UPDATE Course set courseName = '" + course.getCourseName() + "' where id = " + DbCon.IntToString(course.getId()) + ";";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, 0, &ERROR_MESSAGE);

	if (result != SQLITE_OK)
	{
		cout << "Error !!!";
		sqlite3_errmsg(DB);
	}
	else
	{
		cout << "Course Succesfully Updated";
	}

	sqlite3_close(DB);
}

void CourseService::Delete(int courseId) {


	int result = sqlite3_open("CourseSchedule.db", &DB);

	const string sql = "DELETE from Course where id = " + DbCon.IntToString(courseId) + ";";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, 0, &ERROR_MESSAGE);

	if (result != SQLITE_OK)
	{
		cout << "Error !!!";
		sqlite3_errmsg(DB);
	}
	else
	{
		cout << "Course Succesfully Deleted";
	}

	sqlite3_close(DB);
}

void CourseService::Get(int courseId) {


	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string data = "Data\n";

	const string sql = "SELECT *  from Course where id = " + DbCon.IntToString(courseId) + ";";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, (void*)data.c_str(), &ERROR_MESSAGE);

	if (result != SQLITE_OK)
	{
		cout << "Error !!!";
		sqlite3_errmsg(DB);
	}
	else
	{
		cout << "Listed by id";
	}

	sqlite3_close(DB);
}

void CourseService::GetAll() {


	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string data = "Data\n";

	const string sql = "SELECT *  from Course;";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, (void*)data.c_str(), &ERROR_MESSAGE);

	if (result != SQLITE_OK)
	{
		cout << "Error !!!";
		sqlite3_errmsg(DB);
	}
	else
	{
		cout << "All Course listed";
	}

	sqlite3_close(DB);
}