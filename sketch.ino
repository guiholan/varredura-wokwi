const byte segmentos[7] ={23,22,21,19,5,17,4}; // define os pinos conectados aos segmentos A a G
const byte digitos [8] = {33,25,26,27,14,12,13,15}; // define os pinos de controle COM que serao responsaveis por ativar cada display
byte numeros [8] = {1,2,3,4,5,6,7,8}; // numeros que serao exibidos no display
const byte mapaNumeros [10] = {
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B00000111, // 7
  B01111111, // 8
  B01101111  // 9
}; // mapa binario que acendera  e apagara cada segmento do display em sua hora para aparecer o numero desejado
void setup() {
 for(byte i = 0; i<7; i++){
  pinMode(segmentos[i], OUTPUT);
// configurar os pinos escolhidos como saida , permitindo controlar os leds com a funçap digitalWrite
 }
for(byte i = 0 ; i<8; i++){
pinMode(digitos[i], OUTPUT);}
}

void loop() {
for(byte i = 0 ; i<8; i++)// loop que fará a varredura dos 8 digitos
{
  for (byte j = 0 ; j<8; j++){
    digitalWrite(digitos[j], HIGH); // high desativará os outros digitos enquanto um estiver aceso, o high estara deixando-os apagadois
  }
  byte valor = mapaNumeros[numeros[i]]; // traduz o numero exibido para binario ao acender o devido segmento
  for (byte k = 0; k<7; k++){
    digitalWrite(segmentos[k], bitRead(valor,k));
    // acende os segmentos na devida ordem para acender o numero desejado
    //bitRead sera usado para desligar e ligar cada segmento individualmente
  }
  digitalWrite(digitos[i], LOW); // ativa somente do digito i permitindo exibir os segmentos
    delay(2); 
}
}
