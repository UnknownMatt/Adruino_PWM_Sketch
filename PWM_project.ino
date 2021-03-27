// CODE BY MATTIAS FLOYD

int pwm = 4; // assigns pin for variable pwm
float t1 = 0;   // declares variable t1
float t2 = 0;   // declares variable t2
float per = 0; //percent power
int frq = 10000; //frequency (reccomended between 500-32000) arduino math breaks after 32000 for some reason (higher number means lower functioning frequency because it's length in uS)
void setup()  // setup loop
{
  pinMode(pwm, OUTPUT); // declares pin 12 as output
  Serial.begin(9600); //Starts Serial
  t1 = (frq*(per/100)); //calculates on time
  t2 = (frq-(frq*(per/100))); //calculates off time

  
  Serial.println("   ");  //This Section Displays the values over serial
  Serial.print("Pulse width: ");
  Serial.print(per);
  Serial.print("%");
  Serial.print("   ");
  Serial.print("High time: ");
  Serial.print(t1);
  Serial.print("uS");
  Serial.print("   ");
  Serial.print("Low time: ");
  Serial.print(t2);
  Serial.print("uS");
  Serial.println("   ");
}
void loop()
{
   String in = "";
  while (Serial.available()<=0) //Checks for no serial input
  {
  digitalWrite(pwm, HIGH); // sets pin 12 HIGH
  delayMicroseconds(t1);   // waits for t1 uS (high time)
  digitalWrite(pwm, LOW);  // sets pin 12 LOW
  delayMicroseconds(t2);   // waits for t2 uS (low time)
  }

  
   if (Serial.available()>0) //Checks for serial Input
  {
  
    while (Serial.available()>0) //loop while serial is being inputed
    {
  in += char(Serial.read()); //puts the serial charecters into the String 
  delay(250);
  }
   int val = in.toInt(); //converts the input string into a integer
   per = val;
  }

  t1 = (frq*(per/100));  //calculates on time
  t2 = (frq - (frq*(per/100))); //calculates off time 

  Serial.println("   ");    //This Section Displays the values over serial
  Serial.print("Pulse width: ");
  Serial.print(per);
  Serial.print("%");
  Serial.print("   ");
  Serial.print("High time: ");
  Serial.print(t1);
  Serial.print("uS");
  Serial.print("   ");
  Serial.print("Low time: ");
  Serial.print(t2);
  Serial.print("uS");
  Serial.println("   ");
  
 delay(100); //delay for smoothness 


 
}
