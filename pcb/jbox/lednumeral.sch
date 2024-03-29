EESchema Schematic File Version 2
LIBS:power,device,transistors,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,.\Jbox.cache
EELAYER 24  0
EELAYER END
$Descr A4 11700 8267
Sheet 4 9
Title ""
Date "18 aug 2008"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 5750 6200
Connection ~ 5750 6100
Wire Wire Line
	5750 6100 5750 6350
Wire Wire Line
	7450 6050 7450 1850
Wire Wire Line
	7250 6350 6200 6350
Connection ~ 6200 5650
Wire Wire Line
	6400 5650 6200 5650
Connection ~ 4950 6100
Connection ~ 6200 6100
Wire Wire Line
	4950 5650 4700 5650
Wire Wire Line
	4700 5200 4950 5200
Connection ~ 5750 4800
Connection ~ 6200 4600
Wire Wire Line
	6200 4800 5300 4800
Connection ~ 6200 3350
Wire Wire Line
	6400 3350 6200 3350
Connection ~ 6200 4250
Wire Wire Line
	6200 4250 6200 4300
Wire Wire Line
	6200 4250 6400 4250
Connection ~ 4900 3850
Wire Wire Line
	4900 4300 4900 3400
Connection ~ 6200 3050
Wire Wire Line
	5750 3050 5750 2850
Wire Wire Line
	5300 2850 5300 3050
Connection ~ 5350 6600
Wire Wire Line
	4900 6600 4900 6350
Connection ~ 6600 4800
Wire Wire Line
	4850 1850 4850 2350
Wire Wire Line
	4850 2350 6800 2350
Wire Wire Line
	6800 2350 6800 4800
Wire Wire Line
	6800 4800 6400 4800
Wire Wire Line
	6600 5250 6400 5250
Wire Wire Line
	6400 5700 6600 5700
Connection ~ 4450 5250
Wire Wire Line
	4700 5700 4450 5700
Wire Wire Line
	4450 5700 4450 4800
Connection ~ 6650 2950
Wire Wire Line
	4700 1850 4700 2500
Wire Wire Line
	4700 2500 6650 2500
Wire Wire Line
	6650 2500 6650 3850
Wire Wire Line
	6650 2950 6400 2950
Wire Wire Line
	6650 3400 6400 3400
Connection ~ 5350 2650
Wire Wire Line
	4900 2650 4900 2850
Connection ~ 4900 4400
Wire Wire Line
	4250 1850 4250 4400
Wire Wire Line
	4250 4400 5800 4400
Wire Wire Line
	4900 4400 4900 4600
Wire Wire Line
	5350 4400 5350 4600
Connection ~ 4400 3450
Wire Wire Line
	4400 3000 4700 3000
Wire Wire Line
	4700 3900 4400 3900
Wire Wire Line
	4400 3450 4700 3450
Wire Wire Line
	4400 3900 4400 1850
Connection ~ 4400 3000
Wire Wire Line
	5800 4400 5800 4600
Connection ~ 5350 4400
Wire Wire Line
	5800 2850 5800 2650
Wire Wire Line
	5350 2650 5350 2850
Wire Wire Line
	5800 2650 4550 2650
Wire Wire Line
	4550 2650 4550 1850
Connection ~ 4900 2650
Wire Wire Line
	6650 3850 6400 3850
Connection ~ 6650 3400
Wire Wire Line
	4450 5250 4700 5250
Wire Wire Line
	4700 4800 4100 4800
Wire Wire Line
	4100 4800 4100 1850
Connection ~ 4450 4800
Wire Wire Line
	6600 5700 6600 4800
Connection ~ 6600 5250
Wire Wire Line
	5350 6600 5350 6350
Wire Wire Line
	5800 6350 5800 6600
Wire Wire Line
	5800 6600 3950 6600
Wire Wire Line
	3950 6600 3950 1850
Connection ~ 4900 6600
Wire Wire Line
	5300 3050 6200 3050
Connection ~ 5750 3050
Wire Wire Line
	4900 3400 4700 3400
Wire Wire Line
	4900 3850 4700 3850
Wire Wire Line
	6200 4300 4700 4300
Connection ~ 6200 4300
Connection ~ 4900 4300
Wire Wire Line
	6400 3800 6200 3800
Connection ~ 6200 3800
Wire Wire Line
	5300 4800 5300 4600
Wire Wire Line
	5750 4800 5750 4600
