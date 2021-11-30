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
        else if (alarmValveState){
          if (tempAlarmValve == 5){
            tempAlarmValve = 1;
          }
          else{
            tempAlarmValve += 1;
          }
        }
        else if (alarmMinuteDurationState){
          if (tempAlarmMinuteDuration >= 59){
            tempAlarmMinuteDuration = 0;
            resetMillis();
          }
          else{
            tempAlarmMinuteDuration += 1;
            resetMillis();
          }
        }
        else if (alarmHourDurationState){
          if (tempAlarmHourDuration >= 9){
            tempAlarmHourDuration = 0;
          }
          else{
            tempAlarmHourDuration += 1;
          }
        }
        else if (alarmMinuteState){
          if (tempAlarmMinute == 59){
            resetMillis();
            tempAlarmMinute = 0;
          }
          else{
            resetMillis();
            tempAlarmMinute += 1;
          }
        }
        else if (alarmHourState){
          if (tempAlarmHour == 23){
            resetMillis();
            tempAlarmHour = 0;
          }
          else{
            resetMillis();
            tempAlarmHour += 1;
          }
        }
        else if (alarmWeekDayState){
          if (tempWeekDay == 7){
            tempWeekDay = 1;
            lcd.clear();
          }
          else{
            tempWeekDay += 1;
            lcd.clear();
          }
        }
        else if (alarmTypeNameState){
          if (tempAlarm.getAlarmType() == 3){
            tempAlarm.changeAlarmType(0);
            lcd.clear();
          }
          else{
            tempAlarm.changeAlarmType(tempAlarm.getAlarmType() + 1);
            lcd.clear();
          }
        }
        else if (valveState){
          valveState = false;
          resetMillis();
          durationState = true;
        }
        else if (durationState){
          durationState = false;
          resetMillis();
          HourMinState = true;
        }
        else if (HourMinState and MenuState == 16){
          HourMinState = false;
          resetMillis();
          alarmDayState = true;
          lcd.clear();
          MenuState = 15;
        }
        else if (HourMinState){
          HourMinState = false;
          resetMillis();
          alarmDayState = true;
          alarmDayState = true;
        }
        else if (alarmDayState and MenuState == 15){
          alarmDayState = false;
          resetMillis();
          repState = true;
          lcd.clear();
          MenuState = 14;
        }
        else if (alarmDayState){
          alarmDayState = false;
          resetMillis();
          repState = true;
        }
        else if (HourMinState){
          HourMinState = false;
          resetMillis();
          alarmDayState = true;
          alarmDayState = true;
        }
        else if (alarm10State){
          alarm10State = false;
          resetMillis();
          alarm9State = true;
        }
        else if (alarm9State){
          alarm9State = false;
          resetMillis();
          alarm8State = true;
        }
        else if (alarm8State){
          alarm8State = false;
          resetMillis();
          alarm7State = true;
        }
        else if (alarm7State and MenuState == 13){
          alarm7State = false;
          resetMillis();
          lcd.clear();
          MenuState = 12;
          alarm6State = true;
        }
        else if (alarm7State){
          alarm7State = false;
          resetMillis();
          alarm6State = true;
        }
        else if (alarm6State and MenuState == 12){
          alarm6State = false;
          resetMillis();
          lcd.clear();
          MenuState = 11;
          alarm5State = true;
        }
        else if (alarm6State){
          alarm6State = false;
          resetMillis();
          alarm5State = true;
        }
        else if (alarm5State and MenuState == 11){
          alarm5State = false;
          resetMillis();
          lcd.clear();
          MenuState = 10;
          alarm4State = true;
        }
        else if (alarm5State){
          alarm5State = false;
          resetMillis();
          alarm4State = true;
        }
        else if (alarm4State and MenuState == 10){
          alarm4State = false;
          resetMillis();
          lcd.clear();
          MenuState = 9;
          alarm3State = true;
        }
        else if (alarm4State){
          alarm4State = false;
          resetMillis();
          alarm3State = true;
        }
        else if (alarm3State and MenuState == 9){
          alarm3State = false;
          resetMillis();
          lcd.clear();
          MenuState = 8;
          alarm2State = true;
        }
        else if (alarm3State){
          alarm3State = false;
          resetMillis();
          alarm2State = true;
        }
        else if (alarm2State and MenuState == 8){
          alarm2State = false;
          resetMillis();
          lcd.clear();
          MenuState = 7;
          alarm1State = true;
        }
        else if (alarm2State){
          alarm2State = false;
          resetMillis();
          alarm1State = true;
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
          if (Hours == 23)
            Hours = 0;
          else
            Hours++;
            resetMillis();
        }
        else if (MinutesState){
          if (Minutes == 59)
            Minutes = 0;
          else
            Minutes++;
          resetMillis();
        }
        else if (SecondsState){
          if (Seconds == 59)
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
        else if (alarmYesState){
          alarmYesState = false;
          resetMillis();
          alarmNoState = true;
        }
        else if (alarmHourDurationState){
          alarmHourDurationState = false;
          resetMillis();
          alarmMinuteDurationState = true;
        }
        else if (alarmHourState){
          alarmHourState = false;
          resetMillis();
          alarmMinuteState = true;
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
        else if (alarmValveState){
          if (tempAlarmValve == 1){
            tempAlarmValve = 5;
          }
          else{
            tempAlarmValve -= 1;
          }
        }
        else if (alarmMinuteDurationState){
          if (tempAlarmMinuteDuration == 0){
            tempAlarmMinuteDuration = 59;
            resetMillis();
          }
          else{
            tempAlarmMinuteDuration -= 1;
            resetMillis();
          }
        }
        else if (alarmHourDurationState){
          if (tempAlarmHourDuration == 0){
            tempAlarmHourDuration = 9;
          }
          else{
            tempAlarmHourDuration -= 1;
          }
        }
        else if (alarmMinuteState){
          if (tempAlarmMinute == 0){
            resetMillis();
            tempAlarmMinute = 59;
          }
          else{
            resetMillis();
            tempAlarmMinute -= 1;
          }
        }
        else if (alarmHourState){
          if (tempAlarmHour == 0){
            resetMillis();
            tempAlarmHour = 23;
          }
          else{
            resetMillis();
            tempAlarmHour -= 1;
          }
        }
        else if (alarmWeekDayState){
          if (tempWeekDay == 1){
            tempWeekDay = 7;
            lcd.clear();
          }
          else{
            tempWeekDay -= 1;
            lcd.clear();
          }
        }
        else if (alarmTypeNameState){
          if (tempAlarm.getAlarmType() == 0){
            tempAlarm.changeAlarmType(3);
            lcd.clear();
          }
          else{
            tempAlarm.changeAlarmType(tempAlarm.getAlarmType() - 1);
            lcd.clear();
          }
        }
        else if (repState){
          repState = false;
          resetMillis();
          alarmDayState = true;
          alarmDayState = true;
        }
        else if (alarmDayState or alarmDayState){
          alarmDayState = false;
          alarmDayState = false;
          resetMillis();
          HourMinState = true;
        }
        else if (HourMinState and MenuState == 14){
          HourMinState = false;
          resetMillis();
          durationState = true;
          lcd.clear();
          MenuState = 15;
        }
        else if (HourMinState){
          HourMinState = false;
          resetMillis();
          durationState = true;
        }
        else if (durationState and MenuState == 15){
          durationState = false;
          resetMillis();
          valveState = true;
          lcd.clear();
          MenuState = 16;
        }
        else if (durationState){
          durationState = false;
          resetMillis();
          valveState = true;
        }
        else if (alarm1State){
          alarm1State = false;
          resetMillis();
          alarm2State = true;
        }
        else if (alarm2State){
          alarm2State = false;
          resetMillis();
          alarm3State = true;
        }
        else if (alarm3State){
          alarm3State = false;
          resetMillis();
          alarm4State = true;
        }
        else if (alarm4State and MenuState == 7){
          alarm4State = false;
          resetMillis();
          lcd.clear();
          MenuState = 8;
          alarm5State = true;
        }
        else if (alarm4State){
          alarm4State = false;
          resetMillis();
          alarm5State = true;
        }
        else if (alarm5State and MenuState == 8){
          alarm5State = false;
          resetMillis();
          lcd.clear();
          MenuState = 9;
          alarm6State = true;
        }
        else if (alarm5State){
          alarm5State = false;
          resetMillis();
          alarm6State = true;
        }
        else if (alarm6State and MenuState == 9){
          alarm6State = false;
          resetMillis();
          lcd.clear();
          MenuState = 10;
          alarm7State = true;
        }
        else if (alarm6State){
          alarm6State = false;
          resetMillis();
          alarm7State = true;
        }
        else if (alarm7State and MenuState == 10){
          alarm7State = false;
          resetMillis();
          lcd.clear();
          MenuState = 11;
          alarm8State = true;
        }
        else if (alarm7State){
          alarm7State = false;
          resetMillis();
          alarm8State = true;
        }
        else if (alarm8State and MenuState == 11){
          alarm8State = false;
          resetMillis();
          lcd.clear();
          MenuState = 12;
          alarm9State = true;
        }
        else if (alarm8State){
          alarm8State = false;
          resetMillis();
          alarm9State = true;
        }
        else if (alarm9State and MenuState == 12){
          alarm9State = false;
          resetMillis();
          lcd.clear();
          MenuState = 13;
          alarm10State = true;
        }
        else if (alarm9State){
          alarm9State = false;
          resetMillis();
          alarm10State = true;
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
            Hours = 23;
          else
            Hours--;
          resetMillis();  
        }
        else if (MinutesState){
          if (Minutes == 0)
            Minutes = 59;
          else
            Minutes--;
          resetMillis();  
        }
        else if (SecondsState){
          if (Seconds == 0)
            Seconds = 59;
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
        else if (alarmNoState){
          alarmNoState = false;
          resetMillis();
          alarmYesState = true;
        }
        else if (alarmMinuteDurationState){
          alarmMinuteDurationState = false;
          resetMillis();
          alarmHourDurationState = true;
        }
        else if (alarmMinuteState){
          alarmMinuteState = false;
          resetMillis();
          alarmHourState = true;
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
        else if (okState){
          okState = false;
          resetMillis();
          switch (alarmTry){
            case 1:  alarm1State  = true; MenuState = 7; break;
            case 2:  alarm2State  = true; MenuState = 7; break;
            case 3:  alarm3State  = true; MenuState = 7; break;
            case 4:  alarm4State  = true; MenuState = 7; break;
            case 5:  alarm5State  = true; MenuState = 11; break;
            case 6:  alarm6State  = true; MenuState = 11; break;
            case 7:  alarm7State  = true; MenuState = 11; break;
            case 8:  alarm8State  = true; MenuState = 11; break;
            case 9:  alarm9State  = true; MenuState = 13; break;
            case 10: alarm10State = true; MenuState = 13; break;
          }
          lcd.clear();
        }
        else if (alarmYesState){
          alarmYesState = false;
          resetMillis();
          lcd.clear();
          switch (alarmBeingCalibrated){
            case 0: alarm1State  = true; MenuState = 7; break;
            case 1: alarm2State  = true; MenuState = 7; break;
            case 2: alarm3State  = true; MenuState = 7; break;
            case 3: alarm4State  = true; MenuState = 7; break;
            case 4: alarm5State  = true; MenuState = 11; break;
            case 5: alarm6State  = true; MenuState = 11; break;
            case 6: alarm7State  = true; MenuState = 11; break;
            case 7: alarm8State  = true; MenuState = 11; break;
            case 8: alarm9State  = true; MenuState = 13; break;
            case 9: alarm10State = true; MenuState = 13; break;
          }
          int Valve = 0;
          switch (tempAlarmValve){
            case 1: Valve = LED1; break;
            case 2: Valve = LED2; break;
            case 3: Valve = LED3; break;
            case 4: Valve = LED4; break;
            case 5: Valve = LED5; break;
          }
          scheduler.addAlarm(tempWeekDay, tempAlarmHour, tempAlarmMinute, Valve, ((tempAlarmHourDuration * 60 * 60) + (tempAlarmMinuteDuration * 60)), alarmBeingCalibrated, tempAlarm.getAlarmType());
          scheduler.enable(alarmBeingCalibrated);
          updateEEPROM(alarmBeingCalibrated);
        }
        else if (alarmNoState){
          alarmNoState = false;
          resetMillis();
          lcd.clear();
          switch (alarmBeingCalibrated){
            case 0: alarm1State  = true; MenuState = 7; break;
            case 1: alarm2State  = true; MenuState = 7; break;
            case 2: alarm3State  = true; MenuState = 7; break;
            case 3: alarm4State  = true; MenuState = 7; break;
            case 4: alarm5State  = true; MenuState = 11; break;
            case 5: alarm6State  = true; MenuState = 11; break;
            case 6: alarm7State  = true; MenuState = 11; break;
            case 7: alarm8State  = true; MenuState = 11; break;
            case 8: alarm9State  = true; MenuState = 13; break;
            case 9: alarm10State = true; MenuState = 13; break;
          }
        }
        else if (valveState){
          valveState = false;
          resetMillis();
          alarmValveState = true;
        }
        else if (durationState){
          durationState = false;
          resetMillis();
          alarmHourDurationState = true;
        }
        else if (HourMinState){
          HourMinState = false;
          resetMillis();
          alarmHourState = true;
        }
        else if (alarmDayState or alarmWeekDayState){
          alarmDayState = false;
          alarmWeekDayState = false;
          resetMillis();
          alarmWeekDayState = true;
        }
        else if (repState){
          repState = false;
          resetMillis();
          alarmTypeNameState = true;
        }
        else if (alarm1State){
          if (scheduler.getAlarm(0).ON()){
            alarmTry = 1;
            alarm1State = false;
            resetMillis();
            okState = true;
            lcd.clear();
            MenuState = 18;
          }
          else{
            alarm1State = false;
            resetMillis();
            repState = true;
            alarmBeingCalibrated = 0;
            copyAlarm(0);
            lcd.clear();
            MenuState = 14;
          } 
        }
        else if (alarm2State){
          if (scheduler.getAlarm(1).ON()){
            alarmTry = 2;
            alarm1State = false;
            resetMillis();
            okState = true;
            lcd.clear();
            MenuState = 18;
          }
          else{
            alarm2State = false;
            resetMillis();
            repState = true;
            alarmBeingCalibrated = 1;
            copyAlarm(1);
            lcd.clear();
            MenuState = 14;
          } 
        }
        else if (alarm3State){
          if (scheduler.getAlarm(2).ON()){
            alarmTry = 3;
            alarm1State = false;
            resetMillis();
            okState = true;
            lcd.clear();
            MenuState = 18;
          }
          else{
            alarm3State = false;
            resetMillis();
            repState = true;
            alarmBeingCalibrated = 2;
            copyAlarm(2);
            lcd.clear();
            MenuState = 14;
          } 
        }
        else if (alarm4State){
          if (scheduler.getAlarm(3).ON()){
            alarmTry = 4;
            alarm1State = false;
            resetMillis();
            okState = true;
            lcd.clear();
            MenuState = 18;
          }
          else{
            alarm4State = false;
            resetMillis();
            repState = true;
            alarmBeingCalibrated = 3;
            copyAlarm(3);
            lcd.clear();
            MenuState = 14;
          } 
        }
        else if (alarm5State){
          if (scheduler.getAlarm(4).ON()){
            alarmTry = 5;
            alarm1State = false;
            resetMillis();
            okState = true;
            lcd.clear();
            MenuState = 18;
          }
          else{
            alarm5State = false;
            resetMillis();
            repState = true;
            alarmBeingCalibrated = 4;
            copyAlarm(4);
            lcd.clear();
            MenuState = 14;
          } 
        }
        else if (alarm6State){
          if (scheduler.getAlarm(5).ON()){
            alarmTry = 6;
            alarm1State = false;
            resetMillis();
            okState = true;
            lcd.clear();
            MenuState = 18;
          }
          else{
            alarm6State = false;
            resetMillis();
            repState = true;
            alarmBeingCalibrated = 5;
            copyAlarm(5);
            lcd.clear();
            MenuState = 14;
          } 
        }
        else if (alarm7State){
          if (scheduler.getAlarm(6).ON()){
            alarmTry = 7;
            alarm1State = false;
            resetMillis();
            okState = true;
            lcd.clear();
            MenuState = 18;
          }
          else{
            alarm7State = false;
            resetMillis();
            repState = true;
            alarmBeingCalibrated = 6;
            copyAlarm(6);
            lcd.clear();
            MenuState = 14;
          } 
        }
        else if (alarm8State){
          if (scheduler.getAlarm(7).ON()){
            alarmTry = 8;
            alarm1State = false;
            resetMillis();
            okState = true;
            lcd.clear();
            MenuState = 18;
          }
          else{
            alarm8State = false;
            resetMillis();
            repState = true;
            alarmBeingCalibrated = 7;
            copyAlarm(7);
            lcd.clear();
            MenuState = 14;
          } 
        }
        else if (alarm9State){
          if (scheduler.getAlarm(8).ON()){
            alarmTry = 9;
            alarm1State = false;
            resetMillis();
            okState = true;
            lcd.clear();
            MenuState = 18;
          }
          else{
            alarm9State = false;
            resetMillis();
            repState = true;
            alarmBeingCalibrated = 8;
            copyAlarm(8);
            lcd.clear();
            MenuState = 14;
          } 
        }
        else if (alarm10State){
          if (scheduler.getAlarm(9).ON()){
            alarmTry = 10;
            alarm1State = false;
            resetMillis();
            okState = true;
            lcd.clear();
            MenuState = 18;
          }
          else{
            alarm10State = false;
            resetMillis();
            repState = true;
            alarmBeingCalibrated = 9;
            copyAlarm(9);
            lcd.clear();
            MenuState = 14;
          } 
        }
        else if (alarmSettingState){
          alarmSettingState = false;
          resetMillis();
          MenuState = 7;
          lcd.clear();
          alarm1State = true;
        }
        else if (start2State and timerOn){
          //Do Nothing
        }
        else if (start2State){
          timerOn = true;
          digitalWrite(TIMERLED, HIGH);
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
          digitalWrite(TIMERLED, LOW);
          lcd.clear();
          timerState = 0;
          tempTime = 0;
          tempTime2 = 0;
          finalTime = 0;
          EEPROM.write(0, 0);
        }
        else if (stopState){
          digitalWrite(TIMERLED, LOW);
          timerState = 2;
          tempTime2 += tempTime;
        }
        else if (startState){
          digitalWrite(TIMERLED, HIGH);
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
        else if (alarmValveState){
          alarmValveState = false;
          resetMillis();
          valveState = true;
        }
        else if (alarmHourDurationState or alarmMinuteDurationState){
          alarmHourDurationState = false;
          alarmMinuteDurationState = false;
          resetMillis();
          durationState = true;
        }
        else if (alarmHourState or alarmMinuteState){
          alarmHourState = false;
          alarmMinuteState = false;
          resetMillis();
          HourMinState = true;
        }
        else if (alarmWeekDayState){
          alarmWeekDayState = false;
          resetMillis();
          alarmDayState = true;
          alarmDayState = true;
        }
        else if (alarmTypeNameState){
          alarmTypeNameState = false;
          resetMillis();
          repState = true;
        }
        else if (repState or alarmDayState or HourMinState or durationState or valveState){
          repState = false;
          alarmDayState = false;
          alarmDayState = false;
          HourMinState = false;
          durationState = false;
          valveState = false;
//          switch (alarmBeingCalibrated){
//            case 0: alarm1State  = true; MenuState = 7; break;
//            case 1: alarm2State  = true; MenuState = 7; break;
//            case 2: alarm3State  = true; MenuState = 7; break;
//            case 3: alarm4State  = true; MenuState = 7; break;
//            case 4: alarm5State  = true; MenuState = 11; break;
//            case 5: alarm6State  = true; MenuState = 11; break;
//            case 6: alarm7State  = true; MenuState = 11; break;
//            case 7: alarm8State  = true; MenuState = 11; break;
//            case 8: alarm9State  = true; MenuState = 13; break;
//            case 9: alarm10State = true; MenuState = 13; break;
//          }
          resetMillis();
          lcd.clear();
          MenuState = 17;
          alarmYesState = true;
        }
        else if (alarm1State or alarm2State or alarm3State or alarm4State or alarm5State or
                 alarm6State or alarm7State or alarm8State or alarm9State or alarm10State){
          alarm1State = false;
          alarm2State = false;
          alarm3State = false;
          alarm4State = false;
          alarm5State = false;
          alarm6State = false;
          alarm7State = false;
          alarm8State = false;
          alarm9State = false;
          alarm10State = false;
          resetMillis();
          MenuState = 3;
          lcd.clear();
          alarmSettingState = true;
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
          digitalWrite(TIMERLED, LOW);
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
