EESchema Schematic File Version 2
LIBS:power,device,transistors,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,.\Jbox.cache
EELAYER 24  0
EELAYER END
$Descr A4 11700 8267
Sheet 8 9
Title ""
Date "18 aug 2008"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PWR_FLAG #FLG053
U 1 1 48AA084A
P 3250 4550
F 0 "#FLG053" H 3250 4820 30  0001 C C
F 1 "PWR_FLAG" H 3250 4780 30  0000 C C
	1    3250 4550
	1    0    0    -1  
$EndComp
Connection ~ 3250 4700
Wire Wire Line
	3250 4700 3250 4550
Wire Wire Line
	9700 3750 9700 4500
Connection ~ 3750 3650
Wire Wire Line
	4550 3650 2750 3650
Connection ~ 6200 4700
Wire Wire Line
	4950 4700 4950 3950
Wire Wire Line
	6200 4700 6200 4050
Wire Wire Line
	8700 3650 8700 4700
Wire Wire Line
	7850 2800 9700 2800
Wire Wire Line
	9700 2800 9700 3550
Wire Wire Line
	9700 4500 7850 4500
Connection ~ 6200 3650
Wire Wire Line
	5350 3650 7000 3650
Wire Wire Line
	3750 4700 3750 4050
Connection ~ 4950 4700
Wire Wire Line
	8700 4700 2700 4700
Connection ~ 3750 4700
Connection ~ 9700 4500
Wire Wire Line
	2750 3650 2750 3750
$Comp
L VCC #PWR054
U 1 1 48AA0539
P 2750 3750
F 0 "#PWR054" H 2750 3850 30  0001 C C
F 1 "VCC" H 2750 3850 30  0000 C C
	1    2750 3750
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR055
U 1 1 4895DD82
P 2700 4700
F 0 "#PWR055" H 2700 4700 30  0001 C C
F 1 "GND" H 2700 4630 30  0001 C C
	1    2700 4700
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR056
U 1 1 4895DD74
P 2750 3650
F 0 "#PWR056" H 2750 3740 20  0001 C C
F 1 "+5V" H 2750 3740 30  0000 C C
	1    2750 3650
	0    -1   -1   0   
$EndComp
$Comp
L BRIDGE D1
U 1 1 4895DB2D
P 7850 3650
F 0 "D1" H 7850 3700 70  0000 C C
F 1 "BRIDGE" H 7850 3600 70  0000 C C
	1    7850 3650
	-1   0    0    -1  
$EndComp
$Comp
L 7805 U2
U 1 1 4895DB9C
P 4950 3700
F 0 "U2" H 5100 3504 60  0000 C C
F 1 "7805" H 4950 3900 60  0000 C C
	1    4950 3700
	-1   0    0    -1  
$EndComp
$Comp
L CP C6
U 1 1 4895DB5B
P 3750 3850
F 0 "C6" H 3800 3950 50  0000 L C
F 1 "100uF" H 3800 3750 50  0000 L C
	1    3750 3850
	1    0    0    -1  
$EndComp
$Comp
L CP C7
U 1 1 4895DB57
P 6200 3850
F 0 "C7" H 6250 3950 50  0000 L C
F 1 "220uF" H 6250 3750 50  0000 L C
	1    6200 3850
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P1
U 1 1 4895DB1C
P 10050 3650
F 0 "P1" V 10000 3650 40  0000 C C
F 1 "CONN_2" V 10100 3650 40  0000 C C
	1    10050 3650
	1    0    0    -1  
$EndComp
$EndSCHEMATC
