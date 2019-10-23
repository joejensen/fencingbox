EESchema Schematic File Version 2
LIBS:power,device,transistors,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,.\Jbox.cache
EELAYER 24  0
EELAYER END
$Descr A4 11700 8267
Sheet 2 9
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
	3250 7300 3250 7150
Wire Wire Line
	3400 7050 3400 7150
Wire Wire Line
	3400 7150 3100 7150
Wire Wire Line
	3100 7150 3100 7050
Wire Wire Line
	2400 5150 2400 5250
Wire Wire Line
	10900 3600 9350 3600
Wire Wire Line
	8600 4100 9050 4100
Wire Wire Line
	9050 4100 9050 2850
Wire Wire Line
	8600 3050 8850 3050
Wire Wire Line
	8850 3050 8850 2850
Wire Wire Line
	9250 2850 9250 4100
Wire Wire Line
	9450 2850 9450 3050
Wire Wire Line
	9050 1450 9050 1300
Wire Wire Line
	7650 1450 7650 1300
Wire Wire Line
	6250 1450 6250 1300
Wire Wire Line
	4900 1450 4900 1300
Wire Wire Line
	3550 1450 3550 1300
Wire Wire Line
	3850 1450 3850 1300
Wire Wire Line
	5200 1450 5200 1300
Wire Wire Line
	6550 1450 6550 1300
Wire Wire Line
	7950 1450 7950 1300
Wire Wire Line
	9350 1450 9350 1300
Wire Wire Line
	8150 1450 8400 1450
Wire Wire Line
	8400 1450 8400 2850
Wire Wire Line
	8400 2850 8650 2850
Wire Wire Line
	4050 1450 4250 1450
Wire Wire Line
	4250 1450 4250 2850
Wire Wire Line
	4250 2850 4500 2850
Wire Wire Line
	1750 4050 1750 3700
Wire Wire Line
	1850 4050 1850 3700
Wire Wire Line
	850  4050 850  3550
Wire Wire Line
	1250 4050 1250 3700
Wire Wire Line
	650  6450 650  6400
Connection ~ 1000 7500
Wire Wire Line
	1000 7650 1000 7500
Connection ~ 1300 6950
Wire Wire Line
	1300 7100 1300 6700
Wire Wire Line
	1300 6700 1150 6700
Wire Wire Line
	1150 6700 1150 6400
Wire Wire Line
	1300 7500 700  7500
Wire Wire Line
	850  6400 850  6700
Wire Wire Line
	850  6700 700  6700
Wire Wire Line
	700  6700 700  7100
Connection ~ 700  6950
Wire Wire Line
	1950 6450 1950 6400
Wire Wire Line
	1150 4050 1150 3700
Wire Wire Line
	1050 4050 1050 3550
Wire Wire Line
	950  4050 950  3550
Wire Wire Line
	5850 2850 5600 2850
Wire Wire Line
	5600 2850 5600 1450
Wire Wire Line
	5600 1450 5400 1450
Wire Wire Line
	7250 2850 7000 2850
Wire Wire Line
	7000 2850 7000 1450
Wire Wire Line
	7000 1450 6750 1450
Wire Wire Line
	9550 1450 9550 1300
Wire Wire Line
	8950 1450 8950 1300
Wire Wire Line
	7550 1450 7550 1300
Wire Wire Line
	6150 1450 6150 1300
Wire Wire Line
	4800 1450 4800 1300
Wire Wire Line
	3450 1450 3450 1300
Wire Wire Line
	3750 1450 3750 1300
Wire Wire Line
	5100 1450 5100 1300
Wire Wire Line
	6450 1450 6450 1300
Wire Wire Line
	7850 1450 7850 1300
Wire Wire Line
	9250 1450 9250 1300
Wire Wire Line
	9350 3600 9350 2850
Wire Wire Line
	9150 2850 9150 4500
Wire Wire Line
	8950 2850 8950 3600
Wire Wire Line
	8950 3600 8600 3600
Wire Wire Line
	9450 3050 10900 3050
Wire Wire Line
	9250 4100 10900 4100
Wire Wire Line
	3700 4650 3700 4750
