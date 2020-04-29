#pragma once
#include <iostream>
using namespace std;

class Bani
{
private:
	int numOfCoins;
	float coin;
public:
	Bani();
	Bani(int numOfCoins, float coin);
	Bani(const Bani& b);
	~Bani();

	int getNr();
	float getCoin();
	
	void setNr(int nr);
	void setCoin(float coin);

	Bani& operator=(const Bani& b);
	bool operator==(const Bani& b);
	friend ostream& operator<<(ostream& os, const Bani& b);
	friend istream& operator>>(istream& is, Bani& b);
};