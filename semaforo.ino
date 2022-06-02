int pinA1 = 2;    //amarillo 1 pin 2
int pinV1 = 3;    //verde 1 pin 3
int pinR1 = 4;    //rojo 1 pin 4

int pinA2 = 5;    //amarillo 2 pin 5
int pinV2 = 6;    //verde 2 pin 6
int pinR2 = 7;    //rojo 2 pin 7

//asignacion I/O
void setup() {
  pinMode(pinA1, OUTPUT);
  pinMode(pinV1, OUTPUT);
  pinMode(pinR1, OUTPUT);
  
  pinMode(pinA2, OUTPUT);
  pinMode(pinV2, OUTPUT);
  pinMode(pinR2, OUTPUT);
}

void loop() {
  /* ------------ 15 segundos ------------- */
  digitalWrite(pinA1, LOW);
  digitalWrite(pinR2, LOW);
  digitalWrite(pinR1 , HIGH);
  digitalWrite(pinV2, HIGH);
  
  delay(15000);
  /* ------------ 15 segundos ------------- */
  /* ------------ 5 segundos ------------- */
  for(int i = 0; i <= 5; i++) {
    digitalWrite(pinV2, HIGH);
    delay(500);
    digitalWrite(pinV2, LOW);
    delay(500);
  }
  
  digitalWrite(pinV2, LOW);
  digitalWrite(pinA2, HIGH);
  
  delay(5000);
  /* ------------ 5 segundos ------------- */
  /* ------------ 15 segundos ------------- */
  digitalWrite(pinR1, LOW);
  digitalWrite(pinV2, LOW);
  digitalWrite(pinA2, LOW);
  digitalWrite(pinV1, HIGH);
  digitalWrite(pinR2, HIGH);
  
  delay(15000);
  /* ------------ 15 segundos ------------- */
  /* ------------ 5 segundos ------------- */
  for(int i = 0; i <= 5; i++) {
    digitalWrite(pinV1, HIGH);
    delay(500);
    digitalWrite(pinV1, LOW);
    delay(500);
  }
  
  digitalWrite(pinV1, LOW);
  digitalWrite(pinA1, HIGH);
  
  delay(5000);
  /* ------------ 5 segundos ------------- */
}