Wire Wire Line
	6200 6350 6200 2850
Connection ~ 6200 4800
Wire Wire Line
	4950 5200 4950 6100
Connection ~ 4950 5650
Wire Wire Line
	6400 6100 4700 6100
Wire Wire Line
	6400 5200 6200 5200
Connection ~ 6200 5200
Wire Wire Line
	8100 6350 7650 6350
Wire Wire Line
	5300 6350 5300 6200
Wire Wire Line
	5300 6200 5750 6200
Text HLabel 7450 1850 3    60   Input
Numeral Enable
$Comp
L GND #PWR024
U 1 1 48991952
P 8100 6350
AR Path="/4899159D/489A2C26/48991952" Ref="#PWR024"  Part="1" 
AR Path="/4899159D/489A2C11/48991952" Ref="#PWR025"  Part="1" 
AR Path="/4899159D/489A2C10/48991952" Ref="#PWR026"  Part="1" 
AR Path="/4899159D/489A2C06/48991952" Ref="#PWR027"  Part="1" 
AR Path="/4899159D/489A2C05/48991952" Ref="#PWR028"  Part="1" 
AR Path="/4899159D/489A2BF0/48991952" Ref="#PWR029"  Part="1" 
AR Path="/4899159D/489A2B44/48991952" Ref="#PWR031"  Part="1" 
F 0 "#PWR031" H 8100 6350 30  0001 C C
F 1 "GND" H 8100 6280 30  0001 C C
	1    8100 6350
	0    -1   -1   0   
$EndComp
$Comp
L NPN Q21
U 1 1 48991923
P 7450 6250
AR Path="/4899159D/489A2C26/48991923" Ref="Q21"  Part="1" 
AR Path="/4899159D/489A2C11/48991923" Ref="Q20"  Part="1" 
AR Path="/4899159D/489A2C10/48991923" Ref="Q19"  Part="1" 
AR Path="/4899159D/489A2C06/48991923" Ref="Q18"  Part="1" 
AR Path="/4899159D/489A2C05/48991923" Ref="Q17"  Part="1" 
AR Path="/4899159D/489A2BF0/48991923" Ref="Q16"  Part="1" 
AR Path="/4899159D/489A2B44/48991923" Ref="Q15"  Part="1" 
F 0 "Q21" H 7600 6250 50  0000 C C
F 1 "NPN" H 7352 6400 50  0000 C C
	1    7450 6250
	0    -1   1    0   
$EndComp
Text HLabel 4850 1850 3    60   Input
Lower Right Segment
Text HLabel 4700 1850 3    60   Input
Upper Right Segment
Text HLabel 4550 1850 3    60   Input
Upper Segment
Text HLabel 4400 1850 3    60   Input
Upper Left Segment
Text HLabel 4250 1850 3    60   Input
Middle Segment
Text HLabel 4100 1850 3    60   Input
Lower Left Segment
Text HLabel 3950 1850 3    60   Input
Lower Segment
$Comp
L LED D186
U 1 1 489916E5
P 6000 6350
AR Path="/4899159D/489A2C26/489916E5" Ref="D186"  Part="1" 
AR Path="/4899159D/489A2C11/489916E5" Ref="D165"  Part="1" 
AR Path="/4899159D/489A2C10/489916E5" Ref="D144"  Part="1" 
AR Path="/4899159D/489A2C06/489916E5" Ref="D123"  Part="1" 
AR Path="/4899159D/489A2C05/489916E5" Ref="D102"  Part="1" 
AR Path="/4899159D/489A2BF0/489916E5" Ref="D81"  Part="1" 
AR Path="/4899159D/489A2B44/489916E5" Ref="D57"  Part="1" 
F 0 "D186" H 6000 6450 50  0000 C C
F 1 "LED" H 6000 6250 50  0000 C C
	1    6000 6350
	1    0    0    -1  
$EndComp
$Comp
L LED D183
U 1 1 489916E4
P 5550 6350
AR Path="/4899159D/489A2C26/489916E4" Ref="D183"  Part="1" 
AR Path="/4899159D/489A2C11/489916E4" Ref="D162"  Part="1" 
AR Path="/4899159D/489A2C10/489916E4" Ref="D141"  Part="1" 
AR Path="/4899159D/489A2C06/489916E4" Ref="D120"  Part="1" 
AR Path="/4899159D/489A2C05/489916E4" Ref="D99"  Part="1" 
AR Path="/4899159D/489A2BF0/489916E4" Ref="D78"  Part="1" 
AR Path="/4899159D/489A2B44/489916E4" Ref="D54"  Part="1" 
F 0 "D183" H 5550 6450 50  0000 C C
F 1 "LED" H 5550 6250 50  0000 C C
	1    5550 6350
	1    0    0    -1  
