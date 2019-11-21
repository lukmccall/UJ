// suma dwoch zbiorow
#include <iostream>

using namespace std;

int main(){
	int a[ 100 ]; // zbior A
	int b[ 100 ]; // zbior B
	int c[ 200 ]; // zbior A+B
	
	int n;
	int m;
	int active = 0;
	bool add = true;
	
	// wczytywanie zbiorow
	cin >> n;
	for( int i = 0; i < n; i++ )
		cin >> a[ i ];
	cin >> m;
	for( int i = 0; i < m; i++ )
		cin >> b[ i ];
		
	// dodawanie do zbioru wynikowego elementow ze zbioru A bez powtorzen
	for( int i = 0; i < n; i++ ){
		add = true;
		for( int j = 0; j < active; j++ )
			if( a[ i ] == c[ j ] ) add = false;
		if( add ){
			c[ active ] = a[ i ];
			active++;
			}	 
		}
		

	// dodawanie do zbioru wynikowego elementow ze zbioru B bez powtorzen
	for( int i = 0; i < m; i++ ){
		add = true;
		for( int j = 0; j < active; j++ )
			if( b[ i ] == c[ j ] ) add = false;
		if( add ){
			c[ active ] = b[ i ];
			active++;
			}	 
		}
		
	// wypisanie wyniku
	for( int i = 0; i < active; i++ )
		cout << c[ i ] << endl;


	return 0;
}
