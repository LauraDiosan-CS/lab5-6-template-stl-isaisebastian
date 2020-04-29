#include <iostream>
#include "Produs.h"
#include "UI.h"
#include "TestRepoFile.h"
#include "TestService.h"
#include "TestRepository.h"

using namespace std;

int main() {
	TestRepository repo;
	repo.testAll();
	TestRepoFile repofile;
	repofile.testAll();
	TestService testservice;
	testservice.testAll();
	
	RepoFile<Produs> repo_prod("Produse.txt");
	RepoFile<Bani> repo_money("Bani.txt");
	Service s(repo_prod, repo_money);
	UI ui(s);
	ui.run_ui();
	return 0;
}