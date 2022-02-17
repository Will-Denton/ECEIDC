#define Rx 17
#define Tx 16

char outgoing = 'A'; //Char to be sent

void setup() {
  pinMode(6, INPUT); //Button
  pinMode(10, OUTPUT); //Green LED
  pinMode(8, OUTPUT); // Red LED

  digitalWrite(8,LOW); //Set inital LED states to off
  digitalWrite(10,LOW);
  
  Serial.begin(9600); //Open the arduino's serial montitor
  Serial2.begin(9600); //Open the XBee serial monitor
  
  delay(500);
}

void loop(){

  //Send Message
  if(digitalRead(6) == HIGH){ //If button is pressed
    Serial2.print(outgoing); //Send char to the XBee
    digitalWrite(8, HIGH); //Turn Red LED on
    delay(100);
  } else {
    digitalWrite(8, LOW); //If not pressed turn the LED off
  }

  //Recieve Message
  if(Serial2.available()){ //If the XBee Receives a message
    char incoming = Serial2.read(); //Write the char to incoming
    Serial.println(incoming); //Print the char on the Arduino's serial
    digitalWrite(10, HIGH); //Turn the Green LED on
    delay(200); 
  } else {
    digitalWrite(10, LOW); //If not receiving a signal keep LED off
  }
  
  delay(50);
}
