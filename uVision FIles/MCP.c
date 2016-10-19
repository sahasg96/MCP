#include<reg52.h>
#include<DisplayLibrary.h>
#include<UpdateCoordinate.h>
#include<InputLibrary.h>
#include<Snake.h>

unsigned char inputPin;
unsigned int n = 0;
unsigned char bytedata [10] = { 0x00,
																0x00,
																0x00,
																0x00,
																0x00,
																0x00,
																0x00,
																0x00,
																0x00,
																0x00};

void timer0() interrupt 1
	{
	P0 = bytedata[n];
	clkpin = ~clkpin;
	n=n+1;
	if(n==10)
	{
				n=0;
				resetpin=1;
				delay(5);
				resetpin=0;
	}

	}

void ext0() interrupt 2  //P3.2
	{
		UpdateInput();
		if ( UP == 1 )
			inputPin = 1;
		else if ( RIGHT == 1 )
			inputPin = 2;
		else if ( DOWN == 1 )
			inputPin = 3;
		else if ( LEFT == 1 )
			inputPin = 4;
	}

void main()
	{
	/***** Initial Config for timer *******/
		IE = 0x86;
		TMOD = 0x02;
		TH0 = 0x00;
		TR0 = 1;
	//////////////////////////////////////////////
		while(1)
			{
				c2b_all(coord,bytedata);
				/*The game function is below*/
				
/*			UpdateBorder(1);
				UpdateColoumn(5,1);
				UpdateColoumn(1,1);
				UpdateRow(5,1);
				UpdateRow(1,1);
				UpdateBit(2,2,1);
				UpdateBit(2,3,1);
				UpdateBit(2,4,1);
				UpdateBit(2,5,1);  */
				
				movement(inputPin,bytedata);
				
			}
		}
