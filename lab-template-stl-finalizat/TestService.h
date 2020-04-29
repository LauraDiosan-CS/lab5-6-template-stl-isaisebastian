#pragma once
#include "Service.h"
#include "Repository.h"
#include "RepoFile.h"
#include "Produs.h"
#include "Bani.h"
#include <vector>
#include <map>

class TestService {
private:
	Service s;
	
	void test_addProdus();
	void test_updateProdus();
	void test_deleteProdus();

	void test_moneytonomate();
	void test_giverest();
	void test_deleterest();
	void test_getSumOfCoins();
public:
	TestService();
	void testAll();
};