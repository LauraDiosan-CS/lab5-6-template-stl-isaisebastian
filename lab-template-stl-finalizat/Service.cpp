#include "Service.h"

Service::Service() {

}

Service::Service(const RepoFile<Produs>& produse, const RepoFile<Bani>& money) {
	this->repo_product = produse;
	this->repo_money = money;
}

Service::Service(const Service& s) {
	this->repo_money = s.repo_money;
	this->repo_product = s.repo_product;
	this->money_in = s.money_in;
}

Service::~Service() {
	money_in.clear();
}

void Service::addProdus(string code, string name, float price) {
	this->repo_product.addElement(Produs(code, name, price));
	this->repo_product.savetofile();
}

vector<Produs> Service::getAllProducts()
{
	return this->repo_product.getAll();
}


void Service::updateProdus(string code, string newcode, string newname, float newprice) {
	vector<Produs> produse = this->repo_product.getAll();
	Produs newProdus(newcode, newname, newprice);
	vector<Produs>::iterator it = produse.begin();
	while (it != produse.end()) {
		if ((*it).getCode() == code) {
			Produs oldProdus(code, (*it).getName(), (*it).getPrice());
			this->repo_product.updateElem(oldProdus, newProdus);
			return;
		}
		it++;
	}
	this->repo_product.savetofile();
}

void Service::deleteProdus(string code) {
	for (int i = 0; i < this->repo_product.getSize(); i++)
	{
		if (this->repo_product.getAll()[i].getCode() == code) {
			Produs produs(code, this->repo_product.getAll()[i].getName(), this->repo_product.getAll()[i].getPrice());
			this->repo_product.delElem(produs);
			return;
		}
	}
	this->repo_product.savetofile();
}

float Service::getProductPriceByCode(const string code) {
	vector<Produs> produse = repo_product.getAll();
	for (int i = 0; i < repo_product.getSize(); i++) {
		if (produse[i].getCode() == code)
			return produse[i].getPrice();
	}
	return 0;
}

void Service::addMoney(int numOfCoins, float coin) {
	this->repo_money.addElem(Bani(numOfCoins, coin));
}

float Service::getSumOfCoins(int numofCoins, float coin)
{
	return coin * numofCoins;
}

vector<Bani> Service::getAllMoney()
{
	return this->repo_money.getAll();
}

void Service::clear() {
	money_in.clear();
}

void Service::updateMoney(int numOfCoins, float coin) {
	vector<Bani> bani = this->repo_money.getAll();
	Bani newb(numOfCoins - 1, coin);
	for (int i = 0; i < this->repo_money.getSize(); i++)
	{
		if (equalfloat(bani[i].getCoin(), coin)) {
			Bani oldB(numOfCoins, bani[i].getCoin());
			this->repo_money.updateElem(oldB, newb);
			return;
		}
	}
	this->repo_money.savetofile();
}

float Service::how_much_money(string code, int numOfCoins, float coin) {
	int price;
	vector<Produs> produse = repo_product.getAll();
	vector<Produs>::iterator it = produse.begin();
	while (it != produse.end()) {
		if ((*it).getCode() == code) {
			price = (*it).getPrice() - getSumOfCoins(numOfCoins, coin);
		}
		it++;
	}
	return price;
}

int Service::money_to_add(string code, int numOfCoins, float coin) {
	if (how_much_money(code, numOfCoins, coin) <= 0)
		return 0;
	else 
		return 1;
}

int Service::equalfloat(float nr1, float nr2) {
	float var = 0.0001;
	if (abs(nr1 - nr2) < var)
		return 1;
	else 
		return 0;
}

int Service::deleteMoneyTonomate(float rest) {
	float sum = 0.0;
	int numOfCoins;
	for (int i = 0; i < this->repo_money.getSize();) {
		if ((equalfloat(this->repo_money.getAll()[i].getCoin(), 0.5) && (rest - sum >= 0.5) && (this->repo_money.getAll()[i].getNr() > 0) && (rest-sum > 0.0))) {
			numOfCoins = this->repo_money.getAll()[i].getNr();
			updateMoney(numOfCoins, this->repo_money.getAll()[i].getCoin());
			sum += 0.5;
		}
		else
			i++;
	}

	for (int i = 1; i < this->repo_money.getSize();) {
		if (equalfloat(this->repo_money.getAll()[i].getCoin(), 0.1) && (rest - sum >= 0.1) && (this->repo_money.getAll()[i].getNr() > 0.0) && (rest - sum > 0.0)) {
			numOfCoins = this->repo_money.getAll()[i].getNr();
			updateMoney(numOfCoins, this->repo_money.getAll()[i].getCoin());
			sum += 0.1;
		}
		else
			i++;
	}
	if (equalfloat(rest, sum))
		return 1;
	else 
		return 0;
}

int Service::give_rest(float sum, float price) {
	if (equalfloat(sum, price))
		return 1;
	else {
		if (deleteMoneyTonomate(sum - price) == 1)
			return 1;
		else 
			return -1;
	}
}

float Service::moneytonomate() {
	float money = 0.0;
	for (int i = 0; i < this->repo_money.getSize(); i++)
		money += getSumOfCoins(this->repo_money.getAll()[i].getNr(), this->repo_money.getAll()[i].getCoin());
	return money;
}

void Service::delete_rest() {
	for (int i = 0; i < this->repo_money.getSize(); i++)
		if (this->repo_money.getAll()[i].getNr() == 0)
			this->repo_money.delElem(this->repo_money.getAll()[i]);
	this->repo_money.savetofile();
}
 