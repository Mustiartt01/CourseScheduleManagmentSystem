#include "Professor.h"
#include "ProfessorService.h"
#include <iostream>
#include "sqlite/sqlite3.h"
#include "DbService.h"
#include <string>


using namespace std;

extern DbContext DbCon;
extern 	sqlite3* DB;
extern char* ERROR_MESSAGE;

void ProfessorService::Add(Professor professor) {



	int result = sqlite3_open("CourseSchedule.db", &DB);

	const string sql = "INSERT INTO Professor(name) VALUES ('" + professor.getName() + "');";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, 0, &ERROR_MESSAGE);

	if (result != SQLITE_OK)
	{
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}

	else
	{
		cout << "Professor Successfuly Added" << endl;
	}

	sqlite3_close(DB);
}


void ProfessorService::Update(Professor professor) {


	int result = sqlite3_open("CourseSchedule.db", &DB);

	const string sql = "UPDATE Professor SET (name) = ('" + professor.getName() + "') where id = (" + DbCon.IntToString(professor.getId()) + ");";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, 0, &ERROR_MESSAGE);

	if (result != SQLITE_OK) {
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}
	else
		std::cout << "Professor Successfully Updated" << std::endl;

	sqlite3_close(DB);

}

void ProfessorService::Delete(int professorId) {



	int result = sqlite3_open("CourseSchedule.db", &DB);

	const string sql = "DELETE from Professor where id = " + DbCon.IntToString(professorId);

	sqlite3_exec(DB,sql.c_str(),DbCon.callback,0,&ERROR_MESSAGE);

	if (result != SQLITE_OK)
	{
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}

	else
	{
		cout << "Professor Successfuly Deleted" << endl;
	}

	sqlite3_close(DB);

}



void ProfessorService::Get(int professorId) {


	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string data = "Data \n";
	string sql = "SELECT * from Professor where id =" + DbCon.IntToString(professorId);

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, (void*)data.c_str(), &ERROR_MESSAGE);

	if (result != SQLITE_OK) {
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}
	else
		std::cout << "Listed by id" << std::endl;

	sqlite3_close(DB);

}


void ProfessorService::GetAll(){


	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string data = "Data \n";
	string sql = "SELECT * from Professor";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, (void*)data.c_str(), &ERROR_MESSAGE);

	if (result != SQLITE_OK) {
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}
	else
		std::cout << "All Professor Listed" << std::endl;

	sqlite3_close(DB);


}
