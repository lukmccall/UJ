#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a;
	int b;
	int c;
	float delta;
	cout << "Podaj a, b, c: ";
	cin >> a >> b >> c;
	
	if( a == 0 )
		if( b == 0 )
			if ( c == 0 )
				cout << "Tozsamosc";
			else
				cout << "Sprzecznosc";
		else
			cout << -c/b; 
	else{
		delta = b * b - 4 * a * c;
		if( delta > 0 )
			cout << (-b - sqrt( delta )) / (2 * a) << endl << (-b + sqrt( delta )) / (2 * a); 
		else
			if( delta == 0 )
				cout << -b / (2 * a);
			else
				cout << "Brak pierwiastkow rzeczywistych";
		}
	return 0;
}
