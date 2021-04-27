
// initial Time display is set at 12:59:45 PM (Default)
int h=12;
int m=59;
int s=45;
int flag=1; //PM

static uint32_t last_time, now = 0; // For Real Time Clock


void setup()
{
   Serial.begin(9600);
   now=millis(); // read RTC initial value
}


void loop()
{ 
 Serial.print("Time ");
 if(h<10)Serial.print("0");// Hours always 2 digits
 Serial.print(h);
 Serial.print(":");

 if(m<10)Serial.print("0"); //Minutes
 Serial.print(m);
 Serial.print(":");
 
 if(s<10)Serial.print("0"); //Seconds
 Serial.print(s);
 
 if(flag==0) Serial.print(" AM");
 if(flag==1) Serial.print(" AM");
 Serial.println( );
 
 while ((now-last_time) < 1000 ) // wait1000ms
 {
  now=millis();
 }

 last_time=now; // prepare for next loop 
 s=s+1; //increment sec. counting

 if(s==60){
  s=0;
  m=m+1;
 }
 if(m==60)
 {
  m=0;
  h=h+1;
 }
 if(h==13)
 {
  h=1;
  flag=flag+1;
  if(flag==2)flag=0;
 }
 
}

