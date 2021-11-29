#pragma once
#include "Class.h"
#include <vector>
#include <string>
using namespace std;

class ClassService {

public:

	void Add(Class clas);
	void Update(Class clas);
	void Delete(int classId);;
	void Get(int classId);
	void GetAll();
};