$EndComp
$Comp
L LED D180
U 1 1 489916E3
P 5100 6350
AR Path="/4899159D/489A2C26/489916E3" Ref="D180"  Part="1" 
AR Path="/4899159D/489A2C11/489916E3" Ref="D159"  Part="1" 
AR Path="/4899159D/489A2C10/489916E3" Ref="D138"  Part="1" 
AR Path="/4899159D/489A2C06/489916E3" Ref="D117"  Part="1" 
AR Path="/4899159D/489A2C05/489916E3" Ref="D96"  Part="1" 
AR Path="/4899159D/489A2BF0/489916E3" Ref="D75"  Part="1" 
AR Path="/4899159D/489A2B44/489916E3" Ref="D51"  Part="1" 
F 0 "D180" H 5100 6450 50  0000 C C
F 1 "LED" H 5100 6250 50  0000 C C
	1    5100 6350
	1    0    0    -1  
$EndComp
$Comp
L LED D185
U 1 1 489916DD
P 6000 4600
AR Path="/4899159D/489A2C26/489916DD" Ref="D185"  Part="1" 
AR Path="/4899159D/489A2C11/489916DD" Ref="D164"  Part="1" 
AR Path="/4899159D/489A2C10/489916DD" Ref="D143"  Part="1" 
AR Path="/4899159D/489A2C06/489916DD" Ref="D122"  Part="1" 
AR Path="/4899159D/489A2C05/489916DD" Ref="D101"  Part="1" 
AR Path="/4899159D/489A2BF0/489916DD" Ref="D80"  Part="1" 
AR Path="/4899159D/489A2B44/489916DD" Ref="D56"  Part="1" 
F 0 "D185" H 6000 4700 50  0000 C C
F 1 "LED" H 6000 4500 50  0000 C C
	1    6000 4600
	1    0    0    -1  
$EndComp
$Comp
L LED D182
U 1 1 489916DC
P 5550 4600
AR Path="/4899159D/489A2C26/489916DC" Ref="D182"  Part="1" 
AR Path="/4899159D/489A2C11/489916DC" Ref="D161"  Part="1" 
AR Path="/4899159D/489A2C10/489916DC" Ref="D140"  Part="1" 
AR Path="/4899159D/489A2C06/489916DC" Ref="D119"  Part="1" 
AR Path="/4899159D/489A2C05/489916DC" Ref="D98"  Part="1" 
AR Path="/4899159D/489A2BF0/489916DC" Ref="D77"  Part="1" 
AR Path="/4899159D/489A2B44/489916DC" Ref="D53"  Part="1" 
F 0 "D182" H 5550 4700 50  0000 C C
F 1 "LED" H 5550 4500 50  0000 C C
	1    5550 4600
	1    0    0    -1  
$EndComp
$Comp
L LED D179
U 1 1 489916DB
P 5100 4600
AR Path="/4899159D/489A2C26/489916DB" Ref="D179"  Part="1" 
AR Path="/4899159D/489A2C11/489916DB" Ref="D158"  Part="1" 
AR Path="/4899159D/489A2C10/489916DB" Ref="D137"  Part="1" 
AR Path="/4899159D/489A2C06/489916DB" Ref="D116"  Part="1" 
AR Path="/4899159D/489A2C05/489916DB" Ref="D95"  Part="1" 
AR Path="/4899159D/489A2BF0/489916DB" Ref="D74"  Part="1" 
AR Path="/4899159D/489A2B44/489916DB" Ref="D50"  Part="1" 
F 0 "D179" H 5100 4700 50  0000 C C
F 1 "LED" H 5100 4500 50  0000 C C
	1    5100 4600
	1    0    0    -1  
