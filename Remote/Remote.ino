//////////////////////////////////////////////////////////////////////////////
// Imports
#include <SoftwareSerial.h>

///////////////////////////////////////////////////////////////
// defines für Pins
#define BTN_16_9 2
#define BTN_4_3 3
#define BTN_1_1 4
#define BTN_LETTER 5
#define BTN_PWR_ON 6
#define BTN_PWR_OFF 7
#define BTN_BLANK_ON 8
#define BTN_BLANK_OFF 9

#define SOFT_SER_TXD 11
#define SOFT_SER_RXD 12
#define SOFT_BAUD 9600

///////////////////////////////////////////////////////////////////////////
//Variablen deklarationen
byte Btns = 0; // variablen daklarationen Btns-> das ergebnis nach dem asulesen der Btns... 
byte pwrOnCounter = 0;
byte pwrOffCounter = 0;
/////////////////////////////////////////////////////////////////////////
// Funktions deklarationen
byte readButns ();
void setupPins();
void setupSerial();
//////////////////////////////////////////////////////////////////////////
// Objekte initalisieren
SoftwareSerial softSerial (SOFT_SER_RXD, SOFT_SER_TXD);
//////////////////////////////////////////////////////////////////////////
void setup() {
  // setup Serial software Port, Buttons=input,
  setupPins();
  setupSerial();
}
void loop() {
  // Polle alle Buttons, sende per UART das ergebnis wenn einer HIGH ist, 
  Btns = readButns();
  if (Btns)
  {
      softSerial.write(Btns);  // dies sendet die Bitmaske der Buttons auf der Remote
  }
  delay(100); // sleep 100 msec
}
//////////////////////////////////////////////////////////////////////
// funktions DEfinitionen

byte readButns ()
{ 
  byte dasByte = 0b00000000;
  // lese alle Buttns ein, erstelle ein Bitmaske, 1 Byte, zum senden
  if (digitalRead (BTN_16_9))
  {
    dasByte = dasByte | 0b10000000;
  }
  if (digitalRead (BTN_4_3))
  {
    dasByte = dasByte | 0b01000000;
  }
  if (digitalRead (BTN_1_1))
  {
    dasByte = dasByte | 0b00100000;
  }
  if (digitalRead (BTN_LETTER))
  {
    dasByte = dasByte | 0b00010000;
  }
  if (digitalRead (BTN_PWR_ON)) // checke hier ob der pwrOnCounter > 30
  {
    pwrOnCounter++ ;
    if (pwrOnCounter > 30)
      dasByte = dasByte | 0b00000100;
      pwrOnCounter = 0;
  }
  else
  {
    pwrOnCounter = 0;           // button wasn`t pressed long enough
  }
  if (digitalRead (BTN_PWR_OFF)) //checke hier ob der pwrOffCounter > 30
  {
    pwrOffCounter++ ;
    if (pwrOffCounter > 30)
      dasByte = dasByte | 0b00000100;
      pwrOffCounter = 0;
  }    
  else 
  {
    pwrOffCounter = 0;          // button wasn`t pressed long enough
  }
  if (digitalRead (BTN_BLANK_ON))
  {
    dasByte = dasByte | 0b00000010;
  }
  if (digitalRead (BTN_BLANK_OFF))
  {
    dasByte = dasByte | 0b00000001;
  }
  
  return dasByte;
}

void setupPins(){
  pinMode (BTN_16_9,  INPUT_PULLUP);
  pinMode (BTN_4_3,  INPUT_PULLUP);
  pinMode (BTN_1_1,  INPUT_PULLUP);
  pinMode (BTN_LETTER,  INPUT_PULLUP);
  pinMode (BTN_PWR_ON,  INPUT_PULLUP);
  pinMode (BTN_PWR_OFF,  INPUT_PULLUP);
  pinMode (BTN_BLANK_ON,  INPUT_PULLUP);
  pinMode (BTN_BLANK_OFF,  INPUT_PULLUP);

  pinMode (SOFT_SER_TXD,  OUTPUT);
  pinMode (SOFT_SER_RXD,  INPUT);  
  }

 void setupSerial(){
  softSerial.begin(SOFT_BAUD);  
 }
