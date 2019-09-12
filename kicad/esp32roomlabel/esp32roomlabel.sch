EESchema Schematic File Version 4
LIBS:esp32roomlabel-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "ESP32 Room label"
Date ""
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Espressif_devkit:ESP32-DEVKITC-32D U1
U 1 1 5CB03136
P 4850 3300
F 0 "U1" H 4850 4467 50  0001 C CNN
F 1 "NODEMCU ESP32" H 4850 4375 50  0000 C CNN
F 2 "ESP32-DEVKIT:MODULE_ESP32-DEVKITC-32D" H 4850 3300 50  0001 L BNN
F 3 "Unavailable" H 4850 3300 50  0001 L BNN
F 4 "Espressif Systems" H 4850 3300 50  0001 L BNN "Feld4"
F 5 "Eval Board For Esp-Wroom-32" H 4850 3300 50  0001 L BNN "Feld5"
F 6 "None" H 4850 3300 50  0001 L BNN "Feld6"
F 7 "None" H 4850 3300 50  0001 L BNN "Feld7"
F 8 "ESP32-DEVKITC-32D" H 4850 3300 50  0001 L BNN "Feld8"
	1    4850 3300
	1    0    0    -1  
$EndComp
Text GLabel 3850 3700 0    50   Input ~ 0
GND
Text GLabel 5800 3000 2    50   Input ~ 0
GND
Text GLabel 3850 2400 0    50   Input ~ 0
3V3
Text GLabel 3850 4200 0    50   Input ~ 0
5V
Wire Wire Line
	3850 2400 4050 2400
Wire Wire Line
	3850 4200 4050 4200
Wire Wire Line
	5650 3000 5800 3000
Text GLabel 5800 3200 2    50   Input ~ 0
CLK
Text GLabel 5800 3100 2    50   Input ~ 0
DTA
Wire Wire Line
	5800 3100 5650 3100
Wire Wire Line
	5800 3200 5650 3200
Text GLabel 5800 2400 2    50   Input ~ 0
GND
Wire Wire Line
	5650 2400 5800 2400
$Comp
L Connector:Conn_01x04_Male J1
U 1 1 5CB03523
P 1550 2450
F 0 "J1" H 1656 2728 50  0000 C CNN
F 1 "BME280" H 1656 2637 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1550 2450 50  0001 C CNN
F 3 "~" H 1550 2450 50  0001 C CNN
	1    1550 2450
	1    0    0    -1  
$EndComp
Text GLabel 2000 2350 2    50   Input ~ 0
3V3
Text GLabel 2000 2450 2    50   Input ~ 0
GND
Text GLabel 2000 2550 2    50   Input ~ 0
CLK
Text GLabel 2000 2650 2    50   Input ~ 0
DTA
Wire Wire Line
	2000 2650 1750 2650
Wire Wire Line
	1750 2550 2000 2550
Wire Wire Line
	2000 2450 1750 2450
Wire Wire Line
	2000 2350 1750 2350
$Comp
L Connector:Conn_01x04_Male J2
U 1 1 5CB03980
P 1550 3150
F 0 "J2" H 1656 3428 50  0000 C CNN
F 1 "OLED" H 1656 3337 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1550 3150 50  0001 C CNN
F 3 "~" H 1550 3150 50  0001 C CNN
	1    1550 3150
	1    0    0    -1  
$EndComp
Text GLabel 2000 3050 2    50   Input ~ 0
3V3
Text GLabel 2000 3150 2    50   Input ~ 0
GND
Text GLabel 2000 3250 2    50   Input ~ 0
CLK
Text GLabel 2000 3350 2    50   Input ~ 0
DTA
Wire Wire Line
	2000 3350 1750 3350
Wire Wire Line
	1750 3250 2000 3250
Wire Wire Line
	2000 3150 1750 3150
Wire Wire Line
	2000 3050 1750 3050
$Comp
L Connector:Conn_01x04_Male J3
U 1 1 5CB03BBE
P 1550 3800
F 0 "J3" H 1656 4078 50  0000 C CNN
F 1 "LCD2004" H 1656 3987 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1550 3800 50  0001 C CNN
F 3 "~" H 1550 3800 50  0001 C CNN
	1    1550 3800
	1    0    0    -1  
