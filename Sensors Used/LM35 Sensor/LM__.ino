int val; // declaring valriable to store the sensor readings

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  val = analogRead(A0);                     // taking the input from the analog pin A0
  
  //Serial.print(val);                      // Just to check the sensor readings
  
  float mv = ( val/1024.0)*5000;           // equation to covert the sensor values into known format
  float cel = mv/10;                       // to change the readings into celcius scale
  float farh = (cel*9)/5 + 32;             // to change the readings into farhanite scale
  Serial.print("TEMPRATURE in celcius= ");
  Serial.print(cel);
  
  Serial.println();
  delay(1000);


Serial.print("TEMPRATURE in Farhanite= ");
Serial.print(farh);

Serial.println();

}
