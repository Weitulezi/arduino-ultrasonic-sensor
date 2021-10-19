const int echo = 13;
const int trig = 12;

int duration = 0;
int distance = 0;

int LED1 = 8;
int LED2 = 7;
int LED3 = 6;
int LED4 = 5;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  Serial.begin(1000);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 28.5;

  if(distance >= 20) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  if(distance < 10) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  if(distance < 20 && distance >= 10) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }
  
  Serial.println(distance);
}
