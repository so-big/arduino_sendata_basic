#include <ESP8266WiFi.h> //การประกาศเรียกใช้ Library ESP8266
#include <Arduino.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
//#include <Arduino_JSON.h>
const char* ssid = "WiFi NU";
 //การประกาศสร้างตัวแปรเก็บ Username เครื่อข่าย WiFi ชื่อว่า ssid 
const char* pass = "";
 //การประกาศสร้างตัวแปรเก็บ Password ของเครื่อข่าย WiFi ชื่อว่า pass
String serverName ="http://phpserver/02_server_side.php"; 
void setup () {
  Serial.begin(9600); //
  WiFi.begin(ssid, NULL); //ทำการ Connect SSID และ Pass
while (WiFi.status() != WL_CONNECTED) { // ถ้าไม่สามารถเชื่อมต่อได้
    // ทำการ Print "Connectiong..." ทุก 1000ms
    Serial.println("Connecting...  ");  
    // แสดงสถานะการเชื่อมต่อ
    Serial.printf("Connection Status: %d\n", WiFi.status()); 
    delay(1000);
  }
  // จะหลุดออกจาก while ก็ต่อเมือ Connected เรียบร้อย
  Serial.print("Wi-Fi connected."); 
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());  // ทำการ Print IP ที่ได้รับมาจาก 
}
void loop () { 
  Serial.printf("Connection Status: %d\n", WiFi.status());// แสดงสถานะการเชื่อมต่อ
delay(1000);
  if(WiFi.status()==3){
    WiFiClient client;
    HTTPClient http;
    http.begin(client, serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "test=tPmAT5Ab3j7F9sdsadsdsafasfasgasgasdasgfasgasg";
    int httpResponseCode = http.POST(httpRequestData);
    String payload = "{}"; 
    Serial.printf("sending data camera\n");
      if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
    Serial.println(WiFi.gatewayIP().toString());
    delay(1000);
    Serial.println("read data : "+ payload);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
}
