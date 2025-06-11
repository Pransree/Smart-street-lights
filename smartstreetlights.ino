const int pirPin = 2;     // PIR sensor pin
const int ledPin1 = 9;     // PWM pin connected to LED
const int ledPin2 = 4;     // PWM pin connected to LED
const int ldrPin = A0;    // LDR sensor pin

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Read LDR value
  int motionDetected = digitalRead(pirPin); // Read PIR sensor
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Set threshold: adjust 500 if needed
  if (ldrValue > 400) {  // DARK condition (night)
    if (motionDetected == HIGH) {
      analogWrite(ledPin1, 255);
      analogWrite(ledPin2, 255);
      // Full brightness when motion detected
    } else {
      analogWrite(ledPin1, 50); 
      delay(5000); 
      analogWrite(ledPin2, 50);
      // Dim light when no motion
    }
  } else {  // BRIGHT condition (daytime)
    analogWrite(ledPin1, 0);  
    analogWrite(ledPin2, 0);// LED OFF during daytime
  }

}