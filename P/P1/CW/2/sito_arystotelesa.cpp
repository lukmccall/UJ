// sito arystotelesa
#include <iostream>

using namespace std;

int main(){
	bool wynik[ 100 ]; // tablica ktorej indeks oznacza liczbe a wartosc to czy jest to liczba piewsza
	
	// zapelnianie tablicy 
	for( int i = 0; i < 100; i++ )
		wynik[ i ] = true;

	for( int i = 2; i < 100; i++ )
		if( wynik[ i ] )
			for( int j = i+i; j < 100; j = j + i ) // wykreslanie kolejnych wielokrotnosc
				wynik[ j ] = false;

	// wyswietlanie wyniku
	for( int i = 2; i < 100; i++ )
		if( wynik[ i ] )
			cout << i << endl;
	return 0;
}
