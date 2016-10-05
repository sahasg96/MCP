#include<reg52.h>
#include<DisplayLibrary.h>
#include<UpdateCoordinate.h>


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
	void main()
{
	while(1)
	{
		c2b_all(coord,bytedata);
		displayfunction(bytedata);
		//UpdateBit(4,2,1);
		UpdateColoumn(1,1);
		UpdateRow(3,1);
		
	}
}



