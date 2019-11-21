#include <iostream>
#include "Bron.cpp"

using namespace std;

class BronSieczna : public Bron{
private:
	int length;

public:
	BronSieczna();
	BronSieczna(int length);
	BronSieczna(string name, int volume, int weight, int damage, int durability, int length);
	~BronSieczna();

	void print();
	int getLength();
	void setLength(int length);

};
