#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,10);
const byte endereco[6] = "2305g"; //cria um endereço
//mesmo endereço do slave

int pinoBotao = 2; //pino do botao no arduino
int estadoBotao = 0; //variavel para armazenar o estado

void setup() {
  // put your setup code here, to run once:
  pinMode(pinoBotao,INPUT_PULLUP); //define botao como entrada negativa
  radio.begin(); //inicia radio
  radio.openWritingPipe(endereco); //diz quel endereço o sinal ta conversando
  radio.setPALevel(RF24_PA_HIGH); // frequencia alta
  radio.stopListening(); //diz que ele não precisava ouvir, só enviar
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pinoBotao) == HIGH){
    estadoBotao = 1;
    radio.write(&estadoBotao,sizeof(estadoBotao));
    }
  else{
    if(digitalRead(pinoBotao) == LOW){
      estadoBotao = 0;
      radio.write(&estadoBotao,sizeof(estadoBotao));
      }
    }
}
