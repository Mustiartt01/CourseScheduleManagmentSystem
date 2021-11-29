#pragma once
#include "Syllabus.h"

using namespace std;

class SyllabusService {

public:
	void Add(Syllabus syllabus);
	void Delete(int syllabusId);
	void Update(Syllabus syllabus);
	void Get(int id);
	void GetAll();

};