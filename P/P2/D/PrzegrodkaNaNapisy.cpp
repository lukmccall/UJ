#include <iostream>
#include <string>
#include <cstdarg>

class PrzegrodkaNaNapisy{
private:
	std::string word;
	bool init;
	unsigned int size;
	std::string (*func)(unsigned int, std::string);
public:
	PrzegrodkaNaNapisy( std::string w = "", unsigned int s = 1, std::string (*p)(unsigned int, std::string) = NULL, bool say = false ){
		word = w;
		init = true;
		size = s;
		func = p;
		if( say )
			std::cout << "Konstruktor przegrodki" << std::endl;
	}
	
	PrzegrodkaNaNapisy( unsigned int s, std::string (*p)(unsigned int, std::string) = NULL, bool say = false ){
		word = "";
		init = false;
		size = s;
		func = p;
		if( say )
			std::cout << "Konstruktor przegrodki" << std::endl;
	} 
	
	PrzegrodkaNaNapisy( const PrzegrodkaNaNapisy& copy, bool say = false ){
		word = copy.word;
		init = copy.init;
		size = copy.size;
		func = copy.func;
		if( say )
			std::cout << "Konstruktor przegrodki" << std::endl;
	}
	
	PrzegrodkaNaNapisy( const PrzegrodkaNaNapisy* copy, bool say = false ){
		word = copy->word;
		init = copy->init;
		size = copy->size;
		func = copy->func;
		if( say )
			std::cout << "Konstruktor przegrodki" << std::endl;
	}
	
	void prezentuj(){
		std::cout << "Prezentacja przegrodki na napisy" << std::endl;
		std::string value = word;
		for( int i = 1; i <= size; i++ ){
			if( func != NULL )
				std::cout << func( i, value ) << std::endl;
			else
				std::cout << value << std::endl;
			if( init )
				value += word;
		}
	}
	void zeruj(){
		word = "";
		init = false;
		size = 1;
		func = NULL;
	}
};
