// Распределение двигателей
int M1 = 2;                                  // M1 Направление вращения левого мотора
int E1 = 3;                                  // M1 Контроль скорости это тот который ШИМ для левого мотора
int M2 = 4;                                  // M2 Направление вращения правого мотора
int E2 = 5;                                  // M2 Контроль скорости это тот который ШИМ для правого мотора



#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13); // RX, TX

int Led = 13;                                 

uint8_t inByte;  
uint8_t speed=255;                           


void setup() {
 
  Serial.begin(9600);                         
  mySerial.begin(9600);
  int i;
    for(i=2;i<=8;i++)
    pinMode(i, OUTPUT);                       
}

void MoveMotors (int levl_M1,int speed_E1,int levl_M2, int speed_E2) {

    digitalWrite (E1,speed_E1);               
    digitalWrite(M1,levl_M1);
    analogWrite (E2,speed_E2);                 
    digitalWrite(M2,levl_M2);

}

void stop(void)                                          
{ 
  analogWrite(E1,0);
  analogWrite(E2,0);
  digitalWrite(Led, HIGH);              

}

void loop()                                   
  { 

    if(mySerial.available())
    { 
      char inByte = mySerial.read();
   Serial.println(inByte);
  
      if(inByte != -1)
      {
        stop(); 

        switch(inByte)
        {
        case '5':                       
        
        stop();
        break;


        case '1':                             
          
        //advance (speed,speed); MoveMotors(int speed_E1, int speed_E2,int levl_M1, int levl_M2 ){
        MoveMotors(HIGH, speed,HIGH,speed);
        break;
        
        case '2':                      
        
        //MoveMotors(speed,speed,LOW,LOW);   
        MoveMotors(LOW, speed,LOW,speed);     
        break;
        
        case '3':                    
        MoveMotors(HIGH, speed,LOW,0);   
        break;
        
        case '4':                      
        MoveMotors(LOW, 0,HIGH,speed);    
        break;
        
 
        }
      }
     }
    }

