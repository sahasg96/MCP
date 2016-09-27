#include<reg52.h>
#include<DisplayLibrary.h>
#include<CoordinateToByte.h>


unsigned char bytedata [10] = { 0x01,
																0x02,
																0x04,
																0x08,
																0x10,
																0x20,
																0x40,
																0x80,
																0xaa,
																0x55};

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



