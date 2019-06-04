/*
 Name:		Slave.ino
 Created:	12/24/2017 7:22:32 PM
 Author:	ps
*/

//////////////////////////////////////////////////////////////////////////////
// Imports
#include <SoftwareSerial.h>

///////////////////////////////////////////////////////////////
// defines f�r Pins
#define BTN_16_9 2
#define BTN_4_3 3
#define BTN_1_1 4
#define BTN_LETTER 5
#define BTN_PWR_ON 6
#define BTN_PWR_OFF 7
#define BTN_BLANK_ON 8
#define BTN_BLANK_OFF 9
#define BTN_HDMI1 10
#define BTN_HDMI2 11
#define BTN_VGA 12

#define BTN_SPARE_1 A2
#define BTN_SPARE_2 A3
#define BTN_SPARE_3 A4

#define SOFT_SER_TXD A0
#define SOFT_SER_RXD A1
#define SOFT_BAUD 9600
#define BAUD 115200

#define RATIO_16_9		"\r*asp=16:9#\r"   //<CR>*asp=16:9#<CR>
#define RATIO_4_3		"\r*asp=4:3#\r"      //<CR>*asp=4:3#<CR>
#define RATIO_1_1		"\r*asp=REAL#\r"     //<CR>*asp=REAL#<CR>
#define RATIO_LETTER	"\r*asp=LBOX#\r"   //<CR>*asp=LBOX#<CR>
#define PWR_ON			"\r*pow=on#\r"      //<CR>*pow=on#<CR>
#define PWR_OFF			"\r*pow=off#\r"    //<CR>*pow=off#<CR>
#define BLANK_ON		"\r*blank=on#\r"  //<CR>*blank=on#<CR>
#define BLANK_OFF		"\r*blank=off#\r" //<CR>*blank=off#<CR>
#define SRC_HDMI1		 "\r*sour=hdmi#\r"    //<CR>*sour=hdmi#<CR>
#define SRC_HDMI2		"\r*sour=hdmi2#\r"    //<CR>*sour=hdmi2#<CR>
#define SRC_VGA			"\r*sour=RGB#\r"   //<CR>*sour=RGB#<CR>

#define SOFT_RATIO_16_9 "soft 16_9"    //<CR>*asp=16:9#<CR>
#define SOFT_RATIO_4_3 "soft 4:3\n"      //<CR>*asp=4:3#<CR>
#define SOFT_RATIO_1_1 "soft 1:1\n"      //<CR>*asp=REAL#<CR>
#define SOFT_RATIO_LETTER "soft LEtterbox\n"   //<CR>*asp=LBOX#<CR>
#define SOFT_PWR_ON "soft PWR_ON\n"      //<CR>*pow=on#<CR>
#define SOFT_PWR_OFF "soft PWR_OFF\n"    //<CR>*pow=off#<CR>
#define SOFT_BLANK_ON "soft BLank ON\n"  //<CR>*blank=on#<CR>
#define SOFT_BLANK_OFF "soft Blank OFF\n"//<CR>*blank=off#<CR>
#define SOFT_SRC_HDMI1 "soft HDMI1\n"    //<CR>*sour=hdmi#<CR>
#define SOFT_SRC_HDMI2 "soft HDMI2\n"    //<CR>*sour=hdmi2#<CR>
#define SOFT_SRC_VGA "soft VGA\n"    //<CR>*sour=RGB#<CR>

///////////////////////////////////////////////////////////////////////////
//Variablen deklarationen
byte Btns = 0; // variablen daklarationen Btns-> das ergebnis nach dem asulesen der Btns... 
byte pwrOnCounter = 0;
byte pwrOffCounter = 0;
int millisPWR_ON_BTN = 0;
int millisPWR_OFF_BTN = 0;

byte softSerByte = 0;
/////////////////////////////////////////////////////////////////////////
// Funktions deklarationen
byte readButns();
void setupPins();
void setupSerial();
void sendCommands(byte bitMask);
//////////////////////////////////////////////////////////////////////////
// Objekte initalisieren
SoftwareSerial softSerial(SOFT_SER_RXD, SOFT_SER_TXD);
//////////////////////////////////////////////////////////////////////////


void setup()
{


									   // setup Serial software Port, Buttons=input,
	setupPins();
	setupSerial();
}

void loop()
{
	readButns();
	/*
	Btns = readButns();
	if (Btns)
	{
	sendCommands(Btns);
	}
	// lese SoftSerial sende ggf. befehle per Serial
	while (softSerial.available())
	{
	softSerByte = softSerial.read();
	}
	if (softSerByte)
	{
	sendCommands(softSerByte);
	}
	*/
	delay(100); // sleep 100 msec
}
//////////////////////////////////////////////////////////////////////
// funktions DEfinitionen

