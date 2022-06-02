//LED pines
const int pMnr = 7; //LED menor
const int pMyr = 5; //LED mayor
const int pE = 6; //LED igual
//dipswitch pines
const int N1 = 11; //MSB - A
const int N2 = 10; //LSB - A
const int M1 = 9;  //MSB - B
const int M2 = 8;  //LSB - B

int v1_1 = HIGH;  //valor switch 1
int v1_2 = HIGH;  //valor switch 2

int v2_1 = HIGH;  //valor switch 3
int v2_2 = HIGH;  //valor switch 4
int val1;         //valor total primer numero
int val2;         //valor total segundo numero

//asignacion de pines I/O
void setup() {
  pinMode(pMyr, OUTPUT);
  pinMode(pMnr, OUTPUT);
  pinMode(pE, OUTPUT);
  
  pinMode(N1, INPUT_PULLUP);
  pinMode(N2, INPUT_PULLUP);
  pinMode(M1, INPUT_PULLUP);
  pinMode(M2, INPUT_PULLUP);
}

void loop() {
  //lectura de los switch
  v1_1 = digitalRead(N1);
  v1_2 = digitalRead(N2);
  v2_1 = digitalRead(M1);
  v2_2 = digitalRead(M2);

  //switch 1 - valor decimal 2
  if(v1_1 == HIGH) {
    val1 = val1 + 2;
  }

  //switch 2 - valor decimal 1
  if(v1_2 == HIGH) {
    val1 = val1 + 1;
  }

  //switch 3 - valor decimal 2
  if(v2_1 == HIGH) {
    val2 = val2 + 2;
  }

  //switch 4 - valor decimal 1
  if(v2_2 == HIGH) {
    val2 = val2 + 1;
  }
  
  //comprobacion de igualdades
  if(val1 > val2) {
    digitalWrite(pMnr, LOW);
    digitalWrite(pMyr, HIGH);
    digitalWrite(pE, LOW);
  }
  else if(val1 < val2) {
    digitalWrite(pMnr, HIGH);
    digitalWrite(pMyr, LOW);
    digitalWrite(pE, LOW);
  }
  else {
    digitalWrite(pMnr, LOW);
    digitalWrite(pMyr, LOW);
    digitalWrite(pE, HIGH);
  }
  
  //reset de valores
  val1 = 0;
  val2 = 0;
}
