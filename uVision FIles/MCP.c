#include<reg52.h>
#include<DisplayLibrary.h>
#include<CoordinateToByte.h>


unsigned char bytedata [10] = { 0x00,
																0x00,
																0x00,
																0x00,
																0x00,
																0x00,
																0x00,
																0x00,
																0x00,
																0x00};

unsigned char coord [10][8] = {
				{0,0,0,0,0,0,0,1},
				{0,0,0,0,0,0,1,1},
				{0,0,0,0,0,1,1,1},
				{0,0,0,0,1,1,1,1},
				{0,0,0,0,0,1,1,1},
				{1,0,0,0,0,1,1,1},
				{1,1,0,0,0,1,1,1},
				{1,1,1,0,0,1,1,1},
				{1,0,1,0,1,0,1,0},
				{0,1,0,1,0,1,0,1}};

																

	

void main()
{
	while(1)
	{
		c2b_all(coord,bytedata);
		displayfunction(bytedata);
	}
}



