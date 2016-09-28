unsigned char c2b( unsigned char coord[10][8], int row)
	{	
		unsigned char a = 0;
		int temp =0;// This is the temporary byte value which will be returned
		for (temp = 0; temp<8; temp = temp +1)
			{	
				a = a<<1;				// left shift
				a = a + coord[row][temp];    //adding all the values of the row together
			}
		return a;
	}

void c2b_all(unsigned char coord[10][8], unsigned char databyte[])
	{
		for(int temp=0; temp<10; temp = temp +1)
			{
				 databyte[temp] =  c2b(coord, temp);
			}
	}
