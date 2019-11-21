#include "BronPalna.h"
#include <iostream>

using namespace std;

BronPalna::BronPalna() : Bron(){
	noOfBullets = 0;
	cout << "Konstruktor klasy BronPalna" << endl;
}
	
BronPalna::BronPalna(int noOfBullets) : Bron(){
	this->noOfBullets = noOfBullets;
	cout << "Konstruktor klasy BronPalna" << endl;
}
		
BronPalna::BronPalna(string name, int volume, int weight, int damage, int durability, int noOfBullets) : Bron(name, volume, weight, damage, durability){
	this->noOfBullets = noOfBullets;
	cout << "Konstruktor klasy BronPalna" << endl;
}
		
BronPalna::~BronPalna(){
	cout << "Deskruktor klasy BronPalna" << endl;
}

void BronPalna::print(){
	Bron::print();
	cout << "Liczba pociskow: " << noOfBullets << endl;
}

double BronPalna::getBullets(){
	return noOfBullets;
}

void BronPalna::setBullets(int noOfBullets){
	if (noOfBullets < 0){
		cout << "Bledna wartosc" << endl;
		return;
	}
	this->noOfBullets = noOfBullets;
}
