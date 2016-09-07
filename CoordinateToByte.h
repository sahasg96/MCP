byte c2b( int coord[8][8], int row)
	{	
		byte a = 0;
		for (int temp = 0; temp<=8; temp = temp +1)
			{
				a = a + coord[temp][row];    //The x coordinate is the value of the byte data also
			}
		return a;
	}

void c2b_all(int coord[8][8], byte data[])
	{
		for(int temp=0; temp<=8; temp = temp +1)
			{
				 data[temp] =  c2b(coord[8][8], temp);
			}
	}
