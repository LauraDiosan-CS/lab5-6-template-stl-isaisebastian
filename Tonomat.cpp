#include "Tonomat.h"
#include <iostream>
using namespace std;

Tonomat::Tonomat() {
	this->code = 0;
	this->price = 0;
	this->name = NULL;
}

Tonomat::Tonomat(int code, const char* name, int price) {
	this->code = code;
	this->price = price;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

Tonomat::Tonomat(const Tonomat& t) {
	this->code = t.code;
	this->price = t.price;
	this->name = new char[strlen(t.name) + 1];
	strcpy_s(this->name, strlen(t.name) + 1, t.name);
}

int Tonomat::getCode() {
	return this->code;
}

int Tonomat::getPrice() {
	return this->price;
}

char* Tonomat::getName() {
	return this->name;
}

void Tonomat::setCode(int code) {
	this->code = code;
}

void Tonomat::setPrice(int price) {
	this->price = price;
}

void Tonomat::setName(const char* name) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

bool Tonomat::operator==(const Tonomat& t) {
	return this->code == t.code && this->price == t.price && strcmp(this->name, t.name) == 0;
}

Tonomat::~Tonomat() {
	if (this->name) {
		delete[]this->name;
		this->name = NULL;
	}
}
