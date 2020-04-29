#pragma once
#include <iostream>
using namespace std;

class Produs {
private:
	string code;
	string name;
	float price;
public:
	Produs();
	Produs(string code, string name, float price);
	Produs(const Produs& p);
	~Produs();

	string getCode();
	string getName();
	float getPrice();

	void setCode(string newCode);
	void setName(string newName);
	void setPrice(float newPrice);

	Produs& operator=(const Produs p);
	bool operator==(const Produs& p);
	friend ostream& operator<<(ostream& os, const Produs& p);
	friend istream& operator>>(istream& is, Produs& p);
};