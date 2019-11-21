#include "Plecak.h"
#include <iostream>

using namespace std;

Plecak::Plecak(){
	maxNoOfItems = 0;
	noOfItems = 0;
	maxVolume = -1;
	volume = 0;
	maxWeight = -1;
	weight = 0;
	cout << "Konstruktor klasy Plecak" << endl;
}
		
Plecak::Plecak(int noOfItems, int maxVolume, int maxWeight){
	this->maxNoOfItems = noOfItems;
	przedmioty = new Przedmiot*[noOfItems];
	this->noOfItems = 0;
	this->maxVolume = maxVolume;
	this->volume = 0;
	this->maxWeight = maxWeight;
	this->weight = 0;
	cout << "Konstruktor klasy Plecak" << endl;
}

Plecak::~Plecak(){
	delete[] przedmioty;
	
	cout << "Destruktor klasy Plecak" << endl;
}

void Plecak::add(Przedmiot& in){
	if (noOfItems + 1 > maxNoOfItems){
		cout << "Przekroczony limit rzeczy" << endl;
		return;
	}
	if (weight + in.getWeight() > maxWeight){
		cout << "Przekroczony limit wagi" << endl;
		return;
	}
	if (volume + in.getVolume() > maxVolume){
		cout << "Przekroczony limit objetosci" << endl;
		return;
	}
	noOfItems++;
	weight += in.getWeight();
	volume += in.getVolume();
	przedmioty[noOfItems - 1] = &in;
	cout << "Dodano przedmiot: " << in.getName() << endl;
}


void Plecak::remove(Przedmiot& out){
	for (int i = 0; i < noOfItems; i++){
		if ( przedmioty[i] == &out ){
			weight -= out.getWeight();
			volume -= out.getVolume();
			for (int j = i; j < noOfItems - 1; j++){
				przedmioty[j] = przedmioty[j + 1];
			}
			noOfItems--;
			cout << "Usunieto przedmiot: " << out.getName() << endl;
			return;
		}
	}
	cout << "Nie znaleziono przedmiotu" << endl;
}

void Plecak::print(){
	cout << "W plecaku jest: " << noOfItems << " przedmiotow: " << endl;
	for (int i = 0; i < noOfItems; i++){
		cout << przedmioty[i]->getName() << " " << endl;
	}
}

