int rosso1 = 8;
int giallo1 = 10;
int verde1 = 12;
int rosso2 = 6;
int giallo2 = 4;
int verde2 = 2;

String inserito;
int tempoTot = 0;
int tempoVerde = 0;
int tempoGiallo = 0;
int nLampVerde = 0;
int durataLampVerde = 0;
int seriale = 0;
int somma = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("seriale attivata");
  pinMode(rosso1, OUTPUT);
  pinMode(giallo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(rosso2, OUTPUT);
  pinMode(giallo2, OUTPUT);
  pinMode(verde2, OUTPUT);
}
void loop() {
  if(seriale == 0){
    serialeRichiesta();
  }
  Tempo1();
  delay(tempoVerde);  
  lampVerde2();
  Tempo2();
  delay(tempoGiallo);
  Tempo3();
  delay(tempoVerde);
  lampVerde1();
  Tempo4();
  delay(tempoGiallo);
}
void serialeRichiesta() {
  while(seriale == 0){
    serialeTempoTot();
    serialeGiallo();
    serialeNLampVerde();
    sommaTempo();
    if(somma < tempoTot){
      calcoloTempoVerde(); 
      seriale = 1;
    }
    else{
      Serial.println("La durata totale del semaforo è minore della durata del semaforo giallo e i lampeggi di quello verde");
      Serial.println("Reinserire i dati corretti:");
      String inserito;
      tempoTot = 0;
      tempoVerde = 0;
      tempoGiallo = 0;
      nLampVerde = 0;
      durataLampVerde = 0;
      seriale = 0;
      somma = 0;
    }
  }
}
void serialeTempoTot(){
  Serial.println("Inserire la durata totale del semaforo:");
  while(Serial.available() == 0);
    if (Serial.available() > 0){
      inserito = Serial.readString();
      Serial.println(inserito.toInt());
      tempoTot = inserito.toInt();
  }
}
void serialeGiallo(){
  Serial.println("Inserire la durata del giallo:");
  while(Serial.available() == 0);
    if (Serial.available() > 0){
      inserito = Serial.readString();
      Serial.println(inserito.toInt());
      tempoGiallo = inserito.toInt();
    }
}
void serialeNLampVerde(){
  Serial.println("Inserire quanti lampeggi deve fare il semaforo verde:");
  while(Serial.available() == 0);
    if (Serial.available() > 0){
      inserito = Serial.readString();
      Serial.println(inserito.toInt());
      nLampVerde = inserito.toInt();
      if(nLampVerde > 0){
        serialeDurataLampVerde();
      }
    }
}
void serialeDurataLampVerde(){
  Serial.println("Inserire la durata dei ogni lampeggo del semaforo verde:");
  while(Serial.available() == 0);
    if (Serial.available() > 0){
      inserito = Serial.readString();
      Serial.println(inserito.toInt());
      durataLampVerde = inserito.toInt();
    }
}
void sommaTempo(){
  somma = somma + (2*tempoGiallo);
  somma = somma + (durataLampVerde*nLampVerde*2);
}
void calcoloTempoVerde(){
  tempoVerde = tempoTot - somma;
  tempoVerde = tempoVerde/2;
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
  digitalWrite(verde2, LOW);
}
void Tempo3(){
  digitalWrite(rosso1, LOW);
  digitalWrite(giallo1, LOW);
  digitalWrite(verde1, HIGH);
  digitalWrite(rosso2, HIGH);
  digitalWrite(giallo2, LOW);
}
void Tempo4(){  
  digitalWrite(giallo1, HIGH);
  digitalWrite(rosso2, HIGH);
  digitalWrite(giallo2, HIGH);
}
void lampVerde1(){
  for(int i = 0; i < nLampVerde; i++){  
    digitalWrite(verde1, LOW);
    delay(durataLampVerde);
    digitalWrite(verde1, HIGH);
    delay(durataLampVerde);
  }
  digitalWrite(verde1, LOW);
}
void lampVerde2(){
  for(int i = 0; i < nLampVerde; i++){  
    digitalWrite(verde2, LOW);
    delay(durataLampVerde);
    digitalWrite(verde2, HIGH);
    delay(durataLampVerde);
  }
  digitalWrite(verde1, LOW);
}