$EndComp
$Comp
L LED D184
U 1 1 489916AF
P 6000 2850
AR Path="/4899159D/489A2C26/489916AF" Ref="D184"  Part="1" 
AR Path="/4899159D/489A2C11/489916AF" Ref="D163"  Part="1" 
AR Path="/4899159D/489A2C10/489916AF" Ref="D142"  Part="1" 
AR Path="/4899159D/489A2C06/489916AF" Ref="D121"  Part="1" 
AR Path="/4899159D/489A2C05/489916AF" Ref="D100"  Part="1" 
AR Path="/4899159D/489A2BF0/489916AF" Ref="D79"  Part="1" 
AR Path="/4899159D/489A2B44/489916AF" Ref="D55"  Part="1" 
F 0 "D184" H 6000 2950 50  0000 C C
F 1 "LED" H 6000 2750 50  0000 C C
	1    6000 2850
	1    0    0    -1  
$EndComp
$Comp
L LED D181
U 1 1 489916A4
P 5550 2850
AR Path="/4899159D/489A2C26/489916A4" Ref="D181"  Part="1" 
AR Path="/4899159D/489A2C11/489916A4" Ref="D160"  Part="1" 
AR Path="/4899159D/489A2C10/489916A4" Ref="D139"  Part="1" 
AR Path="/4899159D/489A2C06/489916A4" Ref="D118"  Part="1" 
AR Path="/4899159D/489A2C05/489916A4" Ref="D97"  Part="1" 
AR Path="/4899159D/489A2BF0/489916A4" Ref="D76"  Part="1" 
AR Path="/4899159D/489A2B44/489916A4" Ref="D52"  Part="1" 
F 0 "D181" H 5550 2950 50  0000 C C
F 1 "LED" H 5550 2750 50  0000 C C
	1    5550 2850
	1    0    0    -1  
$EndComp
$Comp
L LED D178
U 1 1 4899169E
P 5100 2850
AR Path="/4899159D/489A2C26/4899169E" Ref="D178"  Part="1" 
AR Path="/4899159D/489A2C11/4899169E" Ref="D157"  Part="1" 
AR Path="/4899159D/489A2C10/4899169E" Ref="D136"  Part="1" 
AR Path="/4899159D/489A2C06/4899169E" Ref="D115"  Part="1" 
AR Path="/4899159D/489A2C05/4899169E" Ref="D94"  Part="1" 
AR Path="/4899159D/489A2BF0/4899169E" Ref="D73"  Part="1" 
AR Path="/4899159D/489A2B44/4899169E" Ref="D49"  Part="1" 
F 0 "D178" H 5100 2950 50  0000 C C
F 1 "LED" H 5100 2750 50  0000 C C
	1    5100 2850
	1    0    0    -1  
$EndComp
$Comp
L LED D177
U 1 1 48991698
P 4700 5900
AR Path="/4899159D/489A2C26/48991698" Ref="D177"  Part="1" 
AR Path="/4899159D/489A2C11/48991698" Ref="D156"  Part="1" 
AR Path="/4899159D/489A2C10/48991698" Ref="D135"  Part="1" 
AR Path="/4899159D/489A2C06/48991698" Ref="D114"  Part="1" 
AR Path="/4899159D/489A2C05/48991698" Ref="D93"  Part="1" 
AR Path="/4899159D/489A2BF0/48991698" Ref="D72"  Part="1" 
AR Path="/4899159D/489A2B44/48991698" Ref="D48"  Part="1" 
F 0 "D177" H 4700 6000 50  0000 C C
F 1 "LED" H 4700 5800 50  0000 C C
	1    4700 5900
	0    1    1    0   
$EndComp
$Comp
L LED D176
U 1 1 48991697
P 4700 5450
AR Path="/4899159D/489A2C26/48991697" Ref="D176"  Part="1" 
AR Path="/4899159D/489A2C11/48991697" Ref="D155"  Part="1" 
AR Path="/4899159D/489A2C10/48991697" Ref="D134"  Part="1" 
AR Path="/4899159D/489A2C06/48991697" Ref="D113"  Part="1" 
AR Path="/4899159D/489A2C05/48991697" Ref="D92"  Part="1" 
AR Path="/4899159D/489A2BF0/48991697" Ref="D71"  Part="1" 
AR Path="/4899159D/489A2B44/48991697" Ref="D47"  Part="1" 
F 0 "D176" H 4700 5550 50  0000 C C
F 1 "LED" H 4700 5350 50  0000 C C
	1    4700 5450
	0    1    1    0   
