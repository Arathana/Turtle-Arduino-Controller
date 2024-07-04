const int buttonPin1 = 2;  // pin for penup button
const int buttonPin2 = 3;  // pin for pendown button
const int colorButton1 = 8;  // pin for red button
const int colorButton2 = 9;  // pin for green button
const int colorButton3 = 6;  // pin for blue button
const int colorButton4 = 7;  // pin for yellow button
const int stampButton = 4;  // pin for stamp button
const int dotButton = 5;  // pin for dot button

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(colorButton1, INPUT);
  pinMode(colorButton2, INPUT);
  pinMode(colorButton3, INPUT);
  pinMode(colorButton4, INPUT);
  pinMode(stampButton, INPUT);
  pinMode(dotButton, INPUT);
  Serial.begin(9600);
}

void loop() {
  int joy1X = analogRead(A3);  // Read joystick 1 X-axis
  int joy2X = analogRead(A0);  // Read joystick 2 X-axis
  
  int forwardBackward = map(joy1X, 0, 1023, 50, -50); // Adjust range as needed
  int turn = map(joy2X, 0, 1023, 50, -50); // Adjust range as needed
  
  // Ensure values are within acceptable ranges
  forwardBackward = constrain(forwardBackward, -50, 50);
  turn = constrain(turn, -50, 50);
  


  Serial.print(forwardBackward);
  Serial.print(",");
  Serial.println(turn);

  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int colorState1 = digitalRead(colorButton1);
  int colorState2 = digitalRead(colorButton2);
  int colorState3 = digitalRead(colorButton3);
  int colorState4 = digitalRead(colorButton4);
  int stampState = digitalRead(stampButton);
  int dotState = digitalRead(dotButton);
  
  if (buttonState1 == HIGH) {
    Serial.println("PENUP");  // Send command to lift pen
    delay(100);  // Debounce delay
  }
  
  if (buttonState2 == HIGH) {
    Serial.println("PENDOWN");  // Send command to lower pen
    delay(100);  // Debounce delay
  }

  if (colorState1 == HIGH) {
    Serial.println("COLORRED");  // Send command to change color to red
    delay(100);  // Debounce delay
  }
  
  if (colorState2 == HIGH) {
    Serial.println("COLORGREEN");  // Send command to change color to green
    delay(100);  // Debounce delay
  }

  if (colorState3 == HIGH) {
    Serial.println("COLORBLUE");  // Send command to change color to blue
    delay(100);  // Debounce delay
  }

  if (colorState4 == HIGH) {
    Serial.println("COLORYELLOW");  // Send command to change color to yellow
    delay(100);  // Debounce delay
  }

  if (stampState == HIGH) {
    Serial.println("STAMP");  // Send command to make a stamp
    delay(100);  // Debounce delay
  }

  if (dotState == HIGH) {
    Serial.println("DOT");  // Send command to make a dot
    delay(100);  // Debounce delay
  }
  
  delay(100);  // Adjust delay as needed for stable serial communication
}