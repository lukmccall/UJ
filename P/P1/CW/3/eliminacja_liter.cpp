// Eliminacja znaku
#include <iostream>

using namespace std;

int main(){
	char s[ 100 ]; // tablica wejsciowa
	for( int i = 0; i < 100; i++ ) // czyszczenie tablicy
		s[ i ] = 0;
	char c; // znak do usuniecia
	bool find = false; // flaga oznaczajace ze dany element zostal juz przesuniety
	cin >> s >> c;
	
	
	for( int i = 0; i < 100; i++ ) // zastepowanie znaku c 0 
		if( s[ i ] == c )
			s[ i ] = 0;
			
	for( int i = 0; i < 100; i++ ) // iteracja przez tablice wejsciowa
		if( s[ i ] == 0 ){ // szykanie 0 w ciagu
			find = false;
			for( int j = i + 1; j < 100; j++ ) // zamienianie elementow miejscami
				if( s[ j ] != 0  && !find ){
					s[ i ] = s[ j ];
					s[ j ] = 0;
					find = true;
				}
			}
	cout << s;
	return 0;
	}
