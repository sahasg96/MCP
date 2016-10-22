
unsigned char xH=0, xT=0, yH=3, yT=0;

bit gameOver = 0;

bit deadend_row (unsigned char n)
{
	if (n<0||n>7)
		return 1;
	else
		return 0;
}

bit deadend_col (unsigned char n)
{
	if (n<0||n>9)
		return 1;
	else
		return 0;
}

bit movement (unsigned char inputPin)
{
		// ************** if none of the push buttons are high it will retain ************
		// ************** the previous value of inputPin *********************************
		switch (inputPin)  // left,right,up,down
		{

	    		// UP
	    		case 1: if (!deadend_row(xH-1))
	                		xH=xH-1;
	             		else
	             				gameOver=1;

	             	// RIGHT
	        case 2: if (!deadend_col(yH+1))
	                		yH=yH+1;
	             		else
	             				gameOver=1;

	             	// DOWN
	        case 3: if (!deadend_row(xH+1))
	                		xH=xH+1;
	             		else
	             				gameOver=1;

	             	// LEFT
	        case 4: if (!deadend_col(yH-1))
	                		yH=yH-1;
	             		else
	             				gameOver=1;
	  }
		UpdateBit(xH,yH,1);
		UpdateBit(xT,yT,0);
		return gameOver;
}
