#include <iostream>
#include "Przedmiot.cpp"

using namespace std;

class Plecak{
private:
	int maxNoOfItems;
	int noOfItems;
	int maxVolume;
	int volume;
	int maxWeight;
	int weight;
	Przedmiot** przedmioty;
	
public:	
	Plecak();
	Plecak(int noOfItems, int maxVolume, int maxWeight);
	~Plecak();
	
	void add(Przedmiot& in);
	void remove(Przedmiot& out);
	void print();
};

