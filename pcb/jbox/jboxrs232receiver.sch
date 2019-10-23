EESchema Schematic File Version 2
LIBS:power,device,transistors,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,.\Jbox.cache
EELAYER 24  0
EELAYER END
$Descr A4 11700 8267
Sheet 9 9
Title "JBox RS232 Receiver"
Date "18 aug 2008"
Rev ".1"
Comp "JBox Project"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5600 3100 5600 2000
Connection ~ 5000 2000
Wire Wire Line
	5000 1700 5000 3100
Wire Wire Line
	6300 5650 6300 4700
Wire Wire Line
	6200 4700 6200 4800
Wire Wire Line
	6150 2450 6150 2950
Wire Wire Line
	6150 2950 6100 2950
Wire Wire Line
	6100 2950 6100 3100
Wire Wire Line
	6350 2450 6400 2450
Wire Wire Line
	6400 2450 6400 3100
Wire Wire Line
	5900 2600 5900 2500
Wire Wire Line
	5400 4700 5400 4800
Wire Wire Line
	5900 4700 5900 4800
Wire Wire Line
	5600 2000 5550 2000
Wire Wire Line
	5900 3100 5900 3000
Wire Wire Line
	5400 3100 5400 3000
Wire Wire Line
	5000 2000 5150 2000
Wire Wire Line
	5500 4700 5500 4800
Wire Wire Line
	5000 4700 5000 4800
Wire Wire Line
	5400 2600 5400 2500
Wire Wire Line
	6300 3100 6300 2450
Wire Wire Line
	6300 2450 6250 2450
Wire Wire Line
	6550 2800 6400 2800
Connection ~ 6400 2800
Wire Wire Line
	6100 4700 6100 5650
Wire Wire Line
	5600 2050 5600 1700
Connection ~ 5600 2050
$Comp
L +5V #PWR057
U 1 1 48A9FED3
P 5000 1700
F 0 "#PWR057" H 5000 1790 20  0001 C C
F 1 "+5V" H 5000 1790 30  0000 C C
	1    5000 1700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR058
U 1 1 48A9FECC
P 5600 1700
F 0 "#PWR058" H 5600 1700 30  0001 C C
F 1 "GND" H 5600 1630 30  0001 C C
	1    5600 1700
	1    0    0    1   
$EndComp
Text HLabel 6100 5650 1    60   Input
TO_PC
Text HLabel 6300 5650 1    60   Output
From_PC
NoConn ~ 6200 3100
NoConn ~ 6400 4700
$Comp
L GND #PWR059
U 1 1 4895D98F
P 6200 4800
F 0 "#PWR059" H 6200 4800 30  0001 C C
F 1 "GND" H 6200 4730 30  0001 C C
	1    6200 4800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR060
U 1 1 4895D98E
P 6550 2800
F 0 "#PWR060" H 6550 2800 30  0001 C C
F 1 "GND" H 6550 2730 30  0001 C C
	1    6550 2800
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR061
U 1 1 4895D98D
P 5900 2500
F 0 "#PWR061" H 5900 2500 30  0001 C C
F 1 "GND" H 5900 2430 30  0001 C C
	1    5900 2500
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR062
U 1 1 4895D98C
P 5400 2500
F 0 "#PWR062" H 5400 2590 20  0001 C C
F 1 "+5V" H 5400 2590 30  0000 C C
	1    5400 2500
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K1
U 1 1 4895D98B
P 6250 2100
F 0 "K1" V 6200 2100 50  0000 C C
F 1 "CONN_3" V 6300 2100 40  0000 C C
	1    6250 2100
	0    -1   -1   0   
$EndComp
$Comp
L C C4
U 1 1 4895D98A
P 5700 4800
F 0 "C4" H 5750 4900 50  0000 L C
F 1 "1uF" H 5750 4700 50  0000 L C
	1    5700 4800
	0    1    1    0   
$EndComp
$Comp
L C C2
U 1 1 4895D989
P 5350 2000
F 0 "C2" H 5400 2100 50  0000 L C
F 1 "1uF" H 5400 1900 50  0000 L C
	1    5350 2000
	0    1    1    0   
$EndComp
$Comp
L C C3
U 1 1 4895D988
P 5400 2800
F 0 "C3" H 5450 2900 50  0000 L C
F 1 "1uF" H 5450 2700 50  0000 L C
	1    5400 2800
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 4895D987
P 5200 4800
F 0 "C1" H 5250 4900 50  0000 L C
F 1 "1uF" H 5250 4700 50  0000 L C
	1    5200 4800
	0    1    1    0   
$EndComp
$Comp
L C C5
U 1 1 4895D986
P 5900 2800
F 0 "C5" H 5950 2900 50  0000 L C
F 1 "1uF" H 5950 2700 50  0000 L C
	1    5900 2800
	1    0    0    -1  
$EndComp
$Comp
L MAX232 U1
U 1 1 4895D985
P 5700 3900
F 0 "U1" H 5700 4750 70  0000 C C
F 1 "MAX232" H 5700 3050 70  0000 C C
	1    5700 3900
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
