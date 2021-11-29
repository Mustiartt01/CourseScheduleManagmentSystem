#include "Room.h"
#include "RoomService.h"
#include "sqlite/sqlite3.h"
#include <iostream>
#include "DbService.h"

using namespace std;

extern DbContext DbCon;
extern char* ERROR_MESSAGE;
extern sqlite3* DB;


void RoomService::Add(Room room) {

    
    int result = sqlite3_open("CourseSchedule.db", &DB);

    const string sql = "INSERT INTO Room(name) VALUES('" + room.getName() + "');";

    sqlite3_exec(DB, sql.c_str(), DbCon.callback, 0, &ERROR_MESSAGE);

    if (result != SQLITE_OK) {

        cout << "Error !!!" << endl;
		sqlite3_errmsg(DB);
    }
    else
        cout << "Room Successfully Added" << endl;

    sqlite3_close(DB);
}


void RoomService::Update(Room room) {

	int result = sqlite3_open("CourseSchedule.db", &DB);

	const string sql = "UPDATE Room set name = '" + room.getName() + "' where id = " + DbCon.IntToString(room.getId()) + ";";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, 0, &ERROR_MESSAGE);

	if (result != SQLITE_OK)
	{
		cout << "Error !!!";
		sqlite3_errmsg(DB);
	}
	else
	{
		cout << "Room Successfully Updated";
	}

	sqlite3_close(DB);
}

void RoomService::Delete(int roomId) {

	int result = sqlite3_open("CourseSchedule.db", &DB);

	const string sql = "DELETE from Room where id = " + DbCon.IntToString(roomId) + ";";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, 0, &ERROR_MESSAGE);

	if (result != SQLITE_OK)
	{
		cout << "Error !!!";
		sqlite3_errmsg(DB);
	}
	else
	{
		cout << "Room Successfully Deleted";
	}

	sqlite3_close(DB);


}

void RoomService::Get(int roomId) {

	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string data = "Data\n";

	const string sql = "SELECT *  from Room where id = " + DbCon.IntToString(roomId) + ";";

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

void RoomService::GetAll() {

	int result = sqlite3_open("CourseSchedule.db", &DB);
	const string data = "Data\n";

	const string sql = "SELECT *  from Room;";

	sqlite3_exec(DB, sql.c_str(), DbCon.callback, (void*)data.c_str(), &ERROR_MESSAGE);

	if (result != SQLITE_OK)
	{
		cout << "Error !!!";
		sqlite3_errmsg(DB);
	}
	else
	{
		cout << "All course listed";
	}

	sqlite3_close(DB);

}