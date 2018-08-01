  
    #include "font.h"              // defining the alphabet
    #include <Wire.h>              //I2C communication
    #include "RTClib.h"            // DS 3231 library

RTC_DS3231 rtc;

  char daysOfTheWeek[7][12] = {"Sunday    ", "Monday    ", "Tuesday   ", "Wednesday ", "Thursday  ", "Friday    ", "Saturday  "};
  
  const int LEDpins[] = {2,3,4,5,6,7,8};          // define the Arduino LED pins in use
  int rows= 7;		    // number of LEDs    
  
   const int charHeight = 7;
   const int charWidth = 5;
  int timer = 200 ;
  
  
  
  const int sensorPIN = 10;  // define the Arduino sensor pin
  int sensVal;  // variable to store the value coming from the sensor
  int i;
  String top_str;
  String bottom_str;
  int second,minute,hour,year,month,day,dayOfTheWeek,dow ;
  long previousMillis = 0;
  long interval = 1000;
  int Moment ;
  void setup()
  {
           
   
    pinMode(11, OUTPUT);
    pinMode(A2, OUTPUT);
    digitalWrite(A2, HIGH);
    pinMode(10, INPUT);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    for (i = 0; i < rows; i++)
      pinMode(LEDpins[i], OUTPUT);    
    
    if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    //Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  //delay(500);
  }
  void loop()
  {
   DateTime now = rtc.now();
     second = now.second();
     minute = now.minute();
     hour = now.hour(); 
     year = now.year();
     month = now.month();
     day = now.day();
   dow = now.dayOfTheWeek();
   
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;
     
  }
   Moment = (millis() - previousMillis)/10; 
   
  switch(second)
{
        case 0 ... 1:
        top_str =  "   T h e   ";        //String(Moment); 
        bottom_str = "simplest";
        
        break;
         case 2 ... 3:
        top_str = "  Arduino  ";
        bottom_str = "  P O V ";
       
        break;
        case 4 ... 5:
        top_str = " Propeller";
        bottom_str = " clock  ";
        
        break;
        case 6 ... 7:
        top_str = "with real";
        bottom_str = "time clock";
       
        break;
        
              
        case 8 ... 9:
        top_str = "  Arduino  ";
        bottom_str = "pro mini";
        
        break;
        case 10 ... 11:
        top_str = "WIRELESS";
        bottom_str = " POWER  ";
       
        break;
        
        case 12 ... 18:
         top_str = "Transmission";
          bottom_str = "     (((";
         switch(Moment)
{

        case 0 ... 5 :
        
        bottom_str = "       (";
       
        break;

        case 6 ... 10 :
       
        bottom_str = "      ((";
       
        break; 

        case 11 ... 15 :
        
        bottom_str = "     (((";
       
        break;
        case 16 ... 20 :
        
        bottom_str = "    ((( ";
       
        break;
         case 21 ... 25 :
        
        bottom_str = "   (((  ";
       
        break;
        case 26 ... 30 :
        
        bottom_str = "  (((   ";
       
        break;
        case 31 ... 35 :
        
        bottom_str = " (((    ";
       
        break;
        case 36 ... 40 :
        
        bottom_str = "(((     ";
       
        break;
        case 41 ... 45 :
        
        bottom_str = "((      ";
       
        break;
        case 46 ... 50 :
        
        bottom_str = "(       ";
       
        break;
        case 51 ... 55 :
        
        bottom_str = ")       ";
       
        break;
        
        case 56 ... 60 :
        
        bottom_str = "))      ";
       
        break;
        case 61 ... 65 :
        
        bottom_str = ")))     ";
       
        break;
        case 66 ... 70 :
        
        bottom_str = " )))    ";
       
        break;
        case 71 ... 75 :
        
        bottom_str = "  )))   ";
       
        break;
        case 76 ... 80 :
        
        bottom_str = "   )))  ";
       
        break;
        case 81 ... 85 :
        
        bottom_str = "    ))) ";
       
        break;
        case 86 ... 90 :
        
        bottom_str = "     )))";
       
        break;
        case 91 ... 95 :
        
        bottom_str = "      ))";
       
        break;
        case 96 ... 100 :
        
        bottom_str = "       )";
       
        break;
}
        
        break;
        case 19 ... 20:
        top_str = "  Full  ";
        bottom_str = "description";
       
        break;
        case 21 ... 22:
        top_str = "    and   ";
        bottom_str = "tutorials";
       
        break;
        case 23 ... 24:
        top_str = "   are  "; 
        bottom_str = "coming soon";
       
        break;
        
        case 25 ... 26:
        top_str = " If you like"; 
        bottom_str = "this video";
       
        break;
        case 27 ... 28:
        top_str = "Please (Y)"; 
        bottom_str = "Thumbs up";
       
        break;
        case 29 ... 31:
        top_str = "    AND    "; 
        bottom_str = "SUBSCRIBE";
       
        break;
        
        case 32 ... 34:
        top_str = " Thanks for "; 
        bottom_str = "watching";
       
        break;
        case 35 :
        top_str = "   Holyba  "; 
        bottom_str = " Ferenc ";
         break;
         case 36 :
        top_str = "   HUNGARY  "; 
        bottom_str = "        ";
         break;

        case 37 :
        top_str = "   HUNGARY  "; 
        bottom_str = "       B";
         break;

        case 38:
        top_str = "   HUNGARY  "; 
        bottom_str = "      BU";
         break;
         
        case 39 :
        top_str = "   HUNGARY  "; 
        bottom_str = "     BUD";
         break;
         
        case 40:
        top_str = "   HUNGARY  "; 
        bottom_str = "    BUDA";
         break;
         
        case 41 :
        top_str = "   HUNGARY  "; 
        bottom_str = "   BUDAP";
         break;
         
        case 42 :
        top_str = "   HUNGARY  "; 
        bottom_str = "  BUDAPE";
         break;
         
        case 43 :
        top_str = "   HUNGARY  "; 
        bottom_str = " BUDAPES";
         break;
         
        case 44 ... 50:
                              
        
        top_str = "   HUNGARY  "; 
        bottom_str = "BUDAPEST";
        break;

        
        break;
        case 51 ... 54:
        top_str = String(year)+"-"+String(month)+"-"+String(day)+ " "; 
        bottom_str=klok();
      
        break;
        case 55 ... 59:
        top_str = daysOfTheWeek[dow]; 
        bottom_str=klok();
      
        break;
}
    
    
    while(digitalRead(sensorPIN) != 0)
    {
     digitalWrite(13, LOW);   // set the LED off
    }
    //digitalWrite(13, HIGH);   // set the LED on
    // printen klok letter voor letter


    for (int k=0; k<bottom_str.length(); k++){
      printLetter(bottom_str.charAt(k));
      }
    delay(4); // pauze tussen de teksten  
    for (int k=(top_str.length()-1);k>-1;  k--){
      printLetterboven(top_str.charAt(k));
      
      }  
  }
  
  String klok(){
   
    String result;
    String str1;
    String str2;
    String str3;
    
    if (hour < 10)
      str1 = "0"+String(hour);
    else
      str1 = String(hour);
    if (minute < 10)
      str2 = "0"+String(minute);
    else
      str2 = String(minute);
    if (second < 10)
      str3 = "0"+String(second);
    else
      str3 = String(second);
    result = str1+":"+str2+":"+str3;
    
    return result;
  }
  
