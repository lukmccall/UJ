// Wypisuje tablice charow
#include <iostream>

using namespace std;

int main(){ 
	char s[100]; // tablica wejsciowa
	bool findEnd = false; // flaga konca napisu
	cin >> s;
	
	for( int i = 0; i < 100; i++ ) // iteracja przez tablice wejsciowa
		if( s[ i ] != 0 && !findEnd )
			cout << "s[ " << i<< " ] = '" << s[ i ] << "'" << endl;
		else
			findEnd = true;
	return 0;
}
