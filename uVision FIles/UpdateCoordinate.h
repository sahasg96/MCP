extern unsigned char coord [10][8] = {
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

void UpdateBit (int x, int y, bit value)
	{
		coord[y][x] = value;
	}
    
void UpdateRow (int y, bit value)
	{
		int x =0;
		for(x=0;x<8;x++)
		coord[y][x] = value;
	}
	
void UpdateColoumn ( int x, bit value)
	{
		int y=0;
		for(y=0;y<10;y++)
		coord[y][x] = value;
	}

void ClearData()
	{
		int i,j;
		for(i=0;i<10;i++)
			for(j=0;j<8;j++)
				coord[i][j] = 0;
	}
