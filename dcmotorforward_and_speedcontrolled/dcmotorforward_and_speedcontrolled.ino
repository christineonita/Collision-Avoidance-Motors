const int forward = 2;
const int backward = 3;
int time_delay = 3000;
int val = 0;
int outval = 0;
char temp;
String instr = "Input Value: ";
String outstr = "Output Value: ";
String rotation = "";


void setup() {
  // put your setup code here, to run once:
  pinMode(forward,OUTPUT);
  pinMode(backward,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0) {
    val = Serial.parseInt();
    temp = Serial.read();
    outval = map(val,0,1023,0,255);
    if (outval > 0) {
      rotation = ", Going Forward";
      analogWrite(backward,0);
      analogWrite(forward,outval);
    }
    if (outval == 0) {
      rotation = ", Stopped";
      analogWrite(backward,0);
      analogWrite(forward,0);
    }
    //if (outval < 0) {
      //rotation = ", Going Backward";
      //analogWrite(forward,0);
      //analogWrite(backward,-outval);
   // }
    Serial.println(instr+val+outstr+outval+rotation);
  }
}

//void go_forward() {
  //digitalWrite(forward,HIGH);
  //digitalWrite(backward,LOW);  
//}

//void go_backward() {
  //digitalWrite(forward,LOW);
  //digitalWrite(backward,HIGH);  
//}

//void brake() {
 // digitalWrite(backward,LOW);
  //digitalWrite(forward,LOW);  
//}
