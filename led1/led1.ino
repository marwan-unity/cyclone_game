int buttonValue1 = 0;
int buttonValue2 = 0;
int button1 = 10;
int button2 = 11;

int greenLed1 = 12;
int greenLed2 = 13;
int greenLedValue1 = 0;
int greenLedValue2 = 0;

int ledsArr[5] = {4,5,6,7,8};
int delayValue;
int buttonPressedDelay = 2000;
int speedAdded = 20;

bool gameIsStarted = false;


void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(greenLed1, INPUT);
  pinMode(greenLed2, INPUT);
  for(int i = 0; i <= 4; i++){
    pinMode(ledsArr[i], OUTPUT);
  }
}

void loop() {
  buttonValue1 = digitalRead(button1);
  buttonValue2 = digitalRead(button2);
  delayValue = 250;
  
  if(buttonValue1 && buttonValue2){
    gameIsStarted = true;
  }
  
  while(gameIsStarted){
     for(int i = 0; i <= 4; i++){
      
      buttonValue1 = digitalRead(button1);
      buttonValue2 = digitalRead(button2);
      
      digitalWrite(ledsArr[i], HIGH);
      delay(delayValue);
      
      if(buttonValue1 != 0 || buttonValue2 != 0){
          delay(buttonPressedDelay);
          greenLedValue1 = digitalRead(greenLed1);
          greenLedValue2 = digitalRead(greenLed2);
          
          if(greenLedValue1 == HIGH || greenLedValue2 == HIGH){
            delayValue -= speedAdded;
          }
      }
      digitalWrite(ledsArr[i], LOW); 
    }
    
    for(int j = 3; j >= 1; j--){
      
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
