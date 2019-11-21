#include <iostream>

using namespace std;

class Przedmiot{
private:
	string name;
	int volume;
	int weight;
		
public:	
	Przedmiot();
	Przedmiot(string name, int volume, int weight);
	~Przedmiot();
	
	void print();
	string getName();
	void setName(string name);
	int getVolume();
	void setVolume(int volume);
	int getWeight();
	void setWeight(int weight);
	
};

