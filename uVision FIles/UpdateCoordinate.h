void UpdateBit ( unsigned char coord[10][8], int x, int y, int value =1)
	{
		coord[y][x] = value;
	}
    
void UpdateRow ( unsigned char coord[10][8],int y,int value =1)
	{
		int x =0;
		for(x=0;x<8;x++)
		coord[y][x] = value;
	}
	
void UpdateColoumn ( unsigned char coord[10][8], int x,int value =1)
	{
		int y=0;
		for(y=0;y<10;y++)
		coord[y][x] = value;
	}

void ClearData(unsigned char coord[10][8])
	{
		int i,j;
		for(i=0;i<10;i++)
			for(j=0;j<8;j++)
				coord[i][j] = 0;
	}
