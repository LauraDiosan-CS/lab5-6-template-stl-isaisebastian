#pragma once
#include <iostream>
using namespace std;

class Tonomat {
private: 
	int code; int price;
	char* name;
public:
	Tonomat();
	Tonomat(int code, const char* name, int price);
	Tonomat(const Tonomat& t);
	~Tonomat();
	
	int getCode();
	int getPrice();
	char* getName();

	bool operator==(const Tonomat& t);

	void setCode(int code);
	void setPrice(int price);
	void setName(const char* name);
};