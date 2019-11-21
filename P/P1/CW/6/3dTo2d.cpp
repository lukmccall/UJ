// 3D to 2D
#include <iostream>

#define FIRST_WIDTH 2
#define FIRST_HEIGHT 3
#define FIRST_DEEP 4

#define SECOND_WIDTH 2
#define SECOND_HEIGHT 12

using namespace std;

/*
	Fukcja przepisujaca tablice 3d -> 2d
*/
void Translate(int arr3d[ FIRST_WIDTH ][ FIRST_HEIGHT ][ FIRST_DEEP ],int arr2d[ SECOND_WIDTH ][ SECOND_HEIGHT ] ){
	// indeksy w tablicy 2d
	int i = 0;
	int j = 0;
	for( int w = 0; w < FIRST_WIDTH; w++ )
		for( int h = 0; h < FIRST_HEIGHT; h++ )
			for( int d = 0; d < FIRST_DEEP; d++ ){ // iteracja przez kazdy element tablicy 3d
				arr2d[ i ][ j ] = arr3d[ w ][ h ][ d ]; // wpisanie do tablic 2d elementu z tablicy 3d 
				
				// zmiana indeksu w 2d
				j++;
				if(j != 0 && j % SECOND_HEIGHT == 0){
					j = 0;
					i++;
					}
				}
				
	}

/*
	Wyswietl tablice
*/
void ShowArray( int arr2d[ SECOND_WIDTH ][ SECOND_HEIGHT ] ){
	for( int i = 0; i < SECOND_WIDTH; i++ ){
		for( int j = 0; j < SECOND_HEIGHT; j++ ) // iteracja przez kazdy element tablicy
			cout << arr2d[ i ][ j ] << " ";
		cout << endl;
		}	
	}

int main(){
	int arr3d[ FIRST_WIDTH ][ FIRST_HEIGHT ][ FIRST_DEEP ] = 
		{ 
			{{111, 112, 113, 114},
		     {121, 122, 123, 124},
		     {131, 132, 133, 134}},
		     
			{{211, 212, 213, 214},
			 {221, 222, 223, 224},
			 {231, 232, 233, 234}}
		};
	int arr2d[ SECOND_WIDTH ][ SECOND_HEIGHT ];
	Translate( arr3d, arr2d); // przepisanie
	ShowArray( arr2d );	// wyswietlenie
	return 0;
	}
