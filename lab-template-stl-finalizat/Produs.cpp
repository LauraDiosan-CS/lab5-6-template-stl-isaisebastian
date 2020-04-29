#include "Produs.h"

Produs::Produs()
{
	this->code = "";
	this->price = 0;
	this->name = "";
}

Produs::Produs(string code, string name, float price)
{
	this->code = code;
	this->name = name;
	this->price = price;
}

Produs::Produs(const Produs& p)
{
	this->code = p.code;
	this->price = p.price;
	this->name = p.name;
}

Produs::~Produs()
{
}

string Produs::getCode()
{
	return this->code;
}

string Produs::getName()
{
	return this->name;
}

float Produs::getPrice()
{
	return this->price;
}

void Produs::setCode(string newCode)
{
	this->code = newCode;
}

void Produs::setName(string newName)
{
	this->name = newName;
}

void Produs::setPrice(float newPrice)
{
	this->price = newPrice;
}

Produs& Produs::operator=(const Produs p)
{
	this->setCode(p.code);
	this->setName(p.name);
	this->setPrice(p.price);
	return *this;
}

bool Produs::operator==(const Produs& p)
{
	return (this->code == p.code) && (this->price == p.price) && (this->name == p.name);
}

ostream& operator<<(ostream& os, const Produs& p)
{
	os << p.code << " " << p.name << " " << p.price;
	return os;
}

istream& operator>>(istream& is, Produs& p)
{
	string code;
	is >> code;
	p.setCode(code);
	string name;
	is >> name;
	p.setName(name);
	float price;
	is >> price;
	p.setPrice(price);
	return is;
}
