#include <iostream>
#include <string>
#include "szyfr.cpp"


int main(int argc, char** argv){
	std::cout << "Porownanie szyfrowan" << std::endl << std::endl; 
	
	for( int i = 1; i < argc-1; i += 2 ){
		std::string tekst = argv[ i ];
		std::string klucz = argv[ i + 1 ];
		std::string szyfr = zaszyfruj( tekst, klucz );
		std::string szyfr2 = zaszyfruj2( tekst, klucz );		
		std::string odszyfrowany = odszyfruj( szyfr, klucz );
		std::string odszyfrowany2 = odszyfruj2( szyfr2, klucz );
				 
		std::cout << "Tekst:     " << tekst << "   |   " << (int)zakoduj( tekst ) << std::endl;	
		std::cout << "Klucz:     " << klucz << "   |   " << (int)zakoduj( klucz ) << std::endl;	
		std::cout << "---------------------" << std::endl;
		std::cout << "Szyfr:     " << szyfr << "   |   " << (int)zakoduj( szyfr ) << "   |   " << szyfr2 << "   |   " << (int)zakoduj(szyfr2) << std::endl;	
		std::cout << "---------------------" << std::endl;
		std::cout << "Tekst:     " << odszyfrowany << "   |   " << (int)zakoduj( odszyfrowany ) << "   |   " << odszyfrowany2 << "   |   " << (int)zakoduj(odszyfrowany2) << std::endl;	
	
	}
	return 0;
}