$EndComp
Text GLabel 2000 4700 2    50   Input ~ 0
3V3
Text GLabel 2000 3700 2    50   Input ~ 0
GND
Text GLabel 2000 4000 2    50   Input ~ 0
CLK
Text GLabel 2000 3900 2    50   Input ~ 0
DTA
Wire Wire Line
	2000 4000 1750 4000
Wire Wire Line
	1750 3900 2000 3900
Wire Wire Line
	2000 3800 1750 3800
Wire Wire Line
	2000 3700 1750 3700
Text GLabel 2000 3800 2    50   Input ~ 0
5V
Text GLabel 2000 4300 2    50   Input ~ 0
GND
Text GLabel 2000 4500 2    50   Input ~ 0
CLK
Text GLabel 2000 4600 2    50   Input ~ 0
DTA
Wire Wire Line
	2000 4600 1750 4600
Wire Wire Line
	1750 4500 2000 4500
Wire Wire Line
	2000 4300 1750 4300
$Comp
L Connector:Conn_01x03_Male J5
U 1 1 5CB04494
P 1550 5200
F 0 "J5" H 1656 5478 50  0000 C CNN
F 1 "DHT22" H 1656 5387 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 1550 5200 50  0001 C CNN
F 3 "~" H 1550 5200 50  0001 C CNN
	1    1550 5200
	1    0    0    -1  
$EndComp
Text GLabel 2000 5100 2    50   Input ~ 0
3V3
Text GLabel 2000 5200 2    50   Input ~ 0
GND
Text GLabel 2000 5300 2    50   Input ~ 0
DHT22
Text GLabel 5800 2500 2    50   Input ~ 0
DHT22
Wire Wire Line
	5800 2500 5650 2500
Wire Wire Line
	1750 5100 2000 5100
Wire Wire Line
	1750 5200 2000 5200
Wire Wire Line
	1750 5300 2000 5300
$Comp
L Connector:Conn_01x05_Male J4
U 1 1 5CB06628
P 1550 4500
F 0 "J4" H 1656 4878 50  0000 C CNN
F 1 "DS3231" H 1656 4787 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 1550 4500 50  0001 C CNN
F 3 "~" H 1550 4500 50  0001 C CNN
	1    1550 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 4700 2000 4700
$Comp
L Connector:Conn_01x02_Male J6
U 1 1 5CB0E2D3
P 7100 2500
F 0 "J6" H 7206 2678 50  0000 C CNN
F 1 "Switch1" H 7206 2587 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7100 2500 50  0001 C CNN
F 3 "~" H 7100 2500 50  0001 C CNN
	1    7100 2500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J7
U 1 1 5CB0E32B
P 7100 2900
F 0 "J7" H 7206 3078 50  0000 C CNN
F 1 "Switch2" H 7206 2987 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7100 2900 50  0001 C CNN
F 3 "~" H 7100 2900 50  0001 C CNN
	1    7100 2900
	1    0    0    -1  
$EndComp
Text GLabel 7550 2600 2    50   Input ~ 0
GND
Text GLabel 7550 3000 2    50   Input ~ 0
GND
Wire Wire Line
	7300 3000 7550 3000
Wire Wire Line
	7300 2600 7550 2600
Text GLabel 7550 2500 2    50   Input ~ 0
SW1
Text GLabel 7550 2900 2    50   Input ~ 0
SW2
Wire Wire Line
	7550 2900 7300 2900
Wire Wire Line
	7550 2500 7300 2500
Text GLabel 5800 2900 2    50   Input ~ 0
SW1
Text GLabel 5800 2600 2    50   Input ~ 0
SW2
Wire Wire Line
	5650 2600 5800 2600
Wire Wire Line
	5650 2900 5800 2900
$Comp
L Device:R R1
U 1 1 5CB13ACD
P 5900 3800
F 0 "R1" V 5693 3800 50  0000 C CNN
F 1 "330R" V 5784 3800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5830 3800 50  0001 C CNN
F 3 "~" H 5900 3800 50  0001 C CNN
	1    5900 3800
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J9
U 1 1 5CB13B54
P 6750 3800
F 0 "J9" H 6723 3680 50  0000 R CNN
F 1 "LED" H 6723 3771 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6750 3800 50  0001 C CNN
F 3 "~" H 6750 3800 50  0001 C CNN
	1    6750 3800
	-1   0    0    1   
