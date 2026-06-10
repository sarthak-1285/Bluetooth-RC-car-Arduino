// ============================================
//   Bluetooth Controlled RC Car - Arduino
//   Two DC Motors via L298N Motor Driver
// ============================================
//
// WIRING:
//  Bluetooth Module (HC-05/HC-06):
//    VCC → 5V, GND → GND
//    TX  → Arduino Pin 0 (RX)
//    RX  → Arduino Pin 1 (TX) [use voltage divider if needed]
//
//  L298N Motor Driver:
//    ENA → Pin 5  (PWM speed control - Left Motor)
//    IN1 → Pin 6  (Left Motor direction)
//    IN2 → Pin 7  (Left Motor direction)
//    IN3 → Pin 8  (Right Motor direction)
//    IN4 → Pin 9  (Right Motor direction)
//    ENB → Pin 10 (PWM speed control - Right Motor)
//
//  Bluetooth App Commands:
//    'F' = Forward   'B' = Backward
//    'L' = Left      'R' = Right
//    'S' = Stop
//    '0'-'9' = Speed (0=min, 9=max)
// ============================================

// --- Motor Driver Pins ---
const int ENA = 5;   // Left motor speed (PWM)
const int IN1 = 6;   // Left motor forward
const int IN2 = 7;   // Left motor backward
const int IN3 = 8;   // Right motor forward
const int IN4 = 9;   // Right motor backward
const int ENB = 10;  // Right motor speed (PWM)

// --- Speed Control (0–255) ---
int motorSpeed = 180;  // Default speed

// ============================================
void setup() {
  // Motor pins as OUTPUT
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);  // HC-05/HC-06 default baud rate
  stopCar();           // Ensure car is stopped on startup
}

// ============================================
void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    executeCommand(command);
  }
}

// ============================================
//   Command Dispatcher
// ============================================
void executeCommand(char cmd) {
  switch (cmd) {
    case 'F': moveForward();   break;
    case 'B': moveBackward();  break;
    case 'L': turnLeft();      break;
    case 'R': turnRight();     break;
    case 'S': stopCar();       break;

    // Speed control via digits 0–9
    default:
      if (cmd >= '0' && cmd <= '9') {
        // Map '0'→28, '9'→255
        motorSpeed = map(cmd - '0', 0, 9, 28, 255);
        // Apply new speed to running motors immediately
        analogWrite(ENA, motorSpeed);
        analogWrite(ENB, motorSpeed);
      }
      break;
  }
}

// ============================================
//   Motor Control Functions
// ============================================

void moveForward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  // Left motor backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Right motor backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  // Left motor backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Right motor backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
