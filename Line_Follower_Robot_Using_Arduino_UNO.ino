
// Line Follower Robot using Arduino UNO + L298N + 2 IR Sensors

// Motor driver pins
#define ENA 9     // Enable pin for Left motor (PWM)
#define IN1 8     // Left motor
#define IN2 7     // Left motor 
#define IN3 6     // Right motor 
#define IN4 5     // Right motor 
#define ENB 10    // Enable pin for Right motor (PWM)

// IR sensor pins
#define LEFT_IR 2
#define RIGHT_IR 3

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);

  Serial.begin(9600);
}

void loop() {
  int leftSensor = digitalRead(LEFT_IR);
  int rightSensor = digitalRead(RIGHT_IR);

  Serial.print("Left: ");
  Serial.print(leftSensor);
  Serial.print(" | Right: ");
  Serial.println(rightSensor);

  if (leftSensor == HIGH && rightSensor == HIGH) {
    // Both sensors on white area → Move forward
    forward();
  }
  else if (leftSensor == LOW && rightSensor == HIGH) {
    // Left sensor on black line → Turn left
    turnLeft();
  }
  else if (leftSensor == HIGH && rightSensor == LOW) {
    // Right sensor on black line → Turn right
    turnRight();
  }
  else {
    // Both sensors on black line → Stop
    stopRobot();
  }
}

// ================== Functions ==================

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200); // Speed 0-255
  analogWrite(ENB, 200);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 180);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 180);
  analogWrite(ENB, 0);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
