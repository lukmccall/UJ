// Int To Dec 
#include <iostream>

using namespace std;


int main(){
	int i; // liczba dziesietna
	int index = 0; // index wyniku
	char out[ 100 ] = { 0 }; // tablica wynikowa
	char temp; // zmienna pomocnicza
	
	cin >> i;
	
	while( i > 0 ){ // zapisywanie kolejnych reszt z dzielenia przez 2 
		out[ index ] = '0' + ( i % 2 );
		i /= 2;
		index++;
		}
		
	index--;
	
	for( int i = 0; i <= index / 2; i++ ){ // zamiana kolejnosci w tablicy wynikowej
		temp = out[ i ];
		out[ i ] = out[ index - i];
		out[ index - i ] = temp;
		}
	
	cout << out ;

	return 0;
	}
