// Powtarzanie ciagu
#include <iostream>

using namespace std;

int main(){
	char s[ 100 ]; // tablica wejsciowa
	int endOfString = -1; // indeks konca napisu
	int repeat = 3; // ilosc powtorzen

	cin >> s;
	
	for( int i = 0; i < 100; i++ ) // znajdywanie indeksu ostatniego elementu 
		if( s[ i ] == 0 && endOfString == -1)
			endOfString = i;	
	
	while( repeat > 0 ){ 
		for( int j = 0; j < endOfString; j++ ) // powtarzanie elementow 
			s[ ( endOfString * ( repeat - 1 ) ) + j ] = s[ j ];
		repeat--;
		}

	cout << s;
	
	return 0;	
}
