/* This code works with 4 channel Capacitive touch buttons module or 4 buttons/switches
 * It displays the current state of the buttons on the serial monitor
 */

#define Button1 2 //Buttons pins
#define Button2 3
#define Button3 4
#define Button4 5

bool Button1_State, Button2_State, Button3_State, Button4_State; //Buttons states

String Data; //To regroup stats to be displayed on the serial monitor

void setup() {
  
  Serial.begin(9600);     //Set the serial communications
  pinMode(Button1,INPUT); //Set the pin modes
  pinMode(Button2,INPUT);
  pinMode(Button3,INPUT);
  pinMode(Button4,INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  Button1_State = digitalRead(Button1); //Reading different current states and store them
  Button2_State = digitalRead(Button2);
  Button3_State = digitalRead(Button3);
  Button4_State = digitalRead(Button4);

  Data = String(Button1_State) + "\t" + String(Button2_State) + "\t" + String(Button3_State) + "\t" + String(Button4_State); //Regroup and convert to string

  Serial.println(Data); //Display on the serial monitor
  delay(1000);

  if(digitalRead(Button2) == 1){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    }

  
  
}
