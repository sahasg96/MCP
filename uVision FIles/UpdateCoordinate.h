void UpdateBit (int x, int y, int value = 1, unsigned char coord[10][8])
	{
		coord[y][x] = value;
	}
    
void UpdateRow (int y, int value = 1, unsigned char coord[10][8])
	{
		int x =0;
		for(x=0;x<8;x++)
		coord[y][x] = value;
	}
	
void UpdateColoumn (int x, int value = 1, unsigned char coord[10][8])
	{
		int y=0;
		for(y=0;y<10;y++)
		coord[y][x] = value;
	}
