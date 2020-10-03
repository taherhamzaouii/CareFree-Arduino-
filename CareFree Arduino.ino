
#include <eHealth.h> 
#include <PinChangeInt.h>

int cont = 0;




//Firebase
#define FIREBASE_HOST "carefree-a2fc0.firebaseio.com" ;
#define FIREBASE_AUTH "wlI4Hvoo00I1Vo3Y1BcTtETGZkfaExPLmzNZ2un3";



//  Firebase.begin(FIREBASE_HOST , FIREBASE_AUTH);
//delay(1000);
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(115200);  
  eHealth.initPulsioximeter();
  PCintPort::attachInterrupt(6, readPulsioximeter, RISING);


}

// the loop routine runs over and over again forever:
void loop() {

  float conductance = eHealth.getSkinConductance();
  
  float resistance = eHealth.getSkinResistance();
  float conductanceVol = eHealth.getSkinConductanceVoltage();
  float bpm = eHealth.getBPM();
  float oxy = eHealth.getOxygenSaturation();
  //float resis =(resistance, 4) ;
  Serial.print((String)(conductance)+","+(resistance)+","+(conductanceVol)+","+bpm+","+oxy+"\n");  

//Firebase DB


    //Serial.print((String)(conductance)); 
  //Serial.print("Conductance : ");       
 // Serial.print(conductance, 2);  
  //Serial.println(",");         

  //Serial.print("Resistance : ");       
  //Serial.print(resistance, 2);  
  //Serial.println(",");    

  //Serial.print("Conductance Voltage : ");       
  //Serial.print(conductanceVol, 4);  
  //Serial.println(",");

  //Serial.print("\n");

  //Serial.print("PRbpm : "); 
  //Serial.print(bpm);  
    //Serial.println(",");


  //Serial.print("    %SPo2 : ");
 // Serial.print(oxy);  

  //Serial.print("\n");  
  //Serial.println("============================="); 

  // wait for a second  
  delay(10000);            
}

void readPulsioximeter(){  

  cont ++;

  if (cont == 50) { //Get only of one 50 measures to reduce the latency
    eHealth.readPulsioximeter();  
    cont = 0;
  }
}
