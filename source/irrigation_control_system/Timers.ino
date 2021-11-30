

void timerDisplay(){
  
  switch (timerState){
    
    case 0: {
      lcd.print(finalTime);
      lcd.print("s   ");
      break;
    }
    case 1: {
      tempTime = (millis() - previousMillis4)/1000;
      lcd.print(tempTime2 + tempTime);
      lcd.print("s   ");
      break;
    }

    case 2: {
      lcd.print(tempTime2);
      lcd.print("s   ");
      break;
    }
    
  }
 
}

void UpdateTimer(){
  timer = (millis() - previousMillis5)/1000;

  if (timer == finalTime){
    timerOn = false;
    digitalWrite(TIMERLED, LOW);
    previousMillis5 = 0;
    timer = 0;
  }
}

void checkTimer(){
  if (timerOn){
    UpdateTimer();
  }
}
