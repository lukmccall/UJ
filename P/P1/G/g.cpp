#include <iostream>
#include <fstream>
#include <string>


using namespace std;
	
void SortInt( string inS, string temp1S, string temp2S ){
	bool init = false;
	long long lineCounter = 0;
	long long downLimit = 0;
	long long amount = 0;
	long long tempAmount;
	int minIndex;
	string minSLine;
	string minCLine;
	
	string minRest1;
	string minRest2;
	string minRest3;
	string minRest4;
	
	int index;
	string iLine;
	string sLine;
	string cLine;
	
	string rest1;
	string rest2;
	string rest3;
	string rest4;
	
	fstream io;
	fstream temp;
	fstream temp2;
	
	io.open( inS.c_str(), fstream::in | fstream::out | fstream::ate);
	if( io.tellg() == 0 ){
		io.close();
		return;
		}
	io.close();
	
	io.open( inS.c_str(), fstream::in | fstream::out );
	temp.open( temp1S.c_str(), fstream::in | fstream::out | fstream::trunc );
	
	do{
		io >> index;
		if( io.eof() )
			break;
		getline( io, iLine);
		getline( io, sLine );
		getline( io, cLine );
		
		getline( io, rest1 );
		getline( io, rest2 );
		getline( io, rest3 );
		getline( io, rest4 );
	
		
		temp << index << endl 
			 << sLine << endl
			 << cLine << endl
			 << rest1 << endl
			 << rest2 << endl
			 << rest3 << endl
			 << rest4 << endl;
		
		if( !init ){
			init = true;
			minIndex = index;
			minSLine = sLine;
			minCLine = cLine;
			minRest1 = rest1;
			minRest2 = rest2;
			minRest3 = rest3;
			minRest4 = rest4;
			}
		else if( init ){
			if( index < minIndex ){
				minIndex = index;
				minSLine = sLine;
				minCLine = cLine;
				minRest1 = rest1;
				minRest2 = rest2;
				minRest3 = rest3;
				minRest4 = rest4;	
				}
			}
		
						 
		lineCounter++;
		}while( true );
	
	io.close();
	temp.close();
	
	
	io.open( inS.c_str(), fstream::in | fstream::out | fstream::trunc );
	io << minIndex << endl
		  << minSLine << endl
		  << minCLine << endl
		  << minRest1 << endl
		  << minRest2 << endl
		  << minRest3 << endl
		  << minRest4;
	amount = 1;	  
	
	for( int i = 0; i < lineCounter-1 ; i++ ){
		temp.open( temp1S.c_str(), fstream::in | fstream::out );
		tempAmount = amount;
		downLimit = minIndex;
		init = false;
		
		for( int j = 0; j < lineCounter; j++ ){
			temp >> index;
			getline( temp, iLine );
		
			getline( temp, sLine );
			getline( temp, cLine );
			
			getline( temp, rest1 );
			getline( temp, rest2 );
			getline( temp, rest3 );
			getline( temp, rest4 );
			
		
			if( index == downLimit ){
				tempAmount--;
				if( tempAmount >= 0 )
					continue;
				else{
					amount++;
					minIndex = index;
					minSLine = sLine;
					minCLine = cLine;
					minRest1 = rest1;
					minRest2 = rest2;
					minRest3 = rest3;
					minRest4 = rest4;	
					break;
					}
				}
			else if( index > downLimit ){
				if( !init )
					init = true;
				else{
					if( index >= minIndex )
						continue;
				}
				minIndex = index;
				minSLine = sLine;
				minCLine = cLine;
				minRest1 = rest1;
				minRest2 = rest2;
				minRest3 = rest3;
				minRest4 = rest4;	
				}
			
		
		}
		
		if( minIndex != downLimit )
			amount = 1;
	
		io << endl << minIndex << endl
			  << minSLine << endl
			  << minCLine << endl
			  << minRest1 << endl
			  << minRest2 << endl
			  << minRest3 << endl
			  << minRest4;
		temp.close();
		}
	
	io.close();
	}

