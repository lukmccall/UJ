// zamiana liczby na slowo
#include <iostream>

using namespace std;

/*
	Znajdz indeks konca ciagu znakow
	@param char *s ciag znakow
	@return int indeks konca
*/
int Size( char *s ){
	int i = 0;
	while( s[ i ] != 0 )
		i++;
	return i;  
	}

/*
	Laczenie ciagow znakow
	@param char *word ciag znakow do ktorego dodajemy z lewej strony drugi ciag
	@param char *adds ciag znakow ktory dodajemy
*/
void Concatenate( char *word, char *adds ){
	int sizeOfWord = Size( word );
	int sizeOfAdds = Size( adds );
	for( int i = sizeOfWord; i >= 0; i-- )
		word[ i + sizeOfAdds ] = word[ i ];
	for( int i = 0; i < sizeOfAdds; i++ )
		word[ i ] = adds[ i ];
		
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
	Dodawanie jednosci
	@param int n jednosci
	@param char *word ciag znakow
*/
void Jednosci( int n, char *word ){
	if( n == 1 )
		Concatenate( word, " jeden");
	if( n == 2 )
		Concatenate( word, " dwa");
	if( n == 3 )
		Concatenate( word, " trzy");
	if( n == 4 )
		Concatenate( word, " cztery");
	if( n == 5 )
		Concatenate( word, " piec");
	if( n == 6 )
		Concatenate( word, " szesc");
	if( n == 7 )
		Concatenate( word, " siedem");
	if( n == 8 )
		Concatenate( word, " osiem");
	if( n == 9 )
		Concatenate( word, " dziewiec");	
	}

/*
	Dodawanie nascie
	@param int n nascie
	@param char *word ciag znakow
*/
void Nascie( int n, char *word ){
	if( n == 0 )
		Concatenate( word, " dziesiec");
	if( n == 1 )
		Concatenate( word, " jedenascie");
	if( n == 2 )
		Concatenate( word, " dwanascie");
	if( n == 3 )
		Concatenate( word, " trzynascie");
	if( n == 4 )
		Concatenate( word, " czternascie");
	if( n == 5 )
		Concatenate( word, " pietnascie");
	if( n == 6 )
		Concatenate( word, " szesnascie");
	if( n == 7 )
		Concatenate( word, " siedemnascie");
	if( n == 8 )
		Concatenate( word, " osiemnascie");
	if( n == 9 )
		Concatenate( word, " dziewietnascie");	
	}

/*
	Dodawanie dziesiatek
	@param int n dziesiatki
	@param char *word ciag znakow
*/
void Dziesiatki( int n, char *word ){
	if( n == 1 )
		Concatenate( word, " dziesiec");
	if( n == 2 )
		Concatenate( word, " dwadziescia");
	if( n == 3 )
		Concatenate( word, " trzydziesci");
	if( n == 4 )
		Concatenate( word, " trzydziesci");
	if( n == 5 )
		Concatenate( word, " piecdziesiat");
	if( n == 6 )
		Concatenate( word, " szescdziesiat");
	if( n == 7 )
		Concatenate( word, " siedemdziesiat");
	if( n == 8 )
		Concatenate( word, " osiemdziesiat");
	if( n == 9 )
		Concatenate( word, " dziewiecdziesiat");	
	}

/*
	Dodawanie setek
	@param int n setki
	@param char *word ciag znakow
*/
void Setki( int n, char *word ){
	if( n == 1 )
		Concatenate( word, " sto");
	if( n == 2 )
		Concatenate( word, " dwiescie");
	if( n == 3 )
		Concatenate( word, " trzysta");
	if( n == 4 )
		Concatenate( word, " czterysta");
	if( n == 5 )
		Concatenate( word, " piecset");
	if( n == 6 )
		Concatenate( word, " szescset");
	if( n == 7 )
		Concatenate( word, " siedemset");
	if( n == 8 )
		Concatenate( word, " osiemset");
	if( n == 9 )
		Concatenate( word, " dziewiecset");	
	}

/*
	Dodawanie rzedu wielkosci
	@param int n rzad wielkosci
	@param char *word ciag znakow
*/
void RzedyWielkosci( int n, char *word ){
	if( n == 1 )
		Concatenate( word, " tys.");
	if( n == 2 )
		Concatenate( word, " mln.");
	if( n == 3 )
		Concatenate( word, " mld.");
	if( n == 4 )
		Concatenate( word, " bln.");
	if( n == 5 )
		Concatenate( word, " bld.");
	
	}
	
/*
	Zamiana liczby na ciag znakow
	@param int n liczba do zamiany
	@param char *slownie ciag do zamiany
*/	
void NumToString( int n, char *slownie ){
	int end; // koncowka liczby n (tz n % 10 )
	int i = 0; // licznik
	int	range = 0; // rzad wielkosci
	bool minus = false; // czy liczba jest ujemna
	
	if( n == 0 ) 
		Concatenate( slownie, "zero");
	else{
		if( n < 0 ){
			minus = true;
			n = -n;	
			}
	
		// iteracja przez kazda cyfre
		while( n > 0 ){
			end = n % 10; // oblicanie koncowki 
			n /= 10; // nowa wartosc liczby
			
			if ( ( i == 0 ) && ( n % 100 != 0 || end != 0 ) ) // rzad wielkosci
				RzedyWielkosci( range , slownie );

			if ( ( i == 0 ) && ( n % 10 != 1 ) ) // jednosci
				Jednosci( end, slownie );
				
			if ( ( i == 0 ) && ( n % 10 == 1 ) ){ // nascie
				Nascie( end, slownie );
				n /= 10;
				i += 1;
				}
			else{
				if ( i == 1 ) // dziesiatki
					Dziesiatki( end, slownie );
				if ( i == 2 ){ //setki
					Setki( end, slownie );
					i = -1;
					range++;
					}					
				}
			i++;					
			}
			MoveLeft( slownie );			
		}
	if( minus ) // dopisowanie minusa
		Concatenate( slownie, "minus ");
	}

int main(){
	char slownie[ 500 ] = {0};
	int n;
	
	cin >> n;
	NumToString( n, slownie );
	cout << slownie << endl;
	return 0;
	}