$EndComp
Wire Wire Line
	5650 3800 5750 3800
Text GLabel 6450 3700 0    50   Input ~ 0
GND
Wire Wire Line
	6050 3800 6550 3800
Wire Wire Line
	6450 3700 6550 3700
$Comp
L Connector:Conn_01x04_Male J8
U 1 1 5CB1EC59
P 1550 5750
F 0 "J8" H 1656 6028 50  0000 C CNN
F 1 "I2C" H 1656 5937 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1550 5750 50  0001 C CNN
F 3 "~" H 1550 5750 50  0001 C CNN
	1    1550 5750
	1    0    0    -1  
$EndComp
Text GLabel 2000 5650 2    50   Input ~ 0
3V3
Text GLabel 2000 5750 2    50   Input ~ 0
GND
Text GLabel 2000 5850 2    50   Input ~ 0
CLK
Text GLabel 2000 5950 2    50   Input ~ 0
DTA
Wire Wire Line
	2000 5950 1750 5950
Wire Wire Line
	1750 5850 2000 5850
Wire Wire Line
	2000 5750 1750 5750
Wire Wire Line
	2000 5650 1750 5650
Wire Wire Line
	3850 3700 4050 3700
$Comp
L Connector:Conn_01x04_Male J10
U 1 1 5D7A29E7
P 1550 6400
F 0 "J10" H 1656 6678 50  0000 C CNN
F 1 "Analog" H 1656 6587 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1550 6400 50  0001 C CNN
F 3 "~" H 1550 6400 50  0001 C CNN
	1    1550 6400
	1    0    0    -1  
$EndComp
Text GLabel 2000 6300 2    50   Input ~ 0
3V3
Text GLabel 2000 6400 2    50   Input ~ 0
GND
Text GLabel 2000 6500 2    50   Input ~ 0
5V
Text GLabel 2000 6600 2    50   Input ~ 0
AnalogIn
Wire Wire Line
	2000 6600 1750 6600
Wire Wire Line
	1750 6500 2000 6500
Wire Wire Line
	2000 6400 1750 6400
Wire Wire Line
	2000 6300 1750 6300
Text GLabel 5850 4100 2    50   Input ~ 0
AnalogIn
Wire Wire Line
	5650 4100 5850 4100
Text GLabel 2000 7150 2    50   Input ~ 0
GPIO14
Text GLabel 2000 7250 2    50   Input ~ 0
GPIO15
Text GLabel 2000 7050 2    50   Input ~ 0
GPIO13
Text GLabel 5750 3900 2    50   Input ~ 0
GPIO15
Wire Wire Line
	3850 3500 4050 3500
Wire Wire Line
	3850 3600 4050 3600
Wire Wire Line
	3850 3800 4050 3800
Wire Wire Line
	5650 3900 5750 3900
$Comp
L Connector:Conn_01x06_Male J11
U 1 1 5D7A9346
P 1550 7150
F 0 "J11" H 1656 7528 50  0000 C CNN
F 1 "GPIO" H 1656 7437 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 1550 7150 50  0001 C CNN
F 3 "~" H 1550 7150 50  0001 C CNN
	1    1550 7150
	1    0    0    -1  
$EndComp
Text GLabel 2000 6950 2    50   Input ~ 0
GPIO12
Text GLabel 3850 3600 0    50   Input ~ 0
GPIO12
Text GLabel 3850 3800 0    50   Input ~ 0
GPIO13
Text GLabel 3850 3500 0    50   Input ~ 0
GPIO14
Text GLabel 2000 7350 2    50   Input ~ 0
3V3
Text GLabel 2000 7450 2    50   Input ~ 0
GND
Wire Wire Line
	1750 7450 2000 7450
Wire Wire Line
	1750 7350 2000 7350
Wire Wire Line
	1750 7250 2000 7250
Wire Wire Line
	1750 7150 2000 7150
Wire Wire Line
	1750 7050 2000 7050
Wire Wire Line
	1750 6950 2000 6950
$EndSCHEMATC