$EndComp
$Comp
L LED D175
U 1 1 48991696
P 4700 5000
AR Path="/4899159D/489A2C26/48991696" Ref="D175"  Part="1" 
AR Path="/4899159D/489A2C11/48991696" Ref="D154"  Part="1" 
AR Path="/4899159D/489A2C10/48991696" Ref="D133"  Part="1" 
AR Path="/4899159D/489A2C06/48991696" Ref="D112"  Part="1" 
AR Path="/4899159D/489A2C05/48991696" Ref="D91"  Part="1" 
AR Path="/4899159D/489A2BF0/48991696" Ref="D70"  Part="1" 
AR Path="/4899159D/489A2B44/48991696" Ref="D46"  Part="1" 
F 0 "D175" H 4700 5100 50  0000 C C
F 1 "LED" H 4700 4900 50  0000 C C
	1    4700 5000
	0    1    1    0   
$EndComp
$Comp
L LED D192
U 1 1 4899168B
P 6400 5900
AR Path="/4899159D/489A2C26/4899168B" Ref="D192"  Part="1" 
AR Path="/4899159D/489A2C11/4899168B" Ref="D171"  Part="1" 
AR Path="/4899159D/489A2C10/4899168B" Ref="D150"  Part="1" 
AR Path="/4899159D/489A2C06/4899168B" Ref="D129"  Part="1" 
AR Path="/4899159D/489A2C05/4899168B" Ref="D108"  Part="1" 
AR Path="/4899159D/489A2BF0/4899168B" Ref="D87"  Part="1" 
AR Path="/4899159D/489A2B44/4899168B" Ref="D63"  Part="1" 
F 0 "D192" H 6400 6000 50  0000 C C
F 1 "LED" H 6400 5800 50  0000 C C
	1    6400 5900
	0    1    1    0   
$EndComp
$Comp
L LED D191
U 1 1 4899168A
P 6400 5450
AR Path="/4899159D/489A2C26/4899168A" Ref="D191"  Part="1" 
AR Path="/4899159D/489A2C11/4899168A" Ref="D170"  Part="1" 
AR Path="/4899159D/489A2C10/4899168A" Ref="D149"  Part="1" 
AR Path="/4899159D/489A2C06/4899168A" Ref="D128"  Part="1" 
AR Path="/4899159D/489A2C05/4899168A" Ref="D107"  Part="1" 
AR Path="/4899159D/489A2BF0/4899168A" Ref="D86"  Part="1" 
AR Path="/4899159D/489A2B44/4899168A" Ref="D62"  Part="1" 
F 0 "D191" H 6400 5550 50  0000 C C
F 1 "LED" H 6400 5350 50  0000 C C
	1    6400 5450
	0    1    1    0   
$EndComp
$Comp
L LED D190
U 1 1 48991689
P 6400 5000
AR Path="/4899159D/489A2C26/48991689" Ref="D190"  Part="1" 
AR Path="/4899159D/489A2C11/48991689" Ref="D169"  Part="1" 
AR Path="/4899159D/489A2C10/48991689" Ref="D148"  Part="1" 
AR Path="/4899159D/489A2C06/48991689" Ref="D127"  Part="1" 
AR Path="/4899159D/489A2C05/48991689" Ref="D106"  Part="1" 
AR Path="/4899159D/489A2BF0/48991689" Ref="D85"  Part="1" 
AR Path="/4899159D/489A2B44/48991689" Ref="D61"  Part="1" 
F 0 "D190" H 6400 5100 50  0000 C C
F 1 "LED" H 6400 4900 50  0000 C C
	1    6400 5000
	0    1    1    0   
$EndComp
$Comp
L LED D189
U 1 1 4899166C
P 6400 4050
AR Path="/4899159D/489A2C26/4899166C" Ref="D189"  Part="1" 
AR Path="/4899159D/489A2C11/4899166C" Ref="D168"  Part="1" 
AR Path="/4899159D/489A2C10/4899166C" Ref="D147"  Part="1" 
AR Path="/4899159D/489A2C06/4899166C" Ref="D126"  Part="1" 
AR Path="/4899159D/489A2C05/4899166C" Ref="D105"  Part="1" 
AR Path="/4899159D/489A2BF0/4899166C" Ref="D84"  Part="1" 
AR Path="/4899159D/489A2B44/4899166C" Ref="D60"  Part="1" 
F 0 "D189" H 6400 4150 50  0000 C C
F 1 "LED" H 6400 3950 50  0000 C C
	1    6400 4050
	0    1    1    0   
