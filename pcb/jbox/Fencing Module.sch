EESchema Schematic File Version 2
LIBS:power,device,transistors,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,.\Jbox.cache
EELAYER 24  0
EELAYER END
$Descr A4 11700 8267
Sheet 5 9
Title ""
Date "18 aug 2008"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	7900 3650 8150 3650
Wire Wire Line
	8150 3650 8150 4600
Wire Wire Line
	9450 5250 9650 5250
Wire Wire Line
	8400 5250 8150 5250
Connection ~ 800  3200
Wire Wire Line
	800  3200 700  3200
Connection ~ 1550 2900
Wire Wire Line
	1200 2900 1850 2900
Wire Wire Line
	1850 3350 1850 3500
Wire Wire Line
	1850 3350 2550 3350
Wire Wire Line
	2450 6950 2450 7050
Wire Wire Line
	2450 6250 2450 6450
Connection ~ 4250 5000
Wire Wire Line
	3850 5000 4700 5000
Wire Wire Line
	4400 6000 4400 5900
Wire Wire Line
	4400 5100 4400 5400
Wire Wire Line
	2300 4150 2550 4150
Wire Wire Line
	9000 3950 8200 3950
Wire Wire Line
	8200 3950 8200 3550
Wire Wire Line
	8200 3550 7900 3550
Wire Wire Line
	9000 3650 8300 3650
Wire Wire Line
	8300 3650 8300 3350
Wire Wire Line
	8300 3350 7900 3350
Wire Wire Line
	7900 3150 8250 3150
Wire Wire Line
	8250 3150 8250 2350
Wire Wire Line
	8250 2350 9000 2350
Wire Wire Line
	6500 3550 6300 3550
Wire Wire Line
	6350 3250 6500 3250
Wire Wire Line
	7900 3050 8200 3050
Wire Wire Line
	8200 3050 8200 2200
Wire Wire Line
	8200 2200 9000 2200
Wire Wire Line
	7900 3250 8300 3250
Wire Wire Line
	8300 3250 8300 2500
Wire Wire Line
	8300 2500 9000 2500
Wire Wire Line
	7900 3450 8250 3450
Wire Wire Line
	8250 3450 8250 3800
Wire Wire Line
	8250 3800 9000 3800
Wire Wire Line
	2550 2850 2300 2850
Wire Wire Line
	4550 5200 4550 5400
Wire Wire Line
	4250 5000 4250 5400
Wire Wire Line
	4550 5900 4250 5900
Connection ~ 4400 5900
Wire Wire Line
	3850 5100 4700 5100
Connection ~ 4400 5100
Wire Wire Line
	3850 5200 4700 5200
Connection ~ 4550 5200
Connection ~ 4250 6150
Wire Wire Line
	3850 6150 4700 6150
Wire Wire Line
	4400 7150 4400 7050
Wire Wire Line
	4400 6250 4400 6550
Wire Wire Line
	4550 6350 4550 6550
Wire Wire Line
	4250 6150 4250 6550
Wire Wire Line
	4550 7050 4250 7050
Connection ~ 4400 7050
Wire Wire Line
	3850 6250 4700 6250
Connection ~ 4400 6250
Wire Wire Line
	3850 6350 4700 6350
Connection ~ 4550 6350
Wire Wire Line
	2250 6250 2600 6250
Connection ~ 2450 6250
Wire Wire Line
	2550 3050 1850 3050
Wire Wire Line
	1850 3050 1850 2900
Wire Wire Line
	1850 3500 1200 3500
Connection ~ 1550 3500
Wire Wire Line
	800  2900 800  3500
Wire Wire Line
	8150 4600 8600 4600
Wire Wire Line
	8600 4600 8600 4950
Wire Wire Line
	8800 5250 8950 5250
Wire Wire Line
	9650 5050 9400 5050
