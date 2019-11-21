
void StringRevers( std::string& a ){
	std::string result;
	for( int i = a.size() - 1; i >= 0; i-- )
		result += a[ i ];
	a = result;	
}

void Shift( std::string& a, int n ){
	for( int i = 0; i < n; i++ )
		a+="0";
}

// ? a > b
bool isBigger( const std::string& a, const std::string& b){
	if( a.size() > b.size() )
		return true;
	if( a.size() < b.size() )
		return false;
		
	for( int i = 0; i < a.size(); i++ )
		if( a[ i ] > b[ i ] )
			return true;
		else if( a[ i ] < b[ i ] )
			return false;
	
	return false;
}

// a + b 
std::string Add( std::string a, std::string b ){
	std::string result = "";
	int sum = 0;
	int carry = 0;
	if( a.size() > b.size() )
		a.swap( b );
		
	StringRevers( a );
	StringRevers( b );
	int aSize = a.size();
	int bSize = b.size();
	
	for( int i = 0; i < aSize; i++ ){
		sum = ( a[ i ] - '0' ) + ( b[ i ] - '0' ) + carry;
		result += ( sum%10+'0');
		carry = sum/10;  
	}	
	
	for( int i = aSize; i < bSize; i++ ){
		sum = ( b[ i ] - '0' ) + carry;
		result += ( sum%10+'0');
		carry = sum/10;  
	}
	
	if( carry )
		result += ( carry+'0');
	StringRevers( result );
	return result;
}

// a - b && a >= b 
std::string Sub( std::string a, std::string b ){
	std::string result = "";
	int sum = 0;
	int carry = 0;
	
	StringRevers( a );
	StringRevers( b );
	int aSize = a.size();
	int bSize = b.size();
	
	for( int i = 0; i < bSize; i++ ){
		sum = ( a[ i ] - '0' ) - ( b[ i ] - '0' ) - carry;
		if( sum < 0 ){
			sum += 10;
			carry = 1;
		}  
		else
			carry = 0;
			
		result += ( sum+'0');
	}	
	
	for( int i = bSize; i < aSize; i++ ){
		sum = ( a[ i ] - '0' ) - carry;	
		if( sum < 0 ){
			sum += 10;
			carry = 1;
		}  
		else
			carry = 0;
		result += ( sum+'0');
	}
	
	
	StringRevers( result );
	
	int firstNotZero = result.find_first_not_of('0');
	if( firstNotZero >= result.size())
		result = "0";
	else
		result.erase(0, firstNotZero);
		
	return result;
}

std::string PartSum( std::string a, std::string b ){
	bool aNeg = false;
	bool bNeg = false;
	std::string result ="";
	
	if( a.size() > 0 && a[ 0 ] == '+' )
		a = a.substr( 1 );
	if( b.size() > 0 && b[ 0 ] == '+' )
		b = b.substr( 1 );

		
	if( a.size() > 0 && a[ 0 ] == '-' ){
		aNeg = true;
		a = a.substr( 1 );
	}
	if( b.size() > 0 && b[ 0 ] == '-' ){
		bNeg = true;
		b = b.substr( 1 );
	}
		
	if( !aNeg && !bNeg )
		result = Add( a, b );
	else if( aNeg && bNeg ){
		result = Add( a, b);
		result = "-" + result;		
	}
	else{
		if( aNeg ){  // -a + b 
			if( isBigger( a, b ) ){
				result = Sub( a, b );
				if( result != "0")
					result = "-" + result;
			}
			else
				result = Sub( b, a);
		}
		else{ // a - b
			if( isBigger( b, a )){
				result = Sub( b, a );
				if( result != "0" )
					result = "-" + result;
			}
			else
				result = Sub( a, b);
		}	
	}
	return result;
}

std::string PartMult( std::string a, std::string b ){
			
	bool aNeg = false;
	bool bNeg = false;
	std::string result;
	std::string temp;
	
	if( a.size() > 0 && a[ 0 ] == '+' )
		a = a.substr( 1 );
	if( b.size() > 0 && b[ 0 ] == '+' )
		b = b.substr( 1 );
		
	if( a.size() > 0 && a[ 0 ] == '-' ){
		aNeg = true;
		a = a.substr( 1 );
	}
	if( b.size() > 0 && b[ 0 ] == '-' ){
		bNeg = true;
		b = b.substr( 1 );
	}
	
	if( a == "0" || b == "0")
		return "0";
	
	for( int i = b.size() - 1; i >= 0; i-- ){
		temp = "0";
		for( int j = b[ i ] - '0'; j > 0; j-- )
			temp = Add(temp, a);

		Shift( temp, b.size() - 1 - i );	
		result = Add( result, temp);	
	}
	
	
	if( aNeg ^ bNeg )
		result = "-"+ result;
		
	return result;	
}


