#include <iostream>

using namespace std;

int main(){
	int wA = 0;
	int wB = 0;
	int wC = 0;
	int wD = 0;
	int wE = 0;
	
	int gA = 0;
	int gB = 0;
	int gC = 0;
	int gD = 0;
	int gE = 0;
	
	int rA = 0;
	int rB = 0;
	int rC = 0;
	int rD = 0;
	int rE = 0;

	char player1;
	char player2;
	char win;
	
	int p11;
	int p12;
	int p13;
	int p14;
	
	int p21;
	int p22;
	int p23;
	int p24;
	
	int poker1;
	int poker2;
	int player1_max;
	int player2_max;
	
	int n;
	
	cin >> n;
	
	while( n > 0){
		cin >> player1 >> p11 >> p12 >> p13 >> p14;
		cin >> player2 >> p21 >> p22 >> p23 >> p24;
		
		if( p11 == p12 && p12 == p13 && p13 == p14 )
			poker1 = 1;
		else
			if( p11 != p12 && p11 != p13 && p11 != p14 && p12 != p13 && p12 != p14 && p13 != p14 ) 
				poker1 = 2;
			else
				if( (p11 == p12 && p13 == p14) || (p11 == p13 && p12 == p14) || (p11 == p14 && p12 == p13) )
					poker1 = 3;
				else
					if( (p11 == p12 && p11 == p13) || (p11 == p12 && p11 == p14) || (p11 == p13 && p11 == p14) || (p12 == p13 && p12 == p14))
						poker1 = 4;
				else 
					if( p11 == p12 || p11 == p13 || p11 == p14 || p12 == p13 || p12 == p14 || p13 == p14)
						poker1 = 5;
					else
						poker1 = 6;
		
		if( p21 == p22 && p22 == p23 && p23 == p24 )
			poker2 = 1;
		else
			if( p21 != p22 && p21 != p23 && p21 != p24 && p22 != p23 && p22 != p24 && p23 != p24 )
				poker2 = 2;
			else
				if( (p21 == p22 && p23 == p24) || (p21 == p23 && p22 == p24) || (p21 == p24 && p22 == p23) )
					poker2 = 3;
				else
					if( (p21 == p22 && p21 == p23) || (p21 == p22 && p21 == p24) || (p21 == p23 && p21 == p24) || (p22 == p23 && p22 == p24))
						poker2 = 4;
				else 
					if( p21 == p22 || p21 == p23 || p21 == p24 || p22 == p23 || p22 == p24 || p23 == p24)
						poker2 = 5;
					else
						poker2 = 6;		
		if( poker1 < poker2 )
			win = player1;
		else
			if( poker1 > poker2 )	
				win = player2;
			else{
				if( poker1 == 1 )
					if( p11 > p21 )
						win = player1;
					else
						if( p11 < p21)
							win = player2;
						else 
							if( p11 + p12 + p13 + p14 > p21 + p22 + p23 + p24 )
									win = player1;
							else
								if( p11 + p12 + p13 + p14 < p21 + p22 + p23 + p24 )
									win = player2;
										else
											win = 'r';
				else 
					if( poker1 == 2 )
						if( p11 + p12 + p13 + p14 > p21 + p22 + p23 + p24 )
							win = player1;
						else
							if( p11 + p12 + p13 + p14 < p21 + p22 + p23 + p24 )
								win = player2;
							else
								win = 'r';
					else
						if(poker2 == 3){
							if( p11 >= 	p12 && p11 >= p13 && p11 >= p14 )
								player1_max = p11;
							else if( p12 >= p11 && p12 >= p11 && p12 >= p14 )
								player1_max = p12;
							else if( p13 >= p11 && p13 >= p12 && p13 >= p14 )
								player1_max = p13;
							else if( p14 >= p11 && p14 >= p12 && p14 >= p13 )
								player1_max = p14;
								
							if( p21 >= 	p22 && p21 >= p23 && p21 >= p24 )
								player2_max = p21;
							else if( p22 >= p21 && p22 >= p21 && p22 >= p24 )
								player2_max = p22;
							else if( p23 >= p21 && p23 >= p22 && p23 >= p24 )
								player2_max = p23;
							else if( p24 >= p21 && p24 >= p22 && p24 >= p23 )
								player2_max = p24;
								
							if( player1_max > player2_max )
								win = player1;
							else 
								if( player1_max < player2_max )
									win = player2;
								else
									if( p11 + p12 + p13 + p14 > p21 + p22 + p23 + p24 )
											win = player1;
										else
											if( p11 + p12 + p13 + p14 < p21 + p22 + p23 + p24 )
												win = player2;
											else
												win = 'r';
							
							
							}
						else
							if( poker1 == 4 ){
								player1_max = -1;
								player2_max = -1;
								
								if( p11 == 	p12 && p11 == p13 )
									if( player1_max < p11 )
										player1_max = p11;
								if( p11 == p12 && p11 == p14 )
									if( player1_max < p11 )
										player1_max = p11;
								if( p11 == p13 && p11 == p14 )
									if( player1_max < p11 )
										player1_max = p11;
								if( p12 == p13 && p12 == p14 )
									if( player1_max < p12 )
										player1_max = p12;
										
								if( p21 == 	p22 && p21 == p23 )
									if( player2_max < p21 )
										player2_max = p21;
								if( p21 == p22 && p21 == p24 )
									if( player2_max < p21 )
										player2_max = p21;
								if( p21 == p23 && p21 == p24 )
									if( player2_max < p21 )
										player2_max = p21;
								if( p22 == p23 && p22 == p24 )
									if( player2_max < p22 )
										player2_max = p22;
								
								if( player1_max > player2_max )
									win = player1;
								else 
									if( player1_max < player2_max )
										win = player2;
									else
										if( p11 + p12 + p13 + p14 > p21 + p22 + p23 + p24 )
											win = player1;
										else
											if( p11 + p12 + p13 + p14 < p21 + p22 + p23 + p24 )
												win = player2;
											else
												win = 'r';
								}
							else
								if( poker1 == 5 ){
									player1_max = -1;
									player2_max = -1;
									
									if( p11 == p12 )
										if( player1_max < p11 )
											player1_max = p11;
									if( p11 == p13 )
										if( player1_max < p11 )
											player1_max = p11;
									if( p11 == p14 )
										if( player1_max < p11 )
											player1_max = p11;
									if( p12 == p13 )
										if( player1_max < p12 )
											player1_max = p12;
									if( p12 == p14 )
										if( player1_max < p12 )
											player1_max = p12;
									if( p13 == p14 )
										if( player1_max < p13 )
											player1_max = p13;
									
									if( p21 == p22 )
										if( player2_max < p21 )
											player2_max = p21;
									if( p21 == p23 )
										if( player2_max < p21 )
											player2_max = p21;
									if( p21 == p24 )
										if( player2_max < p21 )
											player2_max = p21;
									if( p22 == p23 )
										if( player2_max < p22 )
											player2_max = p22;
									if( p22 == p24 )
										if( player2_max < p22 )
											player2_max = p22;
									if( p23 == p24 )
										if( player2_max < p23 )
											player2_max = p23;
								
									if( player1_max > player2_max )
										win = player1;
									else 
										if( player1_max < player2_max )
											win = player2;
										else
											if( p11 + p12 + p13 + p14 > p21 + p22 + p23 + p24 )
												win = player1;
											else
												if( p11 + p12 + p13 + p14 < p21 + p22 + p23 + p24 )
													win = player2;
												else
													win = 'r';
									
									
									}
								else 
									if( poker1 == 6 )
										if( p11 + p12 + p13 + p14 > p21 + p22 + p23 + p24 )
											win = player1;
										else
											if( p11 + p12 + p13 + p14 < p21 + p22 + p23 + p24 )
												win = player2;
											else
												win = 'r';
				}
		if( player1 == 'a' || player2 == 'a' )
			gA++;
		if( player1 == 'b' || player2 == 'b' )
			gB++;
		if( player1 == 'c' || player2 == 'c' )
			gC++;
		if( player1 == 'd' || player2 == 'd' ) 
			gD++;
		if( player1 == 'e' || player2 == 'e' ) 
			gE++;
		
		if( win == 'a' )
			wA++;
		if( win == 'b' )
			wB++;
		if( win == 'c' )
			wC++;
		if( win == 'd' )
			wD++;
		if( win == 'e' )
			wE++;
			
		if( win == 'r' ){
			if( player1 == 'a' || player2 == 'a' )
				rA++;
			if( player1 == 'b' || player2 == 'b' )
				rB++;
			if( player1 == 'c' || player2 == 'c' )
				rC++;
			if( player1 == 'd' || player2 == 'd' ) 
				rD++;
			if( player1 == 'e' || player2 == 'e' ) 
				rE++;
			}		
			
		n--;
		}
		
		if( gA != 0 ){
			cout << "gracz a" << endl;
			if( wA != 0 )
				cout << "    wygrane: " << ( (float)wA / (float)gA * 100.0 ) << "%" <<endl;
			if( rA != 0 )
				cout << "    remisy: " << ( (float)rA / (float)gA * 100.0 ) << "%" <<endl;
			if( gA - (wA + rA) != 0 )
				cout << "    przegrane: " << ( ( (float)gA - ( (float)wA + (float)rA ) ) / (float)gA * 100.0 ) << "%"  << endl;
			if( gB != 0 || gC != 0 || gD !=0 || gE != 0 ) cout << endl;
			}

		if( gB != 0 ){
			cout << "gracz b" << endl;
			if( wB != 0 )
				cout << "    wygrane: " << ( (float)wB / (float)gB * 100.0 ) << "%" <<endl;
			if( rB != 0 )
				cout << "    remisy: " << ( (float)rB / (float)gB * 100.0 ) << "%" <<endl;
			if( gB - (wB + rB) != 0 )
				cout << "    przegrane: " << ( ( (float)gB - ( (float)wB + (float)rB ) ) / (float)gB * 100.0 ) << "%"  << endl;
			if( gC != 0 || gD !=0 || gE != 0 ) cout << endl;
			}
			
			
		if( gC != 0 ){
			cout << "gracz c" << endl;
			if( wC != 0 )
				cout << "    wygrane: " << ( (float)wC / (float)gC * 100.0 ) << "%" <<endl;
			if( rC != 0 )
				cout << "    remisy: " << ( (float)rC / (float)gC * 100.0 ) << "%" <<endl;
			if( gC - (wC + rC) != 0 )
				cout << "    przegrane: " << ( ( (float)gC - ( (float)wC + (float)rC ) ) / (float)gC * 100.0 ) << "%"  << endl;
			if( gD !=0 || gE != 0 ) cout << endl;
			}
			
		if( gD != 0 ){
			cout << "gracz d" << endl;
			if( wD != 0 )
				cout << "    wygrane: " << ( (float)wD / (float)gD * 100.0 ) << "%" <<endl;
			if( rD != 0 )
				cout << "    remisy: " << ( (float)rD / (float)gD * 100.0 ) << "%" <<endl;
			if( gD - (wD + rD) != 0 )
				cout << "    przegrane: " << ( ( (float)gD - ( (float)wD + (float)rD ) ) / (float)gD * 100.0 ) << "%" << endl;
			if( gE != 0 ) cout << endl;
			}
		if( gE != 0 ){
			cout << "gracz e" << endl;
			if( wE != 0 )
				cout << "    wygrane: " << ( (float)wE / (float)gE * 100.0 ) << "%" <<endl;
			if( rE != 0 )
				cout << "    remisy: " << ( (float)rE / (float)gE * 100.0 ) << "%" <<endl;
			if( gE - (wE + rE) != 0 )
				cout << "    przegrane: " << ( ( (float)gE - ( (float)wE + (float)rE ) ) / (float)gE * 100.0 ) << "%";
			}
	return 0;
	}
