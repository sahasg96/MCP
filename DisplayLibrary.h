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

void ClearDisplay()
	{
		int rows=8;
		for(int i=0;i<=rows;i++)
			{
				P0 = 0x00;
				CLK();
			}
		ResetCounter();
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
		delay(1);
		clkpin = 0;
		delay(1);         // added
	}


//Testing
