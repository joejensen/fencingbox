EESchema Schematic File Version 2
LIBS:power,device,transistors,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves
EELAYER 24  0
EELAYER END
$Descr A4 11700 8267
Sheet 1 6
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
	8600 4000 8450 4000
Connection ~ 7950 4000
Wire Wire Line
	7950 4100 7950 3300
Wire Wire Line
	7950 3300 6400 3300
Wire Wire Line
	9950 3300 9650 3300
Wire Wire Line
	9150 2950 8850 2950
Wire Wire Line
	8450 3300 8250 3300
Wire Wire Line
	8250 3300 8250 2950
Wire Wire Line
	8250 2950 8450 2950
Wire Wire Line
	6400 3000 7300 3000
Wire Wire Line
	7300 3000 7300 2200
Wire Wire Line
	7300 2200 6400 2200
Wire Wire Line
	5200 2200 4550 2200
Wire Wire Line
	4550 2200 4550 3000
Wire Wire Line
	4550 3000 5100 3000
Wire Wire Line
	6400 3150 8250 3150
Connection ~ 8250 3150
Wire Wire Line
	9650 2950 9950 2950
Wire Wire Line
	9150 3300 8850 3300
Wire Wire Line
	6400 3450 6650 3450
Wire Wire Line
	7950 5100 7950 5450
$Comp
L GND #PWR?
U 1 1 48F7DB4D
P 7950 5450
F 0 "#PWR?" H 7950 5450 30  0001 C C
F 1 "GND" H 7950 5380 30  0001 C C
	1    7950 5450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 48F7DB44
P 8600 4000
F 0 "#PWR?" H 8600 4090 20  0001 C C
F 1 "+5V" H 8600 4090 30  0000 C C
	1    8600 4000
	0    1    -1   0   
$EndComp
$Comp
L SPST SW?
U 1 1 48F7DB22
P 7950 4600
F 0 "SW?" H 7950 4700 70  0000 C C
F 1 "SPST" H 7950 4500 70  0000 C C
	1    7950 4600
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 48F7DAFC
P 8200 4000
F 0 "R?" V 8280 4000 50  0000 C C
F 1 "2000" V 8200 4000 50  0000 C C
	1    8200 4000
	0    1    1    0   
$EndComp
NoConn ~ 6650 3450
$Comp
L +5V #PWR2
U 1 1 48F7DA0E
P 9950 3300
F 0 "#PWR2" H 9950 3390 20  0001 C C
F 1 "+5V" H 9950 3390 30  0000 C C
	1    9950 3300
	0    1    1    0   
$EndComp
$Comp
L GND #PWR1
U 1 1 48F7DA07
P 9950 2950
F 0 "#PWR1" H 9950 2950 30  0001 C C
F 1 "GND" H 9950 2880 30  0001 C C
	1    9950 2950
	0    -1   1    0   
$EndComp
$Comp
L R R2
U 1 1 48F7D9EC
P 9400 3300
F 0 "R2" V 9480 3300 50  0000 C C
F 1 "220" V 9400 3300 50  0000 C C
	1    9400 3300
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 48F7D9DF
P 9400 2950
F 0 "R1" V 9480 2950 50  0000 C C
F 1 "220" V 9400 2950 50  0000 C C
	1    9400 2950
	0    1    1    0   
$EndComp
$Comp
L LED D2
U 1 1 48F7D9A7
P 8650 3300
F 0 "D2" H 8650 3400 50  0000 C C
F 1 "LED" H 8650 3200 50  0000 C C
	1    8650 3300
	-1   0    0    1   
$EndComp
$Comp
L LED D1
U 1 1 48F7D9A4
P 8650 2950
F 0 "D1" H 8650 3050 50  0000 C C
F 1 "LED" H 8650 2850 50  0000 C C
	1    8650 2950
	1    0    0    -1  
$EndComp
$Sheet
S 4950 4200 1600 600 
U 48F7D887
F0 "powerregulator" 60
F1 "jboxpowerregulator.sch" 60
$EndSheet
$Sheet
S 5200 1900 1200 500 
U 48F7D85F
F0 "rs232receiver" 60
F1 "jboxrs232receiver.sch" 60
F2 "TO_PC" I R 6400 2200 60 
F3 "From_PC" O L 5200 2200 60 
$EndSheet
$Sheet
S 5100 2850 1300 750 
U 48F7D78B
F0 "fencingmodule" 60
F1 "Fencing Module.sch" 60
F2 "F-D Line B" B R 6400 3450 60 
F3 "F-D Line A" B R 6400 3300 60 
F4 "usart out" O R 6400 3000 60 
F5 "usart in" I L 5100 3000 60 
F6 "Output C" O R 6400 3150 60 
$EndSheet
$EndSCHEMATC
