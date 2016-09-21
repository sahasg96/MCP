int clk = 13;
int reset = 11;
int enb = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(reset, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(enb, OUTPUT);
  
  digitalWrite(enb, LOW);
  digitalWrite(reset,HIGH);
  delay(100);
  digitalWrite(reset,LOW);
  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(clk,LOW);
  delay(500);
  digitalWrite(clk,HIGH);
  delay(500);

}
