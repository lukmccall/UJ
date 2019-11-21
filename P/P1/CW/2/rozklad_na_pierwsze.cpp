// rozklad na liczby pierwsze
#include <iostream>

using namespace std;

int main(){
	int prime[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59}; // tablica liczb pierwszych
	int n; // liczba do rozkladu
	
	cout << "Podaj liczbe: ";
	cin >> n;	
	
	while( n > 1 ){
		for( int i = 0; i < 17 /*sizeof(prime)/sizeof(*prime)*/; i++ )
			if( n % prime[ i ] == 0 ){ // sprawdzenie czy liczba pierwsza o indeksie i jest dzielnikiem 
				cout << prime[ i ] << endl;
				n /= prime[ i ];
				i = -1;
				}
			}
		
	return 0;
}
