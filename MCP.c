#include<reg52.h>
#include<DisplayLibrary.h>



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

																

	

void main()
{
	while(1)
	displayfunction(bytedata);
}