Wire Wire Line
	3400 4650 3400 4750
Wire Wire Line
	3100 4650 3100 4750
Wire Wire Line
	3700 6550 3700 6650
Wire Wire Line
	3400 6550 3400 6650
Wire Wire Line
	3100 6550 3100 6650
Wire Wire Line
	2800 6550 2800 6650
Wire Wire Line
	2400 4650 2400 4750
Wire Wire Line
	2400 5850 2400 5650
Wire Wire Line
	3700 7050 3700 7200
Wire Wire Line
	3700 7200 2800 7200
Wire Wire Line
	2800 7200 2800 7050
Connection ~ 3250 7200
Connection ~ 3250 7150
Text Label 2400 4150 1    60   ~
timercolon
$Comp
L GND #PWR01
U 1 1 489F25AD
P 2400 5850
F 0 "#PWR01" H 2400 5850 30  0001 C C
F 1 "GND" H 2400 5780 30  0001 C C
	1    2400 5850
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 489F25A5
P 2400 5450
F 0 "D3" H 2400 5550 50  0000 C C
F 1 "LED" H 2400 5350 50  0000 C C
	1    2400 5450
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 489F25A1
P 2400 4400
F 0 "R10" V 2480 4400 50  0000 C C
F 1 "R" V 2400 4400 50  0000 C C
	1    2400 4400
	-1   0    0    1   
$EndComp
$Comp
L LED D2
U 1 1 489F25A0
P 2400 4950
F 0 "D2" H 2400 5050 50  0000 C C
F 1 "LED" H 2400 4850 50  0000 C C
	1    2400 4950
	0    1    1    0   
$EndComp
Text Label 5200 2850 3    60   ~
r1
Text Label 5300 2850 3    60   ~
r10
Text Label 7100 6300 2    60   ~
r1
Text Label 7100 5250 2    60   ~
r10
Text Label 3700 6050 1    60   ~
perot
Text Label 3400 6050 1    60   ~
per3
Text Label 3100 6050 1    60   ~
per2
Text Label 2800 6050 1    60   ~
per1
Text Label 3100 5150 3    60   ~
fanode
Text Label 3400 5150 3    60   ~
eanode
Text Label 3700 5150 3    60   ~
sanode
Text Label 3100 4150 1    60   ~
fcathode
Text Label 3400 4150 1    60   ~
ecathode
Text Label 3700 4150 1    60   ~
scathode
$Comp
L GND #PWR02
U 1 1 489F2488
P 3250 7300
F 0 "#PWR02" H 3250 7300 30  0001 C C
F 1 "GND" H 3250 7230 30  0001 C C
	1    3250 7300
	1    0    0    -1  
$EndComp
Text Label 1250 1900 2    60   ~
grc
Text Label 1250 1750 2    60   ~
gyc
Text Label 1250 1600 2    60   ~
gpri
Text Label 1250 1100 2    60   ~
rrc
Text Label 1250 950  2    60   ~
ryc
Text Label 1250 800  2    60   ~
rpri
Text Label 3750 2850 3    60   ~
timercolon
Text Label 3850 2850 3    60   ~
ryc
Text Label 3950 2850 3    60   ~
rrc
Text Label 4700 2850 3    60   ~
rpri
$Comp
L R R11
U 1 1 489F22D9
P 2800 6300
F 0 "R11" V 2880 6300 50  0000 C C
F 1 "R" V 2800 6300 50  0000 C C
	1    2800 6300
	-1   0    0    1   
$EndComp
$Comp
L LED D4
U 1 1 489F22D8
P 2800 6850
F 0 "D4" H 2800 6950 50  0000 C C
F 1 "LED" H 2800 6750 50  0000 C C
	1    2800 6850
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 489F22D3
P 3100 6300
F 0 "R13" V 3180 6300 50  0000 C C
F 1 "R" V 3100 6300 50  0000 C C
	1    3100 6300
	-1   0    0    1   
$EndComp
$Comp
L LED D6
U 1 1 489F22D2
P 3100 6850
F 0 "D6" H 3100 6950 50  0000 C C
F 1 "LED" H 3100 6750 50  0000 C C
	1    3100 6850
	0    1    1    0   
