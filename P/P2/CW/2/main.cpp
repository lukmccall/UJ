#include <iostream>
#include <fstream>
#include <string>
#include <cstdarg>
#include <iomanip>

void rozdzielNaHex(std::string input, int sets, ...){
	va_list args;
	va_start( args, sets );
	std::fstream in( input.c_str(), std::fstream::in );
	std::fstream out[ sets ];
	for( int i = 0; i < sets; i++ ){
		std::string temp = va_arg( args, char* );
		out[ i ].open( temp.c_str(), std::fstream::out );
	}
	va_end( args );
			
	long long num;
	int file = 0;
	while( !in.eof() ){
		in >> num;
		
		out[ file ] << std::uppercase << std::hex <<  num << std::endl;
		file = ( file + 1 ) % sets;
	}
	in.close();
	for( int i = 0; i < sets; i++ )
		out[ i ].close();
}


struct INPUT_STRUCT{
	std::fstream file;
	bool used;
	
	void Init( std::string f ){
		file.open( f.c_str(), std::fstream::in );
		used = false;
	}
	
	long long getValue(){
		long long val = 0;
		file >> std::hex >> val;
		if( file.eof() )
			used = true;	
		
		return val;
	}
	
	void Close(){
		file.close();
	}
	
	bool isUsed(){
		return used;
	}
};

void polaczNaDec( std::string output, int sets, ...){
	va_list args;
	va_start( args, sets );
	std::fstream out( output.c_str(), std::fstream::out );
	INPUT_STRUCT in[ sets ];
	bool moreData = true;
	for( int i = 0; i < sets; i++ ){
		std::string temp = va_arg( args, char* );
		in[ i ].Init( temp );
	}
	va_end( args );
	
	while( moreData ){
		moreData = false;
		for( int i = 0; i < sets; i++ )
			if( !in[ i ].isUsed() ){
				long long val = in[ i ].getValue();
				if( !in[ i ].isUsed() ){
					out << val << std::endl;
					moreData = true;	
				}
			}
	}
	
	out.close();
	for( int i = 0; i < sets; i++ )
		in[ i ].Close();
}

int main(){
	rozdzielNaHex( "in.txt", 4, "out_1.txt", "out_2.txt", "out_3.txt", "out_4.txt");
	polaczNaDec( "out.txt", 4, "out_1.txt", "out_2.txt", "out_3.txt", "out_4.txt"); 
	return 0;
}
