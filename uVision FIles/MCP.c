#include<reg52.h>
#include<DisplayLibrary.h>
#include<UpdateCoordinate.h>
#include<InputLibrary.h>
#include<Snake.h>

unsigned char inputPin;
unsigned int n = 0;
bit Over = 0;
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

void ext0() interrupt 2  //P3.3
	
	
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
		IE = 0x86;    //Recheck register value
		TMOD = 0x02;
		TH0 = 0x00;
		TR0 = 1;
		P3 = 0x0F;
	/* Game Initialisation */
UpdateBit(0,0,1);
UpdateBit(1,0,1);
UpdateBit(2,0,1);
UpdateBit(3,0,1);
	/////////////////////////////////////////////
		while(1)
			{
				
				UpdateFrame(coord,bytedata);
			/*The game function is below*/
				if(!Over)
					Over = movement(inputPin);
				delay(1000); 
			
/*				if(UP==1)
				{
					ClearData();
					UpdateRow(1,1);
					UpdateRow(8,1);
				}
				
				else
				{
					ClearData();
					UpdateColoumn(1,1);
					UpdateColoumn(7,1);
				}
				
				toggle=~toggle;
				delay(1000);    */
			}
		}
