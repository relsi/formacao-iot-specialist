// C++ code
//
#define ledPin 4
#define sensorPin A0
#define piezzoPin 5
#define motorPin 3

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(piezzoPin,OUTPUT);
  pinMode(motorPin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //le o valor enviado pelo sensor
  int valorSensor = analogRead(sensorPin);

  //transforma o valor lido em volts (milivolts mV)
  float tensaoSensor = valorSensor * (5000 / 1024.0);
  
  //transforma a tensão encontrada em graus celcius
  float temperatura = (tensaoSensor - 500) / 10;
  
  //Serial.println(temperatura);
  if(temperatura > 50.0){
    digitalWrite(ledPin, HIGH);
    digitalWrite(piezzoPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    digitalWrite(piezzoPin, LOW);
    delay(1000);     
  }
  
  if(temperatura >= 30.0){
    //apenas para fazer o motor se mover
    //o correto é utilizar um circuito de ponte H
    digitalWrite(motorPin, HIGH);
    delay(10);
    digitalWrite(motorPin, LOW);
    delay(10);
  }
}