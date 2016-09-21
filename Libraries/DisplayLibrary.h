sbit  clkpin = P3^7;
sbit  resetpin = P3^6;

void delay(unsigned int time)
{
	unsigned int i=0;
	unsigned int j=0;
	
	for( i=0;i<=time;i++)
		for(j=0;j<100;j++);
}


	
void ResetCounter()
	{
		resetpin = 1;
		delay(5);
		resetpin = 0;
	}
	
void CLK()
	{
		clkpin = 1;
		delay(100);
		clkpin = 0;
		delay(100);         // added
	}

	void ClearDisplay()
	{
		int rows=8;
		int i = 0;
		for( i=0;i<=rows;i++)
			{
				P0 = 0x00;
				CLK();
			}
		ResetCounter();
	}
	
void displayfunction(unsigned char ByteData [])
	{
		int rows=10;
		int i = 0;
		for(i=0;i<rows;i++)
			{
				CLK();
				P0 = ByteData[i];   // dispalying 1 row at a time
				//delay(1000);
			}
		ResetCounter();
	}
//Testing
