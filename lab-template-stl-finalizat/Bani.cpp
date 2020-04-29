#include "Bani.h"

Bani::Bani()
{
	this->numOfCoins = 0;
	this->coin = 0.0;
}

Bani::Bani(int n, float coin) {
	this->numOfCoins = n;
	this->coin = coin;
}

Bani::Bani(const Bani& b) {
	this->numOfCoins = b.numOfCoins;
	this->coin = b.coin;
}

int Bani::getNr() {
	return this->numOfCoins;
}

float Bani::getCoin() {
	return this->coin;
}

void Bani::setCoin(float coin) {
	this->coin = coin;
}

void Bani::setNr(int nr) {
	this->numOfCoins = nr;
}

Bani& Bani::operator=(const Bani& b)
{
	this->setNr(b.numOfCoins);
	this->setCoin(b.coin);
	return *this;
}

bool Bani::operator==(const Bani& b)
{
	return (this->numOfCoins == b.numOfCoins) && (this->coin == b.coin);
}

ostream& operator<<(ostream& os, const Bani& b)
{
	os << b.numOfCoins << "	" << b.coin;
	return os;
}

istream& operator>>(istream& is, Bani& b)
{
	int numOfCoins;
	is >> numOfCoins;
	b.setNr(numOfCoins);
	float coin;
	is >> coin;
	b.setCoin(coin);
	return is;
}

Bani::~Bani() {
}