#include <Wire.h>
#include <Adafruit_MLX90614.h>

//Definiendo sensor temperatura GY 906
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
//Definiendo Relay
int relay = 13;
int ledR = 3;
int ledG = 4;
int ledB = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay,OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  Serial.begin(9600);
  Serial.println("Sistema encendido");
  mlx.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("T Ambiente = "); Serial.print(mlx.readAmbientTempC());
  Serial.print("*C\tObjeto = "); Serial.print(mlx.readObjectTempC()); Serial.print("*C");
  Serial.println();

  /*for(int i=0; i<=255; i++){
    analogWrite(ledR, i);
    analogWrite(ledG, 255-i);
    analogWrite(ledB, 255);
    delay(10);
  }*/

  /*digitalWrite(ledR, 0);
  digitalWrite(ledG, 0);
  digitalWrite(ledB, 0);*/

  delay(1500);
  if(mlx.readObjectTempC() >= 31){
    Serial.println("Temperatura alta, enfriando...");
    digitalWrite(relay,LOW);
    //Led color rojo (caliente)
    digitalWrite(ledR, 255);
    digitalWrite(ledG, 0);
    digitalWrite(ledB, 0);
    delay(500);
  }
  else{
    digitalWrite(relay,HIGH);
    //Led color azul (frio)
    digitalWrite(ledR, 0);
    digitalWrite(ledG, 1);
    digitalWrite(ledB, 255);
    delay(500);
  }
}
