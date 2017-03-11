#include <SoftwareSerial.h>

SoftwareSerial BTserial(11, 10); // RX, TX
int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
int turnl = 12;
int turnr = 13;
char A;

void setup() {
  Serial.begin(115200);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(turnl, INPUT);
  pinMode(turnr, INPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  digitalWrite(turnl, LOW);
  digitalWrite(turnr, LOW);
  BTserial.begin(115200);
}

void loop() {
  /*String t; //string to hold data from BT module 
  while(mySerial.available()) { //keep reading bytes while they are still more in the buffer
  Serial.write(mySerial.read());
  mySerial.write(mySerial.read());
    char t = mySerial.read();
  }
  
  //if(t.length()) { //if string is not empty do the following
    if (t == "A")
    digitalWrite(led, HIGH);
    else if (t == "B")
    digitalWrite(led, LOW);
*/
if(BTserial.available())
  A = BTserial.read();

    if (A == 'F')
      digitalWrite(relay1, HIGH);
        else
          digitalWrite(relay1, LOW);
    if (A == 'B')
      digitalWrite(relay2, HIGH);
        else 
          digitalWrite(relay2, LOW); 
    if ((A == 'L') && (digitalRead(turnl) == LOW))
      digitalWrite(relay3, HIGH);
        else
          digitalWrite(relay3, LOW);
    if ((A == 'R')&&(digitalRead(turnr) == LOW))
      digitalWrite(relay4, HIGH);
        else 
          digitalWrite(relay4, LOW);  
}
