#include "Czary.h"
#include <iostream>

using namespace std;

Czary::Czary() : Przedmiot(){
	type = "";
	rangeOfFire = 0;
	cout << "Konstruktor klasy Czary" << endl;
}
	
Czary::Czary(string type, int rangeOfFire) : Przedmiot(){
	this->type = type;
	this->rangeOfFire = rangeOfFire;
	cout << "Konstruktor klasy Czary" << endl;
}
		
Czary::Czary(string name, int volume, int weight, string type, int rangeOfFire) : Przedmiot(name, volume, weight){
	this->type = type;
	this->rangeOfFire = rangeOfFire;
	cout << "Konstruktor klasy Czary" << endl;
}
		
Czary::~Czary(){
	cout << "Deskruktor klasy Czary" << endl;
}

void Czary::print(){
	Przedmiot::print();
	cout << "Typ: " << type << endl;
	cout << "Pole razenia: " << rangeOfFire << endl;
}

string Czary::getType(){
	return type;
}

void Czary::setType(string type){
	if (type == ""){
		cout << "Bledna wartosc" << endl;
		return;
	}
	this->type = type;
}

int Czary::getRange(){
	return rangeOfFire;
}

void Czary::setRange(int range){
	if (range < 0){
		cout << "Bledna wartosc" << endl;
		return;
	}
	this->rangeOfFire = range;
}
