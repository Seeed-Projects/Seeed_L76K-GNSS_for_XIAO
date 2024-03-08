#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
#include <WiFi.h>
#include <Ubidots.h>

// GPS module connection pins
static const int RXPin = D7, TXPin = D6;
// GPS module baud rate
static const uint32_t GPSBaud = 9600;

// WiFi credentials and Ubidots token
const char WIFI_SSID[] = "INPUT YOUR WIFI NAME HERE";
const char WIFI_PASS[] = "INPUT YOUR WIFI PASSWORD HERE";
const char UBIDOTS_TOKEN[] = "INPUT YOUR UBIDOTS TOKEN HERE";

TinyGPSPlus gps; // GPS parser
SoftwareSerial MySerial(RXPin, TXPin); // For communication with the GPS
Ubidots ubidots(UBIDOTS_TOKEN, UBI_UDP); // Ubidots client, using UDP

void setup() {
  Serial.begin(115200);
  MySerial.begin(GPSBaud);
  ubidots.setDebug(true);  // For observing Ubidots uploading log. You can also change it to "false" for a more simplified serial monitor.
  Serial.println("\nTinyGPSPlus library version: " + String(TinyGPSPlus::libraryVersion()));

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    Serial.println(WiFi.status());
    delay(5000);
  }

  Serial.println("WiFi is connected!");
}

void loop() {
  double lat, lng;
  while (MySerial.available() > 0) {
    if (gps.encode(MySerial.read())) {
      getLocation(&lat, &lng);
      sendToUbidots(lat, lng);
      delay(10 * 1000);  // Change the parameter here to modify the interval of getting and uploading location.
    }
  }

  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println("No GPS detected, please check wiring.");
  }
}

void getLocation(double *lat, double *lng) {
  if (gps.location.isValid()) {
    *lat = gps.location.lat();
    *lng = gps.location.lng();

    Serial.print("Location: ");
    Serial.print(gps.location.lat(), 6);
    Serial.print(", ");
    Serial.print(gps.location.lng(), 6);
    Serial.println();
  } else {
    Serial.println("Unable to get location currently");
  }
}

void sendToUbidots(const double lat, const double lng) {
  // Check if location data is valid
  if (lat != 0 && lng != 0) {
    char charLat[20], charLng[20];
    sprintf(charLat, "%.6lf", lat);
    sprintf(charLng, "%.6lf", lng);

    // Add location context for Ubidots
    ubidots.addContext("lat", charLat);
    ubidots.addContext("lng", charLng);
    
    char* context = (char*)malloc(sizeof(char) * 60);
    ubidots.getContext(context);
    ubidots.add("position", 1, context); // Tagging the data with "position"

    // Send data to Ubidots
    if (ubidots.send()) {
      Serial.println("Values sent to Ubidots successfully.");
    } else {
      Serial.println("Failed to send values to Ubidots.");
    }

    free(context); // Free the allocated memory for context
  }
}