NoConn ~ 7900 3850
NoConn ~ 7900 2950
Text Label 6500 3450 2    60   ~
Reg Clock
Text Label 6500 3150 2    60   ~
Ser Clock
Text Label 6500 2950 2    60   ~
Ser Data
Text Label 3850 6350 2    60   ~
Green A Line
Text Label 3850 6250 2    60   ~
Green B Line
Text Label 3850 6150 2    60   ~
Green C Line
Text Label 3850 5200 2    60   ~
Red A Line
Text Label 3850 5100 2    60   ~
Red B Line
Text Label 3850 5000 2    60   ~
Red C Line
Text Label 2250 6250 2    60   ~
Piste
$Comp
L +5V #PWR032
U 1 1 48A9F8B4
P 8150 5250
F 0 "#PWR032" H 8150 5340 20  0001 C C
F 1 "+5V" H 8150 5340 30  0000 C C
	1    8150 5250
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR033
U 1 1 48A9F8A7
P 9400 5050
F 0 "#PWR033" H 9400 5050 30  0001 C C
F 1 "GND" H 9400 4980 30  0001 C C
	1    9400 5050
	0    1    -1   0   
$EndComp
Text Label 4900 3050 0    60   ~
Green A Line
Text Label 4900 3150 0    60   ~
Green B Line
Text Label 4900 3250 0    60   ~
Red B Line
Text Label 4900 3550 0    60   ~
Red A Line
$Comp
L GND #PWR034
U 1 1 48A9F83B
P 700 3200
F 0 "#PWR034" H 700 3200 30  0001 C C
F 1 "GND" H 700 3130 30  0001 C C
	1    700  3200
	0    1    1    0   
$EndComp
Text Label 2550 3700 2    60   ~
Piste
Text Label 4900 3850 0    60   ~
Green C Line
Text Label 4900 3950 0    60   ~
Red C Line
$Comp
L GND #PWR035
U 1 1 48A9F76C
P 2450 7050
F 0 "#PWR035" H 2450 7050 30  0001 C C
F 1 "GND" H 2450 6980 30  0001 C C
	1    2450 7050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR036
U 1 1 48A9F75D
P 4400 7150
F 0 "#PWR036" H 4400 7150 30  0001 C C
F 1 "GND" H 4400 7080 30  0001 C C
	1    4400 7150
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 48A9F75C
P 4250 6800
F 0 "R4" V 4330 6800 50  0000 C C
F 1 "R" V 4250 6800 50  0000 C C
	1    4250 6800
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 48A9F75B
P 4400 6800
F 0 "R6" V 4480 6800 50  0000 C C
F 1 "R" V 4400 6800 50  0000 C C
	1    4400 6800
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 48A9F75A
P 4550 6800
F 0 "R8" V 4630 6800 50  0000 C C
F 1 "R" V 4550 6800 50  0000 C C
	1    4550 6800
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K4
U 1 1 48A9F759
P 5050 6250
F 0 "K4" V 5000 6250 50  0000 C C
F 1 "CONN_3" V 5100 6250 40  0000 C C
	1    5050 6250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR037
U 1 1 48A9F72C
P 4400 6000
F 0 "#PWR037" H 4400 6000 30  0001 C C
F 1 "GND" H 4400 5930 30  0001 C C
	1    4400 6000
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR038
U 1 1 48A9F52C
P 2300 2850
F 0 "#PWR038" H 2300 2940 20  0001 C C
F 1 "+5V" H 2300 2940 30  0000 C C
	1    2300 2850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR039
U 1 1 48A9F524
P 2300 4150
F 0 "#PWR039" H 2300 4150 30  0001 C C
F 1 "GND" H 2300 4080 30  0001 C C
	1    2300 4150
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 48A9F512
P 2450 6700
F 0 "R2" V 2530 6700 50  0000 C C
F 1 "R" V 2450 6700 50  0000 C C
	1    2450 6700
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 48A9F506
P 4250 5650
F 0 "R3" V 4330 5650 50  0000 C C
F 1 "R" V 4250 5650 50  0000 C C
	1    4250 5650
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 48A9F504
P 4400 5650
F 0 "R5" V 4480 5650 50  0000 C C
F 1 "R" V 4400 5650 50  0000 C C
	1    4400 5650
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 48A9F500
P 4550 5650
F 0 "R7" V 4630 5650 50  0000 C C
F 1 "R" V 4550 5650 50  0000 C C
	1    4550 5650
	1    0    0    -1  
