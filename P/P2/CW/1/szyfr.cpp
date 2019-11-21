#include <iostream>
#include <string>

unsigned char zakoduj(std::string word){
	unsigned char code = 0;
	for(int i = 0; i < word.size(); i++ )
		code = code * 2 + ( word[ i ] - '0' );
	return code;
}

std::string odkoduj(unsigned char byte){
	std::string word = "";
	for( int i = 128; i > 0; i /= 2 )
		if( byte / i ){
			word += '1';
			byte -= i;
		}
		else
			word += '0';
	
	return word;
}

unsigned char zaszyfruj(unsigned char tekst, unsigned char klucz){
	return ( tekst & ~klucz ) | ( ~tekst & klucz ); 
}

unsigned char odszyfruj(unsigned char tekst, unsigned char klucz){
	return zaszyfruj( tekst, klucz );
}

std::string zaszyfruj(std::string tekst, std::string klucz){
	return odkoduj( zaszyfruj( zakoduj( tekst ), zakoduj( klucz ) ) );
}

std::string odszyfruj(std::string tekst, std::string klucz){
	return zaszyfruj( tekst, klucz );
}

unsigned char zaszyfruj2(unsigned char tekst, unsigned char klucz){
	unsigned char lastBit = tekst / 64;
	tekst = tekst << 2;
	tekst += lastBit;
	return zaszyfruj( tekst, klucz );
}

unsigned char odszyfruj2(unsigned char tekst, unsigned char klucz){
	tekst = zaszyfruj( tekst, klucz );
	unsigned char firstBit = tekst << 6;
	tekst = tekst >> 2;
	tekst += firstBit;
	return tekst;
}

std::string zaszyfruj2(std::string tekst, std::string klucz){
	return odkoduj( zaszyfruj2( zakoduj( tekst ), zakoduj( klucz ) ) );
}

std::string odszyfruj2(std::string tekst, std::string klucz){
	return odkoduj( odszyfruj2( (unsigned char)zakoduj(tekst), (unsigned char)zakoduj(klucz) ) );
}
