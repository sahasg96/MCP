sbit P_UP = P3^7;
sbit P_DOWN = P3^6;
sbit P_RIGHT = P3^5;
sbit P_LEFT = P3^4;
// Interrupt pin is P3.3

bit UP=0;
bit DOWN=0;
bit LEFT=0;
bit RIGHT=0;
//bit InputFlag=0;

UpdateInput()
	{
	//	if(InputFlag==0)
		
				delay(100);
				UP=P_UP;
				DOWN=P_DOWN;
				RIGHT=P_RIGHT;
				LEFT=P_LEFT;
	//			InputFlag=1;
		

	}

/* ClearInputFlag()
	{
		UP=DOWN=RIGHT=LEFT=InputFlag=0;
	}

	
unsigned char InputValue()
	{
		if ( UP == 1 )
			return 1;
		else if ( RIGHT == 1 )
			return 2;
		else if ( DOWN == 1 )
			return 3;
		else if ( LEFT == 1 )
			return 4;
		else
			return 0;
	}
*/