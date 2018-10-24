#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <TelegramBot.h>


#define LED 13
// Initialize Wifi connection to the router
const char* ssid     = "Broadcast";
const char* password = "gato12345";


// Initialize Telegram BOT
const char BotToken[] = "581782459:AAGH4KJVMMSSs-aeAUNHMHNNP4zSQ1-Ygm8";

WiFiClientSecure net_ssl;
TelegramBot bot (BotToken, net_ssl);

 // the number of the LED pin  
void setup() 
{  
 Serial.begin(115200);  
 while (!Serial) {}  //Start running when the serial is open 
 delay(3000);  
 // attempt to connect to Wifi network:  
 Serial.print("Connecting Wifi: ");  
 Serial.println(ssid);  
 while (WiFi.begin(ssid, password) != WL_CONNECTED) 
       {  
   Serial.print(".");  
   delay(500);  
 }  
 Serial.println("");  
 Serial.println("WiFi connected");  
 bot.begin();  
 pinMode(LED_BUILTIN, OUTPUT);  
}  
void loop() 
{  
 message m = bot.getUpdates(); // Read new messages  
 if (m.text.equals("on")) 
       {  
   digitalWrite(LED_BUILTIN, 1);   
   bot.sendMessage(m.chat_id, "The Led is now ON");  
 }  
 else if (m.text.equals("off")) 
       {  
   digitalWrite(LED_BUILTIN, 0);   
   bot.sendMessage(m.chat_id, "The Led is now OFF");  
 }  
}  
