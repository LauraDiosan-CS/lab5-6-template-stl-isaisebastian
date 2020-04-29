#pragma once
#include "Service.h"
#include "Bani.h"
#include "Produs.h"
#include <iostream>
using namespace std;

class UI {
private:
	Service serv;

	void menu();
	void menu_others();
	void getAll_Product();
	void addProduct();
	void updateProduct();
	void deleteProduct();
	void addmoney();
	void getAll_Money();
	void money_tonomate_ui();

	void ui_tranzactie();

public:
	UI();
	UI(const Service& serv);
	~UI();
	void run_ui();
};