void UpdateBit (int x, int y, unsigned char coord[10][8])
	{
		coord[y][x] = 1;
	}
    
void UpdateRow (int y, unsigned char coord[10][8])
	{
		int x =0;
		for(x=0;x<8;x++)
		coord[y][x] = 1;
	}
	
void UpdateColoumn (int x, unsigned char coord[10][8])
	{
		int y=0;
		for(y=0;y<10;y++)
		coord[y][x] = 1;
	}

void ClearData(unsigned char coord[10][8])
	{
		int i,j;
		for(i=0;i<10;i++)
			for(j=0;j<8;j++)
				coord[i][j] = 0;
	}
