int messageLength;
int readLength;
char message[255];

void applyFunction(char a[], int l)
{
  // Array a with a length l
  // Double the value for each element in the array
  for (int i=0; i<l; i++)
  {
    a[i] = a[i]*2;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(500); // Timeout after 500 ms
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    messageLength = Serial.read(); // range from 0 to 255
    readLength = Serial.readBytes(message, messageLength);

    if (messageLength != readLength)
    {
      // Message does not arrived, handle error by sending back one single value 0
      // indicate that the return message has the length of 0
      Serial.write((byte)0);      
    }
    else
    {
      applyFunction(message, messageLength);
      // Send back the message
      Serial.write((byte)messageLength);
      Serial.write(message, messageLength);
      Serial.flush(); // Wait until all bytes are sent
    }
  }

}
