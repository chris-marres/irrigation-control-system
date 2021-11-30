
void Blinkable(int x, int y, String message, bool state){

  if(state){
    unsigned long currentMillis = millis(); 
    
      if (currentMillis - previousMillis >= interval){
        previousMillis = currentMillis;
    
        if (WRITE){
          lcd.setCursor(x, y);
          lcd.print(message);
          WRITE = false;
        }
        else{
          lcd.setCursor(x, y);
          for (int i = 0; i < message.length(); i++){
            lcd.print(" ");
          }
          WRITE = true;
        }
      }
  }
  else{
    lcd.setCursor(x, y);
    lcd.print(message);
  }
    
}

void Blinkable1(int x, int y, int message, bool state){

  if(state){
    unsigned long currentMillis = millis(); 
    
      if (currentMillis - previousMillis1 >= interval){
        previousMillis1 = currentMillis;
    
        if (WRITE1){
          lcd.setCursor(x, y);
          lcd.print(message);
          WRITE1 = false;
        }
        else{
          lcd.setCursor(x, y);
          int L;
          if (message < 10){
            L = 1;
          }
          else if(message < 100){
            L = 2;
          }
          else if(message < 1000){
            L = 3;
          }
          else if(message < 10000){
            L = 4;
          }
          for (int i = 0; i < L; i++){
            lcd.print(" ");
          }
          WRITE1 = true;
        }
      }
  }
  else{
    lcd.setCursor(x, y);
    lcd.print(message);
  }
    
}

void Blinkable2(int x, int y, int message, bool state){

  if(state){
    unsigned long currentMillis = millis(); 
    
      if (currentMillis - previousMillis2 >= interval){
        previousMillis2 = currentMillis;
    
        if (WRITE2){
          lcd.setCursor(x, y);
          lcd.print(message);
          WRITE2 = false;
        }
        else{
          lcd.setCursor(x, y);
          int L;
          if (message < 10){
            L = 1;
          }
          else if(message < 100){
            L = 2;
          }
          else if(message < 1000){
            L = 3;
          }
          else if(message < 10000){
            L = 4;
          }
          for (int i = 0; i < L; i++){
            lcd.print(" ");
          }
          WRITE2 = true;
        }
      }
  }
  else{
    lcd.setCursor(x, y);
    lcd.print(message);
  }
    
}

void resetMillis(){
  WRITE = false;
  WRITE1 = false;
  WRITE2 = false;
  previousMillis = 0;
  previousMillis1 = 0;
  previousMillis2 = 0;
}
