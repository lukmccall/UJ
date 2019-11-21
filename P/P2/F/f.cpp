class Vector{
protected:
	int* array;
	unsigned int size;	
public:
	Vector( ){
		array = NULL;
		size = 0;
	}
	
	Vector( unsigned int s ){
		size = s;
		array = new int[ size ];
	}
	
	Vector( const Vector& vec ){
		size = vec.size;
		array = new int[ size ];
		
		for( int i = 0; i < size; i++ )
			array[ i ] = vec.array[ i ];
	}
	
	~Vector() {
		delete[] array;
		array = NULL;
	}
	
	Vector& operator=( const Vector& vec ){
		if( this == &vec )
			return (*this);
		
		delete[] array;
		size = vec.size;
		array = new int[ size ];
		for( int i = 0; i < size; i++ )
			array[ i ] = vec.array[ i ];
	}
	
	void Resize( int newSize ){
		if( newSize < 0 ) return;
		
		if( size == 0 && newSize > size )
			array = new int[ newSize ];
		else if( newSize == 0 ){
			delete[] array;
			array = NULL;
		}
		else{
			int* newArray = new int[ newSize ];
			if( newSize > size ){
				for( int i = 0; i < size; i++ )
					newArray[ i ] = array[ i ];
				for( int i = size; i < newSize; i++ )
					newArray[ i ] = 0;
			} else {
				for( int i = 0; i < newSize; i++ )
					newArray[ i ] = array[ i ];
			}
			delete[] array;
			array = newArray;
		}
		
		size = newSize;
	}
	
};

struct Fraction{
	int nominator;
	int denominator;
};


int Max( int a, int b ){
	return a > b ? a : b;
}

int NWD( int a, int b ){
	if( a == 0 )
		return b;
	if( b == 0 )
		return a;
		
	int c;
  	while (b != 0) {
    	c = a % b;
    	a = b;
    	b = c;
  	}
 	return a ;
}

int NWW( int a, int b ){
	if( a < 0 ) a = -a;
	if( b < 0 ) b = -b;
	
	return (a*b)/NWD( a, b );
}
class POLYNOMIAL : public Vector{
private:
		void Normalization( int nwd ){
		if( nwd == 0 ) nwd = 1;
		if( nwd < 0 ) nwd = -nwd;
		
		bool findNotZero = false;
		for( int i = size - 1; i >= 0; i-- ){
			if( !findNotZero ){
				if( array[ i ] != 0 ){
					if( i == 0 )
						array[ i ] = array[ i ] > 0 ? 1 :-1;
					else
						array[ i ] /= nwd;
					
					findNotZero = true;
				}
				else
					Resize( i );
			}
			else
				array[ i ] /= nwd;
		}	
	}

public:
	static int overloaded;
	
	POLYNOMIAL() : Vector() {}
	
	POLYNOMIAL( long long n, ...) : Vector(){
		if( n >= 0 ){
			va_list l;
			va_start(l , n);
			
			size = n + 1;
			array = new int[ size ];
			int nwd = 0;
			int tmp;
			
			for( int i = 0; i <= n; i++ ){
				tmp = va_arg( l, int );
				nwd = NWD( nwd, tmp );
				array[ i ] = tmp;
			} 
			Normalization( nwd );
			va_end( l );
		}
	}
	
	POLYNOMIAL( const POLYNOMIAL& poly ) : Vector( poly ){}
	
	POLYNOMIAL operator-(){
		POLYNOMIAL result( *this );
		for( int i = 0; i < result.size; i++ )
			result.array[ i ] *= -1;
		return result;
	}
	
	POLYNOMIAL operator+( const POLYNOMIAL& poly ){
		int newSize = Max( size, poly.size );
	
		POLYNOMIAL result;
		result.Resize( newSize );
		
		int tmp =0;
		int nwd = 0;
		
		for( int i = 0; i < newSize; i++ ){
			tmp = 0;
			
			if( i < size )
				tmp += array[ i ];	
			if( i < poly.size )
				tmp += poly.array[ i ];
			
			nwd = NWD( nwd, tmp );
			result.array[ i ] = tmp;
		}
		
		result.Normalization( nwd );
		return result;
		
	}
	
