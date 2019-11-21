#include <iostream>
#include <string>
#include <cstdarg>
#include "PrzegrodkaNaLiczby.cpp"
#include "PrzegrodkaNaNapisy.cpp"

class Szuflada{
private:
	PrzegrodkaNaLiczby forNumbers;
	PrzegrodkaNaNapisy forWords;	
public:
	Szuflada():forNumbers( 0.0, 1, NULL, true ), forWords( "", 1, NULL, true ){};
	
	Szuflada(PrzegrodkaNaLiczby& fN ):forNumbers( fN, true ), forWords( 2, NULL, true ){};
	Szuflada(PrzegrodkaNaNapisy& fW ):forNumbers( 2, NULL, true ), forWords( fW, true ){};
	
	Szuflada(PrzegrodkaNaLiczby* fN ):forNumbers( fN, true ), forWords( 2, NULL, true ){};
	Szuflada(PrzegrodkaNaNapisy* fW ):forNumbers( 2, NULL, true), forWords( fW, true ){};
	
	Szuflada( PrzegrodkaNaLiczby& fN, PrzegrodkaNaNapisy& fW ):forNumbers( fN, true ), forWords( fW,true ){};
	Szuflada( PrzegrodkaNaLiczby* fN, PrzegrodkaNaNapisy* fW):forNumbers( fN, true ), forWords( fW,true ){};
	Szuflada( PrzegrodkaNaLiczby* fN, PrzegrodkaNaNapisy& fW):forNumbers( fN, true ), forWords( fW,true ){};
	Szuflada( PrzegrodkaNaLiczby& fN, PrzegrodkaNaNapisy* fW):forNumbers( fN, true ), forWords( fW,true ){};
	
	Szuflada( PrzegrodkaNaNapisy& fW, PrzegrodkaNaLiczby& fN):forNumbers( fN, true ), forWords( fW,true ){};
	Szuflada( PrzegrodkaNaNapisy* fW, PrzegrodkaNaLiczby* fN):forNumbers( fN, true ), forWords( fW,true ){};
	Szuflada( PrzegrodkaNaNapisy& fW, PrzegrodkaNaLiczby* fN):forNumbers( fN, true ), forWords( fW,true ){};
	Szuflada( PrzegrodkaNaNapisy* fW, PrzegrodkaNaLiczby& fN):forNumbers( fN, true ), forWords( fW,true ){};
	
	Szuflada( const Szuflada& copy ):forNumbers( copy.forNumbers, true ), forWords( copy.forWords,true ){};
	Szuflada( const Szuflada* copy ):forNumbers( copy->forNumbers, true ), forWords( copy->forWords,true ){};

	void prezentuj(){
		std::cout << "Prezentacja szuflady" << std::endl;
		forNumbers.prezentuj();
		forWords.prezentuj();
	}
	
	void zeruj(){
		forNumbers.zeruj();
		forWords.zeruj(); 
	}

};