$EndComp
$Comp
L R R15
U 1 1 489F22CF
P 3400 6300
F 0 "R15" V 3480 6300 50  0000 C C
F 1 "R" V 3400 6300 50  0000 C C
	1    3400 6300
	-1   0    0    1   
$EndComp
$Comp
L LED D8
U 1 1 489F22CE
P 3400 6850
F 0 "D8" H 3400 6950 50  0000 C C
F 1 "LED" H 3400 6750 50  0000 C C
	1    3400 6850
	0    1    1    0   
$EndComp
$Comp
L R R17
U 1 1 489F22C7
P 3700 6300
F 0 "R17" V 3780 6300 50  0000 C C
F 1 "R" V 3700 6300 50  0000 C C
	1    3700 6300
	-1   0    0    1   
$EndComp
$Comp
L LED D10
U 1 1 489F22C6
P 3700 6850
F 0 "D10" H 3700 6950 50  0000 C C
F 1 "LED" H 3700 6750 50  0000 C C
	1    3700 6850
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 489F22AE
P 3100 4400
F 0 "R12" V 3180 4400 50  0000 C C
F 1 "R" V 3100 4400 50  0000 C C
	1    3100 4400
	-1   0    0    1   
$EndComp
$Comp
L LED D5
U 1 1 489F22AD
P 3100 4950
F 0 "D5" H 3100 5050 50  0000 C C
F 1 "LED" H 3100 4850 50  0000 C C
	1    3100 4950
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 489F22A7
P 3400 4400
F 0 "R14" V 3480 4400 50  0000 C C
F 1 "R" V 3400 4400 50  0000 C C
	1    3400 4400
	-1   0    0    1   
$EndComp
$Comp
L LED D7
U 1 1 489F22A6
P 3400 4950
F 0 "D7" H 3400 5050 50  0000 C C
F 1 "LED" H 3400 4850 50  0000 C C
	1    3400 4950
	0    1    1    0   
$EndComp
Text Label 4800 2850 3    60   ~
fanode
Text Label 4900 2850 3    60   ~
fcathode
Text Label 5000 2850 3    60   ~
eanode
Text Label 5100 2850 3    60   ~
ecathode
Text Label 6050 2850 3    60   ~
sanode
Text Label 6150 2850 3    60   ~
scathode
Text Label 6450 2850 3    60   ~
t10s
Text Label 6550 2850 3    60   ~
t1s
Text Label 6650 2850 3    60   ~
tm
$Comp
L R R16
U 1 1 489F1ED1
P 3700 4400
F 0 "R16" V 3780 4400 50  0000 C C
F 1 "R" V 3700 4400 50  0000 C C
	1    3700 4400
	-1   0    0    1   
$EndComp
$Comp
L LED D9
U 1 1 489F1E94
P 3700 4950
F 0 "D9" H 3700 5050 50  0000 C C
F 1 "LED" H 3700 4850 50  0000 C C
	1    3700 4950
	0    1    1    0   
