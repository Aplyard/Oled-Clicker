EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:tp4056
LIBS:ce8301
LIBS:dw01
LIBS:fs8205a
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R2
U 1 1 5980CC1A
P 2300 2250
F 0 "R2" V 2380 2250 50  0000 C CNN
F 1 "1k" V 2300 2250 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2230 2250 50  0001 C CNN
F 3 "" H 2300 2250 50  0001 C CNN
	1    2300 2250
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 5980CC73
P 1300 2800
F 0 "C1" H 1325 2900 50  0000 L CNN
F 1 "0.1uF" H 1325 2700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1338 2650 50  0001 C CNN
F 3 "" H 1300 2800 50  0001 C CNN
	1    1300 2800
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 5980CCB4
P 1700 2550
F 0 "D2" H 1700 2650 50  0000 C CNN
F 1 "LED" H 1700 2450 50  0000 C CNN
F 2 "LEDs:LED_0603_HandSoldering" H 1700 2550 50  0001 C CNN
F 3 "" H 1700 2550 50  0001 C CNN
	1    1700 2550
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 5980CDB4
P 2250 2550
F 0 "R1" V 2330 2550 50  0000 C CNN
F 1 "1k" V 2250 2550 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2180 2550 50  0001 C CNN
F 3 "" H 2250 2550 50  0001 C CNN
	1    2250 2550
	0    1    1    0   
$EndComp
$Comp
L LED D1
U 1 1 5980CE60
P 1700 2250
F 0 "D1" H 1700 2350 50  0000 C CNN
F 1 "LED" H 1700 2150 50  0000 C CNN
F 2 "LEDs:LED_0603_HandSoldering" H 1700 2250 50  0001 C CNN
F 3 "" H 1700 2250 50  0001 C CNN
	1    1700 2250
	-1   0    0    1   
$EndComp
$Comp
L R R3
U 1 1 5980D069
P 4050 2500
F 0 "R3" V 4130 2500 50  0000 C CNN
F 1 "10k" V 4050 2500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3980 2500 50  0001 C CNN
F 3 "" H 4050 2500 50  0001 C CNN
	1    4050 2500
	0    1    1    0   
$EndComp
Text GLabel 8050 2250 2    39   Input ~ 0
BAT+
Text GLabel 1100 2100 0    39   Input ~ 0
IN+
Text GLabel 1100 3150 0    39   Input ~ 0
IN-
Text Notes 950  2550 0    60   ~ 0
+5
$Comp
L R R4
U 1 1 598D0D68
P 5400 2700
F 0 "R4" V 5480 2700 50  0000 C CNN
F 1 "1k" V 5400 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5330 2700 50  0001 C CNN
F 3 "" H 5400 2700 50  0001 C CNN
	1    5400 2700
	-1   0    0    1   
$EndComp
$Comp
L C C2
U 1 1 598D1488
P 6950 2550
F 0 "C2" H 6975 2650 50  0000 L CNN
F 1 "0.1uF" H 6975 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6988 2400 50  0001 C CNN
F 3 "" H 6950 2550 50  0001 C CNN
	1    6950 2550
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 598D157A
P 7450 2250
F 0 "R5" V 7530 2250 50  0000 C CNN
F 1 "100" V 7450 2250 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7380 2250 50  0001 C CNN
F 3 "" H 7450 2250 50  0001 C CNN
	1    7450 2250
	0    1    1    0   
$EndComp
$Comp
L DW01 U2
U 1 1 598D23F7
P 6100 2400
F 0 "U2" H 6200 2750 60  0000 C CNN
F 1 "DW01" H 6000 2750 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-6_Handsoldering" H 6050 2100 60  0001 C CNN
F 3 "" H 6050 2100 60  0001 C CNN
	1    6100 2400
	1    0    0    -1  
