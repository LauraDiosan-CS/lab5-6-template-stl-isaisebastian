#include "TestService.h"
#include <cassert>

TestService::TestService() {}

void TestService::testAll()
{
	this->test_addProdus();
	this->test_moneytonomate();
	this->test_giverest();
	this->test_getSumOfCoins();
	this->test_deleterest();
	this->test_deleteProdus();
}

void TestService::test_addProdus() {
	Service s(RepoFile<Produs> repoProdus, RepoFile<Bani> repoMoney);

	Produs p1("A230", "Ciocolata", 5.0);
	Produs p2("A231", "CocaCola", 3.5);
	Produs p3("A232", "Croissant", 2.0);
	Produs p4("A233", "BakeRolls", 4.5);
	Produs p5("A234", "Snickers", 3.5);

	this->s.addProdus("A230", "Ciocolata", 5.0);
	this->s.addProdus("A231", "CocaCola", 3.5);
	this->s.addProdus("A234", "Snickers", 3.5);

	assert(this->s.getAllProducts()[0] == p1);
	assert(this->s.getAllProducts()[1] == p2);
	assert(this->s.getAllProducts()[2] == p5);
}

void TestService::test_updateProdus() {
	Produs p1("A230", "Ciocolata", 5.0);
	Produs p2("A231", "CocaCola", 3.5);
	Produs p3("A232", "Croissant", 2.0);
	Produs p4("UPDATE", "Milka", 2.0);
	Produs p5("A234", "Snickers", 3.5);

	this->s.addProdus("A230", "Ciocolata", 5.0);
	this->s.addProdus("A231", "CocaCola", 3.5);
	this->s.addProdus("A234", "Snickers", 3.5);
	this->s.updateProdus("A230", "UPDATE", "Milka", 2.0);

	assert(this->s.getAllProducts()[0] == p4);
}

void TestService::test_deleteProdus() {
	Produs p1("A238", "Ciocolata", 5.0);
	Produs p2("A231", "CocaCola", 3.5);
	Produs p3("A232", "Croissant", 2.0);
	Produs p4("A233", "BakeRolls", 4.5);
	Produs p5("A234", "Snickers", 3.5);


	this->s.addProdus("A238", "Ciocolata", 5.0);
	this->s.addProdus("A231", "CocaCola", 3.5);
	this->s.addProdus("A234", "Snickers", 3.5);
	this->s.deleteProdus("A238");
	
	assert(!(this->s.getAllProducts()[0] == p1));

}

void TestService::test_moneytonomate() {
	Bani b1(5, 0.5);
	Bani b2(10, 0.1);
	this->s.addMoney(5, 0.5);
	this->s.addMoney(10, 0.1);

	assert(this->s.moneytonomate() == 3.5);
}

void TestService::test_giverest() {
	this->s.addMoney(6, 0.5);
	this->s.addMoney(10, 0.1);

	assert(this->s.give_rest(5, 5) == 1);
}

void TestService::test_deleterest() {
	this->s.addMoney(5, 0.5);
	this->s.addMoney(10, 0.1);
	assert(this->s.deleteMoneyTonomate(3.5) == 1);
}

void TestService::test_getSumOfCoins() {
	this->s.addMoney(12, 0.50);
	assert(this->s.getSumOfCoins(12, 0.5) == 6.0);
}

