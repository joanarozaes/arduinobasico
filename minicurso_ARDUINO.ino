#include "SoftwareSerial.h"
#include <Servo.h>

SoftwareSerial bluetooth(2, 3); // TX, RX (Bluetooth)

int comando = 0;     // Recebe a leitura dos Bluetooth
Servo myservo;            // "Apelido" para o servo
int angulo = 90;

void setup() {

  bluetooth.begin(9600);
  myservo.attach(9);
  myservo.write(90);
}

void loop() {
  
   if (bluetooth.available() > 0) {
   comando = bluetooth.read();  //Leitura do Bluetooth
   
     
     if (comando == 'F') {
      Serial.print(comando);
        myservo.write(angulo+angulo); // Servo motor vai girar a partir da posição atual
     }
     
          
      else{    
         myservo.write(150);  //permanecer na posição atual
      }
        
   } 
 }
