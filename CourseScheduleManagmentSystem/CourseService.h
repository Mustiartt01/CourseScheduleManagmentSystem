#pragma once
#include "Course.h"
#include "sqlite/sqlite3.h"
using namespace std;

class CourseService {


public:
	void Add(Course course);
	void Update(Course course);
	void Delete(int courseId);;
	void Get(int courseId);
	void GetAll();
};