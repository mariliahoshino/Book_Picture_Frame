#include "DigiKeyboard.h"
#define botao  1
int leitura, XYZ=0;      

void setup() {
  pinMode(botao, INPUT); 
  
  // don't need to set anything up to use DigiKeyboard
}


void loop() {
  delay(200);
  DigiKeyboard.sendKeyStroke(0);
  
  if(XYZ==0){
  delay(15000);
  DigiKeyboard.sendKeyStroke(0);

  DigiKeyboard.delay(100);
  DigiKeyboard.println("root");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("orangepi");
  DigiKeyboard.delay(100);
    XYZ++;
  }
  
  DigiKeyboard.sendKeyStroke(0);
  leitura = digitalRead(botao);          // leitura da porta digital do botão (botão conectado em pull-down)
  if(leitura != 1){
    while(digitalRead(botao) != 1){      // cria um loop infinito
      delay(100);
    }
  
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);

  DigiKeyboard.delay(100);
  // Type out this string letter by letter on the computer (assumes US-style
  // keyboard)
  DigiKeyboard.println("root");
  
  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
  DigiKeyboard.delay(500);

  //DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println("orangepi");
  
  DigiKeyboard.delay(1000);
  }
}