$EndComp
Text Label 4650 4800 2    60   ~
tm
Text Label 4650 5850 2    60   ~
t10s
Text Label 4650 6900 2    60   ~
t1s
Text Label 6250 2850 3    60   ~
per1
Text Label 6350 2850 3    60   ~
per2
Text Label 7450 2850 3    60   ~
per3
Text Label 7550 2850 3    60   ~
perot
Text Label 7650 2850 3    60   ~
gpri
Text Label 7750 2850 3    60   ~
grc
Text Label 7850 2850 3    60   ~
gyc
Text Label 9550 6300 2    60   ~
g1
Text Label 9550 5250 2    60   ~
g10
Text Label 7950 2850 3    60   ~
g1
Text Label 8050 2850 3    60   ~
g10
Text Label 7100 7000 2    60   ~
bottom
Text Label 7100 6900 2    60   ~
lower left
Text Label 7100 6800 2    60   ~
middle
Text Label 7100 6700 2    60   ~
upper left
Text Label 7100 6600 2    60   ~
top
Text Label 7100 6500 2    60   ~
upper right
Text Label 7100 6400 2    60   ~
lower right
Text Label 7100 5950 2    60   ~
bottom
Text Label 7100 5850 2    60   ~
lower left
Text Label 7100 5750 2    60   ~
middle
Text Label 7100 5650 2    60   ~
upper left
Text Label 7100 5550 2    60   ~
top
Text Label 7100 5450 2    60   ~
upper right
Text Label 7100 5350 2    60   ~
lower right
Text Label 4650 7200 2    60   ~
top
Text Label 4650 7600 2    60   ~
bottom
Text Label 4650 7500 2    60   ~
lower left
Text Label 4650 7400 2    60   ~
middle
Text Label 4650 7300 2    60   ~
upper left
Text Label 4650 7100 2    60   ~
upper right
Text Label 4650 7000 2    60   ~
lower right
Text Label 4650 6150 2    60   ~
top
Text Label 4650 6550 2    60   ~
bottom
Text Label 4650 6450 2    60   ~
lower left
Text Label 4650 6350 2    60   ~
middle
Text Label 4650 6250 2    60   ~
upper left
Text Label 4650 6050 2    60   ~
upper right
Text Label 4650 5950 2    60   ~
lower right
Text Label 4650 5100 2    60   ~
top
Text Label 4650 5500 2    60   ~
bottom
Text Label 4650 5400 2    60   ~
lower left
Text Label 4650 5300 2    60   ~
middle
Text Label 4650 5200 2    60   ~
upper left
Text Label 4650 5000 2    60   ~
upper right
Text Label 4650 4900 2    60   ~
lower right
Text Label 9550 7000 2    60   ~
bottom
Text Label 9550 6900 2    60   ~
lower left
Text Label 9550 6800 2    60   ~
middle
Text Label 9550 6700 2    60   ~
upper left
Text Label 9550 6600 2    60   ~
top
Text Label 9550 6500 2    60   ~
upper right
Text Label 9550 6400 2    60   ~
lower right
Text Label 9550 5950 2    60   ~
bottom
Text Label 9550 5850 2    60   ~
lower left
Text Label 9550 5750 2    60   ~
middle
Text Label 9550 5650 2    60   ~
upper left
Text Label 9550 5550 2    60   ~
top
Text Label 9550 5450 2    60   ~
upper right
Text Label 9550 5350 2    60   ~
lower right
Text Label 7900 3350 2    60   ~
bottom
Text Label 7900 3900 2    60   ~
lower right
Text Label 7900 4400 2    60   ~
upper right
Text Label 8450 4800 2    60   ~
top
Text Label 10200 4400 2    60   ~
upper left
Text Label 10200 3900 2    60   ~
middle
Text Label 10200 3350 2    60   ~
lower left
$Comp
L R R21
U 1 1 489C67E9
P 8700 4800
F 0 "R21" V 8780 4800 50  0000 C C
F 1 "R" V 8700 4800 50  0000 C C
	1    8700 4800
	0    1    1    0   
$EndComp
$Comp
L R R20
U 1 1 489C67E4
P 8150 4400
F 0 "R20" V 8230 4400 50  0000 C C
F 1 "R" V 8150 4400 50  0000 C C
	1    8150 4400
	0    1    1    0   
$EndComp
$Comp
L R R19
U 1 1 489C67E1
P 8150 3900
F 0 "R19" V 8230 3900 50  0000 C C
F 1 "R" V 8150 3900 50  0000 C C
	1    8150 3900
	0    1    1    0   
$EndComp
$Comp
L R R18
U 1 1 489C67DD
P 8150 3350
F 0 "R18" V 8230 3350 50  0000 C C
F 1 "R" V 8150 3350 50  0000 C C
	1    8150 3350
	0    1    1    0   
$EndComp
$Comp
L R R24
U 1 1 489C67D6
P 10450 4400
F 0 "R24" V 10530 4400 50  0000 C C
F 1 "R" V 10450 4400 50  0000 C C
	1    10450 4400
	0    1    1    0   
$EndComp
$Comp
L R R22
U 1 1 489C67B0
P 10450 3350
F 0 "R22" V 10530 3350 50  0000 C C
F 1 "R" V 10450 3350 50  0000 C C
	1    10450 3350
	0    1    1    0   
