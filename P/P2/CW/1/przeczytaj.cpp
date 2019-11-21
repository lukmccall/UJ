#include <iostream>

unsigned char zakoduj(std::string word){
	unsigned char code = 0;
	for(int i = 0; i < word.size(); i++ )
		code = code * 2 + ( word[ i ] - '0' );
	return code;
}

std::string przeczytaj(std::string tekst){
	std::string ret = "";
	unsigned char t = zakoduj( tekst ); 
	for( int i = 128; i > 0; i /=2 )
		if( t / i ){
			ret += "jeden ";
			t -= i;
		}
		else
			ret += "zero "; 
	return ret;
}

int main(int argc, char** argv){
	for( int i = 1; i < argc; i++ )
		std::cout << przeczytaj( argv[ i ] ) << std::endl;
	return 0;
}
