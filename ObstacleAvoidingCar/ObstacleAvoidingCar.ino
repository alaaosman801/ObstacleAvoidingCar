
#define in1 4
#define in2 5
#define in3 6
#define in4 7
#define ForLed 9
#define BackLed 10
#define LtLed 11
#define RtLed 12
#define alrmLed 13
const int trigPin = 2;
const int echoPin = 3;


void setup() {
 // put your setup code here, to run once:
 Serial.begin(9600);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(ForLed, OUTPUT);
pinMode(BackLed, OUTPUT);
pinMode(LtLed, OUTPUT);
pinMode(RtLed, OUTPUT);
pinMode(alrmLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
long dis;
forward();
 delay(15);
  digitalWrite(ForLed,HIGH);
    delay(1000);
    digitalWrite(ForLed,LOW);
    delay(1000);
dis = Distance();
if(dis<=15){
  digitalWrite(alrmLed,HIGH);
  delay(1000);              // wait for a second
  digitalWrite(alrmLed, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
  Stop();
  delay(15);
          digitalWrite(ForLed,LOW);
          digitalWrite(BackLed,LOW);
          digitalWrite(LtLed,LOW);
           digitalWrite(RtLed,LOW);
  delay(1000);
  backward();
  delay(15);
    digitalWrite(BackLed,HIGH);
    delay(1000);
    digitalWrite(BackLed,LOW);
  delay(1000);
  long rtdis, ltdis;
  // measures disance from right
  right();
  delay(15);
        digitalWrite(RtLed,HIGH);
    delay(1000);
    digitalWrite(RtLed,LOW);
  rtdis=Distance();
  Serial.print("The Right Distance = "); Serial.print(rtdis); Serial.println("cm");
  delay(1000);
  left();
  delay(1000);
  // measures distance from left
  left();
   delay(15);
      digitalWrite(LtLed,HIGH);
    delay(1000);
    digitalWrite(LtLed,LOW);
  ltdis=Distance();
    Serial.print("The Left Distance = "); Serial.print(ltdis); Serial.println("cm");
  delay(1000);
  right();
  // decide which direction to go
  if(rtdis>=ltdis){
    right();
    Serial.println("Going Right Direction");
    delay(1000);
    }
    else{
      left();
      Serial.println("Going Left Direction");
      delay(1000);
      }
  }
}

void forward(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }
void backward(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }
void left(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }
void right(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }
  void Stop(){
    digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
    }
  long Distance(){
  long duration,  cm;
pinMode(trigPin,OUTPUT);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
cm = microsecondsToCentimeters(duration);
Serial.print(cm); Serial.print(" cm"); Serial.println(); delay(100);
return cm;
    }
    long microsecondsToCentimeters(long microseconds) {
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return (microseconds / 29) / 2;
}