void SortString( string inS, string temp1S, string temp2S ){
	bool init = false;
	long long lineCounter = 0;
	
	string downLimit;
	long long amount = 0;
	long long tempAmount;
	
	string minILine;
	string minSLine;
	string minCLine;
	
	string minRest1;
	string minRest2;
	string minRest3;
	string minRest4;
	
	string iLine;
	string sLine;
	string cLine;
	
	string rest1;
	string rest2;
	string rest3;
	string rest4;
	
	fstream io;
	fstream temp;
	fstream temp2;
	
	io.open( inS.c_str(), fstream::in | fstream::out | fstream::ate);
	if( io.tellg() == 0 ){
		io.close();
		return;
		}
	io.close();
	
	io.open( inS.c_str(), fstream::in | fstream::out );
	temp.open( temp1S.c_str(), fstream::in | fstream::out | fstream::trunc );
	
	do{
		getline( io, iLine );
		if( io.eof() )
			break;
		getline( io, sLine );
		getline( io, cLine );
		
		getline( io, rest1 );
		getline( io, rest2 );
		getline( io, rest3 );
		getline( io, rest4 );
	
		
		temp << iLine << endl 
			 << sLine << endl
			 << cLine << endl
			 << rest1 << endl
			 << rest2 << endl
			 << rest3 << endl
			 << rest4 << endl;
		
		if( !init ){
			init = true;
			minILine = iLine;
			minSLine = sLine;
			minCLine = cLine;
			minRest1 = rest1;
			minRest2 = rest2;
			minRest3 = rest3;
			minRest4 = rest4;
			}
		else if( init ){
			if( sLine < minSLine ){
				minILine = iLine;
				minSLine = sLine;
				minCLine = cLine;
				minRest1 = rest1;
				minRest2 = rest2;
				minRest3 = rest3;
				minRest4 = rest4;	
				}
			}
		
						 
		lineCounter++;
		}while( true );
	
	io.close();
	temp.close();
	
	
	io.open( inS.c_str(), fstream::in | fstream::out | fstream::trunc );
	io << minILine << endl
		  << minSLine << endl
		  << minCLine << endl
		  << minRest1 << endl
		  << minRest2 << endl
		  << minRest3 << endl
		  << minRest4;
	amount = 1;	  
	
	for( int i = 0; i < lineCounter-1 ; i++ ){
		temp.open( temp1S.c_str(), fstream::in | fstream::out );
		tempAmount = amount;
		downLimit = minSLine;
		init = false;
		
		for( int j = 0; j < lineCounter; j++ ){
			
			getline( temp, iLine );
			getline( temp, sLine );
			getline( temp, cLine );
			
			getline( temp, rest1 );
			getline( temp, rest2 );
			getline( temp, rest3 );
			getline( temp, rest4 );
			
		
			if( sLine == downLimit ){
				tempAmount--;
				if( tempAmount >= 0 )
					continue;
				else{
					amount++;
					minILine = iLine;
					minSLine = sLine;
					minCLine = cLine;
					minRest1 = rest1;
					minRest2 = rest2;
					minRest3 = rest3;
					minRest4 = rest4;	
					break;
					}
				}
			else if( sLine > downLimit ){
				if( !init )
					init = true;
				else{
					if( sLine >= minSLine )
						continue;
				}
				minILine = iLine;
				minSLine = sLine;
				minCLine = cLine;
				minRest1 = rest1;
				minRest2 = rest2;
				minRest3 = rest3;
				minRest4 = rest4;	
				}
			
		
		}
		
		if( minSLine != downLimit )
			amount = 1;
	
		io << endl << minILine << endl
			  << minSLine << endl
			  << minCLine << endl
			  << minRest1 << endl
			  << minRest2 << endl
			  << minRest3 << endl
			  << minRest4;
		temp.close();
		}
	
	io.close();
	}