$EndComp
$Comp
L TP4056 U1
U 1 1 597F50E3
P 3350 2350
F 0 "U1" H 3000 2750 60  0000 L CNN
F 1 "TP4056" H 3700 2750 60  0000 R CNN
F 2 "lib:TP4056_SOP-8-PP" H 3350 2350 60  0001 C CNN
F 3 "" H 3350 2350 60  0000 C CNN
	1    3350 2350
	1    0    0    -1  
$EndComp
NoConn ~ 5550 2250
Text GLabel 8050 1950 2    39   Input ~ 0
OUT+
Text GLabel 8050 3000 2    39   Input ~ 0
BAT-
Text GLabel 8050 3350 2    39   Input ~ 0
OUT-
$Comp
L CONN_01X01 J2
U 1 1 598F8785
P 950 1600
F 0 "J2" H 950 1700 50  0000 C CNN
F 1 "CONN_in+" V 1050 1600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 950 1600 50  0001 C CNN
F 3 "" H 950 1600 50  0001 C CNN
	1    950  1600
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X01 J1
U 1 1 598F8882
P 900 3550
F 0 "J1" H 900 3650 50  0000 C CNN
F 1 "CONN_in-" V 1000 3550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 900 3550 50  0001 C CNN
F 3 "" H 900 3550 50  0001 C CNN
	1    900  3550
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X01 J5
U 1 1 598F8A0B
P 8700 2400
F 0 "J5" H 8700 2500 50  0000 C CNN
F 1 "CONN_bat+" V 8800 2400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 8700 2400 50  0001 C CNN
F 3 "" H 8700 2400 50  0001 C CNN
	1    8700 2400
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 J6
U 1 1 598F8B93
P 8800 2800
F 0 "J6" H 8800 2900 50  0000 C CNN
F 1 "CONN_bat-" V 8900 2800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 8800 2800 50  0001 C CNN
F 3 "" H 8800 2800 50  0001 C CNN
	1    8800 2800
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 J4
U 1 1 598F8EE2
P 8600 4400
F 0 "J4" H 8600 4500 50  0000 C CNN
F 1 "conOut-" V 8700 4400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 8600 4400 50  0001 C CNN
F 3 "" H 8600 4400 50  0001 C CNN
	1    8600 4400
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 J3
U 1 1 598F8FBA
P 8500 1650
F 0 "J3" H 8500 1750 50  0000 C CNN
F 1 "conOut+" V 8600 1650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 8500 1650 50  0001 C CNN
F 3 "" H 8500 1650 50  0001 C CNN
	1    8500 1650
	1    0    0    -1  
$EndComp
Text Notes 3700 2850 0    39   ~ 0
Set Charging\n Current to 130ma\n
Wire Wire Line
	1850 2250 2150 2250
Wire Wire Line
	1850 2550 2100 2550
Wire Wire Line
	2450 2250 2450 2400
Wire Wire Line
	2450 2400 2850 2400
Wire Wire Line
	2400 2550 2450 2550
Wire Wire Line
	2450 2550 2450 2500
Wire Wire Line
	2450 2500 2850 2500
Wire Wire Line
	3850 2500 3900 2500
Wire Wire Line
	3850 2100 5650 2100
Wire Wire Line
	2550 2200 2850 2200
Wire Wire Line
	1100 2100 2850 2100
Connection ~ 2550 2100
Wire Wire Line
	2550 2100 2550 2300
Wire Wire Line
	1100 3150 4900 3150
Wire Wire Line
	3350 3150 3350 2750
Wire Wire Line
	3850 2400 4300 2400
Wire Wire Line
	4300 2400 4300 3150
Wire Wire Line
	4300 2500 4200 2500
Connection ~ 3350 3150
Connection ~ 4300 2500
Wire Wire Line
	1550 2250 1450 2250
Wire Wire Line
	1450 2100 1450 2550
Connection ~ 1450 2100
Wire Wire Line
	1450 2550 1550 2550
Connection ~ 1450 2250
Wire Wire Line
	1300 2650 1300 2100
Connection ~ 1300 2100
Wire Wire Line
	1300 2950 1300 3150
Connection ~ 1300 3150
Wire Wire Line
	6700 2250 7300 2250
