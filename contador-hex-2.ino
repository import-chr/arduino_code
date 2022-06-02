#define PUSH 2            //pin boton
#define LED1 6            //pin led valor binario 1
#define LED2 5            //pin led valor binario 2
#define LED4 4            //pin led valor binario 4
#define LED8 3            //pin led valor binario 8

int contador = 0;         //contador numerico
unsigned long duration;   //duracion de pulsacion
int counter;

//catodo
const int valores[16][7] = {
  /*0*/ {1, 1, 1, 1, 1, 1, 0},
  /*1*/ {0, 1, 1, 0, 0, 0, 0},
  /*2*/ {1, 1, 0, 1, 1, 0, 1},
  /*3*/ {1, 1, 1, 1, 0, 0, 1},
  /*4*/ {0, 1, 1, 0, 0, 1, 1},
  /*5*/ {1, 0, 1, 1, 0, 1, 1},
  /*6*/ {1, 0, 1, 1, 1, 1, 1},
  /*7*/ {1, 1, 1, 0, 0, 0, 0},
  /*8*/ {1, 1, 1, 1, 1, 1, 1},
  /*9*/ {1, 1, 1, 1, 0, 1, 1},
  /*A*/ {1, 1, 1, 0, 1, 1, 1},
  /*B*/ {0, 0, 1, 1, 1, 1, 1},
  /*C*/ {1, 0, 0, 1, 1, 1, 0},
  /*D*/ {0, 1, 1, 1, 1, 0, 1},
  /*E*/ {1, 0, 0, 1, 1, 1, 1},
  /*F*/ {1, 0, 0, 0, 1, 1, 1}
};

const int OFF = LOW;
const int A = 8;      //segmento a - pin 8
const int B = 7;      //segmento b - pin 7
const int C = 11;     //segmento c - pin 11
const int D = 12;     //segmento d - pin 12
const int E = 13;     //segmento e - pin 13
const int F = 9;      //segmento f - pin 9
const int G = 10;     //segmento g - pin 10
const int nSeg = 7;   //cantidad de segmentos
const int segmentos[nSeg] = {A, B, C, D, E, F, G};

void setup() {
  Serial.begin(9600);
  pinMode(PUSH, INPUT);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED8, OUTPUT);

  for(int i = 0; i < nSeg; i++) {
    pinMode(segmentos[i], OUTPUT);
    digitalWrite(segmentos[i], OFF);
  }
}

void signal(int d) {
  for(int i = 0; i < nSeg; i++) {
    digitalWrite(segmentos[i], valores[d][i]);
  }
}

void loop() {
  if(contador == 0) {
    signal(0);
  }
  
  if(digitalRead(PUSH) == HIGH && counter == 0) {
    contador++;
    counter = 1;
    signal(contador);
  }
  
  /*duration = pulseIn(PUSH, HIGH);
  Serial.println(duration);    

  if(duration > 1 && duration < 550000) {
    Serial.println(duration);
    contador++;
    signal(contador);
  }*/
  
  if(digitalRead(PUSH) == LOW) {
    counter = 0;
  }

  /*for(int i = 0; i <= 15; i++) {
    signal(i);
    delay(500);
  }*/
  
  switch(contador) {
    case 1:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED8, LOW);
    break;
    case 2:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED8, LOW);
    break;
    case 3:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED8, LOW);
    break;
    case 4:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED8, LOW);
    break;
    case 5:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED8, LOW);
    break;
    case 6:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED8, LOW);
    break;
    case 7:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED8, LOW);
    break;
    case 8:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED8, HIGH);
    break;
    case 9:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED8, HIGH);
    break;
    case 10:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED8, HIGH);
    break;
    case 11:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED8, HIGH);
    break;
    case 12:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED8, HIGH);
    break;
    case 13:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED8, HIGH);
    break;
    case 14:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED8, HIGH);
    break;
    case 15:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED8, HIGH);
    break;
    case 16:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED8, LOW);
      contador = 0;
    break;
  }
}