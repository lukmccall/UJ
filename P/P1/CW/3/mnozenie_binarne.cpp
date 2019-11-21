// mnozenie binarne
#include <iostream>

using namespace std;

/*
	Znajdywanie konca ciagu
 	@param char *s wskaznik do tablicy
 	@return int indeks konca ciagu
*/
int FindEnd( char *s ){ 
	for( int i = 0; i < 100; i++ )
		if( s[i] == 0 )
			return i;	
	}

/*
	Usuwanie znaku minus
 	@param char *s wskaznik do tablicy
*/
void DeleteMinus( char *s ){
	int end = FindEnd( s );
	for( int i = 1; i <= end; i++)
		s[ i - 1 ] = s[ i ]; 
	}

/*
	Sprawdzenie czy liczba jest rowna 0
 	@param char *s wskaznik do tablicy
 	@return bool 
*/	
bool IsNull( char *s ){
	int end = FindEnd( s );
	for( int i = 0; i < end; i++ )
		if( s[ i ]  == '1' )
			return false;
	return true;
	}
	
/*
	Przesuniecie w lewo
 	@param char *s wskaznik do tablicy
 	@param int jump dlugosc przesuniecia
*/
void Move( char *s, int jump){
	int end = FindEnd( s );
	for( int i = end; i < end + jump; i++)
		s[ i ] = '0';
	s[ end + jump ] = 0;
	} 	

/*
	wyswietlanie liczy binarnej z pominieciem nieznaczacych 0
 	@param char *s wskaznik do tablicy
*/	
void ShowBin( char *s ){
	int end = FindEnd( s );
	bool first = false;
	if( !IsNull( s ) ){
		for( int i = 0; i < end; i++ ) // iteracja przez tablice wejsciowa
			if( s[ i ] == '0' ){ // pomijanie nieznaczacych 0
				if( first )
			 		cout << s[ i ];
				}
		 	else{
		 		cout << s[ i ];
		 		first = true;
				}
		}	
	else
		cout << "0";
	}
	
/*
	Dodawanie dwoch liczb
 	@param char *sL wskaznik do pierwszej tablicy
 	@param char *sR wskaznik do drugiej tablicy
*/
void AddBin(char *sL, char *sR){
	int size = FindEnd( sL );
	int carry = 0;
	int s;
	for( int i = size - 1; i >= 0; i-- ){ // dodawanie binarne
		s = ( sL[ i ] - '0' ) + (sR[ i ] - '0') + carry;
		sL[ i ] = '0' + s%2;

		if( s > 1 )
			carry = 1;
		else
			carry = 0;
		}
	}

/*
	Zmiana rozmiaru interpretacja liczby binarnej
 	@param char *s wskaznik do tablicy
 	@param int size nowy rozmiara
*/	
void ReSize( char *s, int size ){
	int end = FindEnd( s );
	int jump = size - end;
	int flag = -1;
	for( int i = end; i >= 0; i-- ){
		if( s [ i ] == '1' && flag == -1 )
			flag = i;
		s[ jump + i ] = s[ i ];
		}
	for( int i = jump-1; i >=0 ; i-- )
		s[ i ] = '0';
	}
		
/*
	Mnozenie bez znaku licz binarnych
	@param char *sL wskaznik do pierwszej tablicy
 	@param char *sR wskaznik do drugiej tablicy
	@param char *result wskaznik do wyniku
*/	
void Mull( char *sL, char *sR, char *result){
	
	if( IsNull( sL ) || IsNull( sR ) ){
		result[ 0 ] = '0';
		result[ 1 ] = 0;
		}		
	else{
		char temp[ 100 ] = {0}; // tablica pomocnicza 
		int lEnd = FindEnd( sL );
		int rEnd = FindEnd( sR );
		int length = lEnd >= rEnd ? ( lEnd + 1 ) : ( rEnd + 1 ); // ustalanie dlugosci kodu do dodawania
		int size = length * 2; 
		
		
		for( int i = 0; i < 100; i++) // czyszczenie tablicy z wynikiem
			result[ i ] = '0';
			
		result[ size ] = 0; // znak konca
	
		// mnozenie
		for( int i = length - 1; i >= 0; i--)
			if( sR[ i ] == '1' ){
				for(int j = 0; j < length; j++ )
					temp[ j ] = sL[ j ]; 
				
				temp[ length ] = 0;
				Move( temp, rEnd - 1 -  i );
				ReSize( temp, size);
				AddBin( result, temp);
				}
		}
}
int main(){
	char sL[ 100 ] = {0}; // liczba w zapisie binarnym
	char sR[ 100 ] = {0}; // liczba w zapisie binarnym
	char result[ 100 ] = {0}; // Wynik 
	int minus = 0; // zmienna znaku
	
	cin >> sL >> sR;
	
	//Usuwanie znaku
	if( sL[ 0 ] == '-'){
		minus++;
		DeleteMinus( sL );
		}
	if( sR[ 0 ] == '-' ){
		minus++;
		DeleteMinus( sR );
	}
	
	//Mnozenie bez znaku 
	Mull( sL , sR, result );
	
	//Znak 
	if( minus % 2 != 0 )
		cout << "-";
	ShowBin(result);
	return 0;
	}

