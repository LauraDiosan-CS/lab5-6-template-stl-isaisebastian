#include "TestRepoFile.h"
#include <cassert>

TestRepoFile::TestRepoFile()
{
	Produs p1("A230", "Ciocolata", 5.0);
	Produs p2("A231", "CocaCola", 3.5);
	Produs p3("A232", "Croissant", 2.0);
	Produs p4("A233", "BakeRolls", 4.5);
	Produs p5("A234", "Snickers", 3.5);
	this->produse.push_back(p1);
	this->produse.push_back(p2);
	this->produse.push_back(p3);
	this->produse.push_back(p4);
	this->produse.push_back(p5);
}

void TestRepoFile::test_repofile_addElem()
{
	this->repo.setf_name("TestProduse.txt");
	this->repo.loadfromfile();
	this->repo.clear();
	Produs p6("C321", "KitKat", 2.5);
	Produs p7("D333", "Acadele", 2.0);
	this->repo.addElem(p6);
	this->repo.addElem(p7);

	assert(this->repo.getSize() == 2);
	assert(this->repo.getAtPosition(0) == p6);
	assert(this->repo.getAtPosition(1) == p7);
}

void TestRepoFile::test_repofile_updateElem() {
	this->repo.setf_name("TestProduse.txt");
	this->repo.loadfromfile();
	this->repo.clear();
	Produs p6("C321", "KitKat", 2.5);
	Produs p7("D333", "Acadele", 2.0);
	Produs pNew("ABCD", "Bounty", 3.5);
	
	this->repo.addElem(p6);
	this->repo.addElem(p7);
	this->repo.updateElem(p6, pNew);

	assert(this->repo.getAll()[0] == pNew);
}

void TestRepoFile::test_repofile_delElem()
{
	this->repo.setf_name("TestProduse.txt");
	this->repo.loadfromfile();
	this->repo.clear();
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

void TestRepoFile::test_repofile_getAll() {
	this->repo.setf_name("TestProduse.txt");
	this->repo.loadfromfile();
	this->repo.clear();

	Produs p1("A123", "Ciocolata", 5.0);
	Produs p2("B231", "Snickers", 3.5);
	Produs p3("C333", "Acadea", 1.0);
	Produs p4("G665", "Pepsi", 4.5);

	this->repo.addElem(p1);
	this->repo.addElem(p2);
	this->repo.addElem(p3);
	this->repo.addElem(p4);

	assert(this->repo.getAll()[0] == p1);
	assert(this->repo.getAll()[1] == p2);
	assert(this->repo.getAll()[2] == p3);
	assert(this->repo.getAll()[3] == p4);
}

void TestRepoFile::testAll()
{
	this->test_repofile_addElem();
	this->test_repofile_delElem();
	this->test_repofile_getAll();
	this->test_repofile_updateElem();
}
