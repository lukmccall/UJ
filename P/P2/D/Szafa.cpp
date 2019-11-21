#include "Szuflada.cpp"

class Szafa{
private:
	unsigned int size;
	Szuflada** array;
public:
	Szafa(){
		size = 0;
		array = NULL;
	}
	Szafa( const Szafa& copy ){
		size = copy.size;
		array = new Szuflada*[ size ];
		for( int i = 0; i < size; i++ )
			array[ i ] = copy.array[ i ];
	}
	Szafa( const Szafa* copy ){
		size = copy->size;
		array = new Szuflada*[ size ];
		for( int i = 0; i < size; i++ )
			array[ i ] = copy->array[ i ];
	}
	Szafa( unsigned int s, ...){
		size = s ;
		array = new Szuflada*[ s ];
		va_list list;
		va_start( list, s );
		for( int i = 0; i < s; i++ )
			array[ i ] = va_arg( list, Szuflada* );
		va_end( list );
	}
	Szafa( unsigned int s, Szuflada** a ){
		size = s;
		array = new Szuflada*[ s ];
		for( int i = 0; i < s; i++ )
			array[ i ] = a[ i ];
	}
	~Szafa(){
		delete[] array;
	}
	void prezentuj(){
		std::cout << "Prezentacja szafy" << std::endl;
		for(int i = 0; i < size; i++)
			array[ i ]->prezentuj();
	}
	void zeruj(){
		delete[] array;
		array = NULL;
		size = 0;
	}
};