$EndComp
$Comp
L R R23
U 1 1 489C6776
P 10450 3900
F 0 "R23" V 10530 3900 50  0000 C C
F 1 "R" V 10450 3900 50  0000 C C
	1    10450 3900
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR03
U 1 1 489C6744
P 8800 3350
F 0 "#PWR03" H 8800 3440 20  0001 C C
F 1 "+5V" H 8800 3440 30  0000 C C
	1    8800 3350
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR04
U 1 1 489C6740
P 8800 3900
F 0 "#PWR04" H 8800 3990 20  0001 C C
F 1 "+5V" H 8800 3990 30  0000 C C
	1    8800 3900
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR05
U 1 1 489C673C
P 8800 4400
F 0 "#PWR05" H 8800 4490 20  0001 C C
F 1 "+5V" H 8800 4490 30  0000 C C
	1    8800 4400
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR06
U 1 1 489C6738
P 9350 4800
F 0 "#PWR06" H 9350 4890 20  0001 C C
F 1 "+5V" H 9350 4890 30  0000 C C
	1    9350 4800
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR07
U 1 1 489C6731
P 11100 4400
F 0 "#PWR07" H 11100 4490 20  0001 C C
F 1 "+5V" H 11100 4490 30  0000 C C
	1    11100 4400
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR08
U 1 1 489C6729
P 11100 3900
F 0 "#PWR08" H 11100 3990 20  0001 C C
F 1 "+5V" H 11100 3990 30  0000 C C
	1    11100 3900
	0    1    -1   0   
$EndComp
$Comp
L +5V #PWR09
U 1 1 489C671F
P 11100 3350
F 0 "#PWR09" H 11100 3440 20  0001 C C
F 1 "+5V" H 11100 3440 30  0000 C C
	1    11100 3350
	0    1    -1   0   
$EndComp
$Comp
L NPN Q8
U 1 1 489C656C
P 10900 4300
F 0 "Q8" H 11050 4300 50  0000 C C
F 1 "NPN" H 10802 4450 50  0000 C C
	1    10900 4300
	0    1    1    0   
$EndComp
$Comp
L NPN Q3
U 1 1 489C656A
P 8600 3800
F 0 "Q3" H 8750 3800 50  0000 C C
F 1 "NPN" H 8502 3950 50  0000 C C
	1    8600 3800
	0    1    1    0   
$EndComp
$Comp
L NPN Q7
U 1 1 489C6567
P 10900 3800
F 0 "Q7" H 11050 3800 50  0000 C C
F 1 "NPN" H 10802 3950 50  0000 C C
	1    10900 3800
	0    1    1    0   
$EndComp
$Comp
L NPN Q4
U 1 1 489C6563
P 8600 4300
F 0 "Q4" H 8750 4300 50  0000 C C
F 1 "NPN" H 8502 4450 50  0000 C C
	1    8600 4300
	0    1    1    0   
$EndComp
$Comp
L NPN Q2
U 1 1 489C6560
P 8600 3250
F 0 "Q2" H 8750 3250 50  0000 C C
F 1 "NPN" H 8502 3400 50  0000 C C
	1    8600 3250
	0    1    1    0   
$EndComp
$Comp
L NPN Q6
U 1 1 489C655E
P 10900 3250
F 0 "Q6" H 11050 3250 50  0000 C C
F 1 "NPN" H 10802 3400 50  0000 C C
	1    10900 3250
	0    1    1    0   
$EndComp
NoConn ~ 3150 2850
NoConn ~ 3350 2850
NoConn ~ 3450 2850
NoConn ~ 3550 2850
NoConn ~ 3650 2850
NoConn ~ 4050 2850
NoConn ~ 5400 2850
NoConn ~ 6750 2850
NoConn ~ 8150 2850
NoConn ~ 9550 2850
$Comp
L GND #PWR010
U 1 1 489A3B78
P 3450 1300
F 0 "#PWR010" H 3450 1300 30  0001 C C
F 1 "GND" H 3450 1230 30  0001 C C
	1    3450 1300
	1    0    0    1   
