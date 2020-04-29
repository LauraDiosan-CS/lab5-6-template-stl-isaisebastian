#pragma once
#include "Produs.h"
#include "RepoFile.h"

class TestRepoFile {
private:
	RepoFile<Produs> repo;
	vector<Produs> produse;
	void test_repofile_addElem();
	void test_repofile_delElem();
	void test_repofile_updateElem();
	void test_repofile_getAll();
public:
	TestRepoFile();
	void testAll();
};