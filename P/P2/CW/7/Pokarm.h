#include <iostream>
#include "Przedmiot.cpp"

using namespace std;

class Pokarm : public Przedmiot{
private:
	string efect;
	int nutrition;
	
public:
	Pokarm();
	Pokarm(string efect, int nutrition);
	Pokarm(string name, int volume, int weight, string efect, int nutrition);
	~Pokarm();
	
	void print();
	string getEfect();
	void setEfect(string efect);
	int getNutrition();
	void setNutrition(int nutrition);
};
