// 1 = UP || 2 = RIGHT || 3 = DOWN || 4 = LEFT || 5 = ENTER || 6 = ESC/RESET

void checkButtons() {

  resistorValue = analogRead(A0);

  buttonNumber = checkControler();

  if (buttonPressed and !actionDone) {
    doAction();
  } 

  delay(5);

}

void doAction() {

  switch (buttonNumber) {
    case 1: {

        if (sleepMode){
          sleepMode = false;
          previousMillis3 = millis();
        }
        else if (testTimerSettingState){
          testTimerSettingState = false;
          resetMillis();
          calibrateTimerSettingState = true;
        }
        else if (manualTimerSettingState){
          manualTimerSettingState = false;
          resetMillis();
          alarmSettingState = true; 
        }
        else if (alarmSettingState){
          alarmSettingState = false;
          resetMillis();
          dateTimeSettingState = true;
        }
        else if (DateSetting) {
          DateSetting = false;
          resetMillis();
          TimeSetting = true;
        }
        else if (DaySetting) {
          DaySetting = false;
          resetMillis();
          DateSetting = true;
        }
        else if (TimeSetting) {
          TimeSetting = false;
          resetMillis();
          DaySetting = true;
        }
        else if (HoursState){
          if (Hours == 24)
            Hours = 0;
          else
            Hours++;
            resetMillis();
        }
        else if (MinutesState){
          if (Minutes == 60)
            Minutes = 0;
          else
            Minutes++;
          resetMillis();
        }
        else if (SecondsState){
          if (Seconds == 60)
            Seconds = 0;
          else
            Seconds++;
          resetMillis();
        }
        else if (MonthDayState){
          if (MonthDay == 31)
            MonthDay = 0;
          else
            MonthDay++;
          resetMillis();
        }
        else if (MonthState){
          if (Month == 12)
            Month = 0;
          else
            Month++;
          resetMillis();
        }
        else if (YearState){
            Year++;
            resetMillis();
        }
        else if (DayState){
          if (Day == 6)
            Day = 0;
          else
            Day++;
          lcd.setCursor(6,2);
          lcd.print("          ");    
        }

        break;
      }
    case 2: {

        if (sleepMode){
          sleepMode = false;
          previousMillis3 = millis();
        }
        else if (startState){
          startState = false;
          resetMillis();
          stopState = true;
        }
        else if (stopState){
          stopState = false;
          resetMillis();
          resetState = true;
        }
        else if (MonthDayState){
          MonthDayState = false;
          resetMillis();
          MonthState = true;
        }
        else if (MonthState){
          MonthState = false;
          resetMillis();
          YearState = true;
        }
        else if (YearState){
          YearState = false;
          resetMillis();
          MonthDayState = true;
        }
        else if (HoursState){
          HoursState = false;
          resetMillis();
          MinutesState = true;
        }
        else if (MinutesState){
          MinutesState = false;
          resetMillis();
          SecondsState = true;
        }
        else if (SecondsState){
          SecondsState = false;
          resetMillis();
          HoursState = true;
        }
        else if (YesState){
          YesState = false;
          resetMillis();
          NoState = true;
        }
      
        break;
      }
    case 3: {

        if (sleepMode){
          sleepMode = false;
          previousMillis3 = millis();
        }
        else if (calibrateTimerSettingState){
          calibrateTimerSettingState = false;
          resetMillis();
          testTimerSettingState = true;
        }
        else if (alarmSettingState){
          alarmSettingState = false;
          resetMillis();
          manualTimerSettingState = true;
        }
        else if (dateTimeSettingState){
          dateTimeSettingState = false;
          resetMillis();
          alarmSettingState = true;
        }
        else if (DateSetting) {
          DateSetting = false;
          resetMillis();
          DaySetting = true;
        }
        else if (DaySetting) {
          DaySetting = false;
          resetMillis();
          TimeSetting = true;
        }
        else if (TimeSetting) {
          TimeSetting = false;
          resetMillis();
          DateSetting = true;
        }
        else if (HoursState){
          if (Hours == 0)
            Hours = 24;
          else
            Hours--;
          resetMillis();  
        }
        else if (MinutesState){
          if (Minutes == 0)
            Minutes = 60;
          else
            Minutes--;
          resetMillis();  
        }
        else if (SecondsState){
          if (Seconds == 0)
            Seconds = 60;
          else
            Seconds--;
          resetMillis();  
        }
        else if (MonthDayState){
          if (MonthDay == 0)
            MonthDay = 31;
          else
            MonthDay--;
          resetMillis();  
        }
        else if (MonthState){
          if (Month == 0)
            Month = 12;
          else
            Month--;
          resetMillis();  
        }
        else if (YearState){
            Year--;
            resetMillis();
        }
        else if (DayState){
          if (Day == 0)
            Day = 6;
          else
            Day--;
          lcd.setCursor(6,2);
          lcd.print("          ");  
        }

        break;
      }
    case 4: {

        if (sleepMode){
          sleepMode = false;
          previousMillis3 = millis();
        }
        else if (resetState){
          resetState = false;
          resetMillis();
          stopState = true;
        }
        else if (stopState){
          stopState = false;
          resetMillis();
          startState = true;
        }
        else if (MonthDayState){
          MonthDayState = false;
          resetMillis();
          YearState = true;
        }
        else if (MonthState){
          MonthState = false;
          resetMillis();
          MonthDayState = true;
        }
        else if (YearState){
          YearState = false;
          resetMillis();
          MonthState = true;
        }
        else if (HoursState){
          HoursState = false;
          resetMillis();
          SecondsState = true;
        }
        else if (MinutesState){
          MinutesState = false;
          resetMillis();
          HoursState = true;
        }
        else if (SecondsState){
          SecondsState = false;
          resetMillis();
          MinutesState = true;
        }
        else if (NoState){
          NoState = false;
          resetMillis();
          YesState = true;
        }
      
        break;
      }
    case 5: {

        if (sleepMode){
          sleepMode = false;
          previousMillis3 = millis();
        }
        else if (start2State and timerOn){
          //Do Nothing
        }
        else if (start2State){
          timerOn = true;
          digitalWrite(LED1, HIGH);
          previousMillis5 = millis();
        }
        else if (testTimerSettingState){
          testTimerSettingState = false;
          resetMillis();
          MenuState = 6;
          lcd.clear();
          start2State = true;
        }
        else if (stopState and timerState == 2){
          //Do Nothing
        }
        else if (stopState and timerState == 0){
          //Do Nothing
        }
        else if (startState and timerState == 1){
          //Do Nothing
        }
        else if (resetState){
          digitalWrite(LED1, LOW);
          lcd.clear();
          timerState = 0;
          tempTime = 0;
          tempTime2 = 0;
          finalTime = 0;
          EEPROM.write(0, 0);
        }
        else if (stopState){
          digitalWrite(LED1, LOW);
          timerState = 2;
          tempTime2 += tempTime;
        }
        else if (startState){
          digitalWrite(LED1, HIGH);
          timerState = 1;
          tempTime = 0;
          lcd.clear();
          previousMillis4 = millis();
        }
        else if (calibrateTimerSettingState){
          calibrateTimerSettingState = false;
          resetMillis();
          lcd.clear();
          MenuState = 5;
          startState = true;
          tempTime = finalTime;
          tempTime2 = finalTime;
        }
        else if (manualTimerSettingState){
          manualTimerSettingState = false;
          resetMillis();
          lcd.clear();
          MenuState = 4;
          calibrateTimerSettingState = true;
        }
        else if (dateTimeSettingState){
          lcd.clear();
          MenuState = 1;
          t = rtc.getTime();
          MonthDay = t.date;
          Month = t.mon;
          Year = t.year;
          Hours = t.hour;
          Minutes = t.min;
          Seconds = t.sec;
          Day = t.dow - 1;
          resetMillis();
          dateTimeSettingState = false;
          DateSetting = true;
        }
        else if (DateSetting) {
          DateSetting = false;
          resetMillis();
          MonthDayState = true;
        }
        else if (DaySetting) {
          DaySetting = false;
          resetMillis();
          DayState = true;
        }
        else if (TimeSetting) {
          TimeSetting = false;
          resetMillis();
          HoursState = true;
        }
        else if (YesState){
          YesState = false;
          resetMillis();
          switch (Day){
            case 0: rtc.setDOW(MONDAY); break;
            case 1: rtc.setDOW(TUESDAY); break;
            case 2: rtc.setDOW(WEDNESDAY); break;
            case 3: rtc.setDOW(THURSDAY); break;
            case 4: rtc.setDOW(FRIDAY); break;
            case 5: rtc.setDOW(SATURDAY); break;
            case 6: rtc.setDOW(SUNDAY); break;
          }
          rtc.setTime(Hours, Minutes, Seconds);
          rtc.setDate(MonthDay, Month, Year);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SAVED");
          delay(2000);
          lcd.clear();
          MenuState = 3;
          dateTimeSettingState = true;
        }
        else if (NoState){
          NoState = false;
          resetMillis();
          lcd.clear();
          MenuState = 3;
          dateTimeSettingState = true;
        }

        break;
      }

    case 6: {

        if (sleepMode){
          sleepMode = false;
          previousMillis3 = millis();
        }
        else if (MenuState == 6){
          start2State = false;
          resetMillis();
          lcd.clear();
          MenuState = 4;
          testTimerSettingState = true;
        }
        else if (MenuState == 5 and timerState == 2){
          lcd.clear();
          lcd.home();
          lcd.print("Timer Saved");
          delay(1500);
          finalTime = tempTime2;
          EEPROM.write(0, finalTime);
          lcd.clear();
          MenuState = 4;
          startState = false;
          stopState = false;
          resetState = false;
          resetMillis();
          calibrateTimerSettingState = true;
          timerState = 0;
        }
        else if (MenuState == 5){
          startState = false;
          stopState = false;
          resetState = false;
          tempTime = 0;
          tempTime2 = 0;
          timerState = 0; 
          resetMillis();
          lcd.clear();
          MenuState = 4;
          calibrateTimerSettingState = true;
          digitalWrite(LED1, LOW);
        }
        else if (MenuState == 4){
          calibrateTimerSettingState = false;
          testTimerSettingState = false; 
          resetMillis();
          lcd.clear();
          MenuState = 3;
          manualTimerSettingState = true;
        }
        else if (MenuState == 3){
          dateTimeSettingState = false;
          alarmSettingState = false;
          manualTimerSettingState = false;
          MenuState = 0;
          resetMillis();
          lcd.clear();
        }
        else if (MenuState == 0){
          lcd.clear();
          MenuState = 3;
          resetMillis();
          dateTimeSettingState = true;
        }
        else if (DateSetting or DaySetting or TimeSetting) {
          DateSetting = false;
          DaySetting = false;
          TimeSetting = false;
          resetMillis();
          lcd.clear();
          YesState = true;
          MenuState = 2;
        }
        else if (MonthDayState or MonthState or YearState) {
          MonthDayState = false;
          MonthState = false;
          YearState = false;
          resetMillis();
          DateSetting = true;
        }
        else if (DayState) {
          DayState = false;
          resetMillis();
          DaySetting = true;
        }
        else if (HoursState or MinutesState or SecondsState) {
          HoursState = false;
          MinutesState = false;
          SecondsState = false;
          resetMillis();
          TimeSetting = true;
        }

        break;
      }
  }
  actionDone = true;
}

int checkControler() {

  if (resistorValue > 900) {
    buttonPressed = false;
    actionDone = false;
    return 0;
  }
  else {
    buttonPressed = true;
    previousMillis3 = millis();
  }

  if (resistorValue <= 20) {
    return 2;
  }
  else if (resistorValue >= 120 and resistorValue <= 170) {
    return 1;
  }
  else if (resistorValue >= 320 and resistorValue <= 360) {
    return 3;
  }
  else if (resistorValue >= 490 and resistorValue <= 530) {
    return 4;
  }
  else if (resistorValue >= 720 and resistorValue <= 760) {
    return 5;
  }
  else if (resistorValue >= 800 and resistorValue <= 860) {
    return 6;
  }

}
