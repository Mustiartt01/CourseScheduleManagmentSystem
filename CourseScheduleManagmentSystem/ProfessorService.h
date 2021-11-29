#pragma once
#include "Professor.h"

class ProfessorService {

public:
	void Add(Professor professor);
	void Delete(int professorId);
	void Update(Professor professor);
	void Get(int professorId);
	void GetAll();

};