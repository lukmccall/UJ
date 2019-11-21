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
		if(d == 0)
			cout << coeffs[ 0 ];
		else
			cout << "0";
	}

/*
	Pochodana wielomianu
	@param int nD stopien wielomianu wejsciowego
	@param int *coeffsD wspolczynniki wielomianu
	@param d pochodna
	@param int *nR stopien wielomianu wyjsciowego
	@param int *coeffsR wspolczynniki wielomianu wyjsciowego
*/
void Devrative( int nD, int *coeffsD, int d, int *nR, int *coeffsR ){
	int cR;
	bool checkD = false;
	*nR = nD - d;
	for( int i = 0; i <= nD - d; i++ ){
		cR = coeffsD[ i ];
		for( int j = 0; j < d; j++ ) {
			cR *= (nD - i) - j ;	
			}
		coeffsR[ i ] = cR;
		}
	}

int main(){
	int coeffsA[] = { 1, 2, 3 };
	int result[100];
	int dR;
	Devrative( 2, coeffsA, 1, &dR, result);
	ShowSet( dR, result);
	
	return 0;
	}
