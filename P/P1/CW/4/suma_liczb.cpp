// dodawanie dwoch licz przez funkcje
#include <iostream>

using namespace std;

/*
	Dodawanie i spaw zmiennych
	@param int *a wskaznik do jednej zmiennej
	@param int *b wskaznik do drugiej zmiennej
	@return int a + b;
*/
int Sum( int *a, int *b ){ 
	int temp = *b;
	*b = *a;
	*a = temp;
	return *a + *b;
	}	

/*
	Procedura dodawania
	@param int a zmienna a
	@param int b zmienna b
	@param int *c wskaznik do wyniku
	
*/
void SumVoid( int a, int b, int *c ){
	*c = a + b;
	}

int main(){
	int a = 5;
	int b = 8;
	int c = 0;
	
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;  
	cout << "c: " << c << endl;
	cout << endl;
	
	
	cout << "a + b: " <<  Sum( &a, &b ) << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;  
	cout << "c: " << c << endl;
	cout << endl;
	
	SumVoid( a, b, &c);
	cout << "a + b: " << c << endl; 
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;  
	cout << "c: " << c  << endl;
	
	return 0;
	}
