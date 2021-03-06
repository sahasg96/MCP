
unsigned char xH=0, xT=0, yH=4, yT=0;
unsigned char coord[10]={0xF0,0,0,0,0,0,0,0,0,0};

sbit UP = P3^0;
sbit RIGHT = P3^1;
sbit DOWN = P3^2;
sbit LEFT = P3^3;
unsigned char inputPin;

void buttonPressed () interrupt 1
{
	if ( UP == 1 )
		inputPin = 1;
	else if ( RIGHT == 1 )
		inputPin = 2;
	else if ( DOWN == 1 )
		inputPin = 3;
	else if ( LEFT == 1 )
		inputPin = 4;
}

void movement (unsigned char length, unsigned char &xH, unsigned char &yH, unsigned char &xT, unsigned char &yT)
{
	while (1)
	{
		// ************** if none of the push buttons are high it will retain ************
		// ************** the previous value of inputPin *********************************
		
		switch (inputPin)  // left,right,up,down
		{
	    		// UP
			case 1: if (!deadend_row(xH-1))
					xH=xH-1;
				else
					gameOver();
				break;

			// RIGHT
			case 2: if (!deadend_col(yH+1))
					yH=yH+1;
				else
					gameOver();
				break;

			// DOWN
			case 3: if (!deadend_row(xH+1))
					xH=xH+1;
				else
					gameOver();
				break;

			// LEFT
			case 4: if (!deadend_col(yH-1))
					yH=yH-1;
				else
					gameOver();
				break;
			default: gameOver();
	  	}
		Update(xH,yH,1);       // ACTIVATE xH,yH cell
		Update(xT,yT,0);       // DEACTIVATE xT,yT cell
   	}
}

bit deadend_row (unsigned char n)
{
	if (n<0||n>9)
		return 0;
	else 
		return 1;
}

bit deadend_col (unsigned char n)
{
	if (n<0||n>7)
		return 0;
	else 
		return 1;
}

void Update (unsigned int x, unsigned int y, bit value)
{
  	if (value)
  	{
		switch(y)
		{
			case 0: coord[x] = coord[x] | 0x80;		break;
					   
			case 1: coord[x] = coord[x] | 0x40; 	break;
	
			case 2: coord[x] = coord[x] | 0x20;		break;
					
			case 3: coord[x] = coord[x] | 0x10; 	break;
					
			case 4: coord[x] = coord[x] | 0x08; 	break;
				
			case 5: coord[x] = coord[x] | 0x04; 	break;
					
			case 6: coord[x] = coord[x] | 0x02; 	break;
						
			case 7: coord[x] = coord[x] | 0x01; 	break;
						
			default: gameOver();
		  }
	}
	else
	{
		switch(y)
		{
			case 0: coord[x] = coord[x] & ~0x80; 	break;
						  
			case 1: coord[x] = coord[x] & ~0x40; 	break;
						
			case 2: coord[x] = coord[x] & ~0x20; 	break;
						
			case 3: coord[x] = coord[x] & ~0x10; 	break;
						
			case 4: coord[x] = coord[x] & ~0x08; 	break;
						
			case 5: coord[x] = coord[x] & ~0x04; 	break;
						
			case 6: coord[x] = coord[x] & ~0x02; 	break;
						
			case 7: coord[x] = coord[x] & ~0x01; 	break;
						
			default: gameOver();
		  }
	}	
}
