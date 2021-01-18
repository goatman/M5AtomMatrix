
int thirdSensor = 0;    // digital sensor
int inByte = 0;         // incoming serial byte
  int switchPin = 12;
  int ledPin = 11;


void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);   // digital sensor is on digital pin 12
  //establishContact();  // send a byte to establish contact until receiver responds
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    analogWrite(ledPin, inByte);
  }

    thirdSensor = digitalRead(switchPin);

    Serial.println(thirdSensor);
    //Serial.println(inByte);

}