Connection ~ 6950 2250
Wire Wire Line
	6950 2400 6950 2250
Wire Wire Line
	6700 2450 6750 2450
Wire Wire Line
	6750 2450 6750 3000
Wire Wire Line
	5550 2450 5400 2450
Wire Wire Line
	5400 2450 5400 2550
Wire Wire Line
	5650 2100 5650 1950
Wire Wire Line
	5650 1950 8050 1950
Wire Wire Line
	7600 2250 8050 2250
Wire Wire Line
	7750 1950 7750 2250
Connection ~ 7750 2250
Connection ~ 7750 1950
Wire Wire Line
	4900 4400 8400 4400
Wire Wire Line
	7900 4400 7900 3350
Wire Wire Line
	7900 3350 8050 3350
Wire Wire Line
	1150 1600 1200 1600
Wire Wire Line
	1200 1600 1200 2100
Connection ~ 1200 2100
Wire Wire Line
	1100 3550 1200 3550
Wire Wire Line
	1200 3550 1200 3150
Connection ~ 1200 3150
Wire Wire Line
	8500 2400 7900 2400
Wire Wire Line
	7900 2400 7900 2250
Connection ~ 7900 2250
Wire Wire Line
	8600 2800 7900 2800
Connection ~ 7900 4400
Wire Wire Line
	8300 1650 7950 1650
Wire Wire Line
	7950 1650 7950 1950
Connection ~ 7950 1950
$Comp
L C C3
U 1 1 5996DEBE
P 4600 2700
F 0 "C3" H 4625 2800 50  0000 L CNN
F 1 "10uF" H 4625 2600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4638 2550 50  0001 C CNN
F 3 "" H 4600 2700 50  0001 C CNN
	1    4600 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2550 4600 2100
Connection ~ 4600 2100
Wire Wire Line
	4600 3150 4600 2850
Text Notes 4650 2450 0    60   ~ 0
ceramic cap\n
$Comp
L FS8205A U3
U 1 1 59976E41
P 6150 3500
F 0 "U3" H 6200 3500 60  0000 C CNN
F 1 "FS8205A" H 6200 3350 60  0000 C CNN
F 2 "Housings_SSOP:TSSOP-8_4.4x3mm_Pitch0.65mm" H 7100 3750 60  0001 C CNN
F 3 "" H 7100 3750 60  0001 C CNN
	1    6150 3500
	1    0    0    -1  
$EndComp
NoConn ~ 6350 3100
NoConn ~ 6350 4100
Wire Wire Line
	5950 3100 5950 2900
Wire Wire Line
	5950 2900 6250 2900
Wire Wire Line
	6250 2900 6250 2850
Wire Wire Line
	5950 4100 5700 4100
Wire Wire Line
	5700 4100 5700 2850
Wire Wire Line
	5700 2850 5950 2850
Wire Wire Line
	6050 4100 6250 4100
Wire Wire Line
	6050 3100 6250 3100
Wire Wire Line
	6150 3100 6150 3000
Wire Wire Line
	6150 3000 8050 3000
Connection ~ 6150 3100
Wire Wire Line
	5400 2850 5400 4250
Wire Wire Line
	5400 4250 6150 4250
Wire Wire Line
	6150 4250 6150 4100
Connection ~ 6150 4100
Wire Wire Line
	5800 4250 5800 4400
Connection ~ 5800 4400
Connection ~ 5800 4250
Wire Wire Line
	4900 3150 4900 4400
Connection ~ 4300 3150
Connection ~ 4600 3150
Connection ~ 6750 3000
Wire Wire Line
	6950 2700 6950 3000
Connection ~ 6950 3000
Wire Wire Line
	7900 2800 7900 3000
Connection ~ 7900 3000
Wire Wire Line
	2550 2300 2850 2300
Connection ~ 2550 2200
Text Notes 600  2850 0    60   ~ 0
ceramic cap\n
Text Notes 7200 2550 0    60   ~ 0
ceramic cap\n
$EndSCHEMATC
