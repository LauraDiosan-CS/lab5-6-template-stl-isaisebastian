#pragma once
#include <vector>
using namespace std;

template <class T>
class Repository {
protected:
	vector<T> comp;
public:
	Repository() {}
	
	void addElem(T e) {
		this->comp.push_back(e);
	}

	void delElem(T e) {
		typename vector<T>::iterator it;
		it = find(this->comp.begin(), this->comp.end(), e);
		if (it != comp.end())
			this->comp.erase(it);
	}

	void clear()
	{
		this->comp.clear();
	}

	void updateElem(T& oldE, T& newE)
	{
		typename vector<T>::iterator it;
		for (it = this->comp.begin(); it != this->comp.end(); it++)
		{
			if (*it == oldE)
				*it = newE;
		}
	}

	vector<T> getAll() {
		return this->comp;
	}

	int getSize() {
		return this->comp.size();
	}

	T getAtPosition(int pos)
	{
		return this->comp[pos];
	}

	~Repository()
	{
		this->comp.clear();
	}
};