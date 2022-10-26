int redled = 10;
int yellowled = 9;
int greenled = 8;
const int trigPin = 4;
const int echoPin = 5;
const int forward = 2;
const int backward = 3;
int outval = 0;
float duration, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(forward,OUTPUT);
  pinMode(backward,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2; // distance from sensor in centimeters
  Serial.println(distance);
  delay(1000);
  outval = map(distance,0,50,0,255); // changes distance range from 0-50 to 0-255 
  analogWrite(backward,0); // I want the dc motor to move in only one direction (forward)
  analogWrite(forward,outval); // the further away it is, the higher outval is, then the faster the motor turns
  if (distance <= 15) { // closest to sensor, all LEDs turn on
      digitalWrite(yellowled, HIGH);
      digitalWrite(greenled, HIGH);
      digitalWrite(redled, HIGH);
    }
  else if ((distance > 15)&&(distance < 25)) { // further away, green and yellow are both on (and green os off)
      digitalWrite(greenled, HIGH);
      digitalWrite(yellowled, HIGH);
      digitalWrite(redled, LOW);
    }
  else if ((distance > 25)&&(distance < 32 )) { // some more distance, only the green is on
    digitalWrite(greenled, HIGH);
    digitalWrite(yellowled, LOW);
    digitalWrite(redled, LOW);
    }
  else { // further than or equal to 32cm, all LEDs turn off
    digitalWrite(yellowled, LOW);
    digitalWrite(greenled, LOW);
    digitalWrite(redled, LOW);
  }
}
