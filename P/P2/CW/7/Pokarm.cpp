#include "Pokarm.h"
#include <iostream>

using namespace std;

Pokarm::Pokarm() : Przedmiot(){
	efect = "";
	nutrition = 0;
	cout << "Konstruktor klasy Pokarm" << endl;
}
	
Pokarm::Pokarm(string efect, int nutrition) : Przedmiot(){
	this->efect = efect;
	this->nutrition = nutrition;
	cout << "Konstruktor klasy Pokarm" << endl;
}
				
Pokarm::Pokarm(string name, int volume, int weight, string efect, int nutrition) : Przedmiot(name, volume, weight){
	this->efect = efect;
	this->nutrition = nutrition;
	cout << "Konstruktor klasy Pokarm" << endl;
}
		
Pokarm::~Pokarm(){
	cout << "Destruktor klasy Pokarm" << endl;
}

void Pokarm::print(){
	Przedmiot::print();
	cout << "Efekt: " << efect << endl;
	cout << "Wartosc: " << nutrition << endl;
}

string Pokarm::getEfect(){
	return efect;
}

void Pokarm::setEfect(string efect){
	if (efect == ""){
		cout << "Bledna wartosc" << endl;
		return;
	}
	this->efect = efect;
}

int Pokarm::getNutrition(){
	return nutrition;
}

void Pokarm::setNutrition(int nutrition){
	if (nutrition < 0){
		cout << "Bledna wartosc" << endl;
		return;
	}
	this->nutrition = nutrition;
}
