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


void UpdateRow (int y, bit value)
	{
		if(value==1)
			coord[y] = 0xFF;
		else
			coord[y] = 0x00;
	}

void UpdateBit (int x, int y, bit value)
	{
		if (value==1)
			{
					switch(x)
					{
						case 7: coord[y] = coord[y]|0x01;
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
								case 7: coord[y] = coord[y]|0xFE;
									break;
								case 6:coord[y] = coord[y]|0xFD;
									break;
								case 5:coord[y] = coord[y]|0xFB;
									break;
								case 4:coord[y] = coord[y]|0xF7;
									break;
								case 3:coord[y] = coord[y]|0xEF;
									break;
								case 2:coord[y] = coord[y]|0xDF;
									break;
								case 1:coord[y] = coord[y]|0xBF;
									break;
								case 0:coord[y] = coord[y]|0x7F;
									break;
							}
						}
	}


void UpdateColoumn ( int x, bit value)
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
