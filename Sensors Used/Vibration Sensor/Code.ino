int vib_pin=9;  // input pin for sensor

void setup() {
  pinMode(vib_pin,INPUT); 
  pinMode(LED_BUILTIN,OUTPUT); // using built IM LED on Arduino UNO
}

void loop() {
  int val;
  val=digitalRead(vib_pin);
  if(val==1) // as soon as vibration is detected LED is set ON and OFF with a delsy of 1 Second
  {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
   }
   else
   digitalWrite(LED_BUILTIN,LOW);
}
