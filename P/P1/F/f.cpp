//£ukasz Kosmaty
#include <iostream>

using namespace std;

unsigned long long all = 0;

struct PLACE{
	unsigned short int amount;
	char label[ 2 ];
	
	void Clear(){
		all -= amount;
		amount = 0;
		label[ 0 ] = 0;
		label[ 1 ] = 0;
		};
	};

struct SHELF{
	PLACE places[ 128 ];
	unsigned short placeNumber;	
	
	void Clear( unsigned short a, unsigned short b ){
//		cout << "ClearSHELF " << a << " " << b-1 << endl;
		for( int i = a; i < b; i++ )
			places[ i ].Clear();
		};	
	};

struct RACK{
	SHELF shelfs[ 128 ];
	unsigned short shelfNumber;
	
	void Clear( unsigned short a, unsigned short b ){
//		cout << "ClearRACK " << a << " " << b-1 << endl;
		for( int i = a; i < b; i++ )
			shelfs[ i ].Clear(0, 128);
		};
	};

struct WAREHOUSE{
	RACK racks[ 128 ];
	unsigned short rackNumber;
	SHELF handyShelf;
	
	void Clear( unsigned short a, unsigned short b ){
//		cout << "ClearWAREHOUSE " << a << " " << b-1 << endl;
		for( int i = a; i < b; i++ )
			racks[ i ].Clear(0, 128);
		};

	};

struct STOREHOUSE{
	WAREHOUSE warehouses[ 128 ];
	unsigned short warehouseNumber;
	RACK handyRack;
	SHELF handyShelf;
	
	void Clear( unsigned short a, unsigned short b ){
//		cout << "ClearSTOREHOUSE " << a << " " << b-1 << endl;
		for( int i = a; i < b; i++ )
			warehouses[ i ].Clear(0, 128);
	};
	
	void SET_AP( unsigned short wb, unsigned short rb, 
				unsigned short sb, unsigned short Pe){
		if( wb >= warehouseNumber || rb >= warehouses[ wb ].rackNumber
		|| sb >= warehouses[ wb ].racks[ rb ].shelfNumber ){
			cout << "error" << endl;
			}
		else{
			int old = warehouses[ wb ].racks[ rb ].shelfs[ sb ].placeNumber;
			warehouses[ wb ].racks[ rb ].shelfs[ sb ].Clear( Pe, old); 
			warehouses[ wb ].racks[ rb ].shelfs[ sb ].placeNumber = Pe;	
			}
		};
	
	void SET_AS( unsigned short wb, unsigned short rb, 
				unsigned short Se, unsigned short Pe){
		if( wb >= warehouseNumber || rb >= warehouses[ wb ].rackNumber ){
			cout << "error" << endl;
			}
		else{
			int old = warehouses[ wb ].racks[ rb ].shelfNumber;
			warehouses[ wb ].racks[ rb ].Clear(Se, old );
			warehouses[ wb ].racks[ rb ].shelfNumber = Se;
			
			for( int i = 0; i < Se; i++ )
				SET_AP( wb, rb, i, Pe);			
			}
		};
		
	void SET_AR ( unsigned short wb, unsigned short Re, 
				unsigned short Se, unsigned short Pe){
		if( wb >= warehouseNumber ){
			cout << "error" << endl;
			}
		else{

			int old = warehouses[ wb ].rackNumber;
			warehouses[ wb ].Clear(Re, old);
			warehouses[ wb ].rackNumber = Re;
			
			for( int i = 0; i < Re; i++ )
				SET_AS( wb, i, Se, Pe);			
			}
		};
	
	void SET_AW( unsigned short We, unsigned short Re, 
				unsigned short Se, unsigned short Pe ){
		int old = warehouseNumber;
		Clear(We, old);
		warehouseNumber = We;
		
		for( int i = 0; i < We; i++ )
			SET_AR( i, Re, Se, Pe );
		};
	
	void SET_HW( unsigned short w, unsigned short P ){
		if( w >= warehouseNumber )
			cout << "error" << endl;
		else{
			int old = warehouses[ w ].handyShelf.placeNumber;
			warehouses[ w ].handyShelf.Clear( P, old );
			warehouses[ w ].handyShelf.placeNumber = P;
			}
		};
	
