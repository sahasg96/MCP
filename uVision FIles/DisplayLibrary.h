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


	void ClearDisplay()
	{
		int rows=8;
		int i = 0;
		for( i=0;i<=rows;i++)
			{
				P0 = 0x00;
			}
	}

void c2b_all(unsigned char coord[10], unsigned char databyte[10])
	{
		int i;
		for(i=0;i<10;i++)
			databyte[i] = coord[i];
	}
