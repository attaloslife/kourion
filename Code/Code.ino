#define STEPPER_PIN_1 3
#define STEPPER_PIN_2 4
#define STEPPER_PIN_3 5
#define STEPPER_PIN_4 6
#define PotRead A1
#define dirPin 7
int step_number = 0;
bool clockwise = true;
int steps_completed = 0;
int read;
int direction;
//bool dir;
void setup() {
pinMode(STEPPER_PIN_1, OUTPUT);
pinMode(STEPPER_PIN_2, OUTPUT);
pinMode(STEPPER_PIN_3, OUTPUT);
pinMode(STEPPER_PIN_4, OUTPUT);
pinMode(PotRead, INPUT);
pinMode(dirPin,INPUT_PULLUP);

Serial.begin(9600);

}
int n=0;
void loop() {
    direction = digitalRead(dirPin);
    read = analogRead(PotRead);
    read = map(read,0,1023,1,11);
    Serial.println(read);
    OneStep(direction);  
    delay(read);
       
}

//void loop() {
//  if (clockwise) {
//    // Rotate 2 turns clockwise
//    if (steps_completed < 2 * 2048) { // Assuming 2048 steps per revolution
//      OneStep(true);
//      delay(2);
//      steps_completed++;
//    } else {
//      clockwise = false; // Change direction to anticlockwise
//      steps_completed = 0; // Reset step counter
//    }
//  } else {
//    // Rotate 1 turn anticlockwise
//    if (steps_completed < 2048) {
//      OneStep(false);
//      delay(2);
//      steps_completed++;
//    } else {
//      // Stop the motor or perform other actions if needed
//    }
//  }
//}


void OneStep(bool direction){
    if(direction == 1){
switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
 
  
} 
  }
step_number++;

  if(step_number > 3){
    step_number = 0;
    
  }
  
  
  //Serial.println(n);
}