void removeLine( string ioS, string tempS, long long index, long long lineCounter ){
	fstream io, temp;
	string iLine, sLine, cLine, rest1, rest2, rest3, rest4; 
	io.open( ioS.c_str(), fstream::in | fstream::out );
	temp.open( tempS.c_str(), fstream::out | fstream::trunc );
	for( int i = 0; i < index; i++ ){
		getline(io,iLine);
		getline(io,sLine);
		getline(io,cLine);
		
		getline(io,rest1);
		getline(io,rest2);
		getline(io,rest3);
		getline(io,rest4);
	
		temp << iLine << endl
		     << sLine << endl
		     << cLine << endl
		     << rest1 << endl
		     << rest2 << endl
		     << rest3 << endl
		     << rest4 << endl;
		}
	getline(io,iLine);
	getline(io,sLine);
	getline(io,cLine);
		
	getline(io,rest1);
	getline(io,rest2);
	getline(io,rest3);
	getline(io,rest4);
	for( int i = index + 1; i < lineCounter; i++){

		getline(io,iLine);
		getline(io,sLine);
		getline(io,cLine);
		
		getline(io,rest1);
		getline(io,rest2);
		getline(io,rest3);
		getline(io,rest4);
		

		temp << iLine << endl
		     << sLine << endl
		     << cLine << endl
		     << rest1 << endl
		     << rest2 << endl
		     << rest3 << endl
		     << rest4 << endl;
		}
	io.close();
	temp.close();

	io.open( ioS.c_str(), fstream::out | fstream::trunc );
	temp.open( tempS.c_str(), fstream::in );
	
	do{
		getline(temp,iLine);
		if( temp.eof() )
			break;
		getline(temp,sLine);
		getline(temp,cLine);
		
		getline(temp,rest1);
		getline(temp,rest2);
		getline(temp,rest3);
		getline(temp,rest4);
		

		io << iLine << endl
		     << sLine << endl
		     << cLine << endl
		     << rest1 << endl
		     << rest2 << endl
		     << rest3 << endl
		     << rest4 << endl;
	}while( true );
	
		
}	
					  
void SortIntWithCount( string inS, string temp1S ){
	bool init = false;
	long long lineCounter = 0;
	long long downLimit = 0;
	long long amount = 0;
	long long tempAmount;
	
	int minIndex;
	long long ma;
	
	long long a;
	int index;
	
	
	fstream io;
	fstream temp;
	
	io.open( inS.c_str(), fstream::in | fstream::out );
	temp.open( temp1S.c_str(), fstream::in | fstream::out | fstream::trunc );
	
	do{
		io >> a;
		if( io.eof() )
			break;
		io >> index;
	
	
		if( temp.tellg() != 0 )
			temp << endl;
		temp << a << " " << index;
		
		if( !init ){
			init = true;
			ma = a;
			minIndex = index;
			
			}
		else if( init ){
			if( a > ma ){
				ma = a;
				minIndex = index;
				
				}
			else if( a == ma ){
				if( index > minIndex ){
					ma = a;
					minIndex = index;
					}
				}
			}						 
		lineCounter++;
		}while( true );
	
	io.close();
	temp.close();
	
	
	io.open( inS.c_str(), fstream::in | fstream::out | fstream::trunc );
	io << ma << " " << minIndex;
  
	long long lastAmount = ma;
	int lastIndex = minIndex; 
	
	for( int i = 0; i < lineCounter-1 ; i++ ){
		temp.open( temp1S.c_str(), fstream::in | fstream::out );
		init = false;
		
		for( int j = 0; j < lineCounter; j++ ){
			temp >> a >> index;
			
			if( a > lastAmount )
				continue;
			if( a == lastAmount && index >= lastIndex )
				continue;
			
			if( ma == lastAmount && minIndex == lastIndex ){
				ma = a;
				minIndex = index;	
				}
			
			else if( a > ma ){
				ma = a;
				minIndex = index;
				}
			else if( a == ma ){
				if( index > minIndex ){
					ma = a;
					minIndex = index;
					}
				}
			
		
		}
		lastIndex = minIndex;
		lastAmount = ma;
		io << endl << ma << " " << minIndex;
//		cout << ma << " " << minIndex;
		temp.close();
		}
	
	io.close();
	}
	
