#include <Stepper.h>


int i, j; // contadores
int side = 0;  // sentido do motor
int velocidade;
const int stepPerRevolution = 500;

Stepper myStepper(stepPerRevolution, 8,10,9,11);

void setup() {
  Serial.begin(9600);
  Serial.print("Digite 0 , 1 , 2, 3 para movimentar ");
  // inicializar as portas do motor como saida
  myStepper.setSpeed(60);
}

void loop() {
    if (Serial.available() > 0){
      side = Serial.read();
    }

    //velocidade = analogRead(A0);
    //velocidade = map(velocidade,0,1023,0,100);
    velocidade = 100;// travado para o teste do hardware do prof
      
  
    if (side == 48) {  // digitou 0
      Serial.println("Sentido horario");
      Serial.println(velocidade);
      int k = 0;
      for (j=0;j< 10;j++)
      {
        myStepper.step(512);
        delay(1000);
      }
      
    }
    if (side == 49) {  // digitou 0
      Serial.println("Sentido horario");
      Serial.println(velocidade);
      int k = 0;
      for (j=0;j< 10;j++)
      {
        myStepper.step(-512);
        delay(1000);
      }
      
    }
    side = 0;
}



