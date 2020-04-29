#pragma once
#include "Produs.h"
#include "Repository.h"

class TestRepository
{
private:
	Repository<Produs> repo;
	vector<Produs> produse;

	void test_addElem();
	void test_deleteElem();
	void test_updateElem();
	void test_getAll();
public:
	TestRepository();
	void testAll();
};
