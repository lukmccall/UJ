#include "Bron.cpp"
#include "Pokarm.cpp"
#include "Czary.cpp"
#include "BronSieczna.cpp"
#include "BronMiotana.cpp"
#include "BronPalna.cpp"
#include "Plecak.cpp"
#include <iostream>

using namespace std;

int main(){
	BronSieczna miecz("Miecz", 2, 20, 50, 1000, 12);
	miecz.print();
	cout << endl;
	Czary czar("Kula ognia", 1, 1, "Atakujacy", 100);
	czar.print();
	cout << endl;
	BronMiotana granat("Granat", 1, 1, 100, 5, 200);
	granat.print();
	cout << endl;
	BronPalna pistolet("Pistolet", 2, 5, 50, 100, 24);
	pistolet.print();
	cout << endl;
	Przedmiot przedmiot1("P1", 2, 2);
	Przedmiot przedmiot2("P2", 2, 2);
	cout << endl << endl;
	Plecak plecak(5,1000,1000);
	cout << endl;
	plecak.add(przedmiot1);
	plecak.add(przedmiot2);
	cout << endl;
	plecak.print();
	cout << endl;
	
	plecak.remove(przedmiot1);
	plecak.remove(przedmiot1);
	
	plecak.print();
	cout << endl;
	plecak.remove(przedmiot2);
	
	cout << endl << endl;
	
}
