int pins[] = {8, 9, 10, 11, 12, 13};
int s[] = {0,0,0,0,0};
int d[5][24] ={{1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,0,1,0},
               {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1},
               {1,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1},
               {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0},
               {1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0}
};
int l[24][5];

volatile unsigned long t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
volatile float rpm = t3, linet = rpm/90; 
volatile int timerA = 0, timerB = 0;  

void setup() {
  for (int x = 0; x < 24; x++){
  for (int y = 0; y < 5; y++)
    l[x][y] = d[y][x];
}

  for(int i = 0; i <= 5; i++)
  {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }

  attachInterrupt(digitalPinToInterrupt(2), isr, CHANGE);
  
  //Serial.begin(115200);
  
}
void isr(){
  if (digitalRead(2) == HIGH) {
    //Serial.print("Stamp(ms): ");
    
    t1 = t2;
    t2 = millis() ;
    t3 = t2 - t1;
    
    //Serial.println(t3);
    //Serial.println(t3/36);
    
    digitalWrite(pins[0],LOW);
    
    rpm = t3; linet = rpm/90; 
    timerA = millis();
    
  }
  else
    digitalWrite(pins[0],HIGH);
}

void gohighlow(int a[]){
    digitalWrite(pins[5], a[0]);    
    digitalWrite(pins[4], a[1]);    
    digitalWrite(pins[3], a[2]);    
    digitalWrite(pins[2], a[3]);    
    digitalWrite(pins[1], a[4]);    
}

void loop() {
  rpm = t3, linet = rpm/90;   

  int t = millis() - timerA;

  
  if (t > (linet * 9) && t < (linet * 10)){
    gohighlow(l[23]);  
  }
  else if (t > (linet * 11) && t < (linet * 12)){
    gohighlow(l[22]);  
  }
  else if (t > (linet * 12) && t < (linet * 13)){
    gohighlow(l[21]);  
  }
  else if (t > (linet * 13) && t < (linet * 14)){
    gohighlow(l[20]);  
  }
  else if (t > (linet * 14) && t < (linet * 15)){
    gohighlow(l[19]);  
  }
  else if (t > (linet * 15) && t < (linet * 16)){
    gohighlow(l[18]);  
  }
  else if (t > (linet * 16) && t < (linet * 17)){
    gohighlow(l[17]);  
  }
  else if (t > (linet * 17) && t < (linet * 18)){
    gohighlow(l[16]);  
  }
  else if (t > (linet * 18) && t < (linet * 19)){
    gohighlow(l[15]);  
  }
  else if (t > (linet * 19) && t < (linet * 20)){
    gohighlow(l[14]);  
  }
  else if (t > (linet * 20) && t < (linet * 21)){
    gohighlow(l[13]);  
  }
  else if (t > (linet * 21) && t < (linet * 22)){
    gohighlow(l[12]);  
  }
  else if (t > (linet * 22) && t < (linet * 23)){
    gohighlow(l[11]);  
  }
  else if (t > (linet * 23) && t < (linet * 24)){
    gohighlow(l[10]);  
  }
  else if (t > (linet * 24) && t < (linet * 25)){
    gohighlow(l[9]);  
  }
  else if (t > (linet * 25) && t < (linet * 26)){
    gohighlow(l[8]);  
  }
  else if (t > (linet * 26) && t < (linet * 27)){
    gohighlow(l[7]);  
  }
  else if (t > (linet * 27) && t < (linet * 28)){
    gohighlow(l[6]);  
  }
  else if (t > (linet * 28) && t < (linet * 29)){
    gohighlow(l[5]);  
  }
  else if (t > (linet * 29) && t < (linet * 30)){
    gohighlow(l[4]);  
  }
  else if (t > (linet * 30) && t < (linet * 31)){
    gohighlow(l[3]);  
  }
  else if (t > (linet * 31) && t < (linet * 32)){
    gohighlow(l[2]);  
  }
  else if (t > (linet * 32) && t < (linet * 33)){
    gohighlow(l[1]);  
  }
  else if (t > (linet * 33) && t < (linet * 34)){
    gohighlow(l[0]);  
  }
  else
    gohighlow(s);      
  

}