$EndComp
$Comp
L GND #PWR011
U 1 1 489A3B71
P 4800 1300
F 0 "#PWR011" H 4800 1300 30  0001 C C
F 1 "GND" H 4800 1230 30  0001 C C
	1    4800 1300
	1    0    0    1   
$EndComp
$Comp
L GND #PWR012
U 1 1 489A3B6C
P 6150 1300
F 0 "#PWR012" H 6150 1300 30  0001 C C
F 1 "GND" H 6150 1230 30  0001 C C
	1    6150 1300
	1    0    0    1   
$EndComp
$Comp
L GND #PWR013
U 1 1 489A3B64
P 7550 1300
F 0 "#PWR013" H 7550 1300 30  0001 C C
F 1 "GND" H 7550 1230 30  0001 C C
	1    7550 1300
	1    0    0    1   
$EndComp
$Comp
L GND #PWR014
U 1 1 489A3B5B
P 8950 1300
F 0 "#PWR014" H 8950 1300 30  0001 C C
F 1 "GND" H 8950 1230 30  0001 C C
	1    8950 1300
	1    0    0    1   
$EndComp
$Comp
L +5V #PWR015
U 1 1 489A3B3F
P 3750 1300
F 0 "#PWR015" H 3750 1390 20  0001 C C
F 1 "+5V" H 3750 1390 30  0000 C C
	1    3750 1300
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR016
U 1 1 489A3B36
P 5100 1300
F 0 "#PWR016" H 5100 1390 20  0001 C C
F 1 "+5V" H 5100 1390 30  0000 C C
	1    5100 1300
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR017
U 1 1 489A3B33
P 6450 1300
F 0 "#PWR017" H 6450 1390 20  0001 C C
F 1 "+5V" H 6450 1390 30  0000 C C
	1    6450 1300
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR018
U 1 1 489A3B2E
P 7850 1300
F 0 "#PWR018" H 7850 1390 20  0001 C C
F 1 "+5V" H 7850 1390 30  0000 C C
	1    7850 1300
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR019
U 1 1 489A3B28
P 9250 1300
F 0 "#PWR019" H 9250 1390 20  0001 C C
F 1 "+5V" H 9250 1390 30  0000 C C
	1    9250 1300
	1    0    0    -1  
$EndComp
Text Label 3550 1300 1    60   ~
latch clock
Text Label 3850 1300 1    60   ~
serial clock
Text Label 4900 1300 1    60   ~
latch clock
Text Label 5200 1300 1    60   ~
serial clock
Text Label 6250 1300 1    60   ~
latch clock
Text Label 6550 1300 1    60   ~
serial clock
Text Label 7650 1300 1    60   ~
latch clock
Text Label 7950 1300 1    60   ~
serial clock
Text Label 9050 1300 1    60   ~
latch clock
Text Label 9350 1300 1    60   ~
serial clock
Text Label 9550 1300 1    60   ~
serial
NoConn ~ 650  4050
NoConn ~ 750  4050
NoConn ~ 1350 4050
NoConn ~ 1500 6400
NoConn ~ 1550 4050
NoConn ~ 1650 4050
NoConn ~ 1950 4050
Text HLabel 1750 3700 3    60   BiDi
F-D Line B
Text HLabel 1850 3700 3    60   BiDi
F-D Line A
Text Label 950  3550 1    60   ~
latch clock
Text Label 850  3550 1    60   ~
serial clock
Text Label 1050 3550 1    60   ~
serial
Text HLabel 1150 3700 3    60   Output
usart out
Text HLabel 1250 3700 3    60   Input
usart in
$Comp
L GND #PWR020
U 1 1 489A3820
P 1950 6450
F 0 "#PWR020" H 1950 6450 30  0001 C C
F 1 "GND" H 1950 6380 30  0001 C C
	1    1950 6450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR021
U 1 1 489A3812
P 650 6450
F 0 "#PWR021" H 650 6540 20  0001 C C
F 1 "+5V" H 650 6540 30  0000 C C
	1    650  6450
	1    0    0    1   
