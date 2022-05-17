int buttonValue1 = 0; // si on a appuyé sur les boutons
int buttonValue2 = 0;
int button1 = 10; //entrée
int button2 = 11; //sorities

int greenLed1 = 12; //entrée 
int greenLed2 = 13; //entrée
int greenLedValue1 = 0; //si la LED vert est allumé ou non 
int greenLedValue2 = 0;

int ledsArr[5] = {4,5,6,7,8}; // la liste des led utilisée (sorties)
int delayValue; // la vitesse des leds
int buttonPressedDelay = 2000;
int speedAdded = 20; // le valeur ajoutée a cette vitesse

bool gameIsStarted = false; 


void setup() {
  pinMode(button1, INPUT); //initialiser les boutons comme des entrées
  pinMode(button2, INPUT);
  pinMode(greenLed1, INPUT);// initialiser les leds verts comme des entées
  pinMode(greenLed2, INPUT);
  
  for(int i = 0; i <= 4; i++){
    pinMode(ledsArr[i], OUTPUT); //initialiser les leds comme des sorites
  }
}

void loop() {
  buttonValue1 = digitalRead(button1);
  buttonValue2 = digitalRead(button2);
  delayValue = 250;
  
  if(buttonValue1 && buttonValue2){ //si on a appuyé sur les deux bouttons en même temps le jeu commence
    gameIsStarted = true;
  }
  
  while(gameIsStarted){
     for(int i = 0; i <= 4; i++){ // le cycle des leds
      
      buttonValue1 = digitalRead(button1);
      buttonValue2 = digitalRead(button2);
      
      digitalWrite(ledsArr[i], HIGH); //allumer le premier led
      delay(delayValue); // attendre 250 ms
      
      if(buttonValue1 != 0 || buttonValue2 != 0){  //si on appui sur l'un des boutton on attends 2s
          delay(buttonPressedDelay);
          greenLedValue1 = digitalRead(greenLed1);
          greenLedValue2 = digitalRead(greenLed2);
          
          if(greenLedValue1 == HIGH || greenLedValue2 == HIGH){ 
            delayValue -= speedAdded; // et si on est dans l'un des deux leds verts la vitesse des leds augmente 
          }
      }
      digitalWrite(ledsArr[i], LOW); //éteindre la led
      //puis répéter le même cycle pour le deuxième led
    }
    
    for(int j = 3; j >= 1; j--){

      //la même mais seulement la direction des leds qui change 
      buttonValue2 = digitalRead(button2);
      buttonValue1 = digitalRead(button1);
      
      digitalWrite(ledsArr[j], HIGH);
      delay(delayValue);
      
      if(buttonValue1 != 0 || buttonValue2 != 0){
          delay(buttonPressedDelay);
          greenLedValue1 = digitalRead(greenLed1);
          greenLedValue2 = digitalRead(greenLed2);
          
          if((greenLedValue1 == HIGH || greenLedValue2 == HIGH) && (delayValue >= 50)){
            delayValue -= speedAdded;
          }
      }
      digitalWrite(ledsArr[j], LOW);
      
    }
  }
}
