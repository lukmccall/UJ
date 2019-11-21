// Powtarzanie liter w ciagu
#include <iostream>

using namespace std;

int main(){
	char s[ 100 ]; // tablica wejsciowa
	char out[ 300 ]; // tablica wynikowa
	for( int i = 0; i < 300; i++ ) // "czyszczenie" tablicy wynikowej
		out[ i ] = 0;
	
	bool findEnd = false; // flaga napotkania na koniec ciagu
	
	cin >> s;
	
	for( int i = 0; i < 100; i++ ) // iteracja przez tablice wejsciowa
		if( s[ i ] == 0 && !findEnd ) // sprawdzanie konca ciagu
			findEnd = true;
		else
			for( int j = i * 3; j < ( i * 3 ) + 3; j++ ) // kopiowanie z potrojeniem
				out[ j ] = s[ i ];	
	
	cout << out;
	
	return 0;
	}
