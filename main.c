
int Led_High_dB = 13 ;// define LED Interface 
int Led_Medium_dB = 12 ;// define LED Interface 
int Led_Low_dB = 8 ;// define LED Interface 

int buttonpin = A0; // define A0 Sensor Interface 
int digitalReadPin = 2;//define D2 digital sensor interface
int valDigital = 0;
int val = 0;// define numeric variables val (ADC value)
int dB, PdB; //the variable that will hold the value read from the microphone each time

void setup () 
{ 
  Serial.begin(9600);
  
  pinMode (Led_High_dB, OUTPUT) ;// define LED as output interface 
  pinMode (Led_Medium_dB, OUTPUT) ;// define LED as output interface 
  pinMode (Led_Low_dB, OUTPUT) ;// define LED as output interface 
  
  pinMode (buttonpin, INPUT) ;// output interface A0 is defined sensor 
  pinMode (digitalReadPin, INPUT) ;// output interface A0 is defined sensor 
} 


//Start main loop
void loop () 
{ 
  
  PdB = dB; //Store the previous of dB here
  
  val = analogRead(buttonpin) ;// digital interface will be assigned a value of pin 3 to read val 
  Serial.println ( val);//Print ADC value of microphone for initial calculation 
  //Serial.println ("SOUND LEVEL(ADC): " + val);//Print ADC value of microphone for initial calculation 

  //valDigital = digitalRead(digitalReadPin);
  //Serial.println(valDigital);
  
  dB = (val+83.2073) / 11.003; //Convert ADC value to dB using Regression values
  //if (PdB!=dB)
  //  Serial.println (dB);

  //turn on led on adc value
  if (val >= 930) // When the sound detection module detects a signal, LED flashes 
  { 
    digitalWrite (Led_High_dB, HIGH); 
    delay(50);//wait for 1 sec
    digitalWrite (Led_High_dB, LOW);
    
  } else if((val > 920) && (val < 930) ) { 
    
    digitalWrite (Led_Medium_dB, HIGH); 
    delay(50);//wait for 1 sec
    digitalWrite (Led_Medium_dB, LOW);

  } else if(val < 920) { 
    
    digitalWrite (Led_Low_dB, HIGH); 
    delay(50);//wait for 1 sec
    digitalWrite (Led_Low_dB, LOW);
 
  } 

  

  //turn on LED on dB(deciBell) value
  /*
  if (dB>60)
  {
    digitalWrite(Led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    digitalWrite(Led, LOW); 
  }
  */


  //wait for 10 miliseconds on each loop
  //delay(500); 
}
//end void loop
