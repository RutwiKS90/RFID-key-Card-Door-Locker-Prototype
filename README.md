
# RFID-key-Card-Door-Locker-Prototype

It is a prototype for new door locking system which involves Radio Frequenct Indentification(RFID) tags/cards instead of keys in traditional locks.
It demonstrates the working of the system and how it can be developed in a affordable manner.


## Components

1. Arduino UNO 
2. RC522 RFID Card Reader Sensor Module
3. Locking System - Servo Motor
4. Arduino USB 2.0 CABLE TYPE A/B
5. Jumper Wire (9 Male to Male)
6. Bread Board

## System Setup

### Hardware 
![RFID Arduino Connection Diagram](https://github.com/RutwiKS90/RFID-key-Card-Door-Locker-Prototype/blob/1667d638c722291d9e8252d728948283a1865415/images/rfid_arduino_connection.jpg)

![RC522 RFID Card Reader Sensor Module](https://github.com/RutwiKS90/RFID-key-Card-Door-Locker-Prototype/blob/1667d638c722291d9e8252d728948283a1865415/images/RC522%20Module.jpg)

![Arduino UNO Board](https://github.com/RutwiKS90/RFID-key-Card-Door-Locker-Prototype/blob/1667d638c722291d9e8252d728948283a1865415/images/Arduino%20Module.jpg)

![Complete Setup](https://github.com/RutwiKS90/RFID-key-Card-Door-Locker-Prototype/blob/1667d638c722291d9e8252d728948283a1865415/images/complete_setup.jpg)
| Arduino Pins  |RFID-RC522  |Servo Motor |Servo Motor |
|---------------|:----------:|-----------:|-----------:|
|5V|-|+ve terminal |739 |
|DG Pin 5|-|-ve terminal |739 |
|GND|GND|-|-|
|3.3V|3.3V|-|-|
|DG Pin 9|RST|-|-|
|DG Pin 10|SDA|-|-|
|DG Pin 13|SCK|-|-|
|DG Pin 11|MOSI|-|-|
|DG Pin 12|MISO|-|-|

*DG Pin - Digital Pin*

### Software 
1. Install Arduino IDE 1.8.19 : https://downloads.arduino.cc/arduino-1.8.19-windows.zip
2. Unzip the folder
3. Open arduino.exe from the unzipped folder
4. Download the Key_Card_Unlocker.ino file from this repo and open it in Arduino IDE from File tab or using `Ctrl+O` shortcut


    
## Deployment

To deploy this project:
1. Connect the Arduino Board with Laptop/PC on which Arduino IDE is running using Arduino USB Cable
2. Now upload the code to Arduino board from the button available at top left in IDE
3. Get Serial ID of your card/tag from serial monitor
4. Now change it in accessGranted variable in code
5. Now again upload the code
6. Now try with the card/tag for which you have entered the servo motor will rotate which indicates door opening after 10secs it will rotate back to its orginal positon indicating door closed
7. For other card/tag it will not rotate

## 👉[Click Here for Video Demonstartion](https://drive.google.com/file/d/11c5twD5oF7B8NoWruL4P4LxhATu4VApe/view?usp=sharing)


## Badges

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)
[![AGPL License](https://img.shields.io/badge/license-AGPL-blue.svg)](http://www.gnu.org/licenses/agpl-3.0)


## License

[MIT](https://choosealicense.com/licenses/mit/)


## Contact Me

Feel free to Contact Me on rutwiksenta90@gmail.com or connect on [LinkedIn](https://www.linkedin.com/in/rutwiks90/)