void intCount( string ioS, string tempS, long long lineCounter ){
	fstream io;
	fstream temp;
	int active;
	int pre;
	long long amount = 1;
	bool init = false;

	io.open( ioS.c_str(), fstream::in );
	temp.open( tempS.c_str(), fstream::out | fstream::trunc );
	
	io >> pre;

	
	for( int i = 0; i < lineCounter - 1; i++ ){
		io >> active;
	
		if( active != pre ){
			temp << amount << " " << pre << endl;		
			amount = 1;
			}
		else
			amount++;	
		
		pre = active;
		}
	temp << amount << " " << pre;	
	io.close();
	temp.close();	

	}

void SortChar( string inS, string temp1S, string temp2S ){
	bool init = false;
	long long lineCounter = 0;
	long long deleteLine;
	long long i = 0;
	
	
	string minILine;
	string minSLine;
	string minCLine;
		
	string iLine;
	string sLine;
	string cLine;
	
	bool b1,b2,b3,b4;
	int c1,c2,c3,c4;
	string f1,f2,f3,f4;
	
	bool minb1,minb2,minb3,minb4;
	int minc1,minc2,minc3,minc4;
	string minf1,minf2,minf3,minf4;
	unsigned char wynik1,wynik2;
	
	fstream io;
	fstream temp2;
	
	io.open( inS.c_str(), fstream::in | fstream::out );
	
	do{
		getline( io, iLine);
		if( io.eof() )
			break;
		getline( io, sLine );
		getline( io, cLine );
		
		io >> b1 >> c1;
		getline( io, f1);
		io >> b2 >> c2;
		getline( io, f2);
		io >> b3 >> c3;
		getline( io, f3);
		io >> b4 >> c4;
		getline( io, f4);
		  		 
		lineCounter++;
		}while( true );
	
	io.close();
	
	temp2.open( temp2S.c_str(), fstream::in | fstream::out | fstream::trunc );
	while( lineCounter > 0 ){
		i = -1;
		io.open( inS.c_str(), fstream::in );
		init = false;
		do{
			getline( io, iLine);
			if( io.eof() )
				break;
			getline( io, sLine );
			getline( io, cLine );
			
			io >> b1 >> c1;
			getline( io, f1);
			io >> b2 >> c2;
			getline( io, f2);
			io >> b3 >> c3;
			getline( io, f3);
			io >> b4 >> c4;
			getline( io, f4);
			i++;
				 
			if( !init ){
				init = true;
				minILine = iLine;
				minSLine = sLine;
				minCLine = cLine;
				minb1 = b1;
				minb2 = b2;
				minb3 = b3;
				minb4 = b4;
				
				minc1 = c1;
				minc2 = c2;
				minc3 = c3;
				minc4 = c4;
				
				minf1 = f1;
				minf2 = f2;
				minf3 = f3;
				minf4 = f4;
				deleteLine = i;
				}
			else if( init ){
				wynik1 = (c1+c2+c3+c4)%256;
				wynik2 = (minc1+minc2+minc3+minc4)%256;
				if( wynik1 > wynik2 ){
					minILine = iLine;
					minSLine = sLine;
					minCLine = cLine;
					minb1 = b1;
					minb2 = b2;
					minb3 = b3;
					minb4 = b4;
					
					minc1 = c1;
					minc2 = c2;
					minc3 = c3;
					minc4 = c4;
					
					minf1 = f1;
					minf2 = f2;
					minf3 = f3;
					minf4 = f4;	
					deleteLine = i;
					}
				}
		}while( true );
		io.close();
		if( temp2.tellg() != 0 )
			temp2 << endl;
		temp2 << minILine << endl
			  << minSLine << endl
			  << minCLine << endl
			  << minb1 << " " << minc1 << minf1 << endl
			  << minb2 << " " << minc2 << minf2 << endl
			  << minb3 << " " << minc3 << minf3 << endl
			  << minb4 << " " << minc4 << minf4;
	
		removeLine( inS, temp1S, deleteLine, lineCounter);
	
		lineCounter--;
		}
	temp2.close();
	temp2.open( temp2S.c_str(),fstream::in);
	io.open( inS.c_str(), fstream::out | fstream::trunc);
	do{
			getline( temp2, iLine);
			if( temp2.eof() )
				break;
			getline( temp2, sLine );
			getline( temp2, cLine );
			
			temp2 >> b1 >> c1;
			getline( temp2, f1);
			temp2 >> b2 >> c2;
			getline( temp2, f2);
			temp2 >> b3 >> c3;
			getline( temp2, f3);
			temp2 >> b4 >> c4;
			getline( temp2, f4);
			
			
			if( io.tellg() != 0 )
				io << endl;
			io << iLine << endl
			  << sLine << endl
			  << cLine << endl
			  << b1 << " " << c1 << f1 << endl
			  << b2 << " " << c2 << f2 << endl
			  << b3 << " " << c3 << f3 << endl
			  << b4 << " " << c4 << f4;
			
		} while( true );
		io.close();
		temp2.close();
	}

