void DisplayFunction(byte ByteData [8])
	{
		int rows=8;
		for(int i=0;i<=rows;i++)
			{
				P0 = ByteData[i];
				CLK();
			}
		ResetCounter();
	}


void ClearDisplay()
	{
		int rows=8;
		for(int i=0;i<=rows;i++)
			{
				P0 = 0x00000000;
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
	}