	POLYNOMIAL operator-( const POLYNOMIAL& poly ){
		int newSize = Max( size, poly.size );
	
		POLYNOMIAL result;
		result.Resize( newSize );
		
		int tmp =0;
		int nwd = 0;
		
		for( int i = 0; i < newSize; i++ ){
			tmp = 0;
			
			if( i < size )
				tmp += array[ i ];	
			if( i < poly.size )
				tmp -= poly.array[ i ];
			
			nwd = NWD( nwd, tmp );
			result.array[ i ] = tmp;
		}
		
		result.Normalization( nwd );
		return result;
		
	}
	
	POLYNOMIAL operator*( const POLYNOMIAL& poly ){
		int newSize = size + poly.size - 1;
		int nwd = 0;
		
		POLYNOMIAL result;
		result.Resize( newSize );
		
		for( int i = 0; i < newSize; i++ )
			result.array[ i ] = 0;
			
		for( int i = 0; i < size; i++)
			for( int j = 0; j < poly.size; j++ )
				result.array[ i + j ] += array[ i ] * poly.array[ j ];
			
		for( int i = 0; i < newSize; i++)
			nwd = NWD( nwd, result.array[ i ] );
		result.Normalization( nwd );	
		return result;
	}
	
	POLYNOMIAL operator>>( long long n ){
		if( n == 0 || size == 0 )
			return (*this);
		
		if( n > 0 ){
			POLYNOMIAL result;
			int newSize = size + n;
			result.Resize( newSize );		
			
			for( int i = 0; i < n; i++ )
				result.array[ i ] = 0;
			
			for( int i = 0; i < size; i++ )
				result.array[ n + i] = array[ i ];	
			
			return result;
		}
		POLYNOMIAL result;
		return result;
	}
	
	POLYNOMIAL operator<<( long long n ){
		if( n == 0 )
			return (*this);
			
		if( n > 0 ){
			if( n >= size ){
				POLYNOMIAL result;
				return result;
			}
			int nwd = 0;
			int newSize = size - n;
			
			POLYNOMIAL result;
			result.size = newSize;
			result.array = new int[ newSize ];
			
			for( int i = 0; i < newSize; i++ ){
			 	result.array[ newSize - i - 1 ] = array[ size - i - 1 ];
				nwd = NWD( nwd, array[ size - i - 1 ] );
			 } 
			result.Normalization( nwd );
			return result;
		}
		POLYNOMIAL result;
		return result;
	}
	
	POLYNOMIAL& operator++(){
		if( size == 0 ){
			POLYNOMIAL ret( 0, 1);
			(*this) = ret;
		} else {
			int nwd = 0;
			for( int i = 0; i < size; i++ ){
				array[ i ]++;
				nwd = NWD( nwd, array[ i ] );
			}
			Normalization( nwd );
		}
		return (*this);
	}
	
	POLYNOMIAL operator++( int ){
		POLYNOMIAL result( *this );
		
		if( size == 0 ){
			Resize( 1 );
			array[ 0 ] = 1;
			return result;
		}
		
		int nwd = 0;
		for( int i = 0; i < size; i++ ){
			array[ i ]++;
			nwd = NWD( nwd, array[ i ] );
		}
		Normalization( nwd );
		return result;
	}
	
	POLYNOMIAL& operator--(){
		if( size == 0 ){
			POLYNOMIAL ret( 0, -1);
			(*this) = ret;
		} else {
			int nwd = 0;
			for( int i = 0; i < size; i++ ){
				array[ i ]--;
				nwd = NWD( nwd, array[ i ] );
			
			}
			Normalization( nwd );
		}
		return (*this);
	}
	
