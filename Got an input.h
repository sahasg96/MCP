
// ********* FUNCTION CALLED AS SOON AS WE GET AN INPUT ON A PUSHBUTTON *****************

xH=0;
xT=0;
yH=3;
yT=0;

void movement (int length, int &xH, int &yH, int &xT, int &yT)
{
	while (1)
	{
		if ( UP == 1 )
			inputPin = 1;
		else if ( RIGHT == 1 )
			inputPin = 2;
		else if ( DOWN == 1 )
			inputPin = 3;
		else if ( LEFT == 1 )
			inputPin = 4;
			
		// ************** if none of the push buttons are high it will retain ************
		// ************** the previous value of inputPin *********************************
		
		switch (inputPin)  // left,right,up,down
		{
	    
	    		// UP
	    		case 1: if (!deadend_row(xH-1))
	                		xH=xH-1;
	             		else
	             			gameOver();
	             	
	             	// RIGHT
	             	case 2: if (!deadend_col(yH+1))
	                		yH=yH+1;
	             		else
	             			gameOver();
	             	
	             	// DOWN
	             	case 3: if (!deadend_row(xH+1))
	                		xH=xH+1;
	             		else
	             			gameOver();
	             			
	             	// LEFT
	             	case 4: if (!deadend_col(yH-1))
	                		yH=yH-1;
	             		else
	             			gameOver();
	        }
	        
		UpdateBit(coord,1,xH,yH);
		UpdateBit(coord,0,xT,yT);
        }
}

int deadend_row (int n)
{
	if (n<0||n>9)
		return 0;
	else 
		return 1;
}
int deadend_col (int n)
{
	if (n<0||n>7)
		return 0;
	else 
		return 1;
}
