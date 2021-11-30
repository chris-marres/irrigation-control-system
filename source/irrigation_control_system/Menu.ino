
void menuDisplay(){

  switch(MenuState){
    case 0: {
      t = rtc.getTime();

//      lcd.setCursor(0, 0);
//      lcd.print(t.date);
//      if (t.date == 1){
//        lcd.print("st");
//      }
//      else if (t.date == 2){
//        lcd.print("nd");
//      }
//      else if (t.date == 3){
//        lcd.print("rd");
//      }
//      else{
//        lcd.print("th");
//      }
//      lcd.print(" of ");
//      lcd.print(Months[t.mon-1]);
//      lcd.print(" ");
//      lcd.print(t.year);

      lcd.setCursor(0, 0);
      if (t.date < 10)
        lcd.print(0);
      lcd.print(t.date);
      lcd.print("/");
      if (t.mon < 10)
        lcd.print(0);
      lcd.print(t.mon);
      lcd.print("/");
      lcd.print(t.year);
      lcd.print("   ");
      
      lcd.setCursor(0,2);
      switch (t.dow){ case 1: lcd.print(Days[0]); break;
                      case 2: lcd.print(Days[1]); break;
                      case 3: lcd.print(Days[2]); break;
                      case 4: lcd.print(Days[3]); break;
                      case 5: lcd.print(Days[4]); break;
                      case 6: lcd.print(Days[5]); break;
                      case 7: lcd.print(Days[6]); break;
      }
      lcd.print(" ");
      if (t.hour < 10){
        lcd.print(0);
      }
      lcd.print(t.hour);
      lcd.print(":");
      if (t.min < 10){
        lcd.print(0);
      }
      lcd.print(t.min);
      lcd.print(":");
      if (t.sec < 10){
        lcd.print(0);
      }
      lcd.print(t.sec);
      lcd.print("   ");

      lcd.setCursor(0,3);
      lcd.print("Temp: ");
      lcd.print(rtc.getTemp());
      lcd.print((char)223);
      lcd.print("C");
      lcd.print("   ");
     
      break;
    }

    case 1:{
      lcd.setCursor(0, 0);
      lcd.print("Clock and Callendar");
      Blinkable(0, 1, "Date", DateSetting);
      lcd.setCursor(4, 1);
      lcd.print(":");
      if (MonthDay < 10){
        Blinkable1(6, 1, 0, MonthDayState);
        Blinkable2(7, 1, MonthDay, MonthDayState);
      }
      else{
        Blinkable1(6, 1, MonthDay, MonthDayState);
      }
      lcd.setCursor(8,1);
      lcd.print("/");
      if (Month < 10){
        Blinkable1(9, 1, 0, MonthState);
        Blinkable2(10, 1, Month, MonthState);
      }
      else{
        Blinkable1(9, 1, Month, MonthState);
      }
      lcd.setCursor(11,1);
      lcd.print("/");
      Blinkable1(12, 1, Year, YearState);

      Blinkable(0, 2, "Day", DaySetting);
      lcd.setCursor(4, 2);
      lcd.print(":");
      Blinkable(6, 2, Days[Day], DayState);

      Blinkable(0, 3, "Time", TimeSetting);
      lcd.setCursor(4, 3);
      lcd.print(":");
      if (Hours < 10){
        Blinkable1(6, 3, 0, HoursState);
        Blinkable2(7, 3, Hours, HoursState);
      }
      else{
        Blinkable1(6, 3, Hours, HoursState);
      }
      lcd.setCursor(8,3);
      lcd.print(":");
      if (Minutes < 10){
        Blinkable1(9, 3, 0, MinutesState);
        Blinkable2(10, 3, Minutes, MinutesState);
      }
      else{
        Blinkable1(9, 3, Minutes, MinutesState);
      }
      lcd.setCursor(11,3);
      lcd.print(":");
      if (Seconds < 10){
        Blinkable1(12, 3, 0, SecondsState);
        Blinkable2(13, 3, Seconds, SecondsState);
      }
      else{
        Blinkable1(12, 3, Seconds, SecondsState);
      }
      break;  
    }

    case 2: {
      lcd.setCursor(0, 0);
      lcd.print("Would you like to");
      lcd.setCursor(0, 1);
      lcd.print("save any changes?");
      Blinkable(5, 2, "Yes", YesState);
      Blinkable(12, 2, "No", NoState);
      
      break;
    }

    case 3: {
      lcd.setCursor(0, 0);
      lcd.print("1.");
      Blinkable(2, 0, "Date/Time Settings",dateTimeSettingState);
      lcd.setCursor(0, 1);
      lcd.print("2.");
      Blinkable(2, 1, "Alarm Settings", alarmSettingState);
      lcd.setCursor(0, 2);
      lcd.print("3.");
      Blinkable(2, 2, "Manual Timer", manualTimerSettingState);
      
      break;
    }

    case 4: {

      lcd.setCursor(0, 0);
      lcd.print("1.");
      Blinkable(2, 0, "Calibrate Timer", calibrateTimerSettingState);
      lcd.setCursor(0, 1);
      lcd.print("2.");
      Blinkable(2, 1, "Test Timer", testTimerSettingState);
      
      break;
    }

    case 5: {

      lcd.setCursor(0, 0);
      lcd.print("Timer: ");
      timerDisplay();
      Blinkable(0, 1, "Start", startState);
      Blinkable(7, 1, "Stop", stopState);
      Blinkable(13, 1, "Reset", resetState);
          
      break;
    }

    case 6: {
      
      lcd.setCursor(0, 0);
      lcd.print("Timer: ");
      lcd.print(finalTime - timer);
      lcd.print("s  ");
      Blinkable(0, 1, "Start", start2State);
      
      break;
    }

    case 7: {

      lcd.setCursor(0, 0);
      Blinkable(0, 0, "Alarm 1", alarm1State);
      lcd.setCursor(9, 0);
      if (scheduler.getAlarm(0).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 1);
      Blinkable(0, 1, "Alarm 2", alarm2State);
      lcd.setCursor(9, 1);
      if (scheduler.getAlarm(1).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 2);
      Blinkable(0, 2, "Alarm 3", alarm3State);
      lcd.setCursor(9, 2);
      if (scheduler.getAlarm(2).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 3);
      Blinkable(0, 3, "Alarm 4", alarm4State);
      lcd.setCursor(9, 3);
      if (scheduler.getAlarm(3).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(19, 3);
      lcd.write(4);
      
      break;
    }

    case 8: {

      lcd.setCursor(0, 0);
      Blinkable(0, 0, "Alarm 2", alarm2State);
      lcd.setCursor(9, 0);
      if (scheduler.getAlarm(1).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 1);
      Blinkable(0, 1, "Alarm 3", alarm3State);
      lcd.setCursor(9, 1);
      if (scheduler.getAlarm(2).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 2);
      Blinkable(0, 2, "Alarm 4", alarm4State);
      lcd.setCursor(9, 2);
      if (scheduler.getAlarm(3).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 3);
      Blinkable(0, 3, "Alarm 5", alarm5State);
      lcd.setCursor(9, 3);
      if (scheduler.getAlarm(4).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(19, 0);
      lcd.write(3);
      lcd.setCursor(19, 3);
      lcd.write(4);
      
      break;
    }

    case 9: {

      lcd.setCursor(0, 0);
      Blinkable(0, 0, "Alarm 3", alarm3State);
      lcd.setCursor(9, 0);
      if (scheduler.getAlarm(2).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 1);
      Blinkable(0, 1, "Alarm 4", alarm4State);
      lcd.setCursor(9, 1);
      if (scheduler.getAlarm(3).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 2);
      Blinkable(0, 2, "Alarm 5", alarm5State);
      lcd.setCursor(9, 2);
      if (scheduler.getAlarm(4).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 3);
      Blinkable(0, 3, "Alarm 6", alarm6State);
      lcd.setCursor(9, 3);
      if (scheduler.getAlarm(5).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(19, 0);
      lcd.write(3);
      lcd.setCursor(19, 3);
      lcd.write(4);
      
      break;
    }

    case 10: {

      lcd.setCursor(0, 0);
      Blinkable(0, 0, "Alarm 4", alarm4State);
      lcd.setCursor(9, 0);
      if (scheduler.getAlarm(3).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 1);
      Blinkable(0, 1, "Alarm 5", alarm5State);
      lcd.setCursor(9, 1);
      if (scheduler.getAlarm(4).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 2);
      Blinkable(0, 2, "Alarm 6", alarm6State);
      lcd.setCursor(9, 2);
      if (scheduler.getAlarm(5).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 3);
      Blinkable(0, 3, "Alarm 7", alarm7State);
      lcd.setCursor(9, 3);
      if (scheduler.getAlarm(6).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(19, 0);
      lcd.write(3);
      lcd.setCursor(19, 3);
      lcd.write(4);
      
      break;
    }

    case 11: {

      lcd.setCursor(0, 0);
      Blinkable(0, 0, "Alarm 5", alarm5State);
      lcd.setCursor(9, 0);
      if (scheduler.getAlarm(4).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 1);
      Blinkable(0, 1, "Alarm 6", alarm6State);
      lcd.setCursor(9, 1);
      if (scheduler.getAlarm(5).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 2);
      Blinkable(0, 2, "Alarm 7", alarm7State);
      lcd.setCursor(9, 2);
      if (scheduler.getAlarm(6).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 3);
      Blinkable(0, 3, "Alarm 8", alarm8State);
      lcd.setCursor(9, 3);
      if (scheduler.getAlarm(7).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(19, 0);
      lcd.write(3);
      lcd.setCursor(19, 3);
      lcd.write(4);
      
      break;
    }

    case 12: {

      lcd.setCursor(0, 0);
      Blinkable(0, 0, "Alarm 6", alarm6State);
      lcd.setCursor(9, 0);
      if (scheduler.getAlarm(5).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 1);
      Blinkable(0, 1, "Alarm 7", alarm7State);
      lcd.setCursor(9, 1);
      if (scheduler.getAlarm(6).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 2);
      Blinkable(0, 2, "Alarm 8", alarm8State);
      lcd.setCursor(9, 2);
      if (scheduler.getAlarm(7).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 3);
      Blinkable(0, 3, "Alarm 9", alarm9State);
      lcd.setCursor(9, 3);
      if (scheduler.getAlarm(8).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(19, 0);
      lcd.write(3);
      lcd.setCursor(19, 3);
      lcd.write(4);
      
      break;
    }

    case 13: {

      lcd.setCursor(0, 0);
      Blinkable(0, 0, "Alarm 7", alarm7State);
      lcd.setCursor(9, 0);
      if (scheduler.getAlarm(6).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 1);
      Blinkable(0, 1, "Alarm 8", alarm8State);
      lcd.setCursor(9, 1);
      if (scheduler.getAlarm(7).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 2);
      Blinkable(0, 2, "Alarm 9", alarm9State);
      lcd.setCursor(9, 2);
      if (scheduler.getAlarm(8).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(0, 3);
      Blinkable(0, 3, "Alarm 10", alarm10State);
      lcd.setCursor(9, 3);
      if (scheduler.getAlarm(9).enabled()){
        lcd.print("ENABLED");
      }
      else{
        lcd.print("DISABLED");
      }
      lcd.setCursor(19, 0);
      lcd.write(3);

      break;
    }

    case 14: {

      lcd.setCursor(0, 0);
      lcd.print("Alarm ");
      lcd.print(alarmBeingCalibrated+1);
      lcd.print(" Calibration");
      Blinkable(0, 1, "Rep", repState);
      lcd.setCursor(3, 1);
      lcd.print(": ");
      Blinkable(5, 1, AlarmTypeName[tempAlarm.getAlarmType()], alarmTypeNameState);
      if (tempAlarm.getAlarmType() == 0){
        Blinkable(0, 2, "Day", alarmDayState);
        lcd.setCursor(3, 2);
        lcd.print(": ");
        Blinkable(5, 2, Days[tempWeekDay - 1], alarmWeekDayState);
      }
      else{
        Blinkable(0, 2, "Start at", alarmDayState);
        lcd.setCursor(8, 2);
        lcd.print(": ");
        Blinkable(10, 2, Days[tempWeekDay - 1], alarmWeekDayState);
      }
      Blinkable(0, 3, "Hour/Min", HourMinState);
      lcd.setCursor(8, 3);
      lcd.print(":");
      if (tempAlarmHour < 10){
        Blinkable1(10, 3, 0, alarmHourState);
        Blinkable2(11, 3, tempAlarmHour, alarmHourState);
      }
      else{
        Blinkable1(10, 3, tempAlarmHour, alarmHourState);
      }
      lcd.setCursor(12, 3);
      lcd.print(":");
      if (tempAlarmMinute < 10){
        Blinkable1(13, 3, 0, alarmMinuteState);
        Blinkable2(14, 3, tempAlarmMinute, alarmMinuteState);
      }
      else{
        Blinkable1(13, 3, tempAlarmMinute, alarmMinuteState);
      }
      lcd.setCursor(19, 3);
      lcd.write(4);
      
      break;
    }

    case 15: {

      lcd.setCursor(0, 0);
      lcd.print("Alarm ");
      lcd.print(alarmBeingCalibrated+1);
      lcd.print(" Calibration");
      lcd.setCursor(19, 1);
      lcd.write(3);
      if (tempAlarm.getAlarmType() == 0){
        Blinkable(0, 1, "Day", alarmDayState);
        lcd.setCursor(3, 1);
        lcd.print(": ");
        Blinkable(5, 1, Days[tempWeekDay - 1], alarmWeekDayState);
      }
      else{
        Blinkable(0, 1, "Start at", alarmDayState);
        lcd.setCursor(8, 1);
        lcd.print(": ");
        Blinkable(10, 1, Days[tempWeekDay - 1], alarmWeekDayState);
      }
      Blinkable(0, 2, "Hour/Min", HourMinState);
      lcd.setCursor(8, 2);
      lcd.print(":");
      if (tempAlarmHour < 10){
        Blinkable1(10, 2, 0, alarmHourState);
        Blinkable2(11, 2, tempAlarmHour, alarmHourState);
      }
      else{
        Blinkable1(10, 2, tempAlarmHour, alarmHourState);
      }
      lcd.setCursor(12, 2);
      lcd.print(":");
      if (tempAlarmMinute < 10){
        Blinkable1(13, 2, 0, alarmMinuteState);
        Blinkable2(14, 2, tempAlarmMinute, alarmMinuteState);
      }
      else{
        Blinkable1(13, 2, tempAlarmMinute, alarmMinuteState);
      }
      Blinkable(0, 3, "Duration", durationState);
      lcd.setCursor(8, 3);
      lcd.print(":");
      lcd.setCursor(10, 3);
      lcd.print("H:");
      Blinkable1(12, 3, tempAlarmHourDuration, alarmHourDurationState);
      lcd.setCursor(14, 3);
      lcd.print("M:");
      if (tempAlarmMinuteDuration < 10){
        Blinkable1(16, 3, 0, alarmMinuteDurationState);
        Blinkable2(17, 3, tempAlarmMinuteDuration, alarmMinuteDurationState);
      }
      else{
        Blinkable1(16, 3, tempAlarmMinuteDuration, alarmMinuteDurationState);
      }      
      lcd.setCursor(19, 3);
      lcd.write(4);
      
      break;
    }

    case 16: {

      lcd.setCursor(0, 0);
      lcd.print("Alarm ");
      lcd.print(alarmBeingCalibrated+1);
      lcd.print(" Calibration");
      lcd.setCursor(19, 1);
      lcd.write(3);
      Blinkable(0, 1, "Hour/Min", HourMinState);
      lcd.setCursor(8, 1);
      lcd.print(":");
      if (tempAlarmHour < 10){
        Blinkable1(10, 1, 0, alarmHourState);
        Blinkable2(11, 1, tempAlarmHour, alarmHourState);
      }
      else{
        Blinkable1(10, 1, tempAlarmHour, alarmHourState);
      }
      lcd.setCursor(12, 1);
      lcd.print(":");
      if (tempAlarmMinute < 10){
        Blinkable1(13, 1, 0, alarmMinuteState);
        Blinkable2(14, 1, tempAlarmMinute, alarmMinuteState);
      }
      else{
        Blinkable1(13, 1, tempAlarmMinute, alarmMinuteState);
      }
      Blinkable(0, 2, "Duration", durationState);
      lcd.setCursor(8, 2);
      lcd.print(":");
      lcd.setCursor(10, 2);
      lcd.print("H:");
      Blinkable1(12, 2, tempAlarmHourDuration, alarmHourDurationState);
      lcd.setCursor(14, 2);
      lcd.print("M:");
      if (tempAlarmMinuteDuration < 10){
        Blinkable1(16, 2, 0, alarmMinuteDurationState);
        Blinkable2(17, 2, tempAlarmMinuteDuration, alarmMinuteDurationState);
      }
      else{
        Blinkable1(16, 2, tempAlarmMinuteDuration, alarmMinuteDurationState);
      }
      Blinkable(0, 3, "Valve", valveState);
      lcd.setCursor(5, 3);
      lcd.print(":");
      Blinkable1(7, 3, tempAlarmValve, alarmValveState);     
      
      break;
    }

    case 17: {

      lcd.setCursor(0, 0);
      lcd.print("Would you like to");
      lcd.setCursor(0, 1);
      lcd.print("save the changes");
      lcd.setCursor(0, 2);
      lcd.print("to Alarm ");
      lcd.print(alarmBeingCalibrated + 1);
      Blinkable(5, 3, "Yes", alarmYesState);
      Blinkable(12, 3, "No", alarmNoState);
      
      break;
    }

    case 18: {
      
      lcd.setCursor(0, 0);
      lcd.print("Alarm ");
      lcd.print(alarmTry);
      lcd.print(" is ON and");
      lcd.setCursor(0, 1);
      lcd.print("you shouldn't change");
      lcd.setCursor(0, 2);
      lcd.print("anything!");
      Blinkable(10, 3, "OK", okState);
      
      break;
    }
    
  }
  
}