	POLYNOMIAL operator--( int ){
		POLYNOMIAL result( *this );
		
		if( size == 0 ){
			Resize( 1 );
			array[ 0 ] = -1;
			return result;
		}
		
		int nwd = 0;
		for( int i = 0; i < size; i++ ){
			array[ i ]--;
			nwd = NWD( nwd, array[ i ] );
		}
		Normalization( nwd );
		return result;
	}
	
	POLYNOMIAL operator/( const POLYNOMIAL& poly ){
		POLYNOMIAL result;
			
		if( size >= poly.size && poly.size > 0 && size > 0 ){
		
			int resultSize = size - poly.size + 1;
			Fraction resultArray[ resultSize ];
			
			Fraction p1[ size ];
			Fraction tmp[ size ];
			
			for( int i = 0; i < size; i++ ){
				p1[ i ].nominator = array[ i ];
				p1[ i ].denominator = 1;	
			}
			
			int degP1 = size - 1;
			int degP2 = poly.size - 1;
			int nwd = 0;
			int nww = 0;
			
			while( degP1 >= degP2 ){
				
				for( int i = 0; i < size; i++ ){
					tmp[ i ].nominator = 0;
					tmp[ i ].denominator = 1;
				}
				
				for( int i = 0; i < poly.size; i++ ){
					tmp[ i + degP1 - degP2 ].nominator = poly.array[ i ];
					tmp[ i + degP1 - degP2 ].denominator = 1;
				}
					
		 		resultArray[ degP1 - degP2 ].nominator = p1[ degP1 ].nominator * tmp[ degP1 ].denominator;
		 		resultArray[ degP1 - degP2 ].denominator = p1[ degP1 ].denominator * tmp[ degP1 ].nominator;
				
				nwd = NWD( resultArray[ degP1 - degP2 ].nominator, resultArray[ degP1 - degP2 ].denominator );
				nwd = nwd >= 0 ? nwd : -nwd;
			
				resultArray[ degP1 - degP2 ].nominator /= nwd;
 		 		resultArray[ degP1 - degP2 ].denominator /= nwd;
		 		
				
				for( int i = 0; i < size; i++ ){	
					tmp[ i ].nominator *= resultArray[ degP1 - degP2 ].nominator;
					tmp[ i ].denominator *= resultArray[ degP1 - degP2 ].denominator;
					
					nwd = NWD( tmp[ i ].nominator, tmp[ i ].denominator );
					nwd = nwd >= 0 ? nwd : -nwd;
					tmp[ i ].nominator /= nwd;
					tmp[ i ].denominator /= nwd;
				}
				
				for( int i = 0 ; i < degP1 + 1 ; i++ ){
					nww = NWW( p1[ i ].denominator, tmp[ i ].denominator );
					nww = nww >= 0 ? nww : -nww;
					
					p1[ i ].nominator = ( ( nww/p1[ i ].denominator ) * p1[ i ].nominator ) - ( ( nww/tmp[ i ].denominator ) * tmp[ i ].nominator );
					p1[ i ].denominator = nww;
					
					nwd = NWD( p1[ i ].nominator, p1[ i ].denominator );
					nwd = nwd >= 0 ? nwd : -nwd;
					
					p1[ i ].nominator /= nwd;
					p1[ i ].denominator /= nwd;
					
				}
				degP1--;
			}
			
			nww = 1;
			nwd = 0;
			for( int i = 0; i < resultSize; i++ ){
				nww = NWW( nww, resultArray[ i ].denominator );
			}
			nww = nww >= 0 ? nww : -nww;
			
			result.Resize( resultSize );
			for( int i = 0; i < resultSize; i++ ){
				result.array[ i ] = (nww/resultArray[i].denominator)* resultArray[ i ].nominator;
				nwd = NWD( nwd, result.array[ i ] );
			}
		
			result.Normalization( nwd );
		}
		
		return result;	
	}
	