	void SET_HR( unsigned short S, unsigned short P){
		int old = handyRack.shelfNumber;
		handyRack.Clear( S, old );
		handyRack.shelfNumber = S;
		
		for( int i = 0; i < S; i++ ){
			old = handyRack.shelfs[ i ].placeNumber;
			handyRack.shelfs[ i ].Clear( P, old );
			handyRack.shelfs[ i ].placeNumber = P;
			}
		};	
	
	void SET_HS( unsigned short P ){
		int old = handyShelf.placeNumber;
		handyShelf.Clear(P, old);
		handyShelf.placeNumber = P; 
		};	
	
	void PUT_W( unsigned short w, unsigned short r,
				unsigned short s, unsigned short p,
				long long A ){
		if( w >= warehouseNumber || r >= warehouses[ w ].rackNumber
		|| s >= warehouses[ w ].racks[ r ].shelfNumber 
		|| p >=  warehouses[ w ].racks[ r ].shelfs[ s ].placeNumber )
			cout << "error" << endl;
		else{
			long long n = warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].amount + A;
			if( n > 65535 ){
				n = 65535;
				all += 65535 - warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].amount;
				}
			else
				all += A;
			warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].amount = n;	
			}
						
		};
	
	void PUT_H( unsigned short w, unsigned short p,
				long long A ){
		if( w >= warehouseNumber || p >= warehouses[ w ].handyShelf.placeNumber )
			cout << "error" << endl;
		else{
			long long n = warehouses[ w ].handyShelf.places[p].amount + A;
			if( n > 65535 ){
				n = 65535;
				all += 65535 -  warehouses[ w ].handyShelf.places[p].amount;
				}
			else
				all += A;
			warehouses[ w ].handyShelf.places[p].amount = n;
			}					
		};
	
	void PUT_R( unsigned short s, unsigned short p,
				long long A ){
		if( s >= handyRack.shelfNumber || p >= handyRack.shelfs[ s ].placeNumber )
			cout << "error" << endl;
		else{
			long long n = handyRack.shelfs[ s ].places[ p ].amount + A;
			if( n > 65535 ){
				n = 65535;
				all += 65535 - handyRack.shelfs[ s ].places[ p ].amount;
				}
			else
				all += A;
			handyRack.shelfs[ s ].places[ p ].amount = n;
			}			
		};	
	
	void PUT_S( unsigned short p, long long A ){
		if( p >= handyShelf.placeNumber )
			cout << "error" << endl;
		else{
			long long n = handyShelf.places[ p ].amount + A;
			if( n > 65535 ){
				n = 65535;
				all += 65535 - handyShelf.places[ p ].amount;
				}
			else
				all += A;
			handyShelf.places[ p ].amount = n;	
			}	
		};	
		
	void FILL( unsigned short W, unsigned short R, unsigned short S,
			   unsigned short P, long long A ){
		Clear( 0, warehouseNumber ); 
		handyShelf.Clear( 0, 128 );
		handyRack.Clear( 0, 128 ); 
		
		SET_AW( W, R, S, P );
		SET_HR( S, P );
		SET_HS( P );
		for( int i = 0; i < W; i++ )
			for( int j = 0; j < R; j++ )
				for( int m = 0; m < S; m++ )
					for( int n = 0; n < P; n++ )
						PUT_W( i, j, m , n, A );
						
		for( int i = 0; i < W; i++){
			warehouses[ i ].handyShelf.Clear( 0, 128 );
			SET_HW( i, P);	
			for( int n = 0; n < P; n++ )
				PUT_H( i, n, A );
			}
					
		for( int m =0; m < S; m++ )
			for( int n = 0; n < P; n++)	
				PUT_R( m, n, A );
			
		for( int n = 0; n < P; n++ )
			PUT_S( n, A);	
		};
		
	void POP_W( unsigned short w, unsigned short r,
				unsigned short s, unsigned short p,
				long long A ){
		if( w >= warehouseNumber || r >= warehouses[ w ].rackNumber
		|| s >= warehouses[ w ].racks[ r ].shelfNumber 
		|| p >=  warehouses[ w ].racks[ r ].shelfs[ s ].placeNumber )
			cout << "error" << endl;
		else{
			long long n = warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].amount - A;
			if( n <= 0 ){
				n = 0;
				all -= warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].amount;
				}
			else
				all -= A;
			warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].amount = n;	
			}
						
		};
	
	void POP_H( unsigned short w, unsigned short p,
				long long A ){
		if( w >= warehouseNumber || p >= warehouses[ w ].handyShelf.placeNumber )
			cout << "error" << endl;
		else{
			long long n = warehouses[ w ].handyShelf.places[p].amount - A;
			if( n <= 0 ){
				n = 0;
				all -= warehouses[ w ].handyShelf.places[p].amount;
				}
			else
				all -= A;
			warehouses[ w ].handyShelf.places[p].amount = n;
			}					
		};
	
	void POP_R( unsigned short s, unsigned short p,
				long long A ){
		if( s >= handyRack.shelfNumber || p >= handyRack.shelfs[ s ].placeNumber )
			cout << "error" << endl;
		else{
			long long n = handyRack.shelfs[ s ].places[ p ].amount - A;
			if( n <= 0 ){
				n = 0;
				all -= handyRack.shelfs[ s ].places[ p ].amount;
				}
			else
				all -= A;
			handyRack.shelfs[ s ].places[ p ].amount = n;
			}			
		};	
	
	void POP_S( unsigned short p, long long A ){
		if( p >= handyShelf.placeNumber )
			cout << "error" << endl;
		else{
			long long n = handyShelf.places[ p ].amount - A;
			if( n <= 0 ){
				n = 0;
				all -= handyShelf.places[ p ].amount;
				}
			else
				all -= A;
			handyShelf.places[ p ].amount = n;	
			}	
		};	
	
	void MOV_W( unsigned short wb, unsigned short rb, unsigned short sb,
				unsigned short we, unsigned short re, unsigned short se,
				unsigned short p, long long A ){
			if( wb >= warehouseNumber || rb >= warehouses[ wb ].rackNumber
		|| sb >= warehouses[ wb ].racks[ rb ].shelfNumber 
		|| p >=  warehouses[ wb ].racks[ rb ].shelfs[ sb ].placeNumber
	         || we >= warehouseNumber || re >= warehouses[ we ].rackNumber
		|| se >= warehouses[ we ].racks[ re ].shelfNumber 
		|| p >=  warehouses[ we ].racks[ re ].shelfs[ se ].placeNumber )
			cout << "error" << endl;
			else{
				if( wb != we || rb != re || sb != se ){
					
					long long TempWb = warehouses[ wb ].racks[ rb ].shelfs[ sb ].places[ p ].amount;
					long long TempWe = warehouses[ we ].racks[ re ].shelfs[ se ].places[ p ].amount;
					long long TempA = A;
			
					if( TempWb - A < 0 )
						TempA = warehouses[ wb ].racks[ rb ].shelfs[ sb ].places[ p ].amount;
					else
						TempA = A;
						
					if( TempWe + TempA > 65535 )
						TempA = 65535 - warehouses[ we ].racks[ re ].shelfs[ se ].places[ p ].amount;
		
					warehouses[ wb ].racks[ rb ].shelfs[ sb ].places[ p ].amount = TempWb - TempA;
					warehouses[ we ].racks[ re ].shelfs[ se ].places[ p ].amount = TempWe + TempA;
					}
			}
		};
		
	void MOV_H( unsigned short w, unsigned short r, unsigned short s,
				unsigned short p, long long A ){
		if( w >= warehouseNumber || r >= warehouses[ w ].rackNumber
		|| s >= warehouses[ w ].racks[ r ].shelfNumber 
		|| p >=  warehouses[ w ].racks[ r ].shelfs[ s ].placeNumber)
			cout << "error" << endl;
		else{
				long long TempWb = warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].amount;
				long long TempH = warehouses[ w ].handyShelf.places[ p ].amount;
				long long TempA = A;
		
				if( TempWb - A < 0 )
					TempA = warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].amount;
				else
					TempA = A;
					
				if( TempH + TempA > 65535 )
					TempA = 65535 -  warehouses[ w ].handyShelf.places[ p ].amount;
				
				
				warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].amount = TempWb - TempA;
				warehouses[ w ].handyShelf.places[ p ].amount = TempH + TempA;
				}	
		};
	
	void MOV_R( unsigned short w, unsigned short r, unsigned short sb,
				unsigned short se, unsigned short p, long long A ){
		if( w >= warehouseNumber || r >= warehouses[ w ].rackNumber
		|| sb >= warehouses[ w ].racks[ r ].shelfNumber 
		|| p >=  warehouses[ w ].racks[ r ].shelfs[ sb ].placeNumber
		|| se >= handyRack.shelfNumber 
		|| p >= handyRack.shelfs[ se ].placeNumber)
			cout << "error" << endl;
		else{
			long long TempWb = warehouses[ w ].racks[ r ].shelfs[ sb ].places[ p ].amount;
			long long TempR = handyRack.shelfs[ se ].places[ p ].amount ;
			long long TempA = A;
		
			if( TempWb - A < 0 )
				TempA = warehouses[ w ].racks[ r ].shelfs[ sb ].places[ p ].amount;
			else
				TempA = A;
					
			if( TempR + TempA > 65535 )
				TempA = 65535 -  handyRack.shelfs[ se ].places[ p ].amount;
				
				
			warehouses[ w ].racks[ r ].shelfs[ sb ].places[ p ].amount = TempWb - TempA;
			handyRack.shelfs[ se ].places[ p ].amount = TempR + TempA;
			}
		};
	
	void MOV_S( unsigned short s, unsigned short p, long long A ){
		if( s >= handyRack.shelfNumber || p >= handyRack.shelfs[ s ].placeNumber 
		|| p >= handyShelf.placeNumber)
			cout << "error" << endl;
		else{
			long long TempR = handyRack.shelfs[ s ].places[ p ].amount ;
			long long TempS = handyShelf.places[ p ].amount;
			long long TempA = A;
		
			if( TempR - A < 0 )
				TempA = handyRack.shelfs[ s ].places[ p ].amount ;
			else
				TempA = A;
					
			if( TempS + TempA > 65535 )
				TempA = 65535 - handyShelf.places[ p ].amount;
				
				
			handyRack.shelfs[ s ].places[ p ].amount = TempR - TempA;
			handyShelf.places[ p ].amount = TempS + TempA;
			}
		};
		
	void GET_E(){
		cout << all << endl;
		};
	
	void GET_W( unsigned short w){
		unsigned long long r = 0;
		if( w >= warehouseNumber )
			cout << "error" << endl;
		else{
			for( int j = 0; j < warehouses[ w ].rackNumber; j++ )
				for( int k = 0; k < warehouses[ w ].racks[ j ].shelfNumber; k++ )
					for( int m = 0; m < warehouses[ w ].racks[ j ].shelfs[ k ].placeNumber; m++ )
						r += warehouses[ w ].racks[ j ].shelfs[ k ].places[ m ].amount;
			
			for( int j = 0; j < warehouses[ w ].handyShelf.placeNumber; j++ )
				r += warehouses[ w ].handyShelf.places[ j ].amount;
			
			cout << r << endl;
			}
		};
		
	void GET_RW( unsigned short w, unsigned short r){
		unsigned long long res = 0;
		if( w >= warehouseNumber || r >= warehouses[ w ].rackNumber)
			cout << "error" << endl;
		else{
			for( int k = 0; k < warehouses[ w ].racks[ r ].shelfNumber; k++ )
				for( int m = 0; m < warehouses[ w ].racks[ r ].shelfs[ k ].placeNumber; m++ )
					res += warehouses[ w ].racks[ r ].shelfs[ k ].places[ m ].amount;
			
			cout << res << endl;
			}
		};
		
	void GET_RH(){
		unsigned long long res = 0;
	
		for( int i = 0; i < handyRack.shelfNumber; i++ )
			for( int j = 0; j < handyRack.shelfs[ i ].placeNumber; j++ )
				res += handyRack.shelfs[ i ].places[ j ].amount;	
		cout << res << endl;
		};
	
	void GET_SW( unsigned short w, unsigned short r, unsigned short s){
		unsigned long long res = 0;
		
		if( w >= warehouseNumber || r >= warehouses[ w ].rackNumber
		|| s >= warehouses[ w ].racks[ r ].shelfNumber)
			cout << "error" << endl;
		else{
			for( int i = 0; i < warehouses[ w ].racks[ r ].shelfs[ s ].placeNumber; i++ )
				res += warehouses[ w ].racks[ r ].shelfs[ s ].places[ i ].amount;
			cout << res << endl;
			}
		};
	
	void GET_SH( unsigned short w ){
		unsigned long long res = 0;
		if( w >= warehouseNumber )
			cout << "error" << endl;
		else{
			for( int i = 0; i < warehouses[ w ].handyShelf.placeNumber; i++ )
				res += warehouses[ w ].handyShelf.places[ i ].amount;
			cout << res << endl;	
			}		
		};

	void GET_SR( unsigned short s ){
		unsigned long long res = 0;
		if( s >= handyRack.shelfNumber )
			cout << "error" << endl;
		else{
			for( int i = 0; i < handyRack.shelfs[ s ].placeNumber; i++ )
				res += handyRack.shelfs[ s ].places[ i ].amount;
			cout << res << endl;
			}
		};
		
	void GET_S(){
		unsigned long long res = 0;
		for( int i = 0; i < handyShelf.placeNumber; i++ )
			res += handyShelf.places[ i ].amount;
		cout << res << endl;
		};
	
	void SET_LW( unsigned short w, unsigned short r,
				unsigned short s, unsigned short p,
				char dd[]){
		if( w >= warehouseNumber || r >= warehouses[ w ].rackNumber
		|| s >= warehouses[ w ].racks[ r ].shelfNumber 
		|| p >=  warehouses[ w ].racks[ r ].shelfs[ s ].placeNumber )
			cout << "error" << endl;
		else{
			warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].label[ 0 ] = dd[ 0 ];
			warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].label[ 1 ] = dd[ 1 ];
			}
		};
	
	void SET_LH( unsigned short w, unsigned short p, char dd[] ){
		if( w >= warehouseNumber || p >= warehouses[ w ].handyShelf.placeNumber )
			cout << "error" << endl;
		else{
			warehouses[ w ].handyShelf.places[ p ].label[ 0 ] = dd[ 0 ];
			warehouses[ w ].handyShelf.places[ p ].label[ 1 ] = dd[ 1 ];
			}
		};
	
	void SET_LR( unsigned short s, unsigned short p, char dd[] ){
		if( s >= handyRack.shelfNumber || p >= handyRack.shelfs[ s ].placeNumber )
			cout << "error" << endl;
		else{
			handyRack.shelfs[ s ].places[ p ].label[ 0 ] = dd[ 0 ];
			handyRack.shelfs[ s ].places[ p ].label[ 1 ] = dd[ 1 ];
		
			}
		};
		
	void SET_LS( unsigned short p, char dd[] ){
		if( p >= handyShelf.placeNumber )
			cout << "error" << endl;
		else{
			handyShelf.places[ p ].label[ 0 ] = dd[ 0 ];
			handyShelf.places[ p ].label[ 1 ] = dd[ 1 ];
			}
		};
	
	void GET_LW( unsigned short w, unsigned short r,
				unsigned short s, unsigned short p ){
		if( w >= warehouseNumber || r >= warehouses[ w ].rackNumber
		|| s >= warehouses[ w ].racks[ r ].shelfNumber 
		|| p >=  warehouses[ w ].racks[ r ].shelfs[ s ].placeNumber )
			cout << "error" << endl;
		else{
			if( warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].label[ 0 ] == 0 &&
				warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].label[ 1 ] == 0)
					cout << "--" << endl;
			else
				cout << warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].label[ 0 ]
				     << warehouses[ w ].racks[ r ].shelfs[ s ].places[ p ].label[ 1 ]
				     << endl;
			}
		};
	
	void GET_LH( unsigned short w, unsigned short p ){
		if( w >= warehouseNumber || p >= warehouses[ w ].handyShelf.placeNumber )
			cout << "error" << endl;
		else{
			if( warehouses[ w ].handyShelf.places[ p ].label[ 0 ] == 0 &&
				warehouses[ w ].handyShelf.places[ p ].label[ 1 ] == 0 )
				cout << "--" << endl;
			else
				cout << warehouses[ w ].handyShelf.places[ p ].label[ 0 ] 
					 << warehouses[ w ].handyShelf.places[ p ].label[ 1 ]
					 << endl;
			}
		};
	
	void GET_LR( unsigned short s, unsigned short p ){
		if( s >= handyRack.shelfNumber || p >= handyRack.shelfs[ s ].placeNumber )
			cout << "error" << endl;
		else{
			if( handyRack.shelfs[ s ].places[ p ].label[ 0 ] == 0 &&
			    handyRack.shelfs[ s ].places[ p ].label[ 1 ] == 0 )
			    cout << "--" << endl;
			else
				cout << handyRack.shelfs[ s ].places[ p ].label[ 0 ] 
					 << handyRack.shelfs[ s ].places[ p ].label[ 1 ] 
					 << endl; 
		
			}
		};
	
	void GET_LS( unsigned short p ){
		if( p >= handyShelf.placeNumber )
			cout << "error" << endl;
		else{
			if( handyShelf.places[ p ].label[ 0 ] == 0 &&
			    handyShelf.places[ p ].label[ 1 ] == 0 )
			    cout << "--" << endl;
			else
				cout << handyShelf.places[ p ].label[ 0 ] 
					 << handyShelf.places[ p ].label[ 1 ]
					 << endl;  
			}
		};
	
	};
			


