// dodawanie wielomianow
#include <iostream>

using namespace std;

/*
	Wyswielt wielomianu
	@param int d stopien wielomianu
	@param int *coeffs wspolczynniki
*/
void ShowSet( int d, int *coeffs ){
	cout << "Stopien: " << d << endl;
	if( d > 0 ){	
		for( int i = d; i >= 0; i-- ){
			cout << coeffs[ i ] << "x^" << i;
			if( i > 0 )
				cout << " + ";
				
			}
		}
	else
		cout << coeffs[ 0 ];
}
/*	
	Dodawanie wielomianow
	@param int dA stopien wielomianu A
	@param int *coeffsA wspolczynniki wielomianu A
	@param int dB stopien wielomianu B
	@param int *coeffsB wspolczynniki wielomianu B
	@param int *dR stopien wielomianu wynikowego
	@param int *result wynik

*/
void SumSet( int dA, int *coeffsA,
			 int dB, int *coeffsB,
			 int *dR, int *result ){
			 	
	*dR = dA >= dB ? dA : dB; // stopien wielomiany wynikowego	
		 	
	int cA; // zmienna pomocniczy
	int cB;
	int d;
	bool checkD = false;
	// dodawanie 
	for( int i = 0; i <= *dR; i++ ){
		if( i <= dA) 
			cA = coeffsA[ i ];
		else
			cA = 0;			
		if( i <= dB) 
			cB = coeffsB[ i ];
		else
			cB = 0;
			
		if( !checkD && cA + cB  == 0 )
			*dR = *dR - 1;
		else
			if( cA + cB != 0 )
				checkD = true;
					
		result[i] = cA + cB;
		}			
	}

int main(){
	int coeffsA[] =  { -1, -2, -3 };
	int coeffsB[] = { 1, 2, 3 };
	int result[100];
	int dR;
	
	
	SumSet(2, coeffsA, 2, coeffsB, &dR, result);
	cout << "A: " << endl;
	ShowSet( 2 , coeffsA );
	cout << endl;
	cout << "B: " << endl;
	ShowSet( 2 , coeffsB );
	cout << endl;
	cout << "Wynik: " << endl;
	ShowSet( dR , result );
	cout << endl;
	
	
	return 0;
	}
