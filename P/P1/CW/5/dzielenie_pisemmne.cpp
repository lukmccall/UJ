// dzielenie pisemne 
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
	
	while( left[ 0 ] == '0' && Size( left ) > 1 ) // kasowanie zer z przodu wyniku
		MoveLeft( left );	
	while( right[ 0 ] == '0' && Size( right ) > 1 ) 
		MoveLeft( right );
		
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
	Odejmowanie pisemnie dwoch liczb >= 0, bez znaku(left - right)
	@param char left[] libcza left
	@param char right[] libcza right
	@param char result[] wynik 
*/
void Delete( char left[], char right[], char result[] ){
	int leftSize = Size( left );
	int rightSize = Size( right );
	int leftNumber; // pojedyncza cyfra left
	int rightNumber; // pojedyncza cyfra right
	int partDelete; // czesciowa roznica
	int borrow = 0; // pozyczka 
	
	int max = leftSize > rightSize ? leftSize : rightSize; // okreslenie maksymalnego rozmiaru wyniku
	Resize( left, max ); // dostosowanie rozmiarow
	Resize( right, max );
	result[ max ] = 0; // ustawienie bitu zerowego w wyniku
	
	for( int i = max - 1; i >= 0; i--){ // iteracja przez wszystkie cyfry
		leftNumber = left[ i ] - '0';
		rightNumber = right[ i ] - '0';
			
		partDelete = leftNumber - rightNumber - borrow; // wykonywanie odejmowania
		borrow = 0;
		if( partDelete < 0 ){	// pozyczka
			borrow = 1;	
			partDelete += 10;
			}
		result[ i ] = partDelete + '0';
		}

	while( result[ 0 ] == '0' && Size( result ) > 1 ) // kasowanie zer z przodu wyniku
		MoveLeft( result );				

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
	dzielenie dwoch liczb calkowitych
	@param char left[] libcza left
	@param char right[] libcza right
	@param char result[] wynik 
*/
void Divi( char left[], char right[], char total[], char fraction[] ){
	char one[ 1000 ] = "1";
	int minus = 0; // znak wyniku
	total[ 0 ] = 0; // zerowanie wyniku
	fraction[ 0 ] = 0;
	
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
	
	if( left[ 0 ] == '0' && right[ 0 ] != '0' ){ // 0/cos
		total[ 0 ] = '0';
		total[ 1 ] = 0;
		fraction[ 0 ] = '0';
		fraction[ 1 ] = 0;
		}
	else{
		if( right[ 0 ] == '0')
			cout << "Dzielenie przez 0" << endl;
		else{
			total[ 0 ] = '0';
			total[ 1 ] = 0;
			
			while( IsBigger(left, right)) {
//				Add(total, one, total);
				Delete(left, right, left);	
				}
			for( int i = Size( left ); i >= 0; i-- )
				fraction[ i ] = left[ i ];
			
			
			if( minus % 2 == 1){ // okreslanie znaku wyniku
				MoveRight( total );
				total[0] = '-';
				}
			}
		}
	}

int main(){
	char a[ 1000 ];
	char b[ 1000 ];
	char total[ 1000 ];
	char fraction[ 1000 ];
	cin >> a >> b;
	Divi( a, b , total, fraction);
	cout << total << " r. " << fraction;
	return 0;
	}
