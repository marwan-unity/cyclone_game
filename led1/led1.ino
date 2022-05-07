int buttonValue1 = 0;
int buttonValue2 = 0;
int button1 = 10;
int button2 = 11;
int ledsArr[12] = {0,1,2,3,4,5,6,7,8,9,12,13};
int delayValue = 100;
int buttonPressedDelay = 2000;


void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  for(int i = 0; i <= 11; i++){
    pinMode(ledsArr[i], OUTPUT);
  }
}

void loop() {
   for(int i = 0; i <= 11; i++){
    
    buttonValue1 = digitalRead(button1);
    buttonValue2 = digitalRead(button2);
    
    digitalWrite(ledsArr[i], HIGH);
    delay(delayValue);
    
    if(buttonValue1 != 0 || buttonValue2 != 0){
        delay(buttonPressedDelay);}
    digitalWrite(ledsArr[i], LOW);
    
  }
  
  
  for(int j = 10; j >= 1; j--){
    
    buttonValue2 = digitalRead(button2);
    buttonValue1 = digitalRead(button1);
    
    digitalWrite(ledsArr[j], HIGH);
    delay(delayValue);
    
    if(buttonValue1 != 0 || buttonValue2 != 0){
        delay(buttonPressedDelay);
    }
    digitalWrite(ledsArr[j], LOW);
    
  }
}
