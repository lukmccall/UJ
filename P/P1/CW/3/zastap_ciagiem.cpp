// Zastepianie znaku ciagiem
#include <iostream>

using namespace std;

int main(){
	char s[ 100 ]; // tablica z ciagiem, ktory modyfikujemy
	char r[ 100 ]; // ciag zastepczy
	char c; // znak do zastapienia
	char out[ 300 ]; // wynik
	int activeIndex = 0; // aktualnie modyfikowany index tablicy wynikowej
	bool onEnd = false; // flaga konca tablicy wynikowej
	
	cin >> s >> c >> r;
	
	for( int i = 0; i < 100; i++ ) // iteracja przez ciag wejsciowy
		if( s[ i ] == c ){ // sprawdzenie czy ten znak nalezy zastapic
			onEnd = false;
			for( int j = 0; j < 100; j++ ){ // zastepowanie znaku ciagiem
				if( r[ j ] != 0 && !onEnd ){	
					out[ activeIndex ] = r[ j ];
					activeIndex++;
					}
				else
					onEnd = true;
				}	
			}
		else{
			out[ activeIndex ] = s[ i ]; // kopiowanie elementow do tablicy wynikowej
			activeIndex++;
			}
			
	cout << out;
	return 0;
	}
