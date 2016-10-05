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
					case(x)
					{
						0: coord[y] = coord[y]|0x01;
							break;
						1:coord[y] = coord[y]|0x02;
							break;
						2:coord[y] = coord[y]|0x04;
							break;
						3:coord[y] = coord[y]|0x08;
							break;
						4:coord[y] = coord[y]|0x10;
							break;
						5:coord[y] = coord[y]|0x20;
							break;
						6:coord[y] = coord[y]|0x40;
							break;
						7:coord[y] = coord[y]|0x80;
							break;
					}
				}
				else
					{
							case(x)
							{
								0: coord[y] = coord[y]|0xFE;
									break;
								1:coord[y] = coord[y]|0xFD;
									break;
								2:coord[y] = coord[y]|0xFB;
									break;
								3:coord[y] = coord[y]|0xF7;
									break;
								4:coord[y] = coord[y]|0xEF;
									break;
								5:coord[y] = coord[y]|0xDF;
									break;
								6:coord[y] = coord[y]|0xBF;
									break;
								7:coord[y] = coord[y]|0x7F;
									break;
							}
						}
	}


void UpdateColoumn ( int x, bit value)
	{
		int y=0;
		if (value==1)
			{
				for(y=0;y<10;y++)
				{
					case(x)
					{
						0: coord[y] = coord[y]|0x01;
							break;
						1:coord[y] = coord[y]|0x02;
							break;
						2:coord[y] = coord[y]|0x04;
							break;
						3:coord[y] = coord[y]|0x08;
							break;
						4:coord[y] = coord[y]|0x10;
							break;
						5:coord[y] = coord[y]|0x20;
							break;
						6:coord[y] = coord[y]|0x40;
							break;
						7:coord[y] = coord[y]|0x80;
							break;
					}
				}
				else
					{
						for(y=0;y<10;y++)
						{
							case(x)
							{
								0: coord[y] = coord[y]|0xFE;
									break;
								1:coord[y] = coord[y]|0xFD;
									break;
								2:coord[y] = coord[y]|0xFB;
									break;
								3:coord[y] = coord[y]|0xF7;
									break;
								4:coord[y] = coord[y]|0xEF;
									break;
								5:coord[y] = coord[y]|0xDF;
									break;
								6:coord[y] = coord[y]|0xBF;
									break;
								7:coord[y] = coord[y]|0x7F;
									break;
							}
						}

		}
	}

void ClearData()
	{
		int i;
		for(i=0;i<10;i++)
			coord[i] = 0x00;
	}
