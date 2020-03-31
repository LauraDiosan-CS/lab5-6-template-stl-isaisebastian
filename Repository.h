#pragma once
#include "Tonomat.h"
#include <vector>

class Repository {
private:
	vector<Tonomat> elements;
public:
	Repository();
	void addElem(Tonomat t);
	vector<Tonomat> getAll();
	int getSize();
	~Repository();

};