std::string Sum( int sets, const std::string* data ){
	std::string result = "0";
	for( int i = 0; i < sets; i++ )
		result = PartSum( result, data[ i ]);	
	return result;
}

std::string Sum( int sets, ...){
	std::string result = "0";
	std::string temp;
	va_list args;
	va_start( args, sets );
	while( sets-- > 0 ){
		temp = va_arg( args, char* );
		result = PartSum( result, temp );
	}
	
	va_end( args );
	return result;
}

void Sum( std::string* result, int sets, const std::string* data ){
	*result = Sum( sets, data );
}

void Sum( std::string* result, int sets, ... ){
	*result = "0";
	std::string temp;
	va_list args;
	va_start( args, sets );
	while( sets-- > 0 ){
		temp = va_arg( args, char* );
		*result = PartSum( *result, temp );
	}
	
	va_end( args );
}

void Sum( std::string& result, int sets, const std::string* data){
	Sum( &result, sets, data);
}

void Sum( std::string& result, int sets, ... ){
	result = "0";
	std::string temp;
	va_list args;
	va_start( args, sets );
	while( sets-- > 0 ){
		temp = va_arg( args, char* );
		result = PartSum( result, temp );
	}
	
	va_end( args );
}

std::string Mult( int sets, const std::string* data ){
	std::string result = "1";
	for( int i = 0; i < sets; i++ )
		result = PartMult( result, data[ i ]);
	return result;
}

std::string Mult( int sets, ...){
	std::string result = "1";
	std::string temp;
	va_list args;
	va_start( args, sets );
	while( sets-- > 0 ){
		temp = va_arg( args, char* );
		result = PartMult( result, temp );
	}
	
	va_end( args );
	return result;
}

void Mult( std::string* result, int sets, const std::string* data ){
	*result = Mult( sets, data );
}

void Mult( std::string* result, int sets, ... ){
	*result = "1";
	std::string temp;
	va_list args;
	va_start( args, sets );
	while( sets-- > 0 ){
		temp = va_arg( args, char* );
		*result = PartMult( *result, temp );
	}
	
	va_end( args );
}

void Mult( std::string& result, int sets, const std::string* data){
	Mult( &result, sets, data);
}

void Mult( std::string& result, int sets, ... ){
	result = "1";
	std::string temp;
	va_list args;
	va_start( args, sets );
	while( sets-- > 0 ){
		temp = va_arg( args, char* );
		result = PartMult( result, temp );
	}

	va_end( args );
}

std::string Operation( std::string (*funct)(int, const std::string*), int sets, const std::string* data ){
	return funct( sets, data );
}

std::string Operation( std::string (*funct)(int, const std::string*), int sets, ... ){
	std::string* data = new std::string[ sets ];
	va_list args;
	va_start( args, sets );
	for( int i = 0; i < sets; i++ )
		data[ i ] = va_arg( args, char* );
	va_end( args );
	
	std::string result = Operation( funct, sets, data );
	delete[] data;
	return result;
}

void Operation(std::string* result, std::string (*funct)(int, const std::string*), int sets, ... ){
	
	std::string* data = new std::string[ sets ];
	va_list args;
	va_start( args, sets );
	for( int i = 0; i < sets; i++ )
		data[ i ] = va_arg( args, char* );
	va_end( args );

	*result = Operation( funct, sets, data );
	delete[] data;
}

void Operation( std::string* result, std::string (*funct)(int, const std::string*), int sets, const std::string* data ){
	*result = funct( sets, data );
}

void Operation(std::string& result, std::string (*funct)(int, const std::string*), int sets, ... ){
	
	std::string* data = new std::string[ sets ];
	va_list args;
	va_start( args, sets );
	for( int i = 0; i < sets; i++ )
		data[ i ] = va_arg( args, char* );
	va_end( args );

	result = Operation( funct, sets, data );
	delete[] data;
}

void Operation( std::string& result, std::string (*funct)(int, const std::string*), int sets, const std::string* data ){
	result = funct( sets, data );
}



