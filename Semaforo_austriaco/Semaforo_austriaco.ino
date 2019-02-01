int rosso1 = 8;
int giallo1 = 10;
int verde1 = 12;
int rosso2 = 5;
int giallo2 = 3;
int verde2 = 1;

//String incomingByte;

void setup() {
  /*Serial.begin(9600);
  Serial.print("seriale attivata");*/
  pinMode(rosso1, OUTPUT);
  pinMode(giallo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(rosso2, OUTPUT);
  pinMode(giallo2, OUTPUT);
  pinMode(verde2, OUTPUT);
}
void loop() {
  /*while(Serial.available() == 0);
  if (Serial.available() > 0){
    incomingByte = Serial.readString();
    Serial.print("I received");
    Serial.println(incomingByte.toInt());
    
  }*/
  Tempo1();
  delay(3000);  
  lampVerde2();
  Tempo2();
  delay(700);
  Tempo3();
  delay(3000);
  lampVerde1();
  Tempo4();
  delay(700);
}

void Tempo1() {
  digitalWrite(giallo1, LOW);
  digitalWrite(rosso1, HIGH);
  digitalWrite(verde1, LOW);
  digitalWrite(rosso2, LOW);
  digitalWrite(giallo2, LOW);
  digitalWrite(verde2, HIGH);
}
void Tempo2() {
  digitalWrite(rosso1, HIGH);
  digitalWrite(giallo1, HIGH);
  digitalWrite(giallo2, HIGH);
}
void Tempo3(){
  digitalWrite(rosso1, LOW);
  digitalWrite(giallo1, LOW);
  digitalWrite(verde1, HIGH);
  digitalWrite(rosso2, HIGH);
  digitalWrite(giallo2, LOW);
  digitalWrite(verde2, LOW);
}
void Tempo4(){  
  digitalWrite(giallo1, HIGH);
  digitalWrite(rosso2, HIGH);
  digitalWrite(giallo2, HIGH);
}
void lampVerde1(){
  for(int i = 0; i < 4; i++){  
    digitalWrite(verde1, LOW);
    delay(200);
    digitalWrite(verde1, HIGH);
    delay(200);
  }
  digitalWrite(verde1, LOW);
}
void lampVerde2(){
  for(int i = 0; i < 4; i++){  
    digitalWrite(verde2, LOW);
    delay(200);
    digitalWrite(verde2, HIGH);
    delay(200);
  }
  digitalWrite(verde1, LOW);
}
