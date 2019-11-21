#include <iostream>

using namespace std;

int main(){
	int n;
	int k;
	int len;
	int b;
	int e;
	int subLen;
	int maskLen;
	int activeIndex;
	int counter = 0;
	
	double avg = 0;
	double weightAvg = 0;
	double temp;
	char operation; 
	
	cin >> n;
	double mainArray[ n ];
	
	for( int i = 0; i < n; i++ )
		cin >> mainArray[ i ];

	cin >> k;
	double mask[ k ];

	for( int i = 0; i < k; i++ )
		cin >> mask[ i ];

	cin >> len >> b >> e >> operation;
	 
	subLen = e-b>0?e-b:n-(b-e);
	double subArray[ subLen + 1 ];
	
	maskLen = k + (len * ( k - 1 ));
	
	for( int i = 0; i <= subLen; i++ )
		subArray[ i ] = mainArray[ (b + i)% n ];

	for( int i = 0; i <= subLen; i++ ){
		avg = 0;
		weightAvg = 0;
		counter = 0;
		for( int j = 0; j < maskLen; j = j + len + 1){
			activeIndex = ((j + i - ( maskLen / 2 ) ) % (subLen+1))>=0?((j + i - ( maskLen / 2 ) ) % (subLen+1)):(1+subLen+((j + i - ( maskLen / 2 ) ) % (subLen+1)));
			if( operation == 'r' )
				avg += subArray[ activeIndex ];
			else 
				if( operation == 'w' )
					weightAvg += subArray[ activeIndex ] * mask[ counter ];
				else 
					if( operation == 'm' )
						mask[ counter ] = subArray[ activeIndex ];
			counter++;
			
			}
	
			if( operation == 'r' ){
				avg /= (float)counter;
				mainArray[ (b + i)% n ] =  ((int)(avg*100.0)/100.0);
				}	
			else 
				if( operation == 'w')
					mainArray[ (b + i)% n ] = ((int)(weightAvg*100.0)/100.0);
				else
					if( operation == 'm' ){
						for( int a = 0; a < k; a++ )
							for( int b = 0; b < k; b++ )
								if( mask[ a ] < mask[ b ] ){
									temp = mask[ a ];
									mask[ a ] = mask[ b ];
									mask[ b ] = temp;
									}
						mainArray[ (b + i)% n ] = ((int)(mask[ k/2 ]*100.0)/100.0);	
					}
				
	
		}
	for( int i = 0; i < n; i++ )
		cout << mainArray[ i ] << " ";

	return 0;
	}
