#include <iostream>

using namespace std;

int main(){
	int n;
	int e1;
	int e2;
	int e3;
	cin >> n;
	
	if( n == 1 ){
		cin >> e1;
		cout << e1;
		}
	else{
		cin >> e1 >> e2;
		cout << e1 << endl << e2 << endl;
	
		while( n - 2 > 0 ){
			e3 = e1 + e2;
			cout << e3 << endl;
			e1 = e2;
			e2 = e3;
			n--;
			}
		}
	return 0;
}
