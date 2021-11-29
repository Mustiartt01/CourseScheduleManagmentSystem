#include "Class.h"
#include "ClassService.h"
#include <iostream>
#include <fstream>
#include "Windows.h"
#include "DbService.h"
#include "sqlite/sqlite3.h"
#include <sstream>


using namespace std;
extern sqlite3* DB;
extern DbContext DbCon;
extern char* ERROR_MESSAGE;

void ClassService::Add(Class clas) {
	

    int result = sqlite3_open("CourseSchedule.db", &DB);
	
    const string sql = "INSERT INTO Class(grade) VALUES(" + clas.getGrade() + ");";

	sqlite3_exec(DB,sql.c_str() , DbCon.callback, 0, &ERROR_MESSAGE);

    if (result != SQLITE_OK) {

        cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
    }
    else
        std::cout << "Class Successfuly Added" << std::endl;

	sqlite3_close(DB);
}


void ClassService::Update(Class clas) {

	int result = sqlite3_open("CourseSchedule.db", &DB);
	
	const string sql = "UPDATE Class set grade = " + clas.getGrade() + " where id = " + DbCon.IntToString(clas.getId()) + ";";

	sqlite3_exec(DB,sql.c_str(), DbCon.callback,0,&ERROR_MESSAGE);

	if (result != SQLITE_OK) {
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}
	else
		std::cout << "Class Successfully Updated" << std::endl;

	sqlite3_close(DB);
}

void ClassService::Delete(int classId) {


	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string sql = "DELETE from Class where id = " + DbCon.IntToString(classId);

	sqlite3_exec(DB,sql.c_str(), DbCon.callback,NULL,&ERROR_MESSAGE);

	if (result != SQLITE_OK) {
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}
	else
		std::cout << "Class Successfully Deleted" << std::endl;

	sqlite3_close(DB);
}

void ClassService::Get(int classId) {

	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string data = "Data \n";
	string sql = "SELECT * from Class where id =" + DbCon.IntToString(classId);

	sqlite3_exec(DB,sql.c_str(), DbCon.callback,(void*)data.c_str(),&ERROR_MESSAGE);

	if (result != SQLITE_OK) {
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}
	else
		std::cout << "Listed by id" << std::endl;
	sqlite3_close(DB);
}

void ClassService::GetAll() {


	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string data = "Data \n";

	string sql = "SELECT * FROM Class";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, (void*)data.c_str(), &ERROR_MESSAGE);

	if (result != SQLITE_OK) {
		cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
	}
	else
		std::cout << "All class listed" << std::endl;
	sqlite3_close(DB);
	
}
