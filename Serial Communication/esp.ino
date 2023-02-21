#include <SoftwareSerial.h>
SoftwareSerial mySerial(D2, D3); 
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

}
String strs[4];
int StringCount = 0;
  char buff[30]="";
  String str;
void loop() {
 StringCount=0;
  if(mySerial.available()>0){
    mySerial.readBytesUntil('\n',buff,30);
    str=String(buff);
     while (str.length() > 0)
  {
    int index = str.indexOf('|');
    if (index == -1) // No space found
    {
      strs[StringCount++] = str;
      break;
    }
    else
    {
      strs[StringCount++] = str.substring(0, index);
      str = str.substring(index+1);
    }
  }

    for (int i = 0; i < StringCount; i++)
  {
    Serial.print(i);
    Serial.print(": \"");
    Serial.print(strs[i]);
    Serial.println("\"");
  }
  }

delay(50);
}
