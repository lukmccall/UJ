// skoczek - jedno rozwiazanie 
#include <iostream>

using namespace std;

/*
	Liczenie ilosc cyfer liczby
*/
int NumberOfDigits( int num ){
	int i = 0;
	if( num == 0 )
		return 1;
	if( num == -1 )
		return 2;
	while( num > 0 ){
		num /= 10;
		i++;
		}	
	return i;
}

/*
	Rysuje linie 
*/
void DrawLine( int size ){
	for( int i = 0; i < size; i++ )
		cout << "-";
	cout << endl;
	}

/*
	Rysuje szachownice
*/
void DrawChessboard( int matrix[], int n ){
	int dl = NumberOfDigits( ( n * n ) - 1 ); // dlugosc lini
	for( int i = 0; i < n; i++ ){
		DrawLine( ( dl + 3 ) * n + 1 );
		cout << "| ";
		for( int j = 0; j < n; j++ ){
			for( int l = NumberOfDigits( matrix[ i * n + j ] ); l < dl; l++  )
				cout << " ";
			cout << matrix[ i * n + j ] << " | ";
			}
		cout << endl;
		}
	DrawLine( ( dl + 3 ) * n + 1 );
	}

/*
	Sprawdza poprawnosc ruchu
*/
bool CheckMove( int matrix[], int n, int x, int y ){
	if( x < n && x >= 0 && y < n && y >= 0)
		if( matrix[ x * n + y ] == -1 )
			return true;
	return false;
	}

/*
	Implementacja rekurencyjengo algorytmu z powrotami problemu skoczka na szachownicy
*/
bool NextStep( int matrix[], int n, int x, int y, int step ){
	
	matrix[ x * n + y ] = step; // zaznaczenie aktualnej pozycji
	
	if( step == ( n * n ) - 1 ){  // znalazl rozwiazanie
		cout << "Rozwiazanie: " << endl;
		DrawChessboard( matrix, n ); // wyswietl szachownice
		return true;
		}
	else{
		// wynonanie nastepnego skoku
		if( CheckMove( matrix, n, x + 1, y - 2) )
			if( NextStep( matrix, n, x + 1, y - 2, step + 1) )
				return true;
		
		if( CheckMove( matrix, n, x + 2, y - 1) )
			if( NextStep( matrix, n, x + 2, y - 1, step + 1) )
				return true;
		
		if( CheckMove( matrix, n, x + 2, y + 1) )
			if( NextStep( matrix, n, x + 2, y + 1, step + 1) )
				return true;
		
		if( CheckMove( matrix, n, x + 1, y + 2) )
			if( NextStep( matrix, n, x + 1, y + 2, step + 1) )
				return true;
		
		if( CheckMove( matrix, n, x - 1, y + 2) )
			if( NextStep( matrix, n, x - 1, y + 2, step + 1) )
				return true;
		
		if( CheckMove( matrix, n, x - 2, y + 1) )
			if( NextStep( matrix, n, x - 2, y + 1, step + 1) )
				return true;
		
		if( CheckMove( matrix, n, x - 2, y - 1) )
			if( NextStep( matrix, n, x - 2, y - 1, step + 1) )
				return true;
			
		if( CheckMove( matrix, n, x - 1, y - 2) )
			if( NextStep( matrix, n, x - 1, y - 2, step + 1) )
				return true;
				
		matrix[ x * n + y ] = -1; // powrot
		}
	return false;
	}

int main(){
	int n, x, y;
	cin >> n;
	cin >> x >> y; // pozycja startowa;
	int matrix[ n * n ]; // szachownica
	
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			matrix[ i * n + j ] = -1; // oflagowanie miejs nie odwiedzonych	
		
	matrix[ x * n + y ] = 0;
	
	if( !NextStep( matrix, n, x, y, 0) ) 
		cout << "Brak Rozwiazan"; // brak rozwiazan
	return 0;
	}
