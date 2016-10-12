#include<reg52.h>
#include<DisplayLibrary.h>
#include<UpdateCoordinate.h>
#include<InputLibrary.h>

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

void ext0() interrupt 0
	{
		UpdateInput();
	}

void main()
	{
	/***** Initial Config for timer *******/
		IE = 0x82;
		TMOD = 0x02;
		TH0 = 0x00;
		TR0 = 1;
		//////////////////////////////////////////////
		while(1)
			{
				c2b_all(coord,bytedata);

				/****The game function is below*/
				ClearData();
				UpdateBit(4,2,1);
				UpdateColoumn(1,1);
				UpdateRow(3,1);

				
			}
		}
