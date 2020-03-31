#pragma once
#include <vector>
#include "Repository.h"

class TestRepository {
private:
	Repository repo;
	vector<Tonomat> tonomatsIn;

	void testGetAll();
	void testAddElem();
	void testEntity_get_sets();
public:
	TestRepository();
	void testAll();
};