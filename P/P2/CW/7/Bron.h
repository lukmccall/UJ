#pragma once
#include <iostream>
#include "Przedmiot.cpp"

using namespace std;

class Bron : public Przedmiot{
private:
	int damage;
	int durability;

public:
	Bron();
	Bron(int damage, int durability);
	Bron(string name, int volume, int weight, int damage, int durability);
	~Bron();
	
	void print();
	int getDamage();
	void setDamage(int damage);
	int getDurability();
	void setDurability(int durability);
};
