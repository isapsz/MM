#include <Servo.h>
#include <Stepper.h>
#include <limits.h>
int leds[] = {9,10,11};

int cor;
int saida;

Servo servo_1;
Servo servo_2; 
Servo servo_3;
Servo servo_4;
Servo servo_5;

Servo servo[] = {servo_1, servo_2, servo_3, servo_4, servo_5};

const int stepPerRevolution = 200;
Stepper myStepper(stepPerRevolution, 7,10,9,13);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(60);

  for(int i = 0; i< 3; i++)
    pinMode(leds[i],OUTPUT);
 
  for(int i = 0; i< 5; i++)
  { 
    servo[i].attach(i+2);
    if(i == 0)
      servo[i].write(90);
    else
      servo[i].write(0);
  }

  for(int i = 0; i< 3; i++)
    analogWrite(leds[i],255);
}
//0 -> Laranja 1-> Vermelho, 2-> Verde, 3->Amarelo, 4-> Azul, 5-> Marrom
void loop() {
  myStepper.step(260);
  int qtdCores[] = {0,0,0,0,0,0};
  int maior = 0;
  int qtdQual=INT_MIN;
  delay(1000);
  for(int i =0; i<9; i++)
  {
     int qual;
     cor = analogRead(A0);
     saida = map(cor, 0, 1023, 0, 255);
     switch(saida)
     {
        case 246: qual = 0; break;
        case 247: qual = 1; break;
        case 248: qual = 2; break;
        case 250: qual = 3; break;
        case 252: qual = 4; break;
        case 254: qual = 5; break;
     }
     qtdCores[qual]++;
     if(qtdCores[qual] > qtdQual)
     {
        maior = qual;
        qtdQual = qtdCores[qual];
     }
      //Serial.print(i);
     //Serial.print("  ");
     //Serial.print(outputValue);
     //Serial.print("\n");
    delay(500);
  }

  myStepper.step(120);
  delay(1000);
  
  switch(maior)
  {
      case 0: separar(servo[maior], 150);  Serial.println("O"); break;
      case 1: separar(servo[maior],150);  Serial.println("R"); break;
      case 2: separar(servo[maior],150);  Serial.println("G"); break;
      case 3: separar(servo[maior],150);  Serial.println("Y"); break; 
      case 4: separar(servo[maior],150);  Serial.println("B"); break;
      case 5: separar(servo[maior],150);  Serial.println("W"); break;
  }

  myStepper.step(-380);
 delay(1000);
}

                       
void separar(Servo ser,int val)
{ 
    delay(5000);
    ser.write(val);
    delay(5000);
    ser.write(0);
}
