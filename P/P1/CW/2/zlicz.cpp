//Zliczanie elementow w ciagu
#include <iostream>

using namespace std;

int main(){
	int n; // ilosc elementow
	int temp; 
	int active; // dany element
	int l; // licznik
	
	cin >> n;
	int tab[ n ]; 
	
	// wczytywanie ciagu
	for(int i = 0; i < n; i++ )
		cin >> tab[ i ];
	
	// sortowanie babelkowe tablicy
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < n; j++ ){
			if(tab[ i ] < tab[ j ] ){
				temp = tab[ i ];
				tab[ i ] = tab[ j ];
				tab[ j ] = temp;
				}
			}
		}
		
	// zliczanie poszczegolnych elementow	
	for( int i = 0; i < n; i++ ){
		active = tab[ i ]; 
		l = 1;
		for( int j = i + 1; j < n; j++ ){
			if( active == tab[ j ] ){
				l++;
				i = j;		
				}
			}
		cout << active << ": " << l << endl;
		}	
	return 0;
}
