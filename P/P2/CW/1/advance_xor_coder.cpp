#include <iostream>
#include <string>
#include "szyfr.cpp"


int main(int argc, char** argv){
	std::cout << "Szyfrowanie z przesunieciem" << std::endl << std::endl; 
	
	for( int i = 1; i < argc-1; i += 2 ){
		std::string tekst = argv[ i ];
		std::string klucz = argv[ i + 1 ];
		std::string szyfr = zaszyfruj( tekst, klucz );
		std::string odszyfrowany = odszyfruj( szyfr, klucz );
		 
		std::cout << "Tekst: " << tekst << " | " << (int)zakoduj( tekst ) << std::endl;	
		std::cout << "Klucz: " << klucz << " | " << (int)zakoduj( klucz ) << std::endl;	
		std::cout << "---------------------" << std::endl;
		std::cout << "Szyfr: " << szyfr << " | " << (int)zakoduj( szyfr ) << std::endl;	
		std::cout << "---------------------" << std::endl;
		std::cout << "Tekst: " << odszyfrowany << " | " << (int)zakoduj( odszyfrowany ) << std::endl;	
	}
	return 0;
}
