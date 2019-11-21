#include <iostream>
#include "Bron.cpp"

using namespace std;

class BronPalna : public Bron{
private:
	int noOfBullets;

public:
	BronPalna();
	BronPalna(int noOfBullets);
	BronPalna(string name, int volume, int weight, int damage, int durability, int noOfBullets);
	~BronPalna();

	void print();
	double getBullets();
	void setBullets(int noOfBullets);

};
