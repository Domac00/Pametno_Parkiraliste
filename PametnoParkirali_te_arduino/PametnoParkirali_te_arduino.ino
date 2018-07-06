#include <Adafruit_NeoPixel.h>
#include <NewPing.h>
#include <SoftwareSerial.h>

 int s = 16;
 int v=0;
 int vg=0;
 int vd=0;
 bool g= false;
 bool d=false;
 bool l1 = false;
 bool velika = true;
 unsigned long prevMillis =0;
 unsigned long currMillis;
 unsigned long serialTime=0;
 bool f[8] = {false, false, false,false,false,false,false,false};
unsigned long vala = 100;
unsigned long valg = 100;
unsigned long vald = 100;
int crvenaDole=17;
int crvenaGore=17;
int crvenaVelika=25;
int l1Brojac=0;
int provjera[8]={0,0,0,0,0,0,0,0};
int mjesta=8;
int brzina = 80;
byte byteR;
byte byteG;
byte byteB;
byte byteRN;
byte byteGN;
byte byteBN;
byte brz;
int del=20;
int senzor_provjera=100;


Adafruit_NeoPixel L1 = Adafruit_NeoPixel(2,36,NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel L2 = Adafruit_NeoPixel(2,38,NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel L3 = Adafruit_NeoPixel(2,40,NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel L4 = Adafruit_NeoPixel(2,42,NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel L5 = Adafruit_NeoPixel(2,26,NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel L6 = Adafruit_NeoPixel(2,28,NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel L7 = Adafruit_NeoPixel(2,30,NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel L8 = Adafruit_NeoPixel(2,32,NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel L9 = Adafruit_NeoPixel(17,34,NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel L10 = Adafruit_NeoPixel(17,24,NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel L11 = Adafruit_NeoPixel(25,22,NEO_GRB + NEO_KHZ800);

// promjena 14:37
NewPing senzor[8]{
NewPing(49,39,200),
NewPing(49,37,200),
NewPing(49,43,200),
NewPing(49,41,200),
NewPing(49,33,200),
NewPing(49,35,200),
NewPing(49,45,200),
NewPing(49,47,200)

  /*
  NewPing(49,33,5), 
  NewPing(49,35,5),
  NewPing(49,37,5),
  NewPing(49,39,5),
  NewPing(49,41,5),
  NewPing(49,43,5),
  NewPing(49,45,5),
  NewPing(49,47,5)
  */
};

//int timer[8] = {50,150,250,200,50,50,50,50};
unsigned long timer[9] = {50,150,250,350,400,450,500,550,600};
unsigned long timerVal = 200;

//-----
//SETUP
//-----

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
 
  
pinMode(49,OUTPUT);
pinMode(33,INPUT);
pinMode(35,INPUT);
pinMode(37,INPUT);
pinMode(39,INPUT);
pinMode(41,INPUT);
pinMode(43,INPUT);
pinMode(45,INPUT);
pinMode(47,INPUT);

//pinMode(14,OUTPUT);
//pinMode(15,INPUT);

//led
pinMode(24,OUTPUT);
pinMode(26,OUTPUT);
pinMode(28,OUTPUT);
pinMode(30,OUTPUT);
pinMode(32,OUTPUT);
pinMode(34,OUTPUT);
pinMode(36,OUTPUT);
pinMode(38,OUTPUT);
pinMode(40,OUTPUT);
pinMode(42,OUTPUT);

//pokaznik
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);


//BEGIN
L1.begin();
L2.begin();
L3.begin();
L4.begin();
L5.begin();
L6.begin();
L7.begin();
L8.begin();
L9.begin();
L10.begin();
L11.begin();

//pokaznikProba();
pocetak();


Serial.begin(9600);
//PALI SVE
paliL1(true);
paliL2(true);
paliL3(true);
paliL4(true);
paliL5(true);
paliL6(true);
paliL7(true);
paliL8(true);
paliL9(17);
paliL10(17);
paliL11(25);

L1.show();
L2.show();
L3.show();
L4.show();
L5.show();
L6.show();
L7.show();
L8.show();
L9.show();
L10.show();
L11.show();
v=0;

 byteR=15;
    byteG=15;
    byteB=15;
    byteRN=0;
    byteGN=30;
    byteBN=0;
brz=100;
}

//--------------------------------------------------------------------
//---------------------PAMETNO PARKIRALIŠTE---------------------------
//--------------------------------------------------------------------



void loop() {
  
currMillis = millis();

  //GORNJA GRANA
  //SENZOR 1
  if(S1()){
  mjesta--;
      paliL1(false);
      f[0] = true;
    }else{
      
      paliL1(true);
      f[0] = false;
    }
 

//SENZOR 2
    if(S2()){
      mjesta--;
      paliL2(false);
      f[1] = true;
    }else{
      
      paliL2(true);
       f[1] = false;
    }

    
//SENZOR 3
  if(S3()){
    mjesta--;
      paliL3(false);
      f[2] = true;
    }else{
     
      paliL3(true);
       f[2] = false;
    }
    

//SENZOR 4
if(S4()){
  mjesta--;
  paliL9(13);
  crvenaGore=13;
  paliL4(false);

// s4 i s3
 if(f[2] == true){
  paliL9(10);
  crvenaGore=10;
    if(f[1] == true){
      paliL9(6);
crvenaGore=6;
      if(f[0] == true){
        crvenaGore=0;
        crvenaVelika=12;
        paliL9(0);
        paliL11(12);
      }else{
        crvenaGore=6;
        paliL9(6);
        paliL11(25);
        crvenaVelika=25;
      }
    }else{
      crvenaGore=10;
      paliL9(10);
      paliL11(25);
      crvenaVelika=25;
    }
 }else{
  paliL9(13);
  crvenaGore=13;
  paliL11(25);
  crvenaVelika=25;
 }
  
}else{
  crvenaGore=17;
  paliL9(17);
  paliL4(true);
  paliL11(25);
  crvenaVelika=25;
}



//DONJA GRANA
//S5
if(S5()){
  mjesta--;
  paliL5(false);
  f[4] = true;
}else{
  
  paliL5(true);
  f[4] = false;
}


//S6
if(S6()){
  mjesta--;
  paliL6(false);
  f[5] = true;
}else{
  
  paliL6(true);
  f[5] = false;
}

//S7
if(S7()){
  mjesta--;
  paliL7(false);
  f[6] = true;
}else{
  
  paliL7(true);
  f[6] = false;
}


//S8
if(S8()){
  mjesta--;
  paliL8(false);
  paliL10(13);
  crvenaDole =13;
  //Serial.println("ajmooo");
  if(f[6]==true){
    paliL10(10);
    crvenaDole =10;
    if(f[5]==true){
      paliL10(6);
      crvenaDole =6;
      if(f[4]==true){
        paliL10(0);
        crvenaDole =0;
      }else{
        paliL10(6);
        crvenaDole =6;
      }
    }else{
      paliL10(10);
      crvenaDole =10;
    }
  }else{
    paliL10(13);
    crvenaDole =13;
    //Serial.println("ajmooo");
  }
  
}else{
 
  paliL8(true);
  paliL10(17);
   crvenaDole =17;
}

if(crvenaGore ==0 && crvenaDole==0){
  paliL11(0);
  crvenaVelika=0;
}

//SendSerial(mjesta);
pokaznik(mjesta);
  mjesta=8;
val();
//if(currMillis - prevMillis >=100){
 // prevMillis = currMillis;
  L1.show();
L2.show();
L3.show();
L4.show();
L5.show();
L6.show();
L7.show();
L8.show();
L9.show();
L10.show();
L11.show();
//}



}

//-------------------------------------------------------------------
//---------------------------------------------------------------------


//----------------
//PALJENJE LEDICA
//----------------

void paliL1(bool b){
  if(b){
     for(int i=0; i<2; i++){
     
      L1.setPixelColor(i,L1.Color(byteR,byteG,byteB));
    
  }
  }else{
      for(int i=0; i<2; i++){
    L1.setPixelColor(i,L1.Color(s,0,0));
  }
  }
}

//L2
void paliL2(bool b){
  if(b){
     for(int i=0; i<2; i++){
    L2.setPixelColor(i,L2.Color(byteR,byteG,byteB));
  }
  }else{
      for(int i=0; i<2; i++){
    L2.setPixelColor(i,L2.Color(s,0,0));
  }
  }
}

//L3
void paliL3(bool b){
  if(b){
     for(int i=0; i<2; i++){
    L3.setPixelColor(i,L3.Color(byteR,byteG,byteB));
  }
  }else{
      for(int i=0; i<2; i++){
    L3.setPixelColor(i,L3.Color(s,0,0));
  }
  }
}

//L4
void paliL4(bool b){
  if(b){
     for(int i=0; i<2; i++){
    L4.setPixelColor(i,L4.Color(byteR,byteG,byteB));
  }
  }else{
      for(int i=0; i<2; i++){
    L4.setPixelColor(i,L4.Color(s,0,0));
  }
  }
}

//L5
void paliL5(bool b){
  if(b){
     for(int i=0; i<2; i++){
    L5.setPixelColor(i,L5.Color(byteR,byteG,byteB));
  }
  }else{
      for(int i=0; i<2; i++){
    L5.setPixelColor(i,L5.Color(s,0,0));
  }
  }
}

//L6
void paliL6(bool b){
  if(b){
     for(int i=0; i<2; i++){
    L6.setPixelColor(i,L6.Color(byteR,byteG,byteB));
  }
  }else{
      for(int i=0; i<2; i++){
    L6.setPixelColor(i,L6.Color(s,0,0));
  }
  }
}

//L7
void paliL7(bool b){
  if(b){
     for(int i=0; i<2; i++){
    L7.setPixelColor(i,L7.Color(byteR,byteG,byteB));
  }
  }else{
      for(int i=0; i<2; i++){
    L7.setPixelColor(i,L7.Color(s,0,0));
  }
  }
}

//L8
void paliL8(bool b){
  if(b){
     for(int i=0; i<2; i++){
    L8.setPixelColor(i,L8.Color(byteR,byteG,byteB));
  }
  }else{
      for(int i=0; i<2; i++){
    L8.setPixelColor(i,L8.Color(s,0,0));
  }
  }
}

//L9
void paliL9(int n){
  for(int i=0; i<n+1; i++){
    if(i != vg && i != vg-1 && i!= vg-2){
      L9.setPixelColor(i-1,L9.Color(byteR,byteG,byteB));
    }
  }
  for(int i=n; i<17; i++){
    L9.setPixelColor(i,L9.Color(s,0,0));
  }

}

//L10
void paliL10(int n){
  //Serial.println(n);
  for(int i=0; i<n+1; i++){
    if(i != vd && i != vd-1 && i!= vd-2){
      L10.setPixelColor(i-1,L10.Color(byteR,byteG,byteB));
    }
    
 
  }
  for(int i=n; i<17; i++){
    L10.setPixelColor(i,L10.Color(s,0,0));
  }

}

//L11
void paliL11(int n){
  
  for(int i=0; i<n; i++){
    if(i != v && i != v-1 && i!= v-2){
      L11.setPixelColor(i,L11.Color(byteR,byteG,byteB));
    }
    
 
    
  }
  for(int i=n; i<25; i++){
    L11.setPixelColor(i,L11.Color(16,0,0));
  }


}
//------------------------
//SENZORI 
//------------------------
bool S1(){
  //currMillis = millis();
 if(currMillis - timer[0] >= del){
  //Serial.println("senzor 1");
   timer[0] = currMillis;
      if(senzor[0].ping_cm() > 0){

         //  Serial.println(provjera[0]);
          provjera[0] =0;
         
          return true;
         
        
        //return true;
      }else{
        //---
        //delay(10);
        if(!senzor[0].ping_cm() >0){
         provjera[0]++;

         if(provjera[0] == senzor_provjera){
           //Serial.println(provjera[0]);
          provjera[0] =0;
         
          return false;
         }
          
        }
        
      }
  }
}


bool S2(){
  //currMillis = millis();
  if(currMillis - timer[1] >= del){
    timer[1] = currMillis;
    //Serial.println("Udaljenost ");
   // Serial.println(senzor[1].ping_cm());
      if(senzor[1].ping_cm() > 0){
     provjera[1]=0;
          return true;
        
        
      }else{
         //delay(10);
        if(!senzor[1].ping_cm() >0){
          provjera[1]++;
          if(provjera[1]==senzor_provjera){
            provjera[1]=0;
            return false;
          }
         // return false;
        }
      }
  }
}


bool S3(){
  //currMillis = millis();
  if(currMillis - timer[2] >= del){
    timer[2] = currMillis;
      if(senzor[2].ping_cm() > 0){
        provjera[2]=0;
        return true;
      }else{
       //  delay(10);
        if(!senzor[2].ping_cm() >0){
          provjera[2]++;
          if(provjera[2]==senzor_provjera){
            provjera[2]=0;
             return false;
          }
         
        }
      }
  }
}


bool S4(){
  //currMillis = millis();
  if(currMillis - timer[3] >= del){
    timer[3] = currMillis;
      if(senzor[3].ping_cm() > 0){
        provjera[3]=0;
        return true;
      }else{
       //  delay(10);
        if(!senzor[3].ping_cm() >0){
            provjera[3]++;
          if(provjera[3]==senzor_provjera){
            provjera[3]=0;
             return false;
          }
        }
      }
  }
}


bool S5(){
  //currMillis = millis();
  if(currMillis - timer[4] >= del){
    timer[4] = currMillis;
      if(senzor[4].ping_cm() > 0){
        provjera[4]=0;
        return true;
      }else{
       //  delay(10);
        if(!senzor[4].ping_cm() >0){
            provjera[4]++;
          if(provjera[4]==senzor_provjera){
            provjera[4]=0;
             return false;
          }
        }
      }
  }
}


bool S6(){
   Serial.println(senzor[5].ping_cm());
  //currMillis = millis();
  if(currMillis - timer[5] >= del){
    timer[5] = currMillis;
      if(senzor[5].ping_cm() > 0){
        provjera[5]=0;
        return true;
      }else{
       // delay(10);
        if(!senzor[5].ping_cm() >0){
            provjera[5]++;
          if(provjera[5]==senzor_provjera){
            provjera[5]=0;
             return false;
          }
        }
      }
  }
}


bool S7(){
  //currMillis = millis();
  if(currMillis - timer[6] >= del){
    timer[6] = currMillis;
      if(senzor[6].ping_cm() > 0){
        provjera[6]=0;
        return true;
      }else{
         //delay(10);
        if(!senzor[6].ping_cm() >0){
            provjera[6]++;
          if(provjera[6]==senzor_provjera){
            provjera[6]=0;
             return false;
          }
        }
      }
  }
}


bool S8(){
  //currMillis = millis();
  if(currMillis - timer[7] >= del){
    timer[7] = currMillis;
      if(senzor[7].ping_cm() > 0){
        provjera[7]=0;
        return true;
      }else{
       // delay(10);
        if(!senzor[7].ping_cm() >0){
            provjera[7]++;
          if(provjera[7]==senzor_provjera){
            provjera[7]=0;
             return false;
          }
        }
        
        }
      }
  }


void val(){
 
   if(currMillis - vald >brz){
      vala = currMillis;
      
     //velika----------------------------------------
    
    if(!g){
      
      v++;
      if(v<crvenaVelika){
        L11.setPixelColor(v,L11.Color(byteRN,byteGN,byteBN));
       L11.setPixelColor(v-1,L11.Color(byteRN,byteGN,byteBN));
       L11.setPixelColor(v-2,L11.Color(byteRN,byteGN,byteBN));
      }
       
       
    }
    if(v>12){

      d=true;
    }
    if(v > 25){
      v =0;
      g=true;
    }

    //--------------------------donja
    vald = currMillis;
     
    if(d){
      
      vd++;
      if(vd < crvenaDole+1){
         L10.setPixelColor(vd,L10.Color(byteRN,byteGN,byteBN));
       L10.setPixelColor(vd-1,L10.Color(byteRN,byteGN,byteBN));
       L10.setPixelColor(vd-2,L10.Color(byteRN,byteGN,byteBN));
      }
      
       
    }
    if(vd>17){
      vd=0;
      d=false;
    }

    //-------------------------------gornja
    if(g){
      vg++;
      if(vg<crvenaGore+1){
          L9.setPixelColor(vg,L9.Color(byteRN,byteGN,byteBN));
       L9.setPixelColor(vg-1,L9.Color(byteRN,byteGN,byteBN));
       L9.setPixelColor(vg-2,L9.Color(byteRN,byteGN,byteBN));
      }
     
       if(vg>17){
        vg=0;
        g=false;
       }
       if(vg ==6){
        l1 = true;
       }


      
    }

   }




}

void pocetak(){
  for(int i=0 ; i<25; i++){
    L11.setPixelColor(i,L11.Color(13,13,13));
  }
   for(int i=0 ; i<17; i++){
    L10.setPixelColor(i,L10.Color(13,13,13));
  }
   for(int i=0 ; i<17; i++){
    L9.setPixelColor(i,L9.Color(13,13,13));
  }

  //---
   for(int i=0 ; i<3; i++){
    L1.setPixelColor(i,L1.Color(13,13,13));
    L2.setPixelColor(i,L2.Color(13,13,13));
    L3.setPixelColor(i,L3.Color(13,13,13));
    L4.setPixelColor(i,L4.Color(13,13,13));
    L5.setPixelColor(i,L5.Color(13,13,13));
    L6.setPixelColor(i,L6.Color(13,13,13));
    L7.setPixelColor(i,L7.Color(13,13,13));
    L8.setPixelColor(i,L8.Color(13,13,13));
  }



   L1.show();
L2.show();
L3.show();
L4.show();
L5.show();
L6.show();
L7.show();
L8.show();
L9.show();
L10.show();
L11.show();
  delay(5000);
}


//---------------------
//----  POKAZNIK ------
//----------------------

void pokaznik(int n){

  switch(n){
    case 1:
      digitalWrite(13,HIGH);
      digitalWrite(7,HIGH);

      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      
      break;

    case 2:
    digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);

    digitalWrite(7,LOW);
      digitalWrite(11,LOW);
      
  break;

  case 3:
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(6,HIGH);

  digitalWrite(5,LOW);
  digitalWrite(11,LOW);
  break;

  case 4:
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(13,HIGH);

  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(12,LOW);
  break;

  case 5:
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);

  digitalWrite(5,LOW);
  digitalWrite(13,LOW);
  break;

  case 6:
    digitalWrite(11,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(7,HIGH);

  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  break;

  case 7:
    digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
digitalWrite(7,HIGH);

  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  break;

  case 8:
    digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
 digitalWrite(13,HIGH);
 break;

  case 0:
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(13,HIGH);

  digitalWrite(10,LOW);
  break;
  
  }
  

}


int provjeriMjesta(){
  if(currMillis - timer[9] >200){
    timer[9] = currMillis;
     mjesta=0;
  if(S1()){
    mjesta++;
  }
  if(S2()){
    mjesta++;
  }
  if(S3()){
    mjesta++;
  }
  if(S4()){
    mjesta++;
  }
  if(S5()){
    mjesta++;
  }
  if(S6()){
    mjesta++;
  }
  if(S7()){
    mjesta++;
  }
  return mjesta;
  }
 
}


void serialEvent(){

  //za usb
   while(Serial.available()>0){
    //boja pozadine
    byteR=Serial.read();
    delay(10);
    byteG=Serial.read();
    delay(10);
    byteB=Serial.read();
    delay(10);

   //boja nav
    byteRN=Serial.read();
    delay(10);
    byteGN=Serial.read();
    delay(10);
    byteBN=Serial.read();
    delay(10);

    //brzina
    brz=Serial.read();

    if(byteR==255 && byteG==255 && byteB==255 && byteRN==255 && byteGN==255){
      byteR=15;
      byteG=15;
      byteB=15;
      byteRN=0;
      byteGN=30;
      byteBN=100;
    }
  }

  // za bluetooth
  while(Serial1.available()>0){
    //boja pozadine
    byteR=Serial1.read();
    delay(10);
    byteG=Serial1.read();
    delay(10);
    byteB=Serial1.read();
    delay(10);

   //boja nav
    byteRN=Serial1.read();
    delay(10);
    byteGN=Serial1.read();
    delay(10);
    byteBN=Serial1.read();
    delay(10);

    //brzina
    brz=Serial1.read();

    if(byteR==255 && byteG==255 && byteB==255 && byteRN==255 && byteGN==255){
      byteR=15;
      byteG=15;
      byteB=15;
      byteRN=0;
      byteGN=30;
      byteBN=100;
    }
  }
}
/*
void SendSerial(int sm){
  if(currMillis-serialTime >=100){
    serialTime=currMillis;
    if(Serial.available()){
      
Serial.write(sm);
  }
  }
  
}
*/
