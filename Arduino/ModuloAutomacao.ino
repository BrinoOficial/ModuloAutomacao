#include <IRLib.h>

#define MY_PROTOCOL NECX
#define menos 0xE0E0C43B
#define rele 13

IRrecv My_Receiver(2);
IRdecode My_Decoder; 

void setup(){ 
  My_Receiver.No_Output();
  My_Receiver.enableIRIn(); // Start the receiver
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);
} 
 
void loop(){ 
    if(My_Receiver.GetResults(&My_Decoder)){
       My_Decoder.decode();
       if(My_Decoder.decode_type==MY_PROTOCOL){
          if(My_Decoder.value==menos)
            digitalWrite(rele, !(digitalRead(rele)));
          delay(200);
       }
       My_Receiver.resume();
    }
}
