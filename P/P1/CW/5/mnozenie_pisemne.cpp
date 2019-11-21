// mnozenie pisemne 
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

/*
	Wielkosc ciag znakowego
	@param char* s ciag znakowy
	@return int indeks bitu zerowego
*/
int Size( char *s ){
	int i = 0;
	while( s[i] )
		i++;
	return i;
	}

/*
	Przesuniecie ciagu o jeden w lewo
	@param char *word ciag znakow 
*/
void MoveLeft( char *word ){
	int size = Size( word );
	for(int i = 0; i < size; i++ )
		word[ i ] = word[ i + 1 ]; 
	}
	
/*
	Przesuniecie ciagu o jeden w prawo
	@param char *word ciag znakow 
*/
void MoveRight( char *word ){
	int size = Size( word );
	for(int i = size; i >= 0; i-- )
		word[ i + 1 ] = word[ i ]; 
	}

/*
	Zmiana wielkosci ciagu znakowego( dopisanie 0 z przodu)
	@param char *word ciag znakow 
	@param int newSize nowy rozmiar
*/
void Resize( char *word, int newSize ){
	int size = Size( word );
	for(int i = 0; i < newSize - size; i++ ){
		MoveRight( word );
		word[ i ] = '0';
		}
	}

/*
	Sprawdzenie czy ciag znakowy left jest wiekszy lub rowny od ciagu znakowego right
	@param char left[] ciag left
	@param char right[] ciag right
	@return bool
*/
bool IsBigger( char left[], char right[] ){
	int leftSize = Size( left );
	int rightSize = Size( right );
	
	if (leftSize > rightSize )
		return true;
	else 
		if( leftSize < rightSize )
			return false;
		else{
			for( int i = 0; i < leftSize; i++ )
				if( left[ i ] > right[i] )	
					return true;
				else
					if( left[ i ] < right[ i ] )
						return false;	
			}	
	return true;

}

/*
	Dodawanie pisemnie dwoch liczb >= 0, bez znaku(left + right)
	@param char left[] libcza left
	@param char right[] libcza right
	@param char result[] wynik 
*/
void Add( char left[], char right[], char result[] ){
	int leftSize = Size( left );
	int rightSize = Size( right );
	int leftNumber; // pojedyncza cyfra left
	int rightNumber; // pojedyncza cyfra right
	int partSum; // suma czesciowa
	int carry = 0; // przeniesienie 
	
	int max = leftSize > rightSize ? leftSize : rightSize; // okreslanie rozmiaru
	Resize( left, max ); // dostosowanie rozmiarow
	Resize( right, max );
	result[ max ] = 0; // ustawienie bitu konca 
	
	for( int i = max - 1; i >= 0; i-- ){ // iteracja przez wszystkie cyfry
		leftNumber = left[ i ] - '0';
		rightNumber = right[ i ] - '0';
					
		partSum = ( leftNumber + rightNumber + carry ) % 10;
		carry = ( leftNumber + rightNumber + carry ) / 10;
		result[ i ] = partSum + '0';
		}
	
	if( carry != 0 ){ // powiekszenie wyniku gdy po przejsciu przez wszystkie cyfry zostaje przeniesienie
		MoveRight( result );
		result[ 0 ] = carry + '0';
		}
	
	}	


/*
	Mnozenie dwoch liczb calkowitych
	@param char left[] libcza left
	@param char right[] libcza right
	@param char result[] wynik 
*/
void Mull( char left[], char right[], char result[] ){
	int tempSize; // zmienna pomocnicza
	int minus = 0; // znak wyniku
	result[0] = 0; // zerowanie wyniku
	
	if( left[0] == '+' )
		MoveLeft( left );
	if( right[0] == '+' )
		MoveLeft( right );
		
	if( left[0] == '-' ){
		MoveLeft( left );
		minus++;
		}
	if( right[0] == '-' ) {
		MoveLeft( right );
		minus++;
		}
	
	if( right[ 0 ] == '0' || left[ 0 ] == '0' ){ // mnozenie razy 0
		result[ 0 ] = '0';
		result[ 1 ] = 0;
		}
	else{
		for( int i = Size( right ) - 1 ; i >= 0; i-- ){ // algorytm mnozenia pisemnego
			for( int j = right[ i ] - '0'; j > 0; j-- )
				Add(result, left, result);
			tempSize = Size( left );
			left[ tempSize ] = '0';
			left[ tempSize + 1 ] = 0;	
			}
		
		if( minus % 2 == 1){ // okreslanie znaku wyniku
			MoveRight( result );
			result[0] = '-';
			}	
		
		}
	}

int main(){
	char a[ 1000 ];
	char b[ 1000 ];
	char s[ 1000 ];
	cin >> a >> b;

	Mull( a, b , s);
	cout << s;
	return 0;
	}
