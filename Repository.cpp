#include "Repository.h"

Repository::Repository() {

}


void Repository::addElem(Tonomat t) {
	this->elements.push_back(t);
}

vector<Tonomat> Repository::getAll() {
	return this->elements;
}

int Repository::getSize() {
	return this->elements.size();
}

Repository::~Repository() {
	this->elements.clear();
}