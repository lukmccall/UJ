// roznica zbiorow
#include <iostream>

using namespace std;

int main(){
	int a[ 100 ]; // zbior A
	int b[ 100 ]; // zbior B
	int c[ 100 ]; // zbior A-B
	
	int n;
	int m;
	int active = 0;
	bool add = false;
	
	// wczytywanie A i B
	cin >> n;
	for( int i = 0; i < n; i++ )
		cin >> a[ i ];
	cin >> m;
	for( int i = 0; i < m; i++ )
		cin >> b[ i ];
	
	for( int i = 0; i < n; i++ ){
		add = true;
		for( int j = 0; j < m; j++ ) // sprawdzenie czy element znajduje sie w B
			if( a[ i ] == b[ j ] ) add = false;
		if( add ){
			for( int p = 0; p < active; p++ ) // sprawdzenie czy element sie powtarza 
				if( a[ i ] == c[ p ] ) add = false;
			if( add ){
				c[ active ] = a[ i ];
				active++;
				}
			}	  
		}
	
	// wyswietlanie
	for( int i = 0; i < active; i++ )
		cout << c[ i ] << endl;

	return 0;
}
