#include "BronSieczna.h"
#include <iostream>

using namespace std;

BronSieczna::BronSieczna() : Bron(){
	length = 0;
	cout << "Konstruktor klasy BronSieczna" << endl;
}
	
BronSieczna::BronSieczna(int length) : Bron(){
	this->length = length;
	cout << "Konstruktor klasy BronSieczna" << endl;
}
		
BronSieczna::BronSieczna(string name, int volume, int weight, int damage, int durability, int length) : Bron(name, volume, weight, damage, durability){
	this->length = length;
	cout << "Konstruktor klasy BronSieczna" << endl;
}
		
BronSieczna::~BronSieczna(){
	cout << "Deskruktor klasy BronSieczna" << endl;
}

void BronSieczna::print(){
	Bron::print();
	cout << "Dlugosc ostrza: " << length << endl;
}

int BronSieczna::getLength(){
	return length;
}

void BronSieczna::setLength(int length){
	if (length < 0){
		cout << "Bledna wartosc" << endl;
		return;
	}
	this->length = length;
}
