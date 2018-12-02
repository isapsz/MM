#include <Servo.h>
#include <Stepper.h>

const int sensorLuz = A0;

int valorSensor = 0;
int valorDeSaida = 0;
int[] quantosMM = {0,0,0,0,0,0};

const int stepsPerRevolution = 500;
Stepper myStepper(stepsPerRevolution, 0,1,12,13); 
  
void setup() 
{ 
 //Determina a velocidade inicial do motor 
 myStepper.setSpeed(60);
} 
  
void loop() 
{ 
 //Gira o motor no sentido horario a 90 graus
 for (int i = 0; i<=3; i++)
 {
 myStepper.step(-512); 
 delay(2000);
 }
  
 //Gira o motor no sentido anti-horario a 120 graus
 for (int i = 0; i<=2; i++)
 {
 myStepper.step(682); 
 delay(2000);
 }
 
 //Gira o motor no sentido horario, aumentando a
 //velocidade gradativamente
 for (int i = 10; i<=60; i=i+10)
 {
 myStepper.setSpeed(i);
 myStepper.step(40*i);
 }
 delay(2000); 

const int stepPerRevolution = 500;

Stepper stepper (stepPerRevolution,11,10,9,8);       
Servo servo;

void setup() {
Serial.begin(9600);
servo.attach(5);
}

void loop() {
stepper.step(90); // pega um mm
delay(100);
                            
int cor = analogRead(sensorLuz);

stepper.step(45);
delay(100);
stepper.step(-135);

switch(cor)
{
  case 246: organizar(90); quantosMM[0]++ ;break;
  case 247: organizar(60); quantosMM[1]++ ;break;
  case 248: organizar(30); quantosMM[2]++ ;break;
  case 250: organizar(-30); quantosMM[3]++ ;break;
  case 252: organizar(60); quantosMM[4]++ ;break;
  case 254: organizar(-90); quantosMM[5]++; break;
}
delay(1000);
}

void organizar(int valor)
{ 
  servo.write(valor); 
  delay(100);
  servo.write(-valor);
  
}