void SortCount( string inS, string temp1S, string temp2S ){
	fstream io;
	fstream temp1;
	fstream temp2;
	
	io.open( inS.c_str(), fstream::in | fstream::ate );
	if( io.tellg() == 0 ){
		io.close();
		return;	
		}
	io.close();
	
	SortChar( inS,temp1S,temp2S);
	
	
	SortInt( inS, temp1S, temp2S );
	
	long long lineCounter = 0;
	string iLine, sLine, cLine, rest1, rest2, rest3, rest4; 
	io.open( inS.c_str(), fstream::in );
	temp1.open( temp1S.c_str(), fstream::out | fstream::trunc );

	do{	
		getline( io, iLine );
		if( io.eof( ))
			break;
		getline( io, sLine );
		getline( io, cLine );
		
		getline( io, rest1 );
		getline( io, rest2 );
		getline( io, rest3 );
		getline( io, rest4 );
		
		if( temp1.tellg() != 0)
			temp1 << endl;
		temp1 << iLine;
		lineCounter++;
		
	}while( true );
	io.close();
	temp1.close();
	
	intCount( temp1S, temp2S, lineCounter ); 
	SortIntWithCount( temp2S, temp1S);
	// temp2S <- posortowane po ilosci i takie tam 
	
	temp1.open( temp1S.c_str(), fstream::out | fstream::trunc );
	temp2.open( temp2S.c_str(), fstream::in );
		
	
	long long amount;
	int index;
	bool init = false;
	
	bool b1,b2,b3,b4;
	int c1,c2,c3,c4;
	string f1,f2,f3,f4;
	
	bool lb1,lb2,lb3,lb4;
	int lc1,lc2,lc3,lc4;
	string lf1,lf2,lf3,lf4;

	string lsLine, lcLine;	
	int active;

	do{
		temp2 >> amount;
		if( temp2.eof() )
			break;
		temp2 >> index;
	
		io.open( inS.c_str(), fstream::in );
		do{
			io >> active;
			if( io.eof() )
				break;
			getline( io, iLine );
			getline( io, sLine );
			getline( io, cLine );
			
			io >> b1 >> c1;
			getline( io, f1 );
			io >> b2 >> c2;
		    getline( io, f2 );
			io >> b3 >> c3;
			getline( io, f3 );
			io >> b4 >> c4;
			getline( io, f4 );
	
			if( index == active ){
				temp1 << index << endl
				      << sLine << endl
				      << cLine << endl
				      << b1 << " " << c1 << f1 << endl
				      << b2 << " " << c2 << f2 << endl
				      << b3 << " " << c3 << f3 << endl
				      << b4 << " " << c4 << f4 << endl;
				}
						
				
			}while( true );
		io.close();
		
		} while( true );
	temp1.close();
	temp2.close();
	
	temp1.open( temp1S.c_str(), fstream::in );
	io.open( inS.c_str(), fstream::out | fstream::trunc );
	do{
		getline( temp1, iLine );
		if( temp1.eof( ))
			break;
		getline( temp1, sLine );
		getline( temp1, cLine );
		
		getline( temp1, rest1 );
		getline( temp1, rest2 );
		getline( temp1, rest3 );
		getline( temp1, rest4 );
		
		if( io.tellg() != 0 )
			io << endl;
		io << iLine << endl
		   << sLine << endl
		   << cLine << endl
		   << rest1 << endl
		   << rest2 << endl
		   << rest3 << endl
		   << rest4;
			
	}while( true );
	temp1.close();
	io.close();
	

	}	

