EESchema Schematic File Version 2
LIBS:power,device,transistors,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,.\Jbox.cache
EELAYER 24  0
EELAYER END
$Descr A4 11700 8267
Sheet 3 9
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
	5700 3500 5150 3500
Wire Wire Line
	5700 2850 5150 2850
Connection ~ 6600 3200
Wire Wire Line
	6100 3500 6600 3500
Wire Wire Line
	6600 3500 6600 2850
Wire Wire Line
	6600 2850 6100 2850
Wire Wire Line
	7600 3200 6100 3200
Wire Wire Line
	5700 3200 5150 3200
Text HLabel 5150 3500 0    60   Input
Priority
Text HLabel 5150 3200 0    60   Input
Yellow Card
Text HLabel 5150 2850 0    60   Input
Red Card
$Comp
L GND #PWR023
U 1 1 489A236B
P 7600 3200
AR Path="/4899159D/489A2C3C/489A236B" Ref="#PWR023"  Part="1" 
AR Path="/4899159D/489A2B46/489A236B" Ref="#PWR030"  Part="1" 
F 0 "#PWR030" H 7600 3200 30  0001 C C
F 1 "GND" H 7600 3130 30  0001 C C
	1    7600 3200
	0    -1   1    0   
$EndComp
$Comp
L LED D195
U 1 1 489A2320
P 5900 3500
AR Path="/4899159D/489A2C3C/489A2320" Ref="D195"  Part="1" 
AR Path="/4899159D/489A2B46/489A2320" Ref="D66"  Part="1" 
F 0 "D195" H 5900 3600 50  0000 C C
F 1 "LED" H 5900 3400 50  0000 C C
	1    5900 3500
	1    0    0    -1  
$EndComp
$Comp
L LED D194
U 1 1 489A231A
P 5900 3200
AR Path="/4899159D/489A2C3C/489A231A" Ref="D194"  Part="1" 
AR Path="/4899159D/489A2B46/489A231A" Ref="D65"  Part="1" 
F 0 "D194" H 5900 3300 50  0000 C C
F 1 "LED" H 5900 3100 50  0000 C C
	1    5900 3200
	1    0    0    -1  
$EndComp
$Comp
L LED D193
U 1 1 489A2315
P 5900 2850
AR Path="/4899159D/489A2C3C/489A2315" Ref="D193"  Part="1" 
AR Path="/4899159D/489A2B46/489A2315" Ref="D64"  Part="1" 
F 0 "D193" H 5900 2950 50  0000 C C
F 1 "LED" H 5900 2750 50  0000 C C
	1    5900 2850
	1    0    0    -1  
$EndComp
$EndSCHEMATC
