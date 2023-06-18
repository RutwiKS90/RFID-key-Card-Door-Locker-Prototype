#include <MFRC522.h>  // MFRC522 RFID module library.
#include <SPI.h>      // SPI device communication library.
#include <EEPROM.h>   // EEPROM (memory) library.


#define pinRST 9      // Defines pins for RST, SS conncetions respectively.
#define pinSS 10

byte readCard[4];     // Array that will hold UID of the RFID card.
int successRead;

String accessGranted [1] = {"69a6ee3"};  //RFID serial numbers to grant access to(Change with your tag/card serial value)
int accessGrantedSize = 1;  //The number of serial numbers


boolean locked = true;
int motorpin=5;
MFRC522 mfrc522(pinSS, pinRST);   // Creates MFRC522 instance.
MFRC522::MIFARE_Key key;          // Creates MIFARE key instance.

void setup()
{
  Serial.begin(9600); // Starts the serial connection at 9600 baud rate.
  SPI.begin();        // Initiates SPI connection between RFID module and Arduino.
  mfrc522.PCD_Init(); // Initiates MFRC522 RFID module.

  Serial.println("RFID reading process initiated.");    // Prints user commands.
  Serial.println("Please scan your RFID card to the reader.");

  do {
    successRead = getID();     // Loops getID library function until reading process is done.
  }

  while (!successRead);
  for ( int i = 0; i < mfrc522.uid.size; i++ )  // You can add multiple cards to read in the for loop.
  {
    EEPROM.write(i, readCard[i] );     // Saves RFID cards UID to EEPROM.
  }

  Serial.println("RFID card information is saved to memory.");
  Serial.println("Place card/tag near reader...");
}

void loop()
{
getID(); 
}


int getID() // Function that will read and print the RFID cards UID.
{
  if ( ! mfrc522.PICC_IsNewCardPresent())  // If statement that looks for new cards.
  {
    return 1;
  }

  if ( ! mfrc522.PICC_ReadCardSerial())    // If statement that selects one of the cards.
  {
    return 2;
  }
  
  Serial.print("UID: ");  
  String check="";  
  for (int i = 0; i < mfrc522.uid.size; i++) {  
    readCard[i] = mfrc522.uid.uidByte[i];   // Reads RFID cards UID.
    check=check + String(readCard[i], HEX);
  }
  checkAccess(check);
  
  
  mfrc522.PICC_HaltA();     // Stops the reading process.
}

void checkAccess (String temp)    //Function to check if an identified tag is registered to allow access
{
  boolean granted = false;
  for (int i=0; i <= (accessGrantedSize-1); i++)    //Runs through all tag ID numbers registered in the array
  {
    Serial.println(temp);
    if(accessGranted[i] == temp)            //If a tag is found then open/close the lock
    {
      Serial.println ("Access Granted");
      granted = true;
      if (locked == true)         //If the lock is closed then open it
      {
          analogWrite(motorpin,LOW);
          delay(10000);
          digitalWrite(motorpin,HIGH);
          locked = false;
      }
      else if (locked == false)   //If the lock is open then close it
      {
          analogWrite(motorpin,LOW);
          delay(10000);
          digitalWrite(motorpin,HIGH);
          locked = true;
      }
    }
  }
  if (granted == false)     //If the tag is not found
  {
    Serial.println ("Access Denied");
    digitalWrite(motorpin,HIGH);
  }
}
