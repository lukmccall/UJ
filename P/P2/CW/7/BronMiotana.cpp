#include "BronMiotana.h"
#include <iostream>

using namespace std;

BronMiotana::BronMiotana() : Bron(){
	range = 0;
	cout << "Konstruktor klasy BronMiotana" << endl;
}
	
BronMiotana::BronMiotana(double range) : Bron(){
	this->range = range;
	cout << "Konstruktor klasy BronMiotana" << endl;
}
		
BronMiotana::BronMiotana(string name, int volume, int weight, int damage, int durability, double range) : Bron(name, volume, weight, damage, durability){
	this->range = range;
	cout << "Konstruktor klasy BronMiotana" << endl;
}
		
BronMiotana::~BronMiotana(){
	cout << "Deskruktor klasy BronMiotana" << endl;
}

void BronMiotana::print(){
	Bron::print();
	cout << "Zasieg: " << range << endl;
}

double BronMiotana::getRange(){
	return range;
}

void BronMiotana::setRange(double range){
	if (range < 0){
		cout << "Bledna wartosc" << endl;
		return;
	}
	this->range = range;
}