	POLYNOMIAL operator%( const POLYNOMIAL& poly ){
		POLYNOMIAL result;
		
		if( size >= poly.size && poly.size > 0 && size > 0 ){
		
			int resultSize = size - poly.size + 1;
			Fraction resultArray[ resultSize ];
			
			Fraction p1[ size ];
			Fraction tmp[ size ];
			
			for( int i = 0; i < size; i++ ){
				p1[ i ].nominator = array[ i ];
				p1[ i ].denominator = 1;	
			}
			
			int degP1 = size - 1;
			int degP2 = poly.size - 1;
			int nwd = 0;
			int nww = 0;
			
			while( degP1 >= degP2 ){
				
				for( int i = 0; i < size; i++ ){
					tmp[ i ].nominator = 0;
					tmp[ i ].denominator = 1;
				}
				
				for( int i = 0; i < poly.size; i++ ){
					tmp[ i + degP1 - degP2 ].nominator = poly.array[ i ];
					tmp[ i + degP1 - degP2 ].denominator = 1;
				}
					
		 		resultArray[ degP1 - degP2 ].nominator = p1[ degP1 ].nominator * tmp[ degP1 ].denominator;
		 		resultArray[ degP1 - degP2 ].denominator = p1[ degP1 ].denominator * tmp[ degP1 ].nominator;
				
				nwd = NWD( resultArray[ degP1 - degP2 ].nominator, resultArray[ degP1 - degP2 ].denominator );
				nwd = nwd >= 0 ? nwd : -nwd;
			
				resultArray[ degP1 - degP2 ].nominator /= nwd;
 		 		resultArray[ degP1 - degP2 ].denominator /= nwd;
		 		
				
				for( int i = 0; i < size; i++ ){	
					tmp[ i ].nominator *= resultArray[ degP1 - degP2 ].nominator;
					tmp[ i ].denominator *= resultArray[ degP1 - degP2 ].denominator;
					
					nwd = NWD( tmp[ i ].nominator, tmp[ i ].denominator );
					nwd = nwd >= 0 ? nwd : -nwd;
					tmp[ i ].nominator /= nwd;
					tmp[ i ].denominator /= nwd;
				}
				
				for( int i = 0 ; i < degP1 + 1 ; i++ ){
					nww = NWW( p1[ i ].denominator, tmp[ i ].denominator );
					nww = nww >= 0 ? nww : -nww;
					
					p1[ i ].nominator = ( ( nww/p1[ i ].denominator ) * p1[ i ].nominator ) - ( ( nww/tmp[ i ].denominator ) * tmp[ i ].nominator );
					p1[ i ].denominator = nww;
					
					nwd = NWD( p1[ i ].nominator, p1[ i ].denominator );
					nwd = nwd >= 0 ? nwd : -nwd;
					
					p1[ i ].nominator /= nwd;
					p1[ i ].denominator /= nwd;
					
				}
				degP1--;
			}
			
			
			nww = 1;
			nwd = 0;
			for( int i = 0; i < degP1 + 1; i++ )
				nww = NWW( nww, p1[ i ].denominator );
		
			nww = nww >= 0 ? nww : -nww;
	
			result.Resize( degP1 + 1 );
			for( int i = 0; i < degP1 + 1; i++ ){
				result.array[ i ] = (nww/p1[i].denominator)* p1[ i ].nominator;;
				nwd = NWD( nwd, result.array[ i ] );
			}
			result.Normalization( nwd );
			return result;
			
		}
		
//		if( poly.size > 0 && size > 0  )
//			return result;
		
		result = (*this);		
		return result;	
	}
	
	POLYNOMIAL& operator+=( const POLYNOMIAL& poly ){
		(*this) = ( *this ) + poly;
		return (*this); 
	}
	
	POLYNOMIAL& operator-=( const POLYNOMIAL& poly ){
		(*this) = ( *this ) - poly;
		return (*this); 
	}
	
	POLYNOMIAL& operator*=( const POLYNOMIAL& poly ){
		(*this) = ( *this ) * poly;
		return (*this); 
	}
	
