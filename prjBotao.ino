const int LED = 4;
const int BOTAO = 8;
byte botao;
byte botaovelho = HIGH;
boolean estadobotao = false;
boolean debounce ( boolean last ){
boolean current = digitalRead(BOTAO); 
  if( last != current){
    delay(3);
    current = digitalRead(BOTAO);
  } 
 return current;
}
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BOTAO,INPUT_PULLUP);
}
void loop() { 
botao  = debounce (estadobotao);
  if (botao == LOW && botaovelho == HIGH){
     estadobotao = !estadobotao;
  }
  
  botaovelho = botao;
  
  if(estadobotao == true) {
    digitalWrite(LED,HIGH);
  }
  else {
      digitalWrite(LED,LOW);
  }
  
  delay(60);
}
