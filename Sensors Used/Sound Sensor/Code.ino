int soundSensor=8;  // Input pin for sound sensor

boolean LEDStatus=false; // initially the LED is set to off position

void setup() {
 pinMode(soundSensor,INPUT);
 pinMode(LED_BUILTIN,OUTPUT); // Using the built IN LED on Arduino UNO

}

void loop() {

  int SensorData=digitalRead(soundSensor); 
  if(SensorData==1){ // As soon as the input detects any high sound & LED is off it is set to ON state

    if(LEDStatus==false){
        LEDStatus=true;
        digitalWrite(LED_BUILTIN,HIGH); // to show the User the input sound is detected
    }
    else{
        LEDStatus=false;
        digitalWrite(LED_BUILTIN,LOW);
    }
  }
 } 
