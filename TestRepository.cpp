#include "TestRepository.h"
#include <assert.h>

TestRepository::TestRepository() {
	Tonomat t1(3, "croissant", 5);
	Tonomat t2(4, "ciocolata", 3);
	Tonomat t3(5, "fanta", 4);
}

void TestRepository::testEntity_get_sets() {
	Tonomat t1(20, "coca cola", 5);
	this->repo.addElem(t1);
	assert(this->repo.getAll()[0].getCode() == 20);
	assert(this->repo.getAll()[0].getName() == "coca cola");
	assert(this->repo.getAll()[0].getPrice() == 5);
	this->repo.getAll()[0].setCode(30);
	this->repo.getAll()[0].setPrice(6);
	this->repo.getAll()[0].setName("sprite");
	assert(this->repo.getAll()[0].getCode() == 30);
	assert(this->repo.getAll()[0].getName() == "sprite");
	assert(this->repo.getAll()[0].getPrice() == 6);
}

void TestRepository::testAddElem() {
	Tonomat t(30, "ciocolata", 5);
	this->repo.addElem(t);
	assert(this->repo.getSize() == 1);
}

void TestRepository::testGetAll() {
	vector<Tonomat> tonomats = this->repo.getAll();
	for (int i = 0; i < this->repo.getSize(); i++) {
		assert(tonomats[i] == this->tonomatsIn[i]);
	}
}

void TestRepository::testAll() {
	this->testAddElem();
	this->testGetAll();
	this->testEntity_get_sets();
}