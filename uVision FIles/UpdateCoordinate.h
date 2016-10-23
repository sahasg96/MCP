unsigned char coord [10] = {
				0x00,
				0x00,
				0x00,
				0x00,
				0x00,
				0x00,
				0x00,
				0x00,
				0x00,
				0x00};

void UpdateRow (unsigned char y, bit value)
	{
		if(value==1)
			coord[y] = 0xFF;
		else
			coord[y] = 0x00;
	}

void UpdateBit (unsigned char x, unsigned char y, bit value)
	{
		if (value==1)
			{
					switch(x)
						{
						case 7:coord[y] = coord[y]|0x01;
							break;
						case 6:coord[y] = coord[y]|0x02;
							break;
						case 5:coord[y] = coord[y]|0x04;
							break;
						case 4:coord[y] = coord[y]|0x08;
							break;
						case 3:coord[y] = coord[y]|0x10;
							break;
						case 2:coord[y] = coord[y]|0x20;
							break;
						case 1:coord[y] = coord[y]|0x40;
							break;
						case 0:coord[y] = coord[y]|0x80;
							break;
					}
				}
				else
					{
							switch(x)
								{
								case 7: coord[y] = coord[y]&0xFE;
									break;
								case 6:coord[y] = coord[y]&0xFD;
									break;
								case 5:coord[y] = coord[y]&0xFB;
									break;
								case 4:coord[y] = coord[y]&0xF7;
									break;
								case 3:coord[y] = coord[y]&0xEF;
									break;
								case 2:coord[y] = coord[y]&0xDF;
									break;
								case 1:coord[y] = coord[y]&0xBF;
									break;
								case 0:coord[y] = coord[y]&0x7F;
									break;
							}
						}
	}

void UpdateColumn ( unsigned char x, bit value)
	{
		int i;
		for(i=0;i<10;i++)
			UpdateBit(x,i,value);
	}

void ClearData()
	{
		int i;
		for(i=0;i<10;i++)
			coord[i] = 0x00;
	}

void UpdateBorder(bit value)
{
	UpdateRow(0,value);
	UpdateRow(9,value);
	UpdateColumn(0,value);
	UpdateColumn(7,value);
}

bit BitCheck(unsigned int x, unsigned int y)
{ 
	unsigned char c = coord[y];
	switch (x)
	{
		case 0: if((c & 0x80) == 0x80)
							return 1;
						else
							return 0;
						
		case 1: if((c & 0x40) == 0x40)
							return 1;
						else
							return 0;
						
		case 2: if((c & 0x20) == 0x20)
							return 1;
						else
							return 0;
						
		case 3: if((c & 0x10) == 0x10)
							return 1;
						else
							return 0;
						
		case 4: if((c & 0x08) == 0x08)
							return 1;
						else
							return 0;
						
		case 5: if((c & 0x04) == 0x04)
							return 1;
						else
							return 0;
						
		case 6: if((c & 0x02) == 0x02)
							return 1;
						else
							return 0;
						
		case 7: if((c & 0x01) == 0x01)
							return 1;
						else
							return 0;
	}
}