$EndComp
$Comp
L GND #PWR022
U 1 1 489A37FB
P 1000 7650
F 0 "#PWR022" H 1000 7650 30  0001 C C
F 1 "GND" H 1000 7580 30  0001 C C
	1    1000 7650
	1    0    0    -1  
$EndComp
$Comp
L C C14
U 1 1 489A2D01
P 1300 7300
F 0 "C14" H 1350 7400 50  0000 L C
F 1 "C" H 1350 7200 50  0000 L C
	1    1300 7300
	1    0    0    -1  
$EndComp
$Comp
L C C13
U 1 1 489A2CFC
P 700 7300
F 0 "C13" H 750 7400 50  0000 L C
F 1 "C" H 750 7200 50  0000 L C
	1    700  7300
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X3
U 1 1 489A2CF4
P 1000 6950
F 0 "X3" H 1000 7100 60  0000 C C
F 1 "CRYSTAL" H 1000 6800 60  0000 C C
	1    1000 6950
	1    0    0    -1  
$EndComp
$Comp
L 74HC595 U11
U 1 1 489A2CD4
P 9100 2150
F 0 "U11" H 9250 2750 70  0000 C C
F 1 "74HC595" H 9100 1550 70  0000 C C
	1    9100 2150
	0    1    1    0   
$EndComp
$Comp
L 74HC595 U10
U 1 1 489A2CBF
P 7700 2150
F 0 "U10" H 7850 2750 70  0000 C C
F 1 "74HC595" H 7700 1550 70  0000 C C
	1    7700 2150
	0    1    1    0   
$EndComp
$Comp
L 74HC595 U9
U 1 1 489A2CB8
P 6300 2150
F 0 "U9" H 6450 2750 70  0000 C C
F 1 "74HC595" H 6300 1550 70  0000 C C
	1    6300 2150
	0    1    1    0   
$EndComp
$Comp
L 74HC595 U8
U 1 1 489A2CB5
P 4950 2150
F 0 "U8" H 5100 2750 70  0000 C C
F 1 "74HC595" H 4950 1550 70  0000 C C
	1    4950 2150
	0    1    1    0   
$EndComp
$Comp
L 74HC595 U7
U 1 1 489A2CAA
P 3600 2150
F 0 "U7" H 3750 2750 70  0000 C C
F 1 "74HC595" H 3600 1550 70  0000 C C
	1    3600 2150
	0    1    1    0   
$EndComp
$Comp
L NPN Q5
U 1 1 489A2C61
P 9150 4700
F 0 "Q5" H 9300 4700 50  0000 C C
F 1 "NPN" H 9052 4850 50  0000 C C
	1    9150 4700
	0    1    1    0   
$EndComp
$Comp
L PIC16F648A U6
U 1 1 489A2C54
P 1300 5350
F 0 "U6" H 1600 6150 60  0000 C C
F 1 "PIC16F648A" H 1750 4550 60  0000 C C
	1    1300 5350
	0    -1   -1   0   
