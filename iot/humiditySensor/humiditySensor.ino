#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <TimeLib.h>

#define LED 2 // Define blinking LED pin 2

const char* ssid = "Nikhil_Jio";      // Replace with your WiFi SSID
const char* password = "nikhil31";    // Replace with your WiFi password
const char* server = "fir-humidity-8c9c7-default-rtdb.firebaseio.com";  // Firebase host
const int httpsPort = 443;  // HTTPS port

WiFiClientSecure client;  // Secure client for HTTPS

unsigned long previousMillis = 0;  // Timer variable
const long interval = 120000;  // 2 minutes (120000 ms)
bool ledState = LOW; // Track LED state

// NTP Time Setup
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000); // GMT+5:30 (19800 seconds offset)

void toggleLED() {
    ledState = !ledState;  // Toggle state
    if(ledState){
      digitalWrite(LED, HIGH);
    }
    else{
      digitalWrite(LED, LOW);
    }
      // Apply new state
    Serial.print("LED is now: ");
    Serial.println(ledState ? "ON" : "OFF");
}

String getCurrentTime() {
    timeClient.update();  // Update time from NTP server
    return timeClient.getFormattedTime(); 
}
String getCurrentDateTime() {
    timeClient.update();
    unsigned long epochTime = timeClient.getEpochTime(); // Get Unix timestamp

    int dayNum = day(epochTime);
    int monthNum = month(epochTime);
    int yearNum = year(epochTime) % 100; // Get last two digits of the year
    int hourNum = hour(epochTime);
    int minuteNum = minute(epochTime);

    // Convert month number to 3-letter abbreviation
    const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    String monthStr = months[monthNum - 1];

    // Convert 24-hour format to 12-hour format with AM/PM
    String period = (hourNum >= 12) ? "PM" : "AM";
    if (hourNum > 12) hourNum -= 12; // Convert to 12-hour format
    if (hourNum == 0) hourNum = 12;  // Midnight case

    // Format DateTime as "DD-MMM-YY HH:MM AM/PM"
    char dateTimeStr[25];
    sprintf(dateTimeStr, "%02d-%s-%02d %02d:%02d %s", dayNum, monthStr.c_str(), yearNum, hourNum, minuteNum, period.c_str());

    return String(dateTimeStr);
}


void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(19200);
    delay(1000);

    // Connect to WiFi
    Serial.print("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi!");

    // Ignore SSL certificate validation (use only for testing)
    client.setInsecure();

    // Initialize NTP client
    timeClient.begin();
    timeClient.update();
}

void loop() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;  // Reset timer
        sendData();  // Call function to send data
        toggleLED();
    }
}



void sendData() {
    Serial.println("Sending data...");
    
    //timeClient.update();  // Update time from NTP server
    String currentDateTime = getCurrentDateTime();// timeClient.getFormattedTime();  // Get current date-time as HH:MM:SS


    if (client.connect(server, httpsPort)) {
        Serial.println("Connected to server!");


        Serial.println("Time "+currentDateTime);

        // JSON Data in the required format
        // String jsonData = R"rawliteral(
        // {
        //     "DateTime": 56,
        //     "Humidity": 20,
        //     "Temperature": 10
        // }
        // )rawliteral";

        String jsonData = "{ \"DateTime\": \"" + currentDateTime + "\", \"Humidity\": 20, \"Temperature\": 10 }";

        // HTTP Request
        client.print(String("POST ") + "/humidityInfo.json HTTP/1.1\r\n" +
                     "Host: " + server + "\r\n" +
                     "Content-Type: application/json\r\n" +
                     "Content-Length: " + jsonData.length() + "\r\n" +
                     "Connection: close\r\n\r\n" +
                     jsonData);

        Serial.println("Data sent!");
    } else {
        Serial.println("Connection failed!");
    }

    client.stop();  // Close connection
}
