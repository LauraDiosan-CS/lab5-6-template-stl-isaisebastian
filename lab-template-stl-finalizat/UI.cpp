#include "UI.h"
#include <cstring>
#include <iostream>
using namespace std;


UI::UI() {}
UI::~UI() {}

UI::UI(const Service& serv) {
	this->serv = serv;

}

void UI::menu() {
	cout << endl;
	cout << "	MENU" << endl;
	cout << "	1. Arata produsele disponibile" << endl;
	cout << "	2. Cumpara produse" << endl;
	cout << "	3. Iesire" << endl;
	cout << "	Setari" << endl;
}

void UI::menu_others() {
	cout << endl;
	cout << "	1. Adaugare produs" << endl;
	cout << "	2. Actualizare produs" << endl;
	cout << "	3. Stergere produs" << endl;
	cout << "	4. Afisarea tuturor produselor" << endl;
	cout << "	5. Afisarea tuturor monezilor " << endl;
	cout << "	6. Afisarea banilor din tonomat" << endl;
	cout << "	7. Iesire" << endl;
	cout << endl;
}

void UI::addProduct() {
	string code;
	string name;
	float price;
	cout << "Cod: "; cin >> code;
	cout << "Numele produsului: "; cin >> name;
	cout << "Pretul: ";  cin >> price;
	this->serv.addProdus(code, name, price);
}

void UI::deleteProduct() {
	string code;
	cout << "Codul produsului pentru stergere: "; cin >> code;
	this->serv.deleteProdus(code);
}

void UI::updateProduct() {
	string code;
	string newcode;
	string newname;
	float newprice;
	cout << "Codul produsului pentru actualizare: "; cin >> code;
	cout << "Noul cod al produsului: "; cin >> newcode;
	cout << "Noul nume al produsului: ";  cin >> newname;
	cout << "Noul pret al produsului: "; cin >> newprice;
	this->serv.updateProdus(code, newcode, newname, newprice);
}

void UI::getAll_Product() {
	vector<Produs> produse = this->serv.getAllProducts();
	int len = produse.size();
	for (int i = 0; i < len; i++) {
		cout << produse[i] << endl;
	}
}

void UI::ui_tranzactie() {
	string code;
	string name;
	cout << "Codul: "; cin >> code;
	float price = this->serv.getProductPriceByCode(code);
	int numOfCoins = 0;
	float coin = 0.0;
	float money = 0.0;
	while (money < price) {
		cout << "Numarul monezilor / bancnotelor: "; cin >> numOfCoins;
		cout << "Moneda / bancnota: "; cin >> coin;
		money += this->serv.getSumOfCoins(numOfCoins, coin);
		this->serv.addMoney(numOfCoins, coin);
	}
	if (this->serv.give_rest(money, price) == -1) {
		cout << "Nu puteti cumpara, tonomatul nu are sa va dea rest." << endl;
		cout << "Cei " << money << " ron / bani v-au fost returnati";
		cout << endl;
	}
	else {
		this->serv.delete_rest();
		float rest = money - price;
		cout << "Ati primit rest " << rest << endl;
		cout << "Tranzactie efectuata!" << endl;
	}
}

void UI::getAll_Money() {
	vector<Bani> money = this->serv.getAllMoney();
	int len = money.size();
	for (int i = 0; i < len; i++)
		cout << money[i] << endl;
}

void UI::money_tonomate_ui() {
	float money = this->serv.moneytonomate();
	cout << "Banii din tonomat: " << money;
}

void UI::run_ui() {
	char option[10];
	int op;
	while (true) {
		menu();
		cout << "Optiunea: "; cin >> option;
		if (strcmp(option, "1") == 0) {
			this->getAll_Product();
		}
		if (strcmp(option, "2") == 0) {
			this->ui_tranzactie();
		}
		if (strcmp(option, "3") == 0) {
			break;
		}
		if (strcmp(option, "Setari") == 0) {
			while (true)
			{
				menu_others();
				cout << "Optiunea: "; cin >> op;
		
				if (op == 1)
					this->addProduct();
				if (op == 2)
					this->updateProduct();
				if (op == 3)
					this->deleteProduct();
				if (op == 4)
					this->getAll_Product();
				if (op == 5)
					this->getAll_Money();
				if (op == 6)
					this->money_tonomate_ui();
				if (op == 7)
					break;
			}
		}
	}
}