	POLYNOMIAL& operator/=( const POLYNOMIAL& poly ){
		(*this) = ( *this ) / poly;
		return (*this); 
	}
	
	POLYNOMIAL& operator%=( const POLYNOMIAL& poly ){
		(*this) = ( *this ) % poly;
		return (*this); 
	}
	
	POLYNOMIAL& operator<<=( long long n ){
		(*this) = ( *this ) << n;
		return (*this); 
	}
	
	POLYNOMIAL& operator>>=( long long n ){
		(*this) = ( *this ) >> n;
		return (*this); 
	}
	
	void* operator new( size_t amount ){
		POLYNOMIAL::overloaded++;
		return ::new char[ amount ];
	}
	
	void operator delete( void* pointer ){
		POLYNOMIAL::overloaded--;
		::delete pointer;
	}
	
	friend ostream& operator<<( ostream& stream, const POLYNOMIAL& poly );
	friend istream& operator>>( istream& stream, POLYNOMIAL& poly );
	
	friend bool operator<( const POLYNOMIAL& p1, const POLYNOMIAL& p2 );
	friend bool operator<=( const POLYNOMIAL& p1, const POLYNOMIAL& p2 );
	friend bool operator==( const POLYNOMIAL& p1, const POLYNOMIAL& p2 );
	friend bool operator>=( const POLYNOMIAL& p1, const POLYNOMIAL& p2 );
	friend bool operator>( const POLYNOMIAL& p1, const POLYNOMIAL& p2 );
	friend bool operator!=( const POLYNOMIAL& p1, const POLYNOMIAL& p2 );
	
};

ostream& operator<<( ostream& stream, const POLYNOMIAL& poly ){
	cout << "(";
	if( poly.size == 0 )
		cout << " 0";
	else
	for( int i = 0; i < poly.size; i++ ){
		cout << " " << poly.array[ i ];
		if( i != poly.size - 1 )
			cout << ",";
	}
	cout << " )";
	return stream;
}

istream& operator>>( istream& stream, POLYNOMIAL& poly ){
	long long n;
	cin >> n;

	if( n >= 0 ){
		int nwd = 0;
		poly.Resize( n + 1 );
		for( int i = 0; i <= n; i++ ){
			cin >> poly.array[ i ];
			nwd = NWD( nwd, poly.array[ i ] );
		}
		poly.Normalization( nwd );
	}
	
	return stream;
}

bool operator==( const POLYNOMIAL& p1, const POLYNOMIAL& p2 ){
	if( p1.size == p2.size ){
		for( int i = 0; i < p1.size; i++ )
			if( p1.array[ i ] != p2.array[ i ] )
				return false;
		return true;
	}
	return false;
}

bool operator!=( const POLYNOMIAL& p1, const POLYNOMIAL& p2 ){
	return !( p1 == p2 );
}

bool operator<( const POLYNOMIAL& p1, const POLYNOMIAL& p2 ){
	if( (p1.size == 0 && p2.size == 1) || (p1.size == 1 && p2.size == 0)){
		if( p1.size == 0 ){
			return p2.array[ 0 ] > 0;
		} else {
			return p1.array[ 0 ] < 0;
		}
	}
	if( p1.size < p2.size )
		return true;
	if( p1.size == p2.size ){
		for( int i = p1.size - 1; i >= 0; i-- ){
			if( p1.array[ i ] < p2.array[ i ] )
				return true;
			else if( p1.array[ i ] > p2.array[ i ])
				return false; 
		}
	}
	
	return false;
}


bool operator<=( const POLYNOMIAL& p1, const POLYNOMIAL& p2 ){
	return ( p1 == p2 ) || ( p1 < p2 ); 
}

bool operator>( const POLYNOMIAL& p1, const POLYNOMIAL& p2 ){
	return ( p1 != p2 ) && !( p1 < p2 );
}

bool operator>=( const POLYNOMIAL& p1, const POLYNOMIAL& p2 ){
	return ( p1 == p2 ) || ( p1 > p2 );
}

