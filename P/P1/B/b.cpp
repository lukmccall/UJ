#include <iostream>

using namespace std;

int main(){
	int n;
	
	int t1;
	int t2;
	
	int temp;
	int delta; 
	int delta2;
	
	bool bezruch;
	bool postepowy;
	bool wsteczny;
	bool niewsteczny;
	bool niepostepowy;
	
	bool jednostajny;
	bool przyspieszony;
	bool hamowany;
	bool niehamowany;
	bool nieprzyspieszony;
	
	cin >> n;
	
	while( n > 0 ){
		
		bezruch = postepowy = wsteczny = niewsteczny = niepostepowy = true;
		jednostajny = przyspieszony = hamowany = niehamowany = nieprzyspieszony = true;
		
		cin >> t1 >> t2;
		delta = t2 - t1;
		do{
			cin >> temp;
			if( temp != -1 ){
				if( temp != t2 || t2 != t1 ) bezruch = false;
				if( delta <= 0 || temp <= t2 ) postepowy = false;
				if( delta >= 0 || temp >= t2 ) wsteczny = false;
				if( delta < 0 || temp < t2 ) niewsteczny = false;
				if( delta > 0 || temp > t2 ) niepostepowy = false;
				
				delta2 = temp - t2;
				if( delta2 < 0 )
					delta2 = - delta2;
				if( delta < 0 )
					delta = -delta;
				
				if( delta2 != delta ) jednostajny = false;
				if( delta2 <= delta ) przyspieszony = false;
				if( delta2 >= delta ) hamowany = false;
				if( delta2 < delta ) niehamowany = false;
				if( delta2 > delta ) nieprzyspieszony = false;
				
				t1 = t2;
				t2 = temp;
				delta = t2 - t1;	
				}
			}while( temp != -1 );
		
		if( bezruch )
			cout << "bezruch";
		else
			if( postepowy) {
				cout << "postepowy ";
				if( jednostajny ) 
					cout << "jednostajny";
				else 
					if( przyspieszony )
						cout << "przyspieszony";
					else 
						if( hamowany )
							cout << "hamowany";
						else 
							if( niehamowany )
						 		cout << "niehamowany";
							else
								if( nieprzyspieszony )
									cout << "nieprzyspieszony";
								else
									cout << "nieokreslony";
				}
			else
				if( wsteczny ){
					cout << "wsteczny ";
					if( jednostajny )
						cout << "jednostajny";
					else
						if( przyspieszony ) 
							cout << "przyspieszony";
						else 
							if( hamowany ) 
								cout << "hamowany";
							else 
								if( niehamowany ) 
									cout << "niehamowany";
								else 
									if( nieprzyspieszony ) 
										cout << "nieprzyspieszony";
									else 
										cout << "nieokreslony";
					}
				else
					if( niewsteczny )
						cout << "niewsteczny";
					else
						if( niepostepowy )
							cout << "niepostepowy";
						else
							cout << "nieokreslony";
		if( n > 1 ) 
			cout << endl;			
		n--;
		}
	return 0;
}
