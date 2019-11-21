#include <iostream>

using namespace std;

int main(){
	int a;
	int b;
	int c;
	int wa;
	int wb;
	int wc;
	int temp;
	int s = 0;
	
	cin >> a >> b >> c;
	
	wa = a;
	wb = b;
	wc = c;
	s = a + b + c;
	
	do{
		cin >> temp;
		if( b + c + temp > s && temp != 0){
			wa = b;
			wb = c;
			wc = temp;
			s = b + c + temp;
			}			
		a = b;
		b = c;
		c = temp;
		} while
		 	( temp != 0);
	cout << "Suma: " << s << endl;
	cout << "Skladowe: " << wa << " " << wb << " " << wc;
	return 0;
}
