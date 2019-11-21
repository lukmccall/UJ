#include <iostream>
#include "Przedmiot.cpp"

using namespace std;

class Czary : public Przedmiot{
private:
	string type;
	int rangeOfFire;

public:
	Czary();
	Czary(string type, int rangeOfFire);
	Czary(string name, int volume, int weight, string type, int rangeOfFire);
	~Czary();

	void print();
	string getType();
	void setType(string type);
	int getRange();
	void setRange(int range);
};
