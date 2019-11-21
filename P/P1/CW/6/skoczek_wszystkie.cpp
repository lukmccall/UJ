// skoczek - wszystkie mozliwosci
#include <iostream>

using namespace std;

int answer = 1; // ilosc odpowiedzi

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
	int dl = NumberOfDigits( ( n * n ) - 1 );
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
void NextStep( int matrix[], int n, int x, int y, int step ){
	
	matrix[ x * n + y ] = step; // zaznaczenie aktualnej pozycji
	
	if( step == ( n * n ) - 1 ){ // znalazl rozwiazanie
		cout << "Rozwiazanie: " << answer << endl;
		answer++;
		DrawChessboard( matrix, n ); // wyswietl szachownice
		}

	// wynonanie nastepnego skoku
	if( CheckMove( matrix, n, x + 1, y - 2) )
		NextStep( matrix, n, x + 1, y - 2, step + 1);
		
	if( CheckMove( matrix, n, x + 2, y - 1) )
		NextStep( matrix, n, x + 2, y - 1, step + 1);
	
	if( CheckMove( matrix, n, x + 2, y + 1) )
		NextStep( matrix, n, x + 2, y + 1, step + 1);
	
	if( CheckMove( matrix, n, x + 1, y + 2) )
		NextStep( matrix, n, x + 1, y + 2, step + 1);
	
	if( CheckMove( matrix, n, x - 1, y + 2) )
		NextStep( matrix, n, x - 1, y + 2, step + 1);
	
	if( CheckMove( matrix, n, x - 2, y + 1) )
		NextStep( matrix, n, x - 2, y + 1, step + 1);
	
	if( CheckMove( matrix, n, x - 2, y - 1) )
		NextStep( matrix, n, x - 2, y - 1, step + 1);
		
	if( CheckMove( matrix, n, x - 1, y - 2) )
		NextStep( matrix, n, x - 1, y - 2, step + 1);
	
	matrix[ x * n + y ] = -1;
	}


int main(){
	int n, x, y;
	cin >> n; 
	cin >> x >> y; // pozycja startowa;
	int matrix[ n * n ];
	
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			matrix[ i * n + j ] = -1;	
	
	matrix[ x * n + y ] = 0;

	NextStep( matrix, n, x, y, 0);
	return 0;
	}
