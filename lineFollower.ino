//sensor pins
const int right_sensor = 2;
const int middle_sensor = 12;
const int left_sensor = 13;

//Motor control pins- 
const int ENA = 10;
const int ENB = 5;
const int In1 = 9;
const int In2 = 8;
const int In3 = 7;
const int In4 = 6;

void setup() {
Serial.begin(9600);

//pins for motor controller
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(In1, OUTPUT);
pinMode(In2, OUTPUT);
pinMode(In3, OUTPUT);
pinMode(In4, OUTPUT);
pinMode(right_sensor, INPUT);
pinMode(middle_sensor, INPUT);
pinMode(left_sensor, INPUT);
}

void loop() { 
      int S2 = digitalRead(right_sensor);
      int S3 = digitalRead(middle_sensor);
      int S4 = digitalRead(left_sensor);
      int last ;
      
      //Conditions to drive line folower appropriately
      if (S3==0) {
            //if sensor at the center reads low, go straight
            forward() ;
            last = 3;
      } 
      else if (S2==0) {
            //follower moving towads right, stop left motor
            right();
            last = 2;
      } 
      else if (S4==0) {
            //follower moving towads left, stop right motor
            left();
            last = 4;
      }
      else if ( S2==1 && S3==1 && S4==1 ) {
        switch (last) {
         case 3 : forward();
         break;
         case 2 : right();
         break;
         case 4 : left ();
         break;  
        }
      } 
}


// function for driving straight
void forward(){
digitalWrite(In1, HIGH);
digitalWrite(In2, LOW);
 
digitalWrite(In3, HIGH);
digitalWrite(In4, LOW);
 
analogWrite(ENA, 80);
analogWrite(ENB, 80);
}

//function for turning left
void right(){
digitalWrite(In3, LOW);
digitalWrite(In4, LOW);
 
digitalWrite(In1, HIGH);
digitalWrite(In2, LOW);
 
analogWrite(ENB, 0);
analogWrite(ENA, 115);
}
 
//function for turning right
void left(){
digitalWrite(In3, HIGH);
digitalWrite(In4, LOW);
 
digitalWrite(In1, LOW);
digitalWrite(In2, LOW);
 
analogWrite(ENB, 130);
analogWrite(ENA, 0);
}
 
//function for stopping motors
void Stop(){
 
digitalWrite(In1, LOW);
digitalWrite(In2, LOW);

digitalWrite(In3,LOW);
digitalWrite(In4, LOW);
 
analogWrite(ENA, 0);
analogWrite(ENB, 0);
}
