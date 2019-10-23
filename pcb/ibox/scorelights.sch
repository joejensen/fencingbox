EESchema Schematic File Version 2
LIBS:power,device,transistors,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves
EELAYER 24  0
EELAYER END
$Descr A4 11700 8267
Sheet 6 6
Title ""
Date "17 oct 2008"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3350 2650 2700 2650
Wire Wire Line
	8250 2600 7700 2600
Wire Wire Line
	8550 2100 3650 2100
Connection ~ 6450 5250
Connection ~ 6450 5950
Wire Wire Line
	6250 2450 6250 1800
Connection ~ 3650 5600
Connection ~ 3250 5600
Wire Wire Line
	2950 5600 4350 5600
Wire Wire Line
	2950 5600 2950 4550
Wire Wire Line
	2950 4550 3250 4550
Connection ~ 7800 5950
Connection ~ 9250 5150
Connection ~ 9050 5950
Wire Wire Line
	9250 4600 9250 5950
Connection ~ 7800 5150
Wire Wire Line
	8050 5150 7800 5150
Connection ~ 8700 5750
Connection ~ 8700 5950
Wire Wire Line
	8700 5950 8700 4600
Wire Wire Line
	8700 5150 8550 5150
Wire Wire Line
	8700 5750 8550 5750
Connection ~ 8300 5350
Wire Wire Line
	8550 5350 8050 5350
Connection ~ 8300 4750
Wire Wire Line
	8300 5350 8300 3700
Connection ~ 8800 4200
Wire Wire Line
	8800 4200 9050 4200
Connection ~ 8800 3700
Wire Wire Line
	8800 3700 8800 5350
Connection ~ 8550 3700
Wire Wire Line
	9050 4200 9050 3700
Wire Wire Line
	9050 3700 8050 3700
Wire Wire Line
	8550 3700 8550 4200
Wire Wire Line
	6250 3750 6250 4200
Connection ~ 3450 3700
Wire Wire Line
	3250 5000 3450 5000
Wire Wire Line
	3450 5000 3450 3700
Wire Wire Line
	3650 3700 3650 4600
Wire Wire Line
	3250 4150 3250 3700
Wire Wire Line
	3650 2850 3650 3200
Wire Wire Line
	3250 3700 4100 3700
Wire Wire Line
	4100 3700 4100 4150
Connection ~ 3650 3700
Wire Wire Line
	3850 3700 3850 5000
Wire Wire Line
	3850 5000 4100 5000
Connection ~ 3850 3700
Wire Wire Line
	6250 3250 6250 2850
Wire Wire Line
	6250 4200 6000 4200
Wire Wire Line
	6000 4200 6000 4850
Wire Wire Line
	6000 4850 6250 4850
Wire Wire Line
	8050 3700 8050 4200
Wire Wire Line
	8800 5350 9050 5350
Wire Wire Line
	9050 4750 8800 4750
Connection ~ 8800 4750
Connection ~ 8300 3700
Wire Wire Line
	8550 4750 8050 4750
Wire Wire Line
	8050 4600 7800 4600
Wire Wire Line
	7800 4600 7800 5950
Wire Wire Line
	9050 5950 9050 5750
Wire Wire Line
	8700 4600 8550 4600
Connection ~ 8700 5150
Wire Wire Line
	8050 5750 7800 5750
Connection ~ 7800 5750
Wire Wire Line
	9250 4600 9050 4600
Wire Wire Line
	9250 5150 9050 5150
Wire Wire Line
	6250 4600 6450 4600
Wire Wire Line
	6450 5250 6250 5250
Wire Wire Line
	4100 4550 4350 4550
Wire Wire Line
	4350 4550 4350 5600
Wire Wire Line
	3250 5600 3250 5400
Wire Wire Line
	4100 5400 4100 5600
Connection ~ 4100 5600
Wire Wire Line
	3650 5000 3650 5950
Wire Wire Line
	8550 2100 8550 2400
Wire Wire Line
	3650 2100 3650 2450
Connection ~ 6250 2100
Wire Wire Line
	8550 2800 8550 3200
Wire Wire Line
	6450 4600 6450 6400
Wire Wire Line
	3650 5950 9250 5950
Wire Wire Line
	5950 2650 5350 2650
Text HLabel 2700 2650 0    60   Input
Off Target Light
Text HLabel 5350 2650 0    60   Input
Ground Light
Text HLabel 7700 2600 0    60   Input
Score Light
$Comp
L +5V #PWR22
U 1 1 489921DE
P 6250 1800
F 0 "#PWR22" H 6250 1890 20  0001 C C
F 1 "+5V" H 6250 1890 30  0000 C C
	1    6250 1800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR23
U 1 1 489921C8
P 6450 6400
F 0 "#PWR23" H 6450 6400 30  0001 C C
F 1 "GND" H 6450 6330 30  0001 C C
	1    6450 6400
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 489920C8
P 8550 3450
F 0 "R13" V 8630 3450 50  0000 C C
F 1 "R" V 8550 3450 50  0000 C C
	1    8550 3450
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 489920C0
P 6250 3500
F 0 "R12" V 6330 3500 50  0000 C C
F 1 "R" V 6250 3500 50  0000 C C
	1    6250 3500
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 489920BC
P 3650 3450
F 0 "R11" V 3730 3450 50  0000 C C
F 1 "R" V 3650 3450 50  0000 C C
	1    3650 3450
	1    0    0    -1  
