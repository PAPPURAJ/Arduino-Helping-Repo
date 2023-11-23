bool low,high,filling;

//int l=D6,h=D5,pump=D8;
int l=D1,h=D2,pump=D7;

void setup() {
    
  pinMode(l,INPUT);
  pinMode(h,INPUT);
  pinMode(pump,OUTPUT);
}

void loop() {
    low=!digitalRead(l);
    high=!digitalRead(h);


    
    if(low==LOW){
      digitalWrite(pump,1);
      filling=1;
    }
    else if(filling && !high)
      digitalWrite(pump,1);
    
    else if(low && filling && high){
      filling=0;
      digitalWrite(pump,0);
    }
    

  
}
