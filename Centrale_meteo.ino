#include <math.h>

//###########################
// CONSTANTES
//###########################
// define vachement mieux, sera remplacé à la compilation, évite de créer des variables et gagne des octets
// Constantes de l'equations de la girouette. Equation définie par reduction elliptique via l'outil NLREG
#define xc 514.657313 
#define yc 511.220249
#define wcx0 0.95125475
#define wcx1 -0.02694436
#define wcy0 -0.02694436
#define wcy1 0.98510627
#define offsetAWA 0 // Offset girouette pour calibration (en degrés)

// Constantes de l'anémomètre
#define pin_Anemo 2
#define samples_read_Anemo 2
#define factorAWS 1.8 //Offset anemo (en ???)

// Constantes :
#define pi 3.14159265359

//###########################
// SETUP
//###########################
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // On déclare la pinAnemo en entrée:
  pinMode(pin_Anemo, INPUT);
}


//###########################
// PROGRAMME
//###########################
// the loop routine runs over and over again forever:
void loop() {

  int AWA = readAWA();
  Serial.print(AWA);
  Serial.print(";");
  float AWS = readAWS();
  Serial.print(AWS);
  Serial.print("\n");
  
  delay(250);        // delay in between reads for stability
}