int Size( const char s[] ){
	int i = 0;
	while( s[ i ] )
		i++;
	return i;
} 

bool Cmp( char s1[], const char s2[] ){
	int size = Size( s1 );
	if( size != Size( s2 ))
		return false;
	for( int i = 0; i < size; i++ )
		if( s1[ i ] != s2[ i ] )
			return false;
	return true; 
}

bool IsBetween( long long n, long long a, long long b ){
	if( a <= n && n <= b )
		return true;
	return false;
} 
STOREHOUSE store;

int main(){
	char cmd[ 32 ];
	
	do{
		cin >> cmd;
		if( Cmp( cmd, "SET-AP" ) ){
			int wb;
			int rb;
			int sb;
			int Pe;
			cin >> wb >> rb >> sb >> Pe;
	
			if( IsBetween( wb, 0, 127 ) &&
				IsBetween( rb, 0, 127 ) &&
				IsBetween( sb, 0, 127 ) &&
				IsBetween( Pe, 0, 128 ) )
				store.SET_AP( wb, rb , sb , Pe );
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "SET-AS" ) ){
			int wb;
			int rb;
			int Se;
			int Pe;
			cin >> wb >> rb >> Se >> Pe;
			if( IsBetween( wb, 0, 127 ) &&
				IsBetween( rb, 0, 127 ) &&
				IsBetween( Se, 0, 128 ) &&
				IsBetween( Pe, 0, 128 ) )
				store.SET_AS( wb, rb, Se, Pe);
			else
				cout << "error" << endl; 
			}
		else if( Cmp( cmd, "SET-AR" ) ){
			int wb;
			int Re;
			int Se;
			int Pe;
			cin >> wb >> Re >> Se >> Pe;
			if( IsBetween( wb, 0, 127 ) &&
				IsBetween( Re, 0, 128 ) &&
				IsBetween( Se, 0, 128 ) &&
				IsBetween( Pe, 0, 128 ) )
				store.SET_AR( wb, Re, Se, Pe);
			else
				cout << "error" << endl; 
			}
		else if( Cmp( cmd, "SET-AW" )){
			int We;
			int Re;
			int Se;
			int Pe;
			cin >> We >> Re >> Se >> Pe;
			if( IsBetween( We, 0, 128 ) &&
				IsBetween( Re, 0, 128 ) &&
				IsBetween( Se, 0, 128 ) &&
				IsBetween( Pe, 0, 128 ) )
				store.SET_AW( We, Re, Se, Pe);
			else
				cout << "error" << endl; 
			
			}
		else if( Cmp( cmd, "SET-HW" )){
			int w;
			int P;
			cin >> w >> P;
			if( IsBetween( w, 0, 127) &&
				IsBetween( P, 0, 128))
				store.SET_HW( w, P );
			else
				cout << "error" << endl;	
			}
		else if( Cmp( cmd, "SET-HR" )){
			int S;
			int P;
			cin >> S >> P;
			if( IsBetween( S, 0, 128) &&
				IsBetween( P, 0, 128))
				store.SET_HR( S, P );
			else
				cout << "error" << endl;	
			}
		else if( Cmp( cmd, "SET-HS" )){
			int P;
			cin >> P;
			if( IsBetween(  P, 0, 128))
				store.SET_HS( P );
			else
				cout << "error" << endl;	
			}
		else if( Cmp( cmd, "PUT-W" )){
			int w;
			int r;
			int s;
			int p;
			long long A;
			cin >> w >> r >> s >> p >> A;
			if( IsBetween( w, 0, 127) &&
				IsBetween( r, 0, 127) &&
				IsBetween( s, 0, 127) &&
				IsBetween( p, 0, 127) && A >= 0 )
				store.PUT_W( w, r, s, p, A);
			else
				cout << "error" << endl;	 
			}
		else if( Cmp( cmd, "PUT-H" )){
			int w;
			int p;
			long long A;
			cin >> w >> p >> A;
			if( IsBetween( w, 0, 127) &&
				IsBetween( p, 0, 127) && A >= 0 )
				store.PUT_H( w, p, A);
			else	
				cout << "error" << endl;	 
			}
		else if( Cmp( cmd, "PUT-R" )){
			int s;
			int p;
			long long A;
			cin >> s >> p >> A;
			if( IsBetween( s, 0, 127) &&
				IsBetween( p, 0, 127) && A >= 0 )
				store.PUT_R( s, p, A);
			else
				cout << "error" << endl;	 
			}
		else if( Cmp( cmd, "PUT-S" )){
			int p;
			long long A;
			cin >> p >> A;
			if( IsBetween( p, 0, 127) && A >= 0 )
				store.PUT_S( p, A);
			else
				cout << "error" << endl;	 
			}	
		else if( Cmp( cmd, "FILL" )){
			int W;
			int R;
			int S;
			int P;
			long long A;
			cin >> W >> R >> S >> P >> A;
			if( IsBetween( W, 0, 128) &&
				IsBetween( R, 0, 128) &&
				IsBetween( S, 0, 128) &&
				IsBetween( P, 0, 128) && A >= 0 )
				store.FILL( W, R, S, P, A);
			else
				cout << "error" << endl;	 
			}
		else if( Cmp( cmd, "POP-W" )){
			int w;
			int r;
			int s;
			int p;
			long long A;
			cin >> w >> r >> s >> p >> A;
			if( IsBetween( w, 0, 127) &&
				IsBetween( r, 0, 127) &&
				IsBetween( s, 0, 127) &&
				IsBetween( p, 0, 127) && A >= 0 )
				store.POP_W( w, r, s, p, A);
			else
				cout << "error" << endl;	 
			}
		else if( Cmp( cmd, "POP-H" )){
			int w;
			int p;
			long long A;
			cin >> w >> p >> A;
			if( IsBetween( w, 0, 127) &&
				IsBetween( p, 0, 127) && A >= 0 )
				store.POP_H( w, p, A);
			else	
				cout << "error" << endl;	 
			}
		else if( Cmp( cmd, "POP-R" )){
			int s;
			int p;
			long long A;
			cin >> s >> p >> A;
			if( IsBetween( s, 0, 127) &&
				IsBetween( p, 0, 127) && A >= 0 )
				store.POP_R( s, p, A);
			else
				cout << "error" << endl;	 
			}
		else if( Cmp( cmd, "POP-S" )){
			int p;
			long long A;
			cin >> p >> A;
			if( IsBetween( p, 0, 127) && A >= 0 )
				store.POP_S( p, A);
			else
				cout << "error" << endl;	 
			}	
		else if( Cmp( cmd, "MOV-W" )){
			int wb;
			int rb;
			int sb;
			int we;
			int re;
			int se;
			int p;
			long long A;
			cin >> wb >> rb >> sb >> we >> re >> se >> p >> A;
			if( IsBetween( wb, 0, 127) &&
				IsBetween( rb, 0, 127) && 
				IsBetween( sb, 0, 127) &&
				IsBetween( we, 0, 127) &&
				IsBetween( re, 0, 127) &&
				IsBetween( se, 0, 127) &&
				IsBetween( p, 0, 127) && A >= 0 )
				store.MOV_W( wb, rb, sb, we, re, se, p, A );
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "MOV-H")){
			int w;
			int r;
			int s;
			int p;
			long long A;
			cin >> w >> r >> s >> p >> A;
			if( IsBetween( w, 0, 127 ) && 
				IsBetween( r, 0, 127 ) &&
				IsBetween( s, 0, 127 ) &&
				IsBetween( p, 0, 127 ) && A >= 0)
				store.MOV_H( w, r, s, p, A);
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "MOV-R")){
			int w;
			int r;
			int sb;
			int se;
			int p;
			long long A;
			cin >> w >> r >> sb >> se >> p >> A;
			if( IsBetween( w, 0, 127 ) && 
				IsBetween( r, 0, 127 ) &&
				IsBetween( sb, 0, 127 ) &&
				IsBetween( se, 0, 127 ) &&
				IsBetween( p, 0, 127 ) && A >= 0)
				store.MOV_R( w, r, sb, se, p, A);
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "MOV-S")){
			int s;
			int p;
			long long A;
			cin  >> s >> p >> A;
			if( IsBetween( s, 0, 127 ) && 
				IsBetween( p, 0, 127 ) && A >= 0)
				store.MOV_S( s, p, A);
			else
				cout << "error" << endl;
			}	
		else if( Cmp( cmd, "GET-E")){
			store.GET_E();
			}
		else if( Cmp( cmd, "GET-W")){
			int w;
			cin >> w;
			if( IsBetween( w, 0, 127))
				store.GET_W( w );
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "GET-RW")){
			int w;
			int r;
			cin >> w >> r;
			if( IsBetween( w, 0, 127) &&
				IsBetween( r, 0, 127))
				store.GET_RW( w, r );
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "GET-RH")){
			store.GET_RH();
			}
		else if( Cmp( cmd, "GET-SW")){
			int w;
			int r;
			int s;
			cin >> w >> r >> s;
			if( IsBetween( w, 0, 127) &&
				IsBetween( r, 0, 127) &&
				IsBetween( s, 0, 127)) 
				store.GET_SW( w, r ,s);
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "GET-SH")){
			int w;
			cin >> w;
			if( IsBetween( w, 0, 127))
				store.GET_SH( w );
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "GET-SR")){
			int s;
			cin >> s;
			if( IsBetween( s, 0, 127))
				store.GET_SR( s );
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "GET-S")){
			store.GET_S();
			}
		else if( Cmp( cmd, "SET-LW")){
			int w;
			int r;
			int s;
			int p;
			char dd[3] = { 0, 0, 0};
			cin >> w >> r >> s >> p >> dd;
			if( IsBetween( w, 0, 127) &&
				IsBetween( r, 0, 127) &&
				IsBetween( s, 0, 127) &&
				IsBetween( p, 0, 127) )
				store.SET_LW( w, r, s, p, dd );
			else
				cout << "error" << endl;	 
			}
		else if( Cmp( cmd, "SET-LH")){
			int w;
			int p;
			char dd[ 3 ] = { 0, 0, 0};
			cin >> w >> p >> dd;
			if( IsBetween( w, 0, 127) &&
				IsBetween( p, 0, 127) )
				store.SET_LH( w, p, dd );
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "SET-LR")){
			int s;
			int p;
			char dd[ 3 ] = { 0, 0, 0};
			cin >> s >> p >> dd;
			if( IsBetween( s, 0, 127 ) &&
				IsBetween( p, 0, 127) )
				store.SET_LR( s, p, dd);
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "SET-LS")){
			int p;
			char dd[ 3 ] = { 0, 0, 0 };
			cin >> p >> dd;
			if( IsBetween( p, 0, 127 ))
				store.SET_LS( p, dd );
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "GET-LW")){
			int w;
			int r;
			int s;
			int p;
			cin >> w >> r >> s >> p;
			if( IsBetween( w, 0, 127) &&
				IsBetween( r, 0, 127) &&
				IsBetween( s, 0, 127) &&
				IsBetween( p, 0, 127) )
				store.GET_LW( w, r, s, p);
			else
				cout << "error" << endl;	 
			}
		else if( Cmp( cmd, "GET-LH")){
			int w;
			int p;
			cin >> w >> p;
			if( IsBetween( w, 0, 127) &&
				IsBetween( p, 0, 127) )
				store.GET_LH( w, p );
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "GET-LR")){
			int s;
			int p;
			cin >> s >> p;
			if( IsBetween( s, 0, 127 ) &&
				IsBetween( p, 0, 127) )
				store.GET_LR( s, p );
			else
				cout << "error" << endl;
			}
		else if( Cmp( cmd, "GET-LS")){
			int p;
			cin >> p;
			if( IsBetween( p, 0, 127 ))
				store.GET_LS( p );
			else
				cout << "error" << endl;
			}
	} while ( !Cmp( cmd, "END" ) );
	return 0;
}
