#include <ESP32AESB64.h>

__AesB64 aesB64;

uint64_t chipid;
char chip_ID [40];
char encryption_key[] = "esp32bse64aes128";



void setup() {
  Serial.begin(115200);
  chipid = ESP.getEfuseMac();
  sprintf(chip_ID, "ESP32 Chipid= %x",chipid);
  String encrypted_str = aesB64.encry_arr2str(chip_ID,encryption_key);
  char* encrypted_arr = aesB64.encry_arr2arr(chip_ID,encryption_key);
  Serial.println(chip_ID);
  Serial.println(encrypted_str);
  Serial.println(encrypted_arr);
  
  }

void loop() {


}
