const float Echo=6;
const float Trig=7;
long duracion, distancia;   

void setup() {                
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Echo, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Trig, OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(13, 1);            // Define el pin 13 como salida
  }
  
void loop() {
  
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  
  duracion = pulseIn(Echo, HIGH);
  distancia = duracion*0.034/2;            // calcula la distancia en centimetros
  
  if (distancia >= 200 || distancia <= 0){  // si la distancia es mayor a 500cm o menor a 0cm 
    Serial.println("---");                  // no mide nada
  }
  else {
    Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
    digitalWrite(13, 0);               // en bajo el pin 13
  }
  
   if (distancia <= 15 && distancia >= 1){
    digitalWrite(13, 1);                     // en alto el pin 13 si la distancia es menor a 10cm
    Serial.println("La Alarma se ha activado.......");         // envia la palabra Alarma por el puerto serial
  }
  delay(100);                                // Tiempo de refrescamiento de 50ms

}
