#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "pintar-biologi-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "hqJtUlwtYZA0R60qplKz5TRztF4sU8JbHQXhKbrk"
#define WIFI_SSID "Reyhan"
#define WIFI_PASSWORD "skripsi123"

#define baca 5

String statusString;
int id;

void setup() {
  Serial.begin(9600); Serial.swap();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(". ");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected.");

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(baca, INPUT);
  id = Firebase.getInt("lastValue/result");
  delay(10);
  id = Firebase.getInt("lastValue/result");
  delay(10);
}

void loop() {
  int status = digitalRead(baca);
  if(status == 1) {
    statusString = "Daftar";
  } else {
    statusString = "Ujian";
  }
  if(statusString == "Daftar") {
    while(Serial.available()) {
      Serial.read();
    }
    while(Serial.available() == 0) {
      int status = digitalRead(baca);
      if(status == 0) return;
    }
    String rfid = Serial.readString();
    Firebase.setString("lastValue/rfid", rfid);
  } else if(statusString == "Ujian") {
    while(Serial.available()) {
      Serial.read();
    }
    while(Serial.available() == 0) {
      int status = digitalRead(baca);
      if(status == 1) return;
    }
    int nilai = Serial.parseInt();
    Serial.println(nilai);

    while(Serial.available()) {
      Serial.read();
    }
    while(Serial.available() == 0) {}
    int detik = Serial.parseInt();
    Serial.println(detik);

    while(Serial.available()) {
      Serial.read();
    }
    while(Serial.available() == 0) {}
    String rfid = Serial.readString();
    Serial.println(rfid);
    
    Firebase.setInt("studentResult/r" + (String) id + "/number", id);
    Firebase.setInt("studentResult/r" + (String) id + "/number", id); 
    Firebase.setInt("studentResult/r" + (String) id + "/result", nilai*10);
    Firebase.setInt("studentResult/r" + (String) id + "/time", detik);
    Firebase.setString("studentResult/r" + (String) id + "/rfid", rfid);
    Firebase.setInt("lastValue/result", id+1);

    id++;
  }
}