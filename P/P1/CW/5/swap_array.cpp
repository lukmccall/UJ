// Zamiana tablic
#include <iostream>

using namespace std;

/*
	Zamiana miejscami dwoch zmiennych a i b
	@param int* a
	@param int* b
*/
void SwapElement(int* a, int* b ){
	int temp = *b;
	*b = *a;
	*a = temp;
	}

/*
	Zamiana miejscami dwoch tablic 
	@param int* lA - wielkosc tablicy A
	@param int arrayA[] - tablica A
	@param int* lB - wielkosc tablicy B
	@param int arrayB[] - tablica B
*/
void SwapArray( int *lA, int arrayA[], int *lB, int arrayB[] ){
	int max = *lA>*lB?*lA:*lB; // maksymalna ilosc elementow
	for(int i = 0; i < max; i++ ) // iteracja przez wszystkie elementy tablicy
		SwapElement(&arrayA[i],&arrayB[i]);
	SwapElement(lA, lB);
	}

int main(){
	int a[100];
	int b[100];
	int lA;
	int lB;
	cin >> lA;
	for(int i = 0; i < lA; i++ )
		cin >> a[ i ]; 
	cin >> lB;
	for(int i = 0; i < lB; i++ )
		cin >> b[ i ];
	
	cout << "Przed Swape" << endl;
	cout << "Array A: " << endl;
	cout << lA << endl;
	for(int i = 0; i < lA; i++ )
		cout << a[ i ] << " "; 
	cout << endl;
	cout << "Array B: " << endl;
	cout << lB << endl;
	for(int i = 0; i < lB; i++ )
		cout << b[ i ] << " "; 
	cout << endl;
		
	SwapArray(&lA, a, &lB, b);
	
	cout << "Po Swapie" << endl;
	cout << "Array A: " << endl;
	cout << lA << endl;
	for(int i = 0; i < lA; i++ )
		cout << a[ i ] << " "; 
	cout << endl;
	cout << "Array B: " << endl;
	cout << lB << endl;
	for(int i = 0; i < lB; i++ )
		cout << b[ i ] << " "; 
	
	return 0;
	}
