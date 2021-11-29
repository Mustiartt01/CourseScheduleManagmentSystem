#pragma once
#include "Room.h"
using namespace std;

class RoomService {
public:
	void Add(Room room);
	void Delete(int roomId);
	void Update(Room room);
	void Get(int roomId);
	void GetAll();
};