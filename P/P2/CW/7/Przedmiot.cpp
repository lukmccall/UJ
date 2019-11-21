#pragma once
#include "Przedmiot.h"
#include <iostream>

using namespace std;

Przedmiot::Przedmiot(){
	name = "";
	volume = -1;
	weight = -1;
	cout << "Konstruktor klasy Przedmiot" << endl;
}
		
Przedmiot::Przedmiot(string name, int volume, int weight){
	this->name = name;
	this->volume = volume;
	this->weight = weight;
	cout << "Konstruktor klasy Przedmiot" << endl;
}
		
Przedmiot::~Przedmiot(){
	cout << "Destruktor klasy Przedmiot" << endl;
}

void Przedmiot::print(){
	cout << "Nazwa: " << name << endl;
	cout << "Objetosc: " << volume << endl;
	cout << "Waga: " << weight << endl;
}

string Przedmiot::getName(){
	return name;
}

void Przedmiot::setName(string name){
	this->name = name;
}

int Przedmiot::getVolume(){
	return volume;
}

void Przedmiot::setVolume(int volume){
	if (volume < 0){
		cout << "Bledna wartosc" << endl;
		return;
	}
	this->volume = volume;
}

int Przedmiot::getWeight(){
	return weight;
}

void Przedmiot::setWeight(int weight){
	if (weight < 0){
		cout << "Nie moze byc ujemna" << endl;
		return;
	}
	this->weight = weight;
}
