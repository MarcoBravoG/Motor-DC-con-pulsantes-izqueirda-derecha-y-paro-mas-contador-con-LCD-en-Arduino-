#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //

// variables tipo entero

const int Izquierda = 2;
const int Derecha = 3;
const int Stop = 4;

const int M1 = 12;
const int M2 = 13;
int contador=0;
int i=0;
int iz=0;
int der=0;



 
// VARIABLES DE ESTADO DE BOTONES
int estado1 = HIGH;
int estado2 = HIGH;
int estado3 = HIGH;



void setup() {
  // CONFIGURAR PINES COMO ENTRADAS
  pinMode(Izquierda, INPUT);
  pinMode(Derecha, INPUT);
  pinMode(Stop, INPUT);
  
  // CONFIGURAR PIN DE LED COMO SALIDA
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  // COMUNICACION SERIAL
  Serial.begin(9600);
  // LCD
   lcd.init();                         // Se inicializa el LCD 16x2
   lcd.backlight();                           
   lcd.clear(); 
   lcd.setCursor(0,0);  
  lcd.print("      UPS!      ");

}
 
void loop() {
  // LEER EL ESTADO DE PINES DE BOTON A VARIABLES
  estado1 = digitalRead(Izquierda);
  estado2 = digitalRead(Derecha);
  estado3 = digitalRead(Stop);
 
  //                              Izquierda

  if (estado1 == LOW) {
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW); 
    Serial.println("Izquierda");
    lcd.setCursor(0,0);  
    lcd.print("Izquierda:");
    iz=1;
  }

  //                                Derecha

  if (estado2 == LOW) {
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);   
    Serial.println("Derecha");
    lcd.setCursor(0,0);  
    lcd.print("Derecha: ");
    iz=1;
  }

//                                  Stop

    if (estado3 == LOW) {

    iz = 0;
    contador=0;
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);    
    Serial.println("Stop"); 
    lcd.setCursor(0,0);  
    lcd.print("Stop:    ");
    lcd.setCursor(0,1);     
    lcd.print("      ");

  }
//                                 Contador


    if (iz == 1) {
    lcd.setCursor(0,1);     
    lcd.print(contador);
    delay(500);   
    contador++;  
     }

//                        Cuando cumple a condicion 
    if (contador == 80) {
    lcd.setCursor(0,0); 
    lcd.print("Stop:    ");
    contador=0;
    iz=0;
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW); 
     }


}