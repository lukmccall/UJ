// dodawanie binarne
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
	bool first = false;
	for( int i = 0; i < 100; i++ ) // iteracja przez tablice wejsciowa
		if( s[ i ] == '0' ){ // pomijanie nieznaczacych 0
			if( first )
		 		cout << s[ i ];
			}
	 	else{
	 		cout << s[ i ];
	 		first = true;
			}
	}

/*
	Konwertowanie na zapis uzupelnienia do 2
 	@param char *s wskaznik do tablicy
	@param int bit ilosc bitow przeznaczonych na liczbe
*/
void ToU2( char *s, int bit ){
	int end = FindEnd( s ); // koniec ciagu
	int jump = bit - end; // przesuniecie 
	bool find = false; // czy pierwsza 1 zostala znaleziona

	if( jump != 0 ){ // wykluczenie przypadku kiedy nie na trzeba niczeo przesuwac
		for( int i = end - 1; i >= 1 ; i--){ // przesuniecie
			s[ i + jump ] = s[ i ]; 
			s[ i ] = '0';
			}
		s[ end + jump ] = 0; // znak konca ciagu
	}
	
	for( int i = 0; i < bit; i++ ) // uzupelnienie brakujacych miejsc
		if( s[ i ] == 0 )
			s[ i ] = '0';
	
	if( s[ 0 ] == '-' ){ // liczba ujemna
		s[ 0 ] = '0';
		for( int i = end + jump - 1; i >= 0; i--){ // do pierwszej 1 bez zmian pozniej negujemy
			if( !find ){			
				if( s[ i ] == '1' ) 
					find = true;
				}
			else
				s[ i ] = s[ i ] == '1'?'0':'1';
			
			}
		}
	else{ // liczba dodatnia
		s[ jump ] = s[ 0 ];
		s[ 0 ] = '0';
		}
	}	
	
/*
	Dodawanie dwoch liczb
 	@param char *sL wskaznik do pierwszej tablicy
 	@param char *sR wskaznik do drugiej tablicy
*/
void AddBin(char *sL, char *sR){
	bool find = false; // czy pierwsza 1 zostala znaleziona
	int lEnd = FindEnd( sL );
	int rEnd = FindEnd( sR );
	int length = lEnd >= rEnd ? lEnd : rEnd; // ustalanie dlugosci kodu u2
	length += 2;
	
	//Konwersja na u2
	ToU2( sL, length);
	ToU2( sR, length);
	
	int carry = 0; // przeniesienie
	int s; // suma 
	for( int i = length - 1; i >= 0; i-- ){ // dodawanie binarne
		s = ( sL[ i ] - '0' ) + (sR[ i ] - '0') + carry;
		sL[ i ] = '0' + s%2;
		if( s > 1 )
			carry = 1;
		else
			carry = 0;
		}
	
	if( sL[ 0 ] == '1'){ // wynik ujemny -> powrot z u2
		for( int i = length - 1; i >= 0; i--){
			if( !find ){			
				if( sL[ i ] == '1' ) 
					find = true;
				}
			else
				sL[ i ] = sL[ i ] == '1'?'0':'1';
			
			}
		cout << "-";
		}
		ShowBin(sL);	
	}
	

int main(){
	char sL[ 100 ] = {0}; // liczba w zapisie binarnym
	char sR[ 100 ] = {0}; // liczba w zapisie binarnym
	
	cin >> sL >> sR;

	AddBin(sL,sR);
	return 0;
	}
