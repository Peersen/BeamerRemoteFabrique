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
#define BAUD 115200

#define RATIO_16_9 "Test 16:9"    //<CR>*asp=16:9#<CR>
#define RATIO_4_3 "Test 4:3"      //<CR>*asp=4:3#<CR>
#define RATIO_1_1 "Test 1:1"      //<CR>*asp=REAL#<CR>
#define LETTER "Test LEtterbox"   //<CR>*asp=LBOX#<CR>
#define PWR_ON "Test PWR_ON"      //<CR>*pow=on#<CR>
#define PWR_OFF "Test PWR_OFF"    //<CR>*pow=off#<CR>
#define BLANK_ON "Test BLank ON"  //<CR>*blank=on#<CR>
#define BLANK_OFF "Test Blank OFF"//<CR>*blank=off#<CR>

#define SRC_HDMI1 "Test HDMI1"    //<CR>*sour=hdmi#<CR>
#define SRC_HDMI2 "Test HDMI2"    //<CR>*sour=hdmi2#<CR>
#define SRC_VGA "Test VGA"    //<CR>*sour=RGB#<CR>

///////////////////////////////////////////////////////////////////////////
//Variablen deklarationen
byte Btns = 0; // variablen daklarationen Btns-> das ergebnis nach dem asulesen der Btns... 
byte pwrOnCounter = 0;
byte pwrOffCounter = 0;
byte softSerByte =0;
/////////////////////////////////////////////////////////////////////////
// Funktions deklarationen
byte readButns ();
void setupPins();
void setupSerial();
void sendCommands(byte bitMask);
//////////////////////////////////////////////////////////////////////////
// Objekte initalisieren
SoftwareSerial softSerial (SOFT_SER_RXD, SOFT_SER_TXD);
//////////////////////////////////////////////////////////////////////////


void setup() 
{
  // setup Serial software Port, Buttons=input,
  setupPins();
  setupSerial();
}

void loop() 
{
  Btns = readButns();
  if (Btns)
  {
    sendCommands (Btns);
  }
  // lese SoftSerial sende ggf. befehle per Serial
  while (softSerial.available())
  {
    softSerByte = softSerial.read();
  }
  if (softSerByte)
  {
    sendCommands (softSerByte);
  }
  delay(100); // sleep 100 msec
}
//////////////////////////////////////////////////////////////////////
// funktions DEfinitionen

void sendCommands (byte bitMask)
{
  
  // 0b10000000 -> 16_9
  // 0b01000000 -> 4_3
  // 0b00100000 -> 1_1
  // 0b00010000 -> Letter
  // 0b00001000 -> PWR_ON
  // 0b00000100 -> PWR_OFF
  // 0b00000010 -> BLANK_ON
  // 0b00000001 -> BLANK_OFF
  if (bitMask & 0b10000000)
  {
    // 16:9
    Serial.print(RATIO_16_9);
  }
  if (bitMask & 0b10000000)
  {
    // 4:3:9
    Serial.print(RATIO_4_3);
  }
  if (bitMask & 0b01000000)
  {
    // 1:1
    Serial.print(RATIO_1_1);
  }
  if (bitMask & 0b00100000)
  {
    // Letter
    Serial.print(LETTER);
  }
  if (bitMask & 0b00001000)
  {
    // PWR_ON
    Serial.print(PWR_ON);
  }
  if (bitMask & 0b00000100)
  {
    // PWR_OFF
    Serial.print(PWR_OFF);
  }
  if (bitMask & 0b00000010)
  {
    // BLANK_ON
    Serial.print(BLANK_ON);
  }
  if (bitMask & 0b00000001)
  {
    // BLANK_OFF
    Serial.print(BLANK_OFF);
  }
}

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
  Serial.begin (BAUD); 
 }
