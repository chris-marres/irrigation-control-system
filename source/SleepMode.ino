
void checkSleepMode(){

  SleepMode();
  if(sleepMode){
    digitalWrite(8, LOW);
  }
  else{
    digitalWrite(8, HIGH);
  }
  
}

void SleepMode(){

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis3 >= sleepWait){
        sleepMode = true;
  }      

  
}