void SymmetricDifference( string outS, string inS, string tempS ){
	fstream out;
	fstream in;
	fstream temp;
	
	bool add = false;
	string iLineIN, sLineIN, cLineIN, rest1IN, rest2IN, rest3IN, rest4IN; 
	string iLineOUT, sLineOUT, cLineOUT, rest1OUT, rest2OUT, rest3OUT, rest4OUT; 
	
	in.open( inS.c_str(), fstream::in | fstream::ate );
	if( in.tellg() == 0 ){
		in.close();
		return;		
		}
	in.close();
	
	in.open( inS.c_str(), fstream::out | fstream::in );
	temp.open( tempS.c_str(), fstream::out | fstream::in | fstream::trunc );
	
	do{
		getline( in, iLineIN );	
		if( in.eof() )
			break;
		getline( in, sLineIN );
		getline( in, cLineIN );
		
		getline( in, rest1IN );
		getline( in, rest2IN );
		getline( in, rest3IN );
		getline( in, rest4IN );
		
		add = true;
		out.open( outS.c_str(), fstream::in );
		do{
			getline( out, iLineOUT );	
			if( out.eof() )
				break;
			getline( out, sLineOUT );
			getline( out, cLineOUT );
			
			getline( out, rest1OUT );
			getline( out, rest2OUT );
			getline( out, rest3OUT );
			getline( out, rest4OUT );
			
			if( iLineIN == iLineOUT && sLineIN == sLineOUT
			 && cLineIN == cLineOUT && rest1IN == rest1OUT
			 && rest2IN == rest2OUT && rest3IN == rest3OUT
			 && rest4IN == rest4OUT ){
			 	add = false;
			 	break;
			 	}
			}while( true );
		out.close();
	
		if( add ){
			out.open( outS.c_str(), fstream::out | fstream::app ); 
			if( out.tellg() != 0 )
				out << endl;
			out  << iLineIN << endl
				 << sLineIN << endl
				 << cLineIN << endl
				 << rest1IN << endl
				 << rest2IN << endl
				 << rest3IN << endl
				 << rest4IN;
			out.close();
			}
		else{
			if( temp.tellg() != 0 )
				temp << endl;
			temp << iLineIN << endl
				 << sLineIN << endl
				 << cLineIN << endl
				 << rest1IN << endl
				 << rest2IN << endl
				 << rest3IN << endl
				 << rest4IN;
			}
		}while( true );
		in.close();
		temp.close();
		
		in.open( inS.c_str(), fstream::out | fstream::trunc );
		temp.open( tempS.c_str(), fstream::in );
		do{
			getline( temp, iLineIN );	
			if( temp.eof() )
				break;
			getline( temp, sLineIN );
			getline( temp, cLineIN );
			
			getline( temp, rest1IN );
			getline( temp, rest2IN );
			getline( temp, rest3IN );
			getline( temp, rest4IN );
			
			if( in.tellg() != 0 )
				in << endl;
			in << iLineIN << endl
				 << sLineIN << endl
				 << cLineIN << endl
				 << rest1IN << endl
				 << rest2IN << endl
				 << rest3IN << endl
				 << rest4IN;
		} while( true );
			
		in.close();
		temp.close();
		
	}	

//int main(){
//	SortCount("dane.txt", "temp1.txt", "temp2.txt");
//}
