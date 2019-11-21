#include <iostream>
#include <string>
#include <cstdarg>

class PrzegrodkaNaLiczby{
private:
	bool init;
	double number;
	unsigned int size;
	std::string (*func)(unsigned int, double);	
		
public:
	PrzegrodkaNaLiczby( double n = 0.0, unsigned int s = 1, std::string (*p)(unsigned int, double) = NULL, bool say = false){
		init = true;
		number = n;
		size = s;
		func = p;
		if( say )
			std::cout << "Konstruktor przegrodki" << std::endl;		
	}
		
	PrzegrodkaNaLiczby( unsigned int s, std::string (*p)(unsigned int, double) = NULL, bool say = false){
		init = false;
		number = 0;
		size = s;
		func = p;
		if( say )
			std::cout << "Konstruktor przegrodki" << std::endl;
	}
	
	PrzegrodkaNaLiczby( const PrzegrodkaNaLiczby& copy, bool say = false ){
		init = copy.init;
		number = copy.number;
		size = copy.size;
		func = copy.func;
		if( say )
			std::cout << "Konstruktor przegrodki" << std::endl;
	}
	
	PrzegrodkaNaLiczby( const PrzegrodkaNaLiczby* copy, bool say = false ){
		init = copy->init;
		number = copy->number;
		size = copy->size;
		func = copy->func;
		if( say )
			std::cout << "Konstruktor przegrodki" << std::endl;		
	}
	void prezentuj(){
		std::cout << "Prezentacja przegrodki na liczby" << std::endl;
		double value = number;
		for( int i = 1; i <= size; i++ ){
			if( func != NULL )
				std::cout << func( i, value ) << std::endl;
			else
				std::cout << value << std::endl;
			if( init )
				value += 1.0;
		}
	}
	
	void zeruj(){
		number = 0;
		init = false;
		size = 1;
		func = NULL;
	}
};

