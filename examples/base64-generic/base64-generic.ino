#include <QBase64.h>

QBase64generic<80000> mybase64;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (mybase64.encode("There is an electric fire in human nature tending to purify - so that among these human creatures there is  continually some birth of new heroism. The pity is that we must wonder at it, as we should at finding a pearl in rubbish.")
      == QBASE64_STATUS_OK) {
    Serial.println("\nConverted to Base64 : ");
    Serial.println(mybase64.result());
  }

  if (mybase64.decode("VGhlcmUgaXMgYW4gZWxlY3RyaWMgZmlyZSBpbiBodW1hbiBuYXR1cmUgdGVuZGluZyB0byBwdXJpZnkgLSBzbyB0aGF0IGFtb25nIHRoZXNlIGh1bWFuIGNyZWF0dXJlcyB0aGVyZSBpcyAgY29udGludWFsbHkgc29tZSBiaXJ0aCBvZiBuZXcgaGVyb2lzbS4gVGhlIHBpdHkgaXMgdGhhdCB3ZSBtdXN0IHdvbmRlciBhdCBpdCwgYXMgd2Ugc2hvdWxkIGF0IGZpbmRpbmcgYSBwZWFybCBpbiBydWJiaXNoLg==")
      == QBASE64_STATUS_OK) {
    Serial.println("\nConverted from Base64 : ");
    Serial.println(mybase64.result());
  }
  delay(2000);
}
