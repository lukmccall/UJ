// Metoda eliminacji gauss
#include <iostream>

using namespace std;

/*	
	Wyswietl macierz
*/
void PrintMatrix(float matrix[], int dims){
	for( int i = 0; i < dims; i++ ){
		for( int j = 0; j < dims; j++ )
			cout << matrix[ i * dims + j ] << " ";
		cout << endl;
		}
	cout << endl;
}

/*
	Zwraca indeks nie zerowego elementu w danej kolumnie pod elementem w wierszu c
	lub -1 jesli takiego elementu nie ma
*/
int IsNull( float matrix[], int dims, int c){
	for( int i = c; i < dims; i++) // iteracja przez wszystkie elementy pod c w danej kolumnie
		if( matrix[ i * dims + c] != 0 )
			return i; 
	return -1;
}

/*
	Zamiana dwoch zmiennych "miejscami"
*/
void Swap( float *a, float *b ){
	float temp = *b;
	*b = *a;
	*a = temp;
	}

/*
	Zamiana dwoch wierszy "miejscami" w macierzy
*/
void SwapRow( float matrix[], int dims, int r1, int r2){
	for( int i = 0; i < dims; i++)
		Swap( &matrix[ r1 * dims + i],  &matrix[ r2 * dims + i] );
	}

/* 
	Odejmowanie dwoch wierszy od siebie zgodnie z r1 - a * r2
*/
void SubRow( float matrix[], int dims, int r1, int r2, float a ){
	for( int i = 0; i < dims; i++)
		matrix[ r1 * dims + i] = matrix[ r1 * dims + i] - ( a * matrix[ r2 * dims + i] );
	}

/*
	Metoda eliminacji gaussa
*/
float Gauss( float matrix[], int dims ){
	int temp; // zmienna pomocnicza
	float det = 1; // wyznacznik
	for( int c = 0; c < dims; c++ ){  // przejscie przez wszystkie kolumny
		if( matrix[ c*dims + c] == 0){ // zamiana wierszy jesli element na gorze jest zerowy
			temp = IsNull( matrix, dims, c);
			if( temp < 0 ){
				PrintMatrix( matrix, dims); // zero jest na przekatnej wiec wyznacznik jest rowny zero
				return 0;
				}
			else
				SwapRow( matrix, dims, c, temp); // zamiana wierszy
			}
		
		for( int i = c+1; i < dims; i++ ){ // zerowanie elemementow pod przekatna
			SubRow( matrix, dims, i, c, matrix[ i*dims + c]/matrix[ c*dims + c]);
			}
		
		}
		
	PrintMatrix( matrix, dims); // wyswietlenie macierzy po operacjach
	for( int c = 0; c < dims; c++ ) // iloczyn elementow na przekatnej
		det *= matrix[ c*dims + c ];
	return det;
	}
	

int main(){
	int dims;
	cin >> dims;
	float matrix[ dims * dims];
	for( int i = 0; i < dims * dims; i++ ) // wczytanie macierzy
		cin >> matrix[ i ]; 
		
	cout << endl;	
	PrintMatrix( matrix, dims);
	cout << "Wyznacznik: " << Gauss( matrix, dims); 
	return 0;	
	}
