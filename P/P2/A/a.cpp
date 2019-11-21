
int itr = 0;
int itrPrint = 31;

int add( int a, int b ){
    int s;
	int c;
	  
    if ( b == 0 ) return a;
    
	s = a ^ b;
    c = ( a & b ) << 1;
    
	return add( s, c );
}

void Emplace( std::string input, int* set ){
	if( itr == 0 )
		*set = 0;
	
	if( itr < input.length() ){
		if( input.at( itr ) == '0' ||  input.at( itr ) == '1' ){
			int readSet = 1;
			
			if( input.at( itr ) == '1' )
				readSet <<= 16;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 8;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 4;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 2;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 1;
			
			*set |= readSet;
		}
			
		itr = add( itr, 1 );
		Emplace( input, set );
	}
	else
		itr = 0;	
}

void Insert( std::string input, int* set ){	
	if( itr < input.length() ){
		if( input.at( itr ) == '0' ||  input.at( itr ) == '1' ){
			int readSet = 1;
			
			if( input.at( itr ) == '1' )
				readSet <<= 16;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 8;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 4;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 2;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 1;
			
			*set |= readSet;
		}
			
		itr = add( itr, 1 );
		Insert( input, set );
	}
	else
		itr = 0;	
}

void Erase( std::string input, int* set ){
	if( itr < input.length() ){
		if( input.at( itr ) == '0' ||  input.at( itr ) == '1' ){
			int readSet = 1;
			
			if( input.at( itr ) == '1' )
				readSet <<= 16;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 8;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 4;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 2;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 1;
			
			readSet = ~readSet;
			*set &= readSet;
		}
			
		itr = add( itr, 1 );
		Erase( input, set );
	}
	else
		itr = 0;	
}

void Print( int set, std::string* output ){
	if( itrPrint < 0 ){
		itrPrint = 31;
		return;		
	}

	if( set == 0 ){
		itrPrint = 31;
		*output = "empty";
		return;
	}
		
	if( itrPrint == 31 )
		*output = "";
		 
	if( set & ( 1 << itrPrint ) ){
		std::stringstream ss;
		ss << *output;
		ss << ( itrPrint / 16 ) 
		   << ( itrPrint / 8 ) % 2  
		   << ( itrPrint / 4 ) % 4 % 2  
		   << ( itrPrint / 2 ) % 8 % 2 
		   << ( itrPrint % 2 ) << " "; 
		*output = ss.str(); 
	}	
	
	itrPrint = add( itrPrint, add( 1, ~1) );
	Print( set, output );	
}	

bool Emptiness( int set ){
	return ( set == 0 );
}

bool Nonempty( int set ){
	return ( set != 0 );
}

bool Member( std::string input, int set ){
	if( itr < input.length() ){
		if( input.at( itr ) == '0' ||  input.at( itr ) == '1' ){
			int readSet = 1;
			
			if( input.at( itr ) == '1' )
				readSet <<= 16;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 8;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 4;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 2;
			itr = add( itr, 1 );
			
			if( input.at( itr ) == '1' )
				readSet <<= 1;
			
			itr = 0;
			return ( set & readSet );
		}
			
		itr = add( itr, 1 );
		return Member( input, set );
	}
	else{
		itr = 0;
		return 0;
	}
}

bool Disjoint( int set1, int set2 ){
	return  ( set1 & set2 ) == 0;
}

bool Conjunctive( int set1, int set2 ){
	return ( set1 & set2 ) != 0;
}

bool Equality( int set1, int set2 ){
	return ( set1 == set2 ); 
}

bool Inclusion( int set1, int set2 ){
	return ( ( set1 | set2 ) == set2 ); 
}

void Union( int set1, int set2, int* output ){
	*output = set1 | set2;
}

void Intersection( int set1, int set2, int* output ){
	*output = set1 & set2;
}

void Symmetric( int set1, int set2, int* output ){
	*output = set1 ^ set2;
}

void Difference( int set1, int set2, int* output ){
	*output = ( set1 & ( ~set2 ) );
}

void Complement( int set, int* output ){
	*output = ~set;
}

int count( int set, int i = 0 ){
	if( i < 32 ){
		if( set & ( 1 << i ) ) {
			return add( count( set, add( i, 1 ) ), 1 );
		}
		return count( set, add( i, 1 ));
	}
	
	return 0;	
}

bool LessThen( int set1, int set2 ){
	return ( count( set1 ) < count( set2 ) ) 
	    || ( count( set1 ) == count( set2 )  &&  (unsigned int)set1 < (unsigned int)set2 );
}

bool LessEqual( int set1, int set2 ){
	return ( count( set1 ) < count( set2 ) ) 
	    || ( count( set1 ) == count( set2 )  &&  (unsigned int)set1 <= (unsigned int)set2 );
}

bool GreatEqual( int set1, int set2 ){
	return ( count( set1 ) > count( set2 ) ) 
	    || ( count( set1 ) == count( set2 )  &&  (unsigned int)set1 >= (unsigned int)set2 );
}

bool GreatThen( int set1, int set2 ){
	return ( count( set1 ) > count( set2 ) ) 
	    || ( count( set1 ) == count( set2 )  &&  (unsigned int)set1 > (unsigned int)set2 );
}
