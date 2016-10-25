
unsigned int xH=3;
unsigned int xT=0;
unsigned int yH=0;
unsigned int yT=0;

bit gameOver = 0;
bit value = 1;

unsigned char x1=5,y1=0,x2=2,y2=4,x3=5,y3=8;

bit f1=0,f2=0,f3=0;


bit Eat_Fruit()
	{
		if(xH==x1 && yH==y1 && f1==0)
			{
				f1=1;
			 	return 1;
			}
		else if(xH==x2 && yH==y2 && f2==0)
			{
			f2=1;
			return 1;
			}
		else if(xH==x3 && yH==y3 && f3==0)
			{
			f3=1;
			return 1;
			}
			else
				return 0;
	}

void fruit_disp()
	{
		if (f1==0)
			UpdateBit(x1,y1,value);
		else
			UpdateBit(x1,y1,0);

		if (f2==0)
			UpdateBit(x2,y2,value);
		else
			UpdateBit(x2,y2,0);

		if (f3==0)
			UpdateBit(x3,y3,value);
		else
			UpdateBit(x3,y3,0);

			value = ~value;
	}

void UpdateTail()
	{
	unsigned int xT_temp = xT;

	if (BitCheck(xT+1,yT)==1)
		xT++;
	else if (BitCheck(xT-1,yT)==1 && xT>0)
		xT--;

	if (BitCheck(xT_temp,yT+1)==1)
		yT++;
	else if (BitCheck(xT_temp,yT-1)==1 && yT>0)
		yT--;
}

bit Obstacle(unsigned int x, unsigned int y)
	{
		if((xH==x||xH==x+1)&&(yH==y||yH==y+1))
			return 1;
		else
			return 0;
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
									break;

	             	// RIGHT
	        case 2: if (!deadend_col(xH+1))
	                		xH=xH+1;
	             		else
	             				gameOver=1;
									break;

	             	// DOWN
	        case 3: if (!deadend_row(yH+1))
	                		yH=yH+1;
	             		else
	             				gameOver=1;
									break;

	             	// LEFT
	        case 4: if (!deadend_col(xH-1))
	                		xH=xH-1;
	             		else
	             				gameOver=1;
									break;
	  }

		UpdateBit(xH,yH,1);
		UpdateBit(xT,yT,0);
		
		if(Eat_Fruit())
					return gameOver;
		
		UpdateTail();

		if(Obstacle(0,1)==1||Obstacle(3,4)==1||Obstacle(6,7)==1)
				gameOver=1;

		return gameOver;
}