void sendCommands(byte bitMask)
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
	if (bitMask & 0b01000000)
	{
		// 4:3:9
		Serial.print(RATIO_4_3);
	}
	if (bitMask & 0b00100000)
	{
		// 1:1
		Serial.print(RATIO_1_1);
	}
	if (bitMask & 0b00010000)
	{
		// Letter
		Serial.print(RATIO_LETTER);
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

byte readButns()
{
	if (!(digitalRead(BTN_16_9)))
	{
		Serial.print(RATIO_16_9);
		softSerial.print(RATIO_16_9);
	}
	if (!(digitalRead(BTN_4_3)))
	{
		Serial.print(RATIO_4_3);
		softSerial.print(RATIO_4_3);
	}
	if (!(digitalRead(BTN_1_1)))
	{
		Serial.print(RATIO_1_1);
		softSerial.print(RATIO_1_1);
	}
	if (!(digitalRead(BTN_LETTER)))
	{
		Serial.print(RATIO_LETTER);
		softSerial.print(RATIO_LETTER);
	}
	if (!(digitalRead(BTN_PWR_ON))) // checke hier ob der pwrOnCounter > 30
	{
		pwrOnCounter++;
		if (pwrOnCounter > 30)
		{
			Serial.print(PWR_ON);
			softSerial.print(PWR_ON);
			pwrOnCounter = 0;
		}
	}
	else
	{
		pwrOnCounter = 0;           // button wasn`t pressed long enough
	}
	if (!(digitalRead(BTN_PWR_OFF))) //checke hier ob der pwrOffCounter > 30
	{
		pwrOffCounter++;
		if (pwrOffCounter > 30) {
			Serial.print(PWR_OFF);
			softSerial.print(PWR_OFF);
			pwrOffCounter = 0;
		}
	}
	else
	{
		pwrOffCounter = 0;          // button wasn`t pressed long enough
	}
	if (!(digitalRead(BTN_BLANK_ON)))
	{
		Serial.print(BLANK_ON);
		softSerial.print(BLANK_ON);
	}
	if (!(digitalRead(BTN_BLANK_OFF)))
	{
		Serial.print(BLANK_OFF);
		softSerial.print(BLANK_OFF);
	}
	if (!(digitalRead(BTN_HDMI1)))
	{
		Serial.print(SRC_HDMI1);
		softSerial.print(SRC_HDMI1);
	}
	if (!(digitalRead(BTN_HDMI2)))
	{
		Serial.print(SRC_HDMI2);
		softSerial.print(SRC_HDMI2);
	}
	if (!(digitalRead(BTN_VGA)))
	{
		Serial.print(SRC_VGA);
		softSerial.print(SRC_VGA);
	}

	/*
	byte dasByte = 0b00000000;
	// lese alle Buttns ein, erstelle ein Bitmaske, 1 Byte, zum senden
	if (!(digitalRead(BTN_16_9)))
	{
	dasByte = dasByte | 0b10000000;
	}
	if (!(digitalRead(BTN_4_3)))
	{
	dasByte = dasByte | 0b01000000;
	}
	if (!(digitalRead(BTN_1_1)))
	{
	dasByte = dasByte | 0b00100000;
	}
	if (!(digitalRead(BTN_LETTER)))
	{
	dasByte = dasByte | 0b00010000;
	}
	if (!(digitalRead(BTN_PWR_ON))) // checke hier ob der pwrOnCounter > 30
	{
	pwrOnCounter++;
	if (pwrOnCounter > 30)
	dasByte = dasByte | 0b00001000;
	pwrOnCounter = 0;
	}
	else
	{
	pwrOnCounter = 0;           // button wasn`t pressed long enough
	}
	if (!(digitalRead(BTN_PWR_OFF))) //checke hier ob der pwrOffCounter > 30
	{
	pwrOffCounter++;
	if (pwrOffCounter > 30)
	dasByte = dasByte | 0b00000100;
	pwrOffCounter = 0;
	}
	else
	{
	pwrOffCounter = 0;          // button wasn`t pressed long enough
	}
	if (!(digitalRead(BTN_BLANK_ON)))
	{
	dasByte = dasByte | 0b00000010;
	}
	if (!(digitalRead(BTN_BLANK_OFF)))
	{
	dasByte = dasByte | 0b00000001;
	}

	return dasByte;
	*/
}

void setupPins() {
	pinMode(BTN_16_9, INPUT_PULLUP);
	pinMode(BTN_4_3, INPUT_PULLUP);
	pinMode(BTN_1_1, INPUT_PULLUP);
	pinMode(BTN_LETTER, INPUT_PULLUP);
	pinMode(BTN_PWR_ON, INPUT_PULLUP);
	pinMode(BTN_PWR_OFF, INPUT_PULLUP);
	pinMode(BTN_BLANK_ON, INPUT_PULLUP);
	pinMode(BTN_BLANK_OFF, INPUT_PULLUP);
	pinMode(BTN_HDMI1, INPUT_PULLUP);
	pinMode(BTN_HDMI2, INPUT_PULLUP);
	pinMode(BTN_VGA, INPUT_PULLUP);

  pinMode(BTN_SPARE_1, INPUT_PULLUP);
  pinMode(BTN_SPARE_2, INPUT_PULLUP);
  pinMode(BTN_SPARE_3, INPUT_PULLUP);

	pinMode(SOFT_SER_TXD, OUTPUT);
	pinMode(SOFT_SER_RXD, INPUT);
}

void setupSerial() {
	softSerial.begin(SOFT_BAUD);
	softSerial.listen();
	Serial.begin(BAUD);
}
