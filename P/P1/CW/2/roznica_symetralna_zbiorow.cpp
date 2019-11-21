// roznica symetralna zbiorow A-B + B-A
#include <iostream>

using namespace std;

int main(){
	int a[ 100 ]; // zbior A
	int b[ 100 ]; // zbior B
	int c[ 100 ]; // zbior C
	
	int n;
	int m;
	int active = 0;
	bool add = false;
	
	// wczytywanie
	cin >> n;
	for( int i = 0; i < n; i++ )
		cin >> a[ i ];
	cin >> m;
	for( int i = 0; i < m; i++ )
		cin >> b[ i ];
	
	// A-B
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
	
	// B - A
	for( int i = 0; i < m; i++ ){
		add = true;
		for( int j = 0; j < n; j++ ) // sprawdzenie czy element znajduje sie w A
			if( b[ i ] == a[ j ] ) add = false;
		if( add ){
			for( int p = 0; p < active; p++ ) // sprawdzenie czy element sie powtarza
				if( b[ i ] == c[ p ] ) add = false;
			if( add ){
				c[ active ] = b[ i ];
				active++;
				}
			}	  
		}
	
	// wyswietlanie 	
	for( int i = 0; i < active; i++ )
		cout << c[ i ] << endl;

	return 0;
}
