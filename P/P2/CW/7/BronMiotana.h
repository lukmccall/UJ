#include <iostream>
#include "Bron.cpp"

using namespace std;

class BronMiotana : public Bron{
private:
	double range;

public:
	BronMiotana();
	BronMiotana(double range);
	BronMiotana(string name, int volume, int weight, int damage, int durability, double range);
	~BronMiotana();
		
	void print();
	double getRange();
	void setRange(double range);

};
