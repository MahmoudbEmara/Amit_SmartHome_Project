
#define triacpulse 3
//int dimming = 128;
void setup() {
  // put your setup code here, to run once:
//pinMode(A0,INPUT);
pinMode(triacpulse, OUTPUT);
attachInterrupt(0,acon,FALLING);
}

void loop() {
//int sensorValue = map(analogRead(A0),0,1023,0,100);
//  dimming=75*sensorValue;
  
}
void acon(){

//delayMicroseconds(dimming);
digitalWrite(triacpulse,HIGH);
delayMicroseconds(10);
digitalWrite(triacpulse,LOW);

  
}