$EndComp
$Comp
L NPN Q2
U 1 1 4899209E
P 3550 2650
F 0 "Q2" H 3700 2650 50  0000 C C
F 1 "NPN" H 3452 2800 50  0000 C C
	1    3550 2650
	1    0    0    -1  
$EndComp
$Comp
L NPN Q3
U 1 1 48992094
P 6150 2650
F 0 "Q3" H 6300 2650 50  0000 C C
F 1 "NPN" H 6052 2800 50  0000 C C
	1    6150 2650
	1    0    0    -1  
$EndComp
$Comp
L NPN Q4
U 1 1 4899208B
P 8450 2600
F 0 "Q4" H 8600 2600 50  0000 C C
F 1 "NPN" H 8352 2750 50  0000 C C
	1    8450 2600
	1    0    0    -1  
$EndComp
$Comp
L LED D19
U 1 1 4899206E
P 9050 5550
F 0 "D19" H 9050 5650 50  0000 C C
F 1 "LED" H 9050 5450 50  0000 C C
	1    9050 5550
	0    1    1    0   
$EndComp
$Comp
L LED D16
U 1 1 4899206D
P 8550 5550
F 0 "D16" H 8550 5650 50  0000 C C
F 1 "LED" H 8550 5450 50  0000 C C
	1    8550 5550
	0    1    1    0   
$EndComp
$Comp
L LED D13
U 1 1 4899206C
P 8050 5550
F 0 "D13" H 8050 5650 50  0000 C C
F 1 "LED" H 8050 5450 50  0000 C C
	1    8050 5550
	0    1    1    0   
$EndComp
$Comp
L LED D18
U 1 1 48992065
P 9050 4950
F 0 "D18" H 9050 5050 50  0000 C C
F 1 "LED" H 9050 4850 50  0000 C C
	1    9050 4950
	0    1    1    0   
$EndComp
$Comp
L LED D15
U 1 1 48992064
P 8550 4950
F 0 "D15" H 8550 5050 50  0000 C C
F 1 "LED" H 8550 4850 50  0000 C C
	1    8550 4950
	0    1    1    0   
$EndComp
$Comp
L LED D12
U 1 1 48992063
P 8050 4950
F 0 "D12" H 8050 5050 50  0000 C C
F 1 "LED" H 8050 4850 50  0000 C C
	1    8050 4950
	0    1    1    0   
$EndComp
$Comp
L LED D8
U 1 1 48992017
P 4100 5200
F 0 "D8" H 4100 5300 50  0000 C C
F 1 "LED" H 4100 5100 50  0000 C C
	1    4100 5200
	0    1    1    0   
$EndComp
$Comp
L LED D5
U 1 1 48992016
P 3250 5200
F 0 "D5" H 3250 5300 50  0000 C C
F 1 "LED" H 3250 5100 50  0000 C C
	1    3250 5200
	0    1    1    0   
$EndComp
$Comp
L LED D10
U 1 1 4899200C
P 6250 5050
F 0 "D10" H 6250 5150 50  0000 C C
F 1 "LED" H 6250 4950 50  0000 C C
	1    6250 5050
	0    1    1    0   
$EndComp
$Comp
L LED D9
U 1 1 48992009
P 6250 4400
F 0 "D9" H 6250 4500 50  0000 C C
F 1 "LED" H 6250 4300 50  0000 C C
	1    6250 4400
	0    1    1    0   
$EndComp
$Comp
L LED D6
U 1 1 48992004
P 3650 4800
F 0 "D6" H 3650 4900 50  0000 C C
F 1 "LED" H 3650 4700 50  0000 C C
	1    3650 4800
	0    1    1    0   
$EndComp
$Comp
L LED D7
U 1 1 48992000
P 4100 4350
F 0 "D7" H 4100 4450 50  0000 C C
F 1 "LED" H 4100 4250 50  0000 C C
	1    4100 4350
	0    1    1    0   
$EndComp
$Comp
L LED D4
U 1 1 48991FFA
P 3250 4350
F 0 "D4" H 3250 4450 50  0000 C C
F 1 "LED" H 3250 4250 50  0000 C C
	1    3250 4350
	0    1    1    0   
$EndComp
$Comp
L LED D17
U 1 1 48991FEF
P 9050 4400
F 0 "D17" H 9050 4500 50  0000 C C
F 1 "LED" H 9050 4300 50  0000 C C
	1    9050 4400
	0    1    1    0   
$EndComp
$Comp
L LED D14
U 1 1 48991FE8
P 8550 4400
F 0 "D14" H 8550 4500 50  0000 C C
F 1 "LED" H 8550 4300 50  0000 C C
	1    8550 4400
	0    1    1    0   
$EndComp
$Comp
L LED D11
U 1 1 48991FE3
P 8050 4400
F 0 "D11" H 8050 4500 50  0000 C C
F 1 "LED" H 8050 4300 50  0000 C C
	1    8050 4400
	0    1    1    0   
$EndComp
$EndSCHEMATC
