unsigned char c2b( int coord[8][8], int row)
	{	
		unsigned char a = 0;				// This is the temporary byte value which will be returned
		for (int temp = 0; temp<=8; temp = temp +1)
			{	
				a>>1;				// left shift
				a = a + coord[temp][row];    //adding all the values of the row together
			}
		return a;
	}

void c2b_all(int coord[8][8], unsigned char data[])
	{
		for(int temp=0; temp<=8; temp = temp +1)
			{
				 data[temp] =  c2b(coord[8][8], temp);
			}
	}
