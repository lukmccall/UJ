// zaciemnianie zmiennych
#include <iostream>

using namespace std;

char ZMIENNA[] = "zmienna globalna";

int main(){
	int ZMIENNA = 123;
	
	cout << "ZMIENNA = " << ZMIENNA << endl;
	{
		char ZMIENNA = 'A';
		cout << "ZMIENNA = " << ZMIENNA << endl;
		cout << "::ZMIENNA = " << ::ZMIENNA << endl;
		for( int ZMIENNA = 0; ZMIENNA < 10; ZMIENNA++ ){
			cout << ZMIENNA << ": " << ::ZMIENNA << endl;
			{
				char ZMIENNA[] = "zmienna lokalna";
				cout << "   "<< ZMIENNA << " ";
				{
					float ZMIENNA = 1.23;
					cout << ZMIENNA << endl;
				}
			}
		}
	}
	return 0;
	}
