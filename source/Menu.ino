
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
  
  }
  
}