$EndComp
$Comp
L CONN_1 P2
U 1 1 48A9F4F7
P 2750 6250
F 0 "P2" H 2830 6250 40  0000 L C
F 1 "CONN_1" H 2750 6305 30  0001 C C
	1    2750 6250
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K3
U 1 1 48A9F4EC
P 5050 5100
F 0 "K3" V 5000 5100 50  0000 C C
F 1 "CONN_3" V 5100 5100 40  0000 C C
	1    5050 5100
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P3
U 1 1 48A9F4D8
P 10000 5150
F 0 "P3" V 9950 5150 40  0000 C C
F 1 "CONN_2" V 10050 5150 40  0000 C C
	1    10000 5150
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 48A9F4BB
P 9200 5250
F 0 "R9" V 9280 5250 50  0000 C C
F 1 "R" V 9200 5250 50  0000 C C
	1    9200 5250
	0    -1   -1   0   
$EndComp
$Comp
L NPN Q1
U 1 1 48A9F4B4
P 8600 5150
F 0 "Q1" H 8750 5150 50  0000 C C
F 1 "NPN" H 8502 5300 50  0000 C C
	1    8600 5150
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR040
U 1 1 48A9F436
P 6300 3550
F 0 "#PWR040" H 6300 3550 30  0001 C C
F 1 "GND" H 6300 3480 30  0001 C C
	1    6300 3550
	0    1    -1   0   
$EndComp
$Comp
L +5V #PWR041
U 1 1 48A9F41B
P 6350 3250
F 0 "#PWR041" H 6350 3340 20  0001 C C
F 1 "+5V" H 6350 3340 30  0000 C C
	1    6350 3250
	0    -1   -1   0   
$EndComp
Text Label 4900 4150 0    60   ~
Ser Clock
Text Label 4900 2950 0    60   ~
Ser Data
Text Label 4900 2850 0    60   ~
Reg Clock
$Comp
L 74HC595 U5
U 1 1 48A9F368
P 7200 3400
F 0 "U5" H 7350 4000 70  0000 C C
F 1 "74HC595" H 7200 2800 70  0000 C C
	1    7200 3400
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 48A9F33D
P 1000 2900
F 0 "C11" H 1050 3000 50  0000 L C
F 1 "C" H 1050 2800 50  0000 L C
	1    1000 2900
	0    -1   -1   0   
$EndComp
$Comp
L C C12
U 1 1 48A9F33B
P 1000 3500
F 0 "C12" H 1050 3600 50  0000 L C
F 1 "C" H 1050 3400 50  0000 L C
	1    1000 3500
	0    -1   -1   0   
$EndComp
$Comp
L CRYSTAL X2
U 1 1 48A9F332
P 1550 3200
F 0 "X2" H 1550 3350 60  0000 C C
F 1 "CRYSTAL" H 1550 3050 60  0000 C C
	1    1550 3200
	0    1    1    0   
$EndComp
$Comp
L PIC16F648A U4
U 1 1 48A9F2C8
P 3600 3500
F 0 "U4" H 3900 4300 60  0000 C C
F 1 "PIC16F648A" H 4050 2700 60  0000 C C
	1    3600 3500
	1    0    0    -1  
$EndComp
$Sheet
S 9000 2100 1600 500 
U 48A9F29E
F0 "Red Score Lights" 60
F1 "scorelights.sch" 60
F2 "Off Target Light" I L 9000 2200 60 
F3 "Ground Light" I L 9000 2350 60 
F4 "Score Light" I L 9000 2500 60 
$EndSheet
Text HLabel 4900 3750 2    60   BiDi
F-D Line B
Text HLabel 4900 4050 2    60   BiDi
F-D Line A
Text HLabel 4900 3350 2    60   Output
usart out
Text HLabel 4900 3450 2    60   Input
usart in
$Sheet
S 9000 3550 1600 500 
U 489A2B75
F0 "Green Score Lights" 60
F1 "scorelights.sch" 60
F2 "Off Target Light" I L 9000 3950 60 
F3 "Ground Light" I L 9000 3800 60 
F4 "Score Light" I L 9000 3650 60 
$EndSheet
$EndSCHEMATC
