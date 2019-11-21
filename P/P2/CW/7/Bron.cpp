#pragma once
#include "Bron.h"
#include <iostream>

using namespace std;

Bron::Bron() : Przedmiot(){
	damage = 0;
	durability = 0;
	cout << "Konstruktor klasy Bron" << endl;
}

Bron::Bron(int damage, int durability) : Przedmiot(){
	this->damage = damage;
	this->durability = durability;
	cout << "Konstruktor klasy Bron" << endl;
}

Bron::Bron(string name, int volume, int weight, int damage, int durability) : Przedmiot(name, volume, weight){
	this->damage = damage;
	this->durability = durability;
	cout << "Konstruktor klasy Bron" << endl;
}

Bron::~Bron(){
	cout << "Deskruktor klasy Bron" << endl;
}

void Bron::print(){
	Przedmiot::print();
	cout << "Obrazenia: " << damage << endl;
	cout << "Wytrzymalosc: " << durability << endl;
}

int Bron::getDamage(){
	return damage;
}

void Bron::setDamage(int damage){
	if (damage < 0){
		cout << "Bledna wartosc" << endl;
		return;
	}
	this->damage = damage;
}

int Bron::getDurability(){
	return durability;
}

void Bron::setDurability(int durability){
	if (durability < 0){
		cout << "Bledna wartosc" << endl;
		return;
	}
	this->durability = durability;
}
