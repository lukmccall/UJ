#include <iostream>

using namespace std;

int main(){
	int x;
	int n;
	int temp;
	int fx = 0;
	
	cout << "Podaj x: ";
	cin >> x;
	cout << "Podaj stopien wielomianu: ";
	cin >> n;
	n++;
	
	while( n > 0 ){
		cin >> temp;
		fx = x * fx + temp;	
		n--;
		}
	cout << fx;
	return 0;
}
