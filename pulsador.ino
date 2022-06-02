#define LED 2         //asignacion de pin 2 para LED
#define PUSH 3        //asignacion de pin 3 para boton

byte pL = 0;          //estado de btn actual
byte pLa = 0;         //estado de btn anterior
int s = 0;            //estado general led

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PUSH, INPUT);
}

void loop() {
  pL = digitalRead(PUSH); //lectural de boton

  //si estado actual es 1 y anterior 0; estado general es 1 - estado general
  if(pL == HIGH && pLa == LOW) {
    s = 1 - s;
  }

  pLa = pL;   //estado anterior = actual
  
  //si estado general 1, enciende LED
  if(s == 1) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
