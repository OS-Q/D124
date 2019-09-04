#include <QBase64.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (QBase64.encode("Hello Base64, I am qitas.") == QBASE64_STATUS_OK) {
    Serial.println("\nConverted to Base64 : ");
    Serial.println(QBase64.result());
  }

  if (QBase64.decode("SGVsbG8gQmFzZTY0LCBJIGFtIHFpdGFzLg==") == QBASE64_STATUS_OK ) {
    Serial.println("\nConverted from Base64 : ");
    Serial.println(QBase64.result());
  }
  delay(2000);
}
