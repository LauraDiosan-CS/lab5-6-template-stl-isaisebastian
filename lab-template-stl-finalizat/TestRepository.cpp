#include "TestRepository.h"
#include <cassert>
using namespace std;

TestRepository::TestRepository() {}

void TestRepository::testAll()
{
	this->test_addElem();
	this->repo.clear();
	this->test_deleteElem();
	this->repo.clear();
	this->test_getAll();
	this->repo.clear();
	this->test_updateElem();
}

void TestRepository::test_addElem()
{
	Produs p1("A123", "Ciocolata", 5.0);
	Produs p2("B231", "Snickers", 3.5);
	Produs p3("C333", "Acadea", 1.0);
	Produs p4("G665", "Pepsi", 4.5);

	this->repo.addElem(p1);
	this->repo.addElem(p2);
	this->repo.addElem(p3);
	this->repo.addElem(p4);

	assert(this->repo.getSize() == 4);
	assert(this->repo.getAtPosition(0) == p1);
	assert(this->repo.getAtPosition(3) == p4);
}

void TestRepository::test_deleteElem()
{
	Produs p1("A123", "Ciocolata", 5.0);
	Produs p2("B231", "Snickers", 3.5);
	Produs p3("C333", "Acadea", 1.0);
	Produs p4("G665", "Pepsi", 4.5);

	this->repo.addElem(p1);
	this->repo.addElem(p2);
	this->repo.delElem(p2);

	assert(this->repo.getSize() == 1);
	assert(this->repo.getAtPosition(0) == p1);
}

void TestRepository::test_updateElem()
{
	Produs p1("A123", "Ciocolata", 5.0);
	Produs p2("B231", "Snickers", 3.5);
	Produs p3("C333", "Acadea", 1.0);
	Produs p4("G665", "Pepsi", 4.5);
	Produs p5("M595", "Baton", 3.5);

	this->repo.addElem(p1);
	this->repo.addElem(p2);
	this->repo.addElem(p3);
	this->repo.updateElem(p2, p4);

	assert(this->repo.getSize() == 3);
	assert(this->repo.getAtPosition(1) == p4);
}

void TestRepository::test_getAll()
{
	Produs p1("A123", "Ciocolata", 5.0);
	Produs p2("B231", "Snickers", 3.5);
	Produs p3("C333", "Acadea", 1.0);
	Produs p4("G665", "Pepsi", 4.5);
	Produs p5("M595", "Baton", 3.5);

	this->repo.addElem(p1);
	this->repo.addElem(p2);
	this->repo.addElem(p3);
	this->repo.addElem(p4);
	this->repo.addElem(p5);

	assert(this->repo.getSize() == 5);
	assert(this->repo.getAll()[0] == p1);
	assert(this->repo.getAll()[1] == p2);
	assert(this->repo.getAll()[2] == p3);
	assert(this->repo.getAll()[3] == p4);
}