void printLetterboven(char ch)
  {
    // make sure the character is within the alphabet bounds (defined by the font.h file)
    // if it's not, make it a blank character
    if (ch < 32 || ch > 126){
      ch = 32;
      }
    // subtract the space character (converts the ASCII number to the font index number)
    ch -= 32;
    // step through each byte of the character array
    for (int i=charWidth-1; i>-1; i--) {
      byte b = font[ch][i];
      // ventilator draai tegen de klok in
      for (int j=0; j<charHeight; j++) {
        digitalWrite(LEDpins[j], bitRead(b,j));
        }
      delayMicroseconds(timer);
      }
    //clear the LEDs
    for (i = 0; i < rows; i++)
      digitalWrite(LEDpins[i] , LOW);
    // space between letters
    delayMicroseconds(2*timer);;
  
  }  
  
  void printLetter(char ch)
  {
    // make sure the character is within the alphabet bounds (defined by the font.h file)
    // if it's not, make it a blank character
    if (ch < 32 || ch > 126){
      ch = 32;
      }
    // subtract the space character (converts the ASCII number to the font index number)
    ch -= 32;
    // step through each byte of the character array
    for (int i=0; i<charWidth; i++) {
      byte b = font[ch][i];
      // ventilator draai tegen de klok in
      for (int j=0; j<charHeight; j++) {
        digitalWrite(LEDpins[j], bitRead(b, 6-j));
        }
      delayMicroseconds(timer);;
      }
    //clear the LEDs
    for (i = 0; i < rows; i++)
      digitalWrite(LEDpins[i] , LOW);
    // space between letters
    delayMicroseconds(2*timer);;
  
  }
