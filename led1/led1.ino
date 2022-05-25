int buttonValue1 = 0; // si on a appuyé sur les boutons
int buttonValue2 = 0;
int button1 = 10; //entrée
int button2 = 11; //entrée

int ledsPointsArr[8] = {22, 24, 38, 28, 30, 32, 34, 36}; //list des leds jaunes pour calculer les points


int ledsArr[9] = {2, 3, 4 ,5, 6, 7, 8, 9, 40}; // la liste des led utilisée (sorties)
int delayValue; // la vitesse des leds
int buttonPressedDelay = 2000;
int speedAdded = 10; // le valeur ajoutée a cette vitesse

bool gameIsStarted = false; 

int player1points;
int player2points;

void(* resetFunc) (void) = 0;

void setup() {
  pinMode(button1, INPUT); //initialiser les boutons comme des entrées
  pinMode(button2, INPUT);

  for(int i = 0; i <= 8; i++){
    pinMode(ledsArr[i], OUTPUT); //initialiser les leds comme des sorites
  }
  for(int x = 0; x <= 7; x++){
    pinMode(ledsPointsArr[x], OUTPUT); //initialiser les leds "jaunes" comme des sorites
  }
  
}

void loop() {
  buttonValue1 = digitalRead(button1);
  buttonValue2 = digitalRead(button2);
  delayValue = 100;
  player1points = 0;
  player2points = 0;
  
  if(buttonValue1 && buttonValue2){ //si on a appuyé sur les deux bouttons en même temps le jeu commence
    openAllLeds();
    delay(500);
    closeAllLeds();
    delay(150);
    gameIsStarted = true;
  }
  
  while(gameIsStarted == true){
    int i;
     for(i = 0; i <= 8; i++){ // le cycle des leds
        
        buttonValue1 = digitalRead(button1);
        buttonValue2 = digitalRead(button2);       

        digitalWrite(ledsArr[i], HIGH); //allumer le premier led
        delay(delayValue); // attendre 100 ms

        if((buttonValue1 == HIGH || buttonValue2 == HIGH) && (i != 0 && i != 8)){
            delay(buttonPressedDelay);
        }

        else if(buttonValue1 == HIGH && i == 0){  //si on appui sur l'un des boutton on attends 2s
            delayValue -= speedAdded; // et si on est dans l'un des deux leds verts la vitesse des leds augmente 
            player1points += 1;// le joueur gagne un point
            openYellowLedsPlayer1(player1points);
            delay(buttonPressedDelay);
        }
            
        else if(buttonValue2 == HIGH && i == 8){
            delayValue -= speedAdded;
            player2points += 1;
            openYellowLedsPlayer2(player2points);
            delay(buttonPressedDelay);
        } 
      digitalWrite(ledsArr[i], LOW);
      
      //puis répéter le même cycle pour le deuxième led     
    }
  
    
    for(int j = 7; j >= 1; j--){

      //la même mais seulement la direction des leds qui change 
      buttonValue2 = digitalRead(button2);
      buttonValue1 = digitalRead(button1);
      
      digitalWrite(ledsArr[j], HIGH);
      delay(delayValue);
      
      if((buttonValue1 == HIGH || buttonValue2 == HIGH) && (i != 0 && i != 8)){
            delay(buttonPressedDelay);
        }

      digitalWrite(ledsArr[j], LOW);
      
    }
  }
  resetFunc();//
}

void openYellowLedsPlayer2(int numberOfPoints){
  if(numberOfPoints == 0){
    return;
  }
  else if(numberOfPoints == 1){
    digitalWrite(22, HIGH);
  }
  else if(numberOfPoints == 2){
    digitalWrite(24, HIGH);
  }
  else if(numberOfPoints == 3){
    digitalWrite(38, HIGH);
  }
  else if(numberOfPoints == 4){
    digitalWrite(28, HIGH);
    EndTheGame();
  }

}

void openYellowLedsPlayer1(int numberOfPoints){
  if(numberOfPoints == 0){
    return;
  }
  else if(numberOfPoints == 1){
    digitalWrite(30, HIGH);
  }
  else if(numberOfPoints == 2){
    digitalWrite(32, HIGH);
  }
  else if(numberOfPoints == 3){
    digitalWrite(34, HIGH);
  }
  else if(numberOfPoints == 4){
    digitalWrite(36, HIGH);
    EndTheGame();
  }  
  
}

void EndTheGame(){
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(40, HIGH);
  delay(100);
  gameIsStarted = false;
  closeALLYellowLeds();
  closeAllLeds();
}

void openAllLeds(){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(40, HIGH);
}

void closeAllLeds(){
  delay(250);
  digitalWrite(2, LOW);
  delay(250);
  digitalWrite(3, LOW);
  delay(250);
  digitalWrite(4, LOW);
  delay(250);
  digitalWrite(5, LOW);
  delay(250);
  digitalWrite(6, LOW);
  delay(250);
  digitalWrite(7, LOW);
  delay(250);
  digitalWrite(8, LOW);
  delay(250);
  digitalWrite(9, LOW);
  delay(250);
  digitalWrite(40, LOW);
  delay(250);
}

void closeALLYellowLeds(){
  delay(250);
  digitalWrite(22, LOW);
  delay(250);
  digitalWrite(24, LOW);
  delay(250);
  digitalWrite(26, LOW);
  delay(250);
  digitalWrite(28, LOW);
  delay(250);
  digitalWrite(30, LOW);
  delay(250);
  digitalWrite(32, LOW);
  delay(250);
  digitalWrite(34, LOW);
  delay(250);
  digitalWrite(36, LOW);
}
