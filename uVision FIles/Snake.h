
unsigned int xH=3;
unsigned int xT=0;
unsigned int yH=0;
unsigned int yT=0;


bit gameOver = 0;

void UpdateTail()
{	
	if (BitCheck(xT+1,yT)==1) 
		xT++;
	else if (BitCheck(xT-1,yT)==1 && xT>0) 
		xT--;

	if (BitCheck(xT,yT+1)==1)
		yT++;
	else if (BitCheck(xT,yT-1)==1 && yT>0)
		yT--;
	
	
}

bit deadend_row (unsigned char n)
{
	if (n<0||n>9)
		return 1;
	else
		return 0;
}

bit deadend_col (unsigned char n)
{
	if (n<0||n>7)
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
	    		case 1: if (!deadend_row(yH-1))
	                		yH=yH-1;
	             		else
	             				gameOver=1;
									UpdateTail();
									break;

	             	// RIGHT
	        case 2: if (!deadend_col(xH+1))
	                		xH=xH+1;
	             		else
	             				gameOver=1;
									UpdateTail();
									break;

	             	// DOWN
	        case 3: if (!deadend_row(yH+1))
	                		yH=yH+1;
	             		else
	             				gameOver=1;
									UpdateTail();
									break;

	             	// LEFT
	        case 4: if (!deadend_col(xH-1))
	                		xH=xH-1;
	             		else
	             				gameOver=1;
									UpdateTail();
									break;
	  }
		
		UpdateBit(xH,yH,1);
		UpdateBit(xT,yT,0);
		return gameOver;
}

