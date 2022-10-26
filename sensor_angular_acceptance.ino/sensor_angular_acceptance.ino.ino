const int trigPin = 5;
const int echoPin = 6;
int ang = 0;
float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  while (ang <= 180){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
    //Serial.print("Distance: ");
    Serial.print("Angle (deg): ");
  
    Serial.println(ang);
    Serial.println(distance);
    delay(3000);
    ang+=5;
  }
}