$EndComp
$Comp
L LED D188
U 1 1 4899166B
P 6400 3600
AR Path="/4899159D/489A2C26/4899166B" Ref="D188"  Part="1" 
AR Path="/4899159D/489A2C11/4899166B" Ref="D167"  Part="1" 
AR Path="/4899159D/489A2C10/4899166B" Ref="D146"  Part="1" 
AR Path="/4899159D/489A2C06/4899166B" Ref="D125"  Part="1" 
AR Path="/4899159D/489A2C05/4899166B" Ref="D104"  Part="1" 
AR Path="/4899159D/489A2BF0/4899166B" Ref="D83"  Part="1" 
AR Path="/4899159D/489A2B44/4899166B" Ref="D59"  Part="1" 
F 0 "D188" H 6400 3700 50  0000 C C
F 1 "LED" H 6400 3500 50  0000 C C
	1    6400 3600
	0    1    1    0   
$EndComp
$Comp
L LED D187
U 1 1 4899166A
P 6400 3150
AR Path="/4899159D/489A2C26/4899166A" Ref="D187"  Part="1" 
AR Path="/4899159D/489A2C11/4899166A" Ref="D166"  Part="1" 
AR Path="/4899159D/489A2C10/4899166A" Ref="D145"  Part="1" 
AR Path="/4899159D/489A2C06/4899166A" Ref="D124"  Part="1" 
AR Path="/4899159D/489A2C05/4899166A" Ref="D103"  Part="1" 
AR Path="/4899159D/489A2BF0/4899166A" Ref="D82"  Part="1" 
AR Path="/4899159D/489A2B44/4899166A" Ref="D58"  Part="1" 
F 0 "D187" H 6400 3250 50  0000 C C
F 1 "LED" H 6400 3050 50  0000 C C
	1    6400 3150
	0    1    1    0   
$EndComp
$Comp
L LED D174
U 1 1 48991633
P 4700 4100
AR Path="/4899159D/489A2C26/48991633" Ref="D174"  Part="1" 
AR Path="/4899159D/489A2C11/48991633" Ref="D153"  Part="1" 
AR Path="/4899159D/489A2C10/48991633" Ref="D132"  Part="1" 
AR Path="/4899159D/489A2C06/48991633" Ref="D111"  Part="1" 
AR Path="/4899159D/489A2C05/48991633" Ref="D90"  Part="1" 
AR Path="/4899159D/489A2BF0/48991633" Ref="D69"  Part="1" 
AR Path="/4899159D/489A2B44/48991633" Ref="D45"  Part="1" 
F 0 "D174" H 4700 4200 50  0000 C C
F 1 "LED" H 4700 4000 50  0000 C C
	1    4700 4100
	0    1    1    0   
$EndComp
$Comp
L LED D173
U 1 1 48991629
P 4700 3650
AR Path="/4899159D/489A2C26/48991629" Ref="D173"  Part="1" 
AR Path="/4899159D/489A2C11/48991629" Ref="D152"  Part="1" 
AR Path="/4899159D/489A2C10/48991629" Ref="D131"  Part="1" 
AR Path="/4899159D/489A2C06/48991629" Ref="D110"  Part="1" 
AR Path="/4899159D/489A2C05/48991629" Ref="D89"  Part="1" 
AR Path="/4899159D/489A2BF0/48991629" Ref="D68"  Part="1" 
AR Path="/4899159D/489A2B44/48991629" Ref="D44"  Part="1" 
F 0 "D173" H 4700 3750 50  0000 C C
F 1 "LED" H 4700 3550 50  0000 C C
	1    4700 3650
	0    1    1    0   
$EndComp
$Comp
L LED D172
U 1 1 4899161D
P 4700 3200
AR Path="/4899159D/489A2C26/4899161D" Ref="D172"  Part="1" 
AR Path="/4899159D/489A2C11/4899161D" Ref="D151"  Part="1" 
AR Path="/4899159D/489A2C10/4899161D" Ref="D130"  Part="1" 
AR Path="/4899159D/489A2C06/4899161D" Ref="D109"  Part="1" 
AR Path="/4899159D/489A2C05/4899161D" Ref="D88"  Part="1" 
AR Path="/4899159D/489A2BF0/4899161D" Ref="D67"  Part="1" 
AR Path="/4899159D/489A2B44/4899161D" Ref="D43"  Part="1" 
F 0 "D172" H 4700 3300 50  0000 C C
F 1 "LED" H 4700 3100 50  0000 C C
	1    4700 3200
	0    1    1    0   
$EndComp
$EndSCHEMATC
