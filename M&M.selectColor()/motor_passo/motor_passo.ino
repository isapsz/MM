/* Ligar na porta A0 o potenciometro    
 * 
 *     5V
 *      |
 *     |-|
 *     | |<--- A0 -> controlar a velocidade do motor
 *     |_|
 *      |
 *     gnd
 */

int i, j; // contadores
int pins[] = {11,10,9,8};
int side = 0;  // sentido do motor
int velocidade;

void setup() {
  Serial.begin(9600);
  Serial.print("Digite 0 , 1 , 2, 3 para movimentar ");
  // inicializar as portas do motor como saida
  for (i = 0; i < 4; i++)
     pinMode(pins[i], OUTPUT);
}

void loop() {
    if (Serial.available() > 0){
      side = Serial.read();
    }

    velocidade = 1023;
    velocidade = map(velocidade,0,1023,0,100);
      
  
    if (side == 48) {  // digitou 0
      Serial.println("Sentido horario");
      Serial.println(velocidade);
      int k = 0;
      for (j=0;j< 10;j++)
      {
       for (i =0; i< 4; i++){
        k = i - 1;
        if (k < 0) k = 3;
        digitalWrite(pins[i],HIGH);
        digitalWrite(pins[k],HIGH);
        delay(velocidade);
        digitalWrite(pins[i],LOW);
        digitalWrite(pins[k],LOW);
       }
      }
      
    }

    side = 0;
}









