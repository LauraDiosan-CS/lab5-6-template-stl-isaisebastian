#pragma once
#include <fstream>
#include <iostream>
#include <cstddef>
#include "Repository.h"

template <class T>
class RepoFile : public Repository<T> {
private:
	char* f_name;
public:
	RepoFile() : Repository<T>()
	{
		this->f_name = NULL;
	}

	RepoFile(const char* f_name)
	{
		this->f_name = new char[strlen(f_name) + 1];
		strcpy_s(this->f_name, strlen(f_name) + 1, f_name);
		this->loadfromfile();
	}

	RepoFile(const RepoFile& repofile) {
		this->f_name = new char[strlen(repofile.f_name) + 1];
		strcpy_s(this->f_name, 1 + strlen(repofile.f_name), repofile.f_name);
		this->loadfromfile();
	}
	
	void setf_name(const char* f_name) {
		if (this->f_name != NULL)
			delete[]this->f_name;
		if (f_name != NULL)
		{
			this->f_name = new char[strlen(f_name) + 1];
			strcpy_s(this->f_name, strlen(f_name) + 1, f_name);
		}
		else this->f_name = NULL;
	}

	void addElement(T e) {
		Repository<T>::addElem(e);
	}

	void updateElement(T& oldE, T& newE) {
		Repository<T>::updateElem(oldE, newE);
	}

	vector<T> getAll() {
		return Repository<T>::getAll();
	}

	int getSize() {
		return Repository<T>::getSize();
	}

	void loadfromfile()
	{
		if (this->f_name != NULL) {
			Repository<T>::clear();
			ifstream f(this->f_name);
			T elem;
			while (f >> elem)
				Repository<T>::addElem(elem);
			f.close();
		}
	}

	void savetofile()
	{
		if (this->f_name != NULL)
		{
			ofstream f(this->f_name);
			int len = Repository<T>::getSize();
			for (size_t i = 0; i < len; i++)
				f << Repository<T>::getAtPosition(i) << endl;
			f.close();
		}
	}

	~RepoFile() {
		delete[]this->f_name;
	}
};