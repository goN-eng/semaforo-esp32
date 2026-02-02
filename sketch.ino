#define GREEN_LED 4
#define RED_LED 18
#define ORANGE_LED 5
#define BOTAO 17

unsigned long tempoAnterior = 0;
unsigned long intervaloAtual = 10000;
int estado = 0;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(ORANGE_LED, OUTPUT);
  pinMode(BOTAO, INPUT_PULLUP);
}

void loop() {
  unsigned long tempoAtual = millis();

  if (estado == 0) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);

    if (digitalRead(BOTAO) == LOW) {
      intervaloAtual = 3000;
      tempoAnterior = tempoAtual;
    }

    if (tempoAtual - tempoAnterior >= intervaloAtual) {
      estado = 1;
      tempoAnterior = tempoAtual;
      intervaloAtual = 5000;
    }
  } else if (estado == 1) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(ORANGE_LED, HIGH);

    if (tempoAtual - tempoAnterior >= intervaloAtual) {
      estado = 2;
      tempoAnterior = tempoAtual;
      intervaloAtual = 10000;
    }
  } else if (estado == 2) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(ORANGE_LED, LOW);

    if (tempoAtual - tempoAnterior >= intervaloAtual) {
      estado = 0;
      tempoAnterior = tempoAtual;
      intervaloAtual = 10000;
    }
  }
}