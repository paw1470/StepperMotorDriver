#include <Arduino.h>
#include <Stepper.h>

const int stepsPerRevolution = 200; 

int leftButton = 4;
int centerButton = 3;
int rightButton = 2;
int led = 13;
int ledStep = 5;

Stepper myStepper(stepsPerRevolution, 6, 7, 8, 9);

enum Mode{
  ROTATION,
  STEP
};

enum Direction{
  FORWARD,
  BACKWARD,
  STOP
};

Mode mode;
Direction direction;

void stepperStepWithLed(int value){
  digitalWrite(ledStep, HIGH);
  myStepper.step(value);
  digitalWrite(ledStep, LOW);
}

int calculateSensorValue(){
  int sensorValue = analogRead(A3);
  int speed = map(sensorValue, 0, 1023, 1, 100);
  Serial.println("Analog sensor value: " + String(sensorValue)+ "  Speed: " + String(speed));
  return speed;
}

void setSpeed(){
  myStepper.setSpeed(calculateSensorValue());
}

void stepForward(){
  Serial.println("One step forward");
  stepperStepWithLed(1);
}

void stepBackward(){
  Serial.println("One step backward");
  stepperStepWithLed(-1);
}

void forward(){
  Serial.println("Rotate forward");
  stepperStepWithLed(stepsPerRevolution);
}

void backward(){
  Serial.println("Rotate backward");
  stepperStepWithLed(-stepsPerRevolution);
}

void changeMode(){
  direction = Direction::STOP;
  if(mode == Mode::STEP){
    mode = Mode::ROTATION;
    digitalWrite(led, LOW);
  } else if(mode == Mode::ROTATION){
    mode = Mode::STEP;
    digitalWrite(led, HIGH);
  }
}


void rotation(){
  if(direction == Direction::FORWARD){
    forward();
  } else if(direction == Direction::BACKWARD){
    backward();
  }
}

void step(){
  if(direction == Direction::FORWARD){
    stepForward();
  } else if(direction == Direction::BACKWARD){
    stepBackward();
  }
  direction = Direction::STOP;
  delay(150);
}

void checkDirection(){
  boolean left = digitalRead(leftButton);
  boolean right = digitalRead(rightButton);
  if(!left && !right){
      // Serial.println("Both buttons pressed");
      direction = Direction::STOP;
  } else if (!left){
      // Serial.println("Left button pressed");
      direction = Direction::BACKWARD;
  }
  if(!right){
      // Serial.println("Right button pressed");
      direction = Direction::FORWARD;
  }
}

void setup() {
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(centerButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(ledStep, OUTPUT);
  mode = Mode::STEP;
  direction = Direction::STOP;
  digitalWrite(led, HIGH);
  digitalWrite(ledStep, LOW);
  Serial.begin(9600);
  delay(500);
  attachInterrupt(digitalPinToInterrupt(centerButton), changeMode, FALLING);
}

void loop() {
  checkDirection();
  if(direction != Direction::STOP){
    setSpeed();
    if(mode == Mode::ROTATION){      
      rotation();
    } else if (mode == Mode::STEP){
      step();
    }
  }
}