$EndComp
$Sheet
S 1250 700  1600 500 
U 489A2C3C
F0 "Red Card Lights" 60
F1 "cardlights.sch" 60
F2 "Priority" I L 1250 800 60 
F3 "Yellow Card" I L 1250 950 60 
F4 "Red Card" I L 1250 1100 60 
$EndSheet
$Sheet
S 4650 4750 1600 850 
U 489A2C26
F0 "Minutes Numeral" 60
F1 "lednumeral.sch" 60
F2 "Numeral Enable" I L 4650 4800 60 
F3 "Lower Right Segment" I L 4650 4900 60 
F4 "Upper Right Segment" I L 4650 5000 60 
F5 "Upper Segment" I L 4650 5100 60 
F6 "Upper Left Segment" I L 4650 5200 60 
F7 "Middle Segment" I L 4650 5300 60 
F8 "Lower Left Segment" I L 4650 5400 60 
F9 "Lower Segment" I L 4650 5500 60 
$EndSheet
$Sheet
S 4650 6850 1600 850 
U 489A2C11
F0 "Timer 1s Numeral" 60
F1 "lednumeral.sch" 60
F2 "Numeral Enable" I L 4650 6900 60 
F3 "Lower Right Segment" I L 4650 7000 60 
F4 "Upper Right Segment" I L 4650 7100 60 
F5 "Upper Segment" I L 4650 7200 60 
F6 "Upper Left Segment" I L 4650 7300 60 
F7 "Middle Segment" I L 4650 7400 60 
F8 "Lower Left Segment" I L 4650 7500 60 
F9 "Lower Segment" I L 4650 7600 60 
$EndSheet
$Sheet
S 4650 5800 1600 850 
U 489A2C10
F0 "Timer 10s Numeral" 60
F1 "lednumeral.sch" 60
F2 "Numeral Enable" I L 4650 5850 60 
F3 "Lower Right Segment" I L 4650 5950 60 
F4 "Upper Right Segment" I L 4650 6050 60 
F5 "Upper Segment" I L 4650 6150 60 
F6 "Upper Left Segment" I L 4650 6250 60 
F7 "Middle Segment" I L 4650 6350 60 
F8 "Lower Left Segment" I L 4650 6450 60 
F9 "Lower Segment" I L 4650 6550 60 
$EndSheet
$Sheet
S 7100 6250 1600 850 
U 489A2C06
F0 "Red 1's Numeral" 60
F1 "lednumeral.sch" 60
F2 "Numeral Enable" I L 7100 6300 60 
F3 "Lower Right Segment" I L 7100 6400 60 
F4 "Upper Right Segment" I L 7100 6500 60 
F5 "Upper Segment" I L 7100 6600 60 
F6 "Upper Left Segment" I L 7100 6700 60 
F7 "Middle Segment" I L 7100 6800 60 
F8 "Lower Left Segment" I L 7100 6900 60 
F9 "Lower Segment" I L 7100 7000 60 
$EndSheet
$Sheet
S 7100 5200 1600 850 
U 489A2C05
F0 "Red 10's Numeral" 60
F1 "lednumeral.sch" 60
F2 "Numeral Enable" I L 7100 5250 60 
F3 "Lower Right Segment" I L 7100 5350 60 
F4 "Upper Right Segment" I L 7100 5450 60 
F5 "Upper Segment" I L 7100 5550 60 
F6 "Upper Left Segment" I L 7100 5650 60 
F7 "Middle Segment" I L 7100 5750 60 
F8 "Lower Left Segment" I L 7100 5850 60 
F9 "Lower Segment" I L 7100 5950 60 
$EndSheet
$Sheet
S 9550 6250 1600 850 
U 489A2BF0
F0 "Green 1's Numeral" 60
F1 "lednumeral.sch" 60
F2 "Numeral Enable" I L 9550 6300 60 
F3 "Lower Right Segment" I L 9550 6400 60 
F4 "Upper Right Segment" I L 9550 6500 60 
F5 "Upper Segment" I L 9550 6600 60 
F6 "Upper Left Segment" I L 9550 6700 60 
F7 "Middle Segment" I L 9550 6800 60 
F8 "Lower Left Segment" I L 9550 6900 60 
F9 "Lower Segment" I L 9550 7000 60 
$EndSheet
$Sheet
S 1250 1500 1600 500 
U 489A2B46
F0 "Green Card Lights" 60
F1 "cardlights.sch" 60
F2 "Priority" I L 1250 1600 60 
F3 "Yellow Card" I L 1250 1750 60 
F4 "Red Card" I L 1250 1900 60 
$EndSheet
$Sheet
S 9550 5200 1600 850 
U 489A2B44
F0 "Green 10's Numeral" 60
F1 "lednumeral.sch" 60
F2 "Numeral Enable" I L 9550 5250 60 
F3 "Lower Right Segment" I L 9550 5350 60 
F4 "Upper Right Segment" I L 9550 5450 60 
F5 "Upper Segment" I L 9550 5550 60 
F6 "Upper Left Segment" I L 9550 5650 60 
F7 "Middle Segment" I L 9550 5750 60 
F8 "Lower Left Segment" I L 9550 5850 60 
F9 "Lower Segment" I L 9550 5950 60 
$EndSheet
$EndSCHEMATC
