#include <iostream>
#include <string>

using namespace std;

template< typename ValueType >
class Vector{
private:
	unsigned size;
	ValueType* array;
public:
	Vector() : array( nullptr ), size( 0 ){}
	~Vector(){
		delete[] array;
	}
	
	void PushBack( ValueType x ){
		ValueType* newArray = new ValueType[ size + 1 ];
		for( int i = 0; i < size; i++)
			newArray[ i ] = array[ i ];
		newArray[ size++ ] = x;
		delete[] array;
		array = newArray;
	}
	
	ValueType Peek(){
		if( size > 0 )
			return array[ size - 1 ]; 
		return ValueType();
	}
	
	void PopBack(){
		if( size > 1 ){
			ValueType* newArray = new ValueType[ --size ];
			for( int i = 0; i < size; i++)
				newArray[ i ] = array[ i ];
			delete[] array;
			array = newArray;
		} else if( size == 1 ){
			size = 0;
			delete[] array;
			array = nullptr;
		}
	}
	
	class iterator{
	private:
		ValueType* ptr;
	public:
		iterator() :ptr( nullptr ){};
		iterator( ValueType* ptr) : ptr( ptr ){};
		
		ValueType *operator->(){
			return ptr;
		} 
		
		ValueType& operator*(){
			return *ptr;
		}
		
		iterator operator++(int){
			iterator tmp = (*this);
			ptr++;
			return tmp;
		}
		
		iterator operator++(){
			return ++ptr;
		}
		
		bool operator==( const iterator& rV ){
			return ptr == rV.ptr;
		} 
		
		bool operator!=( const iterator& rV ){
			return ptr != rV.ptr;
		}
		
		
		
	};
	
	iterator begin(){
		return iterator(array);
	}
	iterator end(){
		return iterator( array + size );
	}
};


int main(){
	Vector<string> v;
	v.PushBack( "11111" );
	v.PushBack( "222222" );
	v.PushBack( "333" );
	v.PushBack( "44444444" );
	v.PushBack( "55555555555" );
	v.PushBack( "6" );
	v.PushBack( "7" );
	
	cout << v.Peek() << endl;
	
	v.PopBack();
	
	Vector<string>::iterator beg = v.begin();
	Vector<string>::iterator end = v.end();
	
	for( auto& x : v ){
		cout << x << " ";
	}
	cout << endl;
	while( beg != end ){
		cout << "< "<< *beg << " " << beg->size() << " >"<< " ";
		beg++;
	}

	return 0;
}
