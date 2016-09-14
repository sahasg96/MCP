void DisplayFunction(unsigned char ByteData [8])
	{
		int rows=8;
		for(int i=0;i<=rows;i++)
			{
				P0 = ByteData[i];   // dispalying 1 row at a time
				CLK();
			}
		ResetCounter();
	}


void ClearDisplay()
	{
		int rows=8;
		for(int i=0;i<=rows;i++)
			{
				P0 = 0x0;
				CLK();
			}
		ResetCounter();
	}
	
void ResetCounter()
	{
		resetpin = high;
		delay(5);
		resetpin = low;
	}
	
void CLK()
	{
		clkpin = high;
		delay(5);
		clkpin = low;
		delay(5);         // added
	}


//Testing
