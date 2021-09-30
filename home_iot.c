#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); // gsm module connected here
String textForSMS;
int pirsensor = 2; // pir sensor is connected with pin2 of the arduino
void setup() {
 randomSeed(analogRead(0));
 Serial.begin(9600);
 SIM900.begin(9600); // original 19200. while enter 9600 for sim900A
 Serial.println(" logging time completed!");
pinMode(pirsensor, INPUT);
 delay(5000); // wait for 5 seconds
}
void loop() {
 if ( digitalRead(pirsensor) == HIGH) //
 {
 textForSMS = "\nIntruder detected";
 sendSMS(textForSMS);
 Serial.println(textForSMS);
 Serial.println("message sent.");
delay(8000);
 }
 if ( digitalRead(pirsensor) == LOW) //
 {
 delay(1000);
 }

}
void sendSMS(String message)
{
 SIM900.print("AT+CMGF=1\r"); // AT command to send SMS message
 delay(1000);
 SIM900.println("AT + CMGS = \"+913339218213\""); // recipient's mobile number,
in international format
 delay(1000);
 SIM900.println(message); // message to send
 delay(1000);
 SIM900.println((char)26); // End AT command with a ^Z, ASCII
code 26
 delay(1000);
 SIM900.println();
 delay(100); // give module time to send SMS
}
