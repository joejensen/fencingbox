EESchema Schematic File Version 2
LIBS:power,device,transistors,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,.\Jbox.cache
EELAYER 24  0
EELAYER END
$Descr A4 11700 8267
Sheet 1 9
Title "JBox Root Schematic"
Date "18 aug 2008"
Rev ".1"
Comp "JBox Project"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	6000 4400 7000 4400
Wire Wire Line
	6150 3300 8500 3300
Wire Wire Line
	8500 3300 8500 4200
Wire Wire Line
	8500 4200 7850 4200
Wire Wire Line
	5150 4100 4600 4100
Wire Wire Line
	4600 4100 4600 4250
Wire Wire Line
	4600 4250 4050 4250
Wire Wire Line
	5150 3300 3100 3300
Wire Wire Line
	3100 3300 3100 4150
Wire Wire Line
	3100 4150 3300 4150
Wire Wire Line
	6000 4200 6550 4200
Wire Wire Line
	6550 4200 6550 4100
Wire Wire Line
	6550 4100 7000 4100
Wire Wire Line
	7000 4300 6000 4300
$Sheet
S 7000 4000 850  500 
U 4899159D
F0 "Display Module" 60
F1 "displaymodule.sch" 60
F2 "F-D Line B" B L 7000 4400 60 
F3 "F-D Line A" B L 7000 4300 60 
F4 "usart out" O R 7850 4200 60 
F5 "usart in" I L 7000 4100 60 
$EndSheet
$Sheet
S 5150 4000 850  500 
U 4899158D
F0 "fencingmodule" 60
F1 "Fencing Module.sch" 60
F2 "usart out" O R 6000 4200 60 
F3 "usart in" I L 5150 4100 60 
F4 "F-D Line B" B R 6000 4400 60 
F5 "F-D Line A" B R 6000 4300 60 
$EndSheet
$Sheet
S 3300 4000 750  500 
U 48991573
F0 "Receiver Module" 60
F1 "receivermodule.sch" 60
F2 "usart out" I R 4050 4250 60 
F3 "usart in" I L 3300 4150 60 
$EndSheet
$Sheet
S 5050 5150 1000 350 
U 4895DAC0
F0 "JBox Power Regulation" 60
F1 "jboxpowerregulator.sch" 60
$EndSheet
$Sheet
S 5150 3100 1000 400 
U 4895D759
F0 "JBox RS232Receiver" 60
F1 "jboxrs232receiver.sch" 60
F2 "TO_PC" I R 6150 3300 60 
F3 "From_PC" O L 5150 3300 60 
$EndSheet
$EndSCHEMATC
