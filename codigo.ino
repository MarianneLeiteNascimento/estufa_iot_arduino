const int analog = A0;
int valorLido = 0;
double temperatura;
double milivolts = 0;
float seno;
int frequencia;
int LEDO = 8;
int MOTORPIN = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(LEDO, OUTPUT);
  pinMode(MOTORPIN, OUTPUT);
}

void loop()
{
  valorLido = analogRead (analog);
  milivolts = (valorLido/ 1024.0) * 5000;
  temperatura = (milivolts - 500) * 0.1;
  
  Serial.print("Temperatura em °C ");
  Serial.print(temperatura,1);
  
  if (temperatura > 30 && temperatura < 50) {
     digitalWrite(MOTORPIN,HIGH);
  } else if (temperatura > 50.0) {
  //PIEZO
  for(int x=0; x<180; x++){
    seno=(sin(x*3.1416/180));
  frequencia = 2000+(int(seno*1000));
    tone(9, frequencia);
  	delay(2);
  }  
  
  //LED
  digitalWrite(LEDO, HIGH);
  delay(1000);
  digitalWrite(LEDO, LOW);
  delay(1000);
  } else{
    Serial.println ("Temperatura normal");
     digitalWrite(MOTORPIN, LOW);
    
  }    
}
