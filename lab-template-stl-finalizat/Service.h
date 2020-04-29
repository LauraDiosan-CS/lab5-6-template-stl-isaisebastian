#pragma once
#include "Produs.h"
#include "Bani.h"
#include "RepoFile.h"
#include <iostream>
#include <map>

class Service {
private:
	map<int, float> money_in;
	RepoFile<Produs> repo_product;
	RepoFile<Bani> repo_money;
public:
	Service();
	Service(const RepoFile<Produs>& produse, const RepoFile<Bani>& bani);
	Service(const Service& s);
	~Service();

	void addProdus(string code, string name, float price);
	void updateProdus(string code, string newcode, string newname, float newprice);
	void deleteProdus(string code);
	vector<Produs> getAllProducts();
	float getProductPriceByCode(const string code);
	void addMoney(int numOfCoins, float coin);
	float getSumOfCoins(int numOfCoins, float coin);
	vector<Bani> getAllMoney();
	void clear();
	void updateMoney(int numOfCoins, float coin);
	int equalfloat(float nr1, float nr2);
	float moneytonomate();
	int give_rest(float sum, float price);
	int deleteMoneyTonomate(float rest);
	float how_much_money(string code, int numOfCoins, float coin);
	int money_to_add(string code, int numOfCoins, float coin);
	void delete_rest();
};