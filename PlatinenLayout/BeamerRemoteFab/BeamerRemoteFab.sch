EESchema Schematic File Version 4
LIBS:BeamerRemoteFab-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5CEFE3A2
P 6750 4600
F 0 "A1" H 6750 3514 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 6750 3423 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 6900 3650 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 6750 3600 50  0001 C CNN
	1    6750 4600
	1    0    0    -1  
$EndComp
$Comp
L 2019-05-30_17-25-05:max232cse U1
U 1 1 5CF0149D
P 2050 3350
F 0 "U1" H 3350 3737 60  0000 C CNN
F 1 "max232cse" H 3350 3631 60  0000 C CNN
F 2 "Peer:max232cse" H 3350 3590 60  0001 C CNN
F 3 "" H 2050 3350 60  0000 C CNN
	1    2050 3350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x10 J1
U 1 1 5CF0220D
P 7900 1650
F 0 "J1" H 7980 1642 50  0000 L CNN
F 1 "Conn_01x10" H 7980 1551 50  0000 L CNN
F 2 "TerminalBlock_RND:TerminalBlock_RND_205-00295_1x10_P5.08mm_Horizontal" H 7900 1650 50  0001 C CNN
F 3 "~" H 7900 1650 50  0001 C CNN
	1    7900 1650
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J2
U 1 1 5CF0230F
P 5450 4000
F 0 "J2" H 5500 4217 50  0000 C CNN
F 1 "Conn_02x02_Odd_Even" H 5500 4126 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x02_P2.54mm_Vertical" H 5450 4000 50  0001 C CNN
F 3 "~" H 5450 4000 50  0001 C CNN
	1    5450 4000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J3
U 1 1 5CF02476
P 8500 4300
F 0 "J3" H 8550 4717 50  0000 C CNN
F 1 "Conn_02x05_Counter_Clockwise" H 8550 4626 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x05_P2.54mm_Vertical" H 8500 4300 50  0001 C CNN
F 3 "~" H 8500 4300 50  0001 C CNN
	1    8500 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 4000 5750 4000
Wire Wire Line
	6250 4100 5750 4100
Wire Wire Line
	4650 3750 5250 3750
Wire Wire Line
	5250 3750 5250 4000
Wire Wire Line
	5250 4100 4950 4100
Wire Wire Line
	4950 4100 4950 3850
Wire Wire Line
	4950 3850 4650 3850
NoConn ~ 4650 3950
NoConn ~ 4650 4050
Wire Wire Line
	4650 3550 4950 3550
Wire Wire Line
	4950 3550 4950 2100
Wire Wire Line
	4950 2100 5200 2100
Wire Wire Line
	4650 3650 5000 3650
Wire Wire Line
	5000 3650 5000 2200
Wire Wire Line
	4650 3350 6950 3350
NoConn ~ 6850 3600
NoConn ~ 6650 3600
NoConn ~ 7250 4400
NoConn ~ 2050 3950
NoConn ~ 2050 4050
NoConn ~ 2050 3850
NoConn ~ 2050 3450
$Comp
L power:+5V #PWR0101
U 1 1 5CF03F67
P 6950 3350
F 0 "#PWR0101" H 6950 3200 50  0001 C CNN
F 1 "+5V" H 6965 3523 50  0000 C CNN
F 2 "" H 6950 3350 50  0001 C CNN
F 3 "" H 6950 3350 50  0001 C CNN
	1    6950 3350
	1    0    0    -1  
$EndComp
Connection ~ 6950 3350
$Comp
L power:GND #PWR0102
U 1 1 5CF03FAF
P 6850 5900
F 0 "#PWR0102" H 6850 5650 50  0001 C CNN
F 1 "GND" H 6855 5727 50  0000 C CNN
F 2 "" H 6850 5900 50  0001 C CNN
F 3 "" H 6850 5900 50  0001 C CNN
	1    6850 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 5600 6750 5600
Wire Wire Line
	6850 5600 6850 5750
Connection ~ 6850 5600
Wire Wire Line
	4650 3450 5100 3450
Wire Wire Line
	5100 3450 5100 5750
Wire Wire Line
	5100 5750 6850 5750
Connection ~ 6850 5750
Wire Wire Line
	6850 5750 6850 5900
$Comp
L Device:CP C1
U 1 1 5CF04759
P 1600 3450
F 0 "C1" H 1718 3496 50  0000 L CNN
F 1 "CP" H 1718 3405 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 1638 3300 50  0001 C CNN
F 3 "~" H 1600 3450 50  0001 C CNN
	1    1600 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5CF047BB
P 1600 3850
F 0 "C2" H 1718 3896 50  0000 L CNN
F 1 "CP" H 1718 3805 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 1638 3700 50  0001 C CNN
F 3 "~" H 1600 3850 50  0001 C CNN
	1    1600 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 3300 2050 3300
Wire Wire Line
	2050 3300 2050 3350
Wire Wire Line
	1600 3600 1850 3600
Wire Wire Line
	1850 3600 1850 3550
Wire Wire Line
	1850 3550 2050 3550
Wire Wire Line
	1600 3700 1950 3700
Wire Wire Line
	1950 3700 1950 3650
Wire Wire Line
	1950 3650 2050 3650
Wire Wire Line
	1600 4000 1950 4000
Wire Wire Line
	1950 4000 1950 3750
Wire Wire Line
	1950 3750 2050 3750
Wire Wire Line
	6950 3350 6950 3600
NoConn ~ 7250 4000
NoConn ~ 7250 4100
Wire Wire Line
	5200 1250 7700 1250
Wire Wire Line
	5200 1250 5200 2100
Wire Wire Line
	7700 1350 5400 1350
Wire Wire Line
	5400 1350 5400 2200
Wire Wire Line
	5000 2200 5400 2200
Wire Wire Line
	6950 3350 7700 3350
Wire Wire Line
	7700 3350 7700 2150
Wire Wire Line
	6850 5750 7600 5750
Wire Wire Line
	7600 5750 7600 2050
Wire Wire Line
	7600 2050 7700 2050
Text GLabel 9800 1350 0    50   BiDi ~ 0
BTN_16_9
$EndSCHEMATC
