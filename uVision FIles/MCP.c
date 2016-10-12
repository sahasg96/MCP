#include<reg52.h>
#include<DisplayLibrary.h>
#include<UpdateCoordinate.h>

static unsigned int n = 0;
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
	clk_pin = ~clk_pin;
	n=n+1;
	if(n==10)
		n=0;
}
	
	void main()
{
	IE = 0x82;
	TMOD = 0x02;
	TH0 = 0x00;
	
	while(1)
	{
		c2b_all(coord,bytedata);
		displayfunction(bytedata);
		UpdateBit(4,2,1);
		UpdateColoumn(1,1);
		UpdateRow(3,1);
		
	}
}



