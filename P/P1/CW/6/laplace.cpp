// rozwiniecie lacpace
#include <iostream>

using namespace std;

/*	
	Wyswietl macierz
*/
void PrintMatrix(int matrix[], int dims){
	for( int i = 0; i < dims; i++ ){
		for( int j = 0; j < dims; j++ )
			cout << matrix[ i * dims + j ] << " ";
		cout << endl;
		}
	cout << endl;
}

// wyznacznik stopnia 1
int det1( int matrix[] ){
	return matrix[0];
}

//wyznacznik stopnia 2 
int det2( int matrix[] ){
	return ( matrix [ 0 ] * matrix[ 3 ] ) - ( matrix[ 1 ] * matrix[ 2 ] );  // wzor ad - bc
}

// wyznacznik stopnia 3 
int det3( int matrix[] ){
	int det = 0; // wyznanik  
	int temp; // pomocnicza	 
	int tempArr[ 4 ];	// pomocnicza tablica na odpowiednie minory
	int p = 0; // zmiena potrzebna do przepisywania tablic
	
	for( int i = 0; i < 3; i++ ){ // rozwiniecie wzgledem 1 kolumny 
		p = 0;
		for( int w = 0; w < 3; w++) // wyciencie minora
			for( int h = 1; h < 3; h++ )
				if( w != i){
					tempArr[ p ] = matrix[ w*3 + h ];
					p++;
					}
					
		temp = det2( tempArr ) * matrix[ i * 3 ]; // wyznacznik minora
		if( i % 2 != 0) 
			temp *= -1;
		det += temp; 
		}
	return det;	
	}

// wyznacznik stopnia 4
int det4( int matrix[] ){
	int det = 0;
	int temp;
	int tempArr[ 9 ];
	int p = 0;
	
	for( int i = 0; i < 4; i++ ){
		p = 0;
		for( int w = 0; w < 4; w++)
			for( int h = 1; h < 4; h++ )
				if( w != i){
					tempArr[ p ] = matrix[ w*4 + h ];
					p++;
					}
					
		temp = det3( tempArr ) * matrix[ i * 4 ];
		if( i % 2 != 0)
			temp *= -1;
		det += temp;
		}
	return det;	
	
	}	

int det5( int matrix[] ){
	int det = 0;
	int temp;
	int tempArr[ 16 ];
	int p = 0;
	
	for( int i = 0; i < 5; i++ ){
		p = 0;
		for( int w = 0; w < 5; w++)
			for( int h = 1; h < 5; h++ )
				if( w != i){
					tempArr[ p ] = matrix[ w*5 + h ];
					p++;
					}
					
		temp = det4( tempArr ) * matrix[ i * 5 ];
		if( i % 2 != 0)
			temp *= -1;
		det += temp;
		}
	return det;	
	
	}	

int det6( int matrix[] ){
	int det = 0;
	int temp;
	int tempArr[ 25 ];
	int p = 0;
	
	for( int i = 0; i < 6; i++ ){
		p = 0;
		for( int w = 0; w < 6; w++)
			for( int h = 1; h < 6; h++ )
				if( w != i){
					tempArr[ p ] = matrix[ w*6 + h ];
					p++;
					}
					
		temp = det5( tempArr ) * matrix[ i * 6 ];
		if( i % 2 != 0)
			temp *= -1;
		det += temp;
		}
	return det;	
	
	}	

// funkcja glowana obliczajaca wyznaczki 
int det( int matrix[], int d){
	// wywolanie odpowiedniej funkjci obliczajacej wyznacznik
	if( d == 1)
		return det1( matrix );
	else
		if( d == 2 )
			return det2( matrix );
		else
			if( d == 3 )
				return det3( matrix );
			else
				if( d == 4 )
					return det4( matrix );
				else
					if( d == 5 )
						return det5( matrix );
					else
						if( d == 6)
							return det6( matrix );
						else{
							cout << "Nieodzwolona wielkosc" << endl;
							return 0;
							}
}

int main(){
	int dims;
	cin >> dims;
	int matrix[ dims * dims];
	for( int i = 0; i < dims * dims; i++ ) // wczytanie macierzy
		cin >> matrix[ i ];

	cout << endl;
	PrintMatrix( matrix, dims);
	cout << "Wyznacznik: " << det( matrix, dims);
	return 0;
	}
