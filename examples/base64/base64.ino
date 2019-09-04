#include <Base64.h>

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(115200);
  while (!Serial); // wait for serial port to connect. Needed for Leonardo only
  Serial.println("");
  
  // encoding
  char input[] = "Hello Base64, I am qitas.";
  int inputLen = sizeof(input);
  
  int encodedLen = base64_enc_len(inputLen);
  char encoded[encodedLen];
  Serial.printf("input len:%d / %d",inputLen,sizeof(input));
  Serial.println("");
  Serial.print(input); Serial.print(" = ");
  
  // note input is consumed in this step: it will be empty afterwards
  base64_encode(encoded, input, inputLen); 
  
  Serial.println(encoded);
  Serial.println("");
  // decoding
  char input2[] = "SGVsbG8gQmFzZTY0LCBJIGFtIHFpdGFzLg==";
  int input2Len = sizeof(input2);
  
  int decodedLen = base64_dec_len(input2, input2Len);
  char decoded[decodedLen];
  
  base64_decode(decoded, input2, input2Len);
  Serial.printf("decoded len:%d",decodedLen);
  Serial.println("");
  Serial.print(input2); Serial.print(" = "); Serial.println(decoded);
}


void loop()
{
  
}
