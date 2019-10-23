EESchema Schematic File Version 2
LIBS:power,device,transistors,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,.\Jbox.cache
EELAYER 24  0
EELAYER END
$Descr A4 11700 8267
Sheet 7 9
Title ""
Date "18 aug 2008"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
NoConn ~ 7100 3100
NoConn ~ 7100 3200
NoConn ~ 7100 3300
NoConn ~ 7100 3800
NoConn ~ 7100 3400
NoConn ~ 7100 4000
NoConn ~ 7100 4100
NoConn ~ 7100 4200
NoConn ~ 7100 4400
NoConn ~ 4750 3950
Text Label 7100 3500 0    60   ~
wpn sel
Text Label 7100 4300 0    60   ~
ir
Wire Wire Line
	4750 3100 4500 3100
Connection ~ 3150 3450
Wire Wire Line
	2800 3450 3150 3450
Connection ~ 3950 3150
Wire Wire Line
	3550 3150 4250 3150
Wire Wire Line
	4750 3600 4250 3600
Wire Wire Line
	4250 3600 4250 3750
Connection ~ 9100 2850
Wire Wire Line
	8700 2850 9650 2850
Connection ~ 9800 4250
Wire Wire Line
	9800 3900 9800 4250
Wire Wire Line
	9550 4250 9900 4250
Wire Wire Line
	9900 4450 9400 4450
Wire Wire Line
	9550 4350 9900 4350
Wire Wire Line
	9800 3500 9650 3500
Wire Wire Line
	9650 3500 9650 4350
Connection ~ 9650 4350
Wire Wire Line
	9100 2250 9100 2350
Wire Wire Line
	10250 2850 10550 2850
Wire Wire Line
	4750 3300 4250 3300
Wire Wire Line
	4250 3300 4250 3150
Wire Wire Line
	4250 3750 3550 3750
Connection ~ 3950 3750
Wire Wire Line
	3150 3150 3150 3750
Wire Wire Line
	4750 4400 4450 4400
Text Label 8700 2850 2    60   ~
wpn sel
Text Label 9400 4450 2    60   ~
ir
$Comp
L GND #PWR046
U 1 1 48A9FAA4
P 10550 2850
F 0 "#PWR046" H 10550 2850 30  0001 C C
F 1 "GND" H 10550 2780 30  0001 C C
	1    10550 2850
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR047
U 1 1 48A9FAA2
P 9100 2250
F 0 "#PWR047" H 9100 2340 20  0001 C C
F 1 "+5V" H 9100 2340 30  0000 C C
	1    9100 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR048
U 1 1 48A9FAA0
P 9550 4350
F 0 "#PWR048" H 9550 4350 30  0001 C C
F 1 "GND" H 9550 4280 30  0001 C C
	1    9550 4350
	0    1    -1   0   
$EndComp
$Comp
L +5V #PWR049
U 1 1 48A9FA9E
P 9550 4250
F 0 "#PWR049" H 9550 4340 20  0001 C C
F 1 "+5V" H 9550 4340 30  0000 C C
	1    9550 4250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR050
U 1 1 48A9FA99
P 2800 3450
F 0 "#PWR050" H 2800 3450 30  0001 C C
F 1 "GND" H 2800 3380 30  0001 C C
	1    2800 3450
	0    1    1    0   
$EndComp
$Comp
L GND #PWR051
U 1 1 48A9FA93
P 4450 4400
F 0 "#PWR051" H 4450 4400 30  0001 C C
F 1 "GND" H 4450 4330 30  0001 C C
	1    4450 4400
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR052
U 1 1 48A9FA8D
P 4500 3100
F 0 "#PWR052" H 4500 3190 20  0001 C C
F 1 "+5V" H 4500 3190 30  0000 C C
	1    4500 3100
	0    -1   1    0   
$EndComp
$Comp
L CRYSTAL X1
U 1 1 48A9FA78
P 3950 3450
F 0 "X1" H 3950 3600 60  0000 C C
F 1 "CRYSTAL" H 3950 3300 60  0000 C C
	1    3950 3450
	0    1    1    0   
$EndComp
$Comp
L C C9
U 1 1 48A9FA73
P 3350 3750
F 0 "C9" H 3400 3850 50  0000 L C
F 1 "C" H 3400 3650 50  0000 L C
	1    3350 3750
	0    1    1    0   
$EndComp
$Comp
L C C8
U 1 1 48A9FA72
P 3350 3150
F 0 "C8" H 3400 3250 50  0000 L C
F 1 "C" H 3400 3050 50  0000 L C
	1    3350 3150
	0    1    1    0   
$EndComp
$Comp
L C C10
U 1 1 48A9FA67
P 9800 3700
F 0 "C10" H 9850 3800 50  0000 L C
F 1 "C" H 9850 3600 50  0000 L C
	1    9800 3700
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K2
U 1 1 48A9FA60
P 10250 4350
F 0 "K2" V 10200 4350 50  0000 C C
F 1 "CONN_3" V 10300 4350 40  0000 C C
	1    10250 4350
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 48A9FA4E
P 9100 2600
F 0 "R1" V 9180 2600 50  0000 C C
F 1 "R" V 9100 2600 50  0000 C C
	1    9100 2600
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 48A9FA41
P 9950 2850
F 0 "SW1" H 10100 2960 50  0000 C C
F 1 "SW_PUSH" H 9950 2770 50  0000 C C
	1    9950 2850
	1    0    0    -1  
$EndComp
$Comp
L PIC16F648A U3
U 1 1 48A9F9B8
P 5800 3750
F 0 "U3" H 6100 4550 60  0000 C C
F 1 "PIC16F648A" H 6250 2950 60  0000 C C
	1    5800 3750
	1    0    0    -1  
$EndComp
Text HLabel 7100 3600 2    60   Output
usart out
Text HLabel 7100 3700 2    60   Input
usart in
$EndSCHEMATC
