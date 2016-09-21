

int coord[8][8] = {{0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0}};
byte ByteData[8] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
int clkpin = 13;
int resetpin = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRD = B11111111;
  pinMode(clkpin, OUTPUT);
  pinMode(resetpin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  c2b_all(coord, ByteData);
  DisplayFunction(ByteData);
  
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");

}





void DisplayFunction(byte ByteData [8])
	{
		int rows=8;
		for(int i=0;i<=rows;i++)
			{
				PORTD = ByteData[i]; // dispalying 1 row at a time
                                Serial.println(ByteData[i]);
				CLK();
			}
		ResetCounter();
	}


void ClearDisplay()
	{
		int rows=8;
		for(int i=0;i<=rows;i++)
			{
				PORTD = 0x0;
				CLK();
			}
		ResetCounter();
	}
	
void ResetCounter()
	{
		digitalWrite(resetpin, HIGH);
		delay(5);
		digitalWrite(resetpin, LOW);
	}
	
void CLK()
	{
		digitalWrite(clkpin, HIGH);
		delayMicroseconds(5);
		digitalWrite(clkpin, LOW);
		delayMicroseconds(5);         // added
	}

byte c2b( int coord[8][8], int row)
	{	
		byte a = B00000000;				// This is the temporary byte value which will be returned
		for (int temp = 0; temp<=8; temp = temp +1)
			{	
				a = a<<1;				// left shift
				a = a + coord[temp][row];    //adding all the values of the row together
			}
		return a;
	}

void c2b_all(int coord[8][8], byte data[8])
	{
		for(int temp=0; temp<8; temp = temp +1)
			{
				 data[temp] =  c2b(coord, temp);
			}
	}

