int const motor_right_front = 2 ; 
int const  motor_right_back= 3 ;   //define arduino pin
int const motor_left_front = 4 ; 
int const motor_left_back = 5 ; 
int const Front_light = 6;
int const Back_liht = 7;
int const horn = 8;
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int speedPinA = 9; // Needs to be a PWM pin to be able to control motor speed
int speedPinB = 10; // Needs to be a PWM pin to be able to control motor speed
String message;
int PWM = 127;

//#define trigPin 10  //Ultrasonic Sensor
//#define echoPin 9   //Ultrasonic Sensor

void setup() {
  pinMode(motor_right_front, OUTPUT);
  pinMode(motor_right_back, OUTPUT);
  pinMode(motor_left_front, OUTPUT);  
  pinMode(motor_left_back, OUTPUT);
  pinMode(Front_light, OUTPUT);
  pinMode(Back_liht, OUTPUT);
  pinMode(horn, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(speedPinB,OUTPUT);
//  pinMode(trigPin, OUTPUT);
//  pinMode(echoPin, INPUT);
  
  //initial set up straight forward, no speed
   digitalWrite(motor_right_front, LOW);
   digitalWrite(motor_right_back, LOW);
   digitalWrite(motor_left_front, LOW);
   digitalWrite(motor_left_back, LOW);
   digitalWrite(Front_light, LOW);
   digitalWrite(Back_liht, LOW);
   digitalWrite(horn, LOW);
   digitalWrite(LED1, LOW);
   digitalWrite(LED2, LOW);
   digitalWrite(LED3, LOW);
  
  Serial.begin(9600); 
}

void loop() {
//--------------------------------------------------------------------------
//  This part is for Ultrasonic Sensor

//  long duration, distance;
//  digitalWrite(trigPin, LOW);  
//  delayMicroseconds(2); 
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10); 
//  digitalWrite(trigPin, LOW);
//  duration = pulseIn(echoPin, HIGH);
//  distance = (duration/2) / 29.1;
//  if (distance < 50) {  //you are free to change this
//  digitalWrite(Front_light,HIGH); //distance is less than 50 so white LED turns on
//}
//  else {
//  digitalWrite(Front_light,LOW); //distance is more than 100 so green LED turns on
//
//  }
//  if (distance >= 400 || distance <= 0){    //range is 400 cm for HC-SR04 sensor
//    Serial.println("Out of range");
//  }
//  else {
//    Serial.print(distance);
//    Serial.println(" cm"); //in centimeters
//  }
//  delay(1000);
//-----------------------------------------------------------------------------


 
  // see if there's incoming serial data:
  
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    int incomingByte = Serial.read();
    Serial.println(incomingByte);
    
    // action depending on the instruction
    // as well as sending a confirmation back to the app
    switch (incomingByte) {
      case '1': PWM = 25; break;    //motor speed, min is 0, max is 255.
      case '2': PWM = 50; break;
      case '3': PWM = 75; break;
      case '4': PWM = 100; break;
      case '5': PWM = 125; break;
      case '6': PWM = 150; break;
      case '7': PWM = 175; break;
      case '8': PWM = 200; break;
      case '9': PWM = 225; break;
      case 'q': PWM = 255; break;
              
      case 'F':
        analogWrite(speedPinA, PWM);
        analogWrite(speedPinB, PWM);
        digitalWrite (motor_right_front,HIGH);
        digitalWrite (motor_left_front,HIGH);
        Serial.print(PWM);
        Serial.print("   ");
        Serial.println("Going forward");
        break;
      case 'L':
        analogWrite(speedPinA, PWM);
        analogWrite(speedPinB, PWM);
        digitalWrite (motor_right_back,HIGH);
        digitalWrite (motor_left_front,HIGH);
        Serial.print(PWM);
        Serial.print("   ");
        Serial.println("Turning right");
        break;
      case 'R':
        analogWrite(speedPinA, PWM);
        analogWrite(speedPinB, PWM);
        digitalWrite (motor_right_front,HIGH);
        digitalWrite (motor_left_back,HIGH);
        Serial.print(PWM);
        Serial.print("   ");
        Serial.println("Turning left");
        break;
      case 'B':
        analogWrite(speedPinA, PWM);
        analogWrite(speedPinB, PWM);
        digitalWrite (motor_right_back,HIGH);
        digitalWrite (motor_left_back,HIGH);
        Serial.print(PWM);
        Serial.print("   ");
        Serial.println("Going backwards");
        break;
        
      case 'S':
       digitalWrite (motor_right_front,LOW);
       digitalWrite (motor_right_back,LOW);
       digitalWrite (motor_left_front,LOW);
       digitalWrite (motor_left_back,LOW);
        Serial.println("Stopping");
        break;
        
      case 'W':
        digitalWrite (Front_light,HIGH);
        Serial.println("Front light On");
        break;
        
      case 'w':
        digitalWrite (Front_light,LOW);
        Serial.println("Front light Off");
        break;

      case 'U':
        digitalWrite (Back_liht,HIGH);
        Serial.println("Back_liht On");
        break;
        
      case 'u':
        digitalWrite (Back_liht,LOW);
        Serial.println("Back_liht Off");
        break;
        
     case 'V':
        digitalWrite (horn,HIGH);
        Serial.println("horn On");
        break;
        
      case 'v':
        digitalWrite (horn,LOW);
        Serial.println("horn Off");
        break;


      case 'X':
        digitalWrite(LED1, HIGH);    // turn on LED1 
        delay(10000);                // wait for 200ms
        digitalWrite(LED1, LOW);     // turn off LED1
        delay(300);                  // wait for 300ms
        digitalWrite(LED2, HIGH);    // turn on LED2
        delay(500);                  // wait for 200ms       
        digitalWrite(LED2, LOW);     // turn off LED2
        delay(300);                  // wait for 300ms
        digitalWrite(LED1, HIGH);    // turn on LED1 
        delay(500);                  // wait for 200ms
        digitalWrite(LED1, LOW);     // turn off LED1
        delay(300);                  // wait for 300ms 
        digitalWrite(LED3, HIGH);    // turn on LED3 
        delay(500);                  // wait for 200ms
        digitalWrite(LED3, LOW);     // turn off LED3  
        delay(900);                  // wait for 300ms 
        digitalWrite(LED1, HIGH);    // turn on LED1 
        delay(300);                  // wait for 200ms
        digitalWrite(LED3, HIGH);    // turn on LED3
        delay(500);                  // wait for 200ms
        digitalWrite(LED2, HIGH);    // turn on LED2
        delay(15000);                // wait for 200ms       
        digitalWrite(LED1, LOW);    // turn on LED1 
        delay(30);                  // wait for 200ms
        digitalWrite(LED2, LOW);    // turn on LED2
        delay(30);                  // wait for 200ms       
        digitalWrite(LED3, LOW);    // turn on LED3
        delay(300);                  // wait for 300ms before running case 'X' again

        
      case 'x':
        digitalWrite (LED1,LOW);
        digitalWrite (LED2,LOW);
        digitalWrite (LED3,LOW);
        Serial.println("Extra Off");
        break;
        
      default: 
        // if nothing matches, do nothing
        break;
    }
  }
}
