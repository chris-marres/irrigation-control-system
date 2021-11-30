#include <LiquidCrystal.h>
#include <DS3231.h>
#include <EEPROM.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
DS3231 rtc(SDA, SCL);
Time t;

byte upArrow[8] = {
  0b00000,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b00100,
  0b00100,
  0b00000
};

byte downArrow[8] = {
  0b00000,
  0b00100,
  0b00100,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00000
};
 
//Clock and Callendar Settings
  int  Year     = 0;
  bool YearState     = false;
  int  Month    = 0;
  bool MonthState    = false;
  int  MonthDay = 0;
  bool MonthDayState = false;
  int  Day      = 0;
  bool DayState      = false;
  int  Hours    = 0;
  bool HoursState    = false;
  int  Minutes  = 0;
  bool MinutesState  = false;
  int  Seconds  = 0;
  bool SecondsState  = false;

  int  ClockAndCallendarState = 0;
  bool DateSetting = false;
  bool DaySetting  = false;
  bool TimeSetting = false;

  bool YesState = false;
  bool NoState  = false;

//Constants
  String Days[7]          = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  String Months[12]       = {"January",  "February" , "March", "April" , "May", "June", "July", "August", "September", "October", "November", "December"};
  String AlarmTypeName[4] = {"Once a week", "Everyday", "Every 2nd day", "Every 3rd day"};
  const int TIMERLED = 9;
  const int LED1     = 10;
  const int LED2     = 11;
  const int LED3     = 12;
  const int LED4     = 13;
  const int LED5     = 15;
  

//Blinking
  bool WRITE  = false;
  bool WRITE1 = false;
  bool WRITE2 = false;
  unsigned long previousMillis  = 0;
  unsigned long previousMillis1 = 0;
  unsigned long previousMillis2 = 0;
  int interval = 200;

//Buttons
  int  resistorValue = 0;
  bool buttonPressed = false;
  int  buttonNumber  = 0; // 1 = UP || 2 = RIGHT || 3 = DOWN || 4 = LEFT || 5 = ENTER || 6 = ESC/RESET
  bool actionDone    = true;

//SleepMode
  int sleepWait = 30 * 1000;
  unsigned long previousMillis3 = 0;
  bool sleepMode = false;

//Main Menu
  bool dateTimeSettingState       = false;
  bool alarmSettingState          = false;
  bool manualTimerSettingState    = false; 
  bool calibrateTimerSettingState = false;
  bool testTimerSettingState      = false; 

//Timer Calibration
  unsigned long previousMillis4 = 0;
  bool startState = false;
  bool stopState  = false;
  bool resetState = false;
  int tempTime   = 0; 
  int tempTime2  = 0;
  int finalTime  = 0;
  int timerState = 0;

//Timer Test 
  unsigned long previousMillis5 = 0;
  int  timer = 0;
  bool start2State = false; 
  bool timerOn     = false; 

//Alarms Setting
  bool alarm1State  = false;
  bool alarm2State  = false;
  bool alarm3State  = false;
  bool alarm4State  = false;
  bool alarm5State  = false;
  bool alarm6State  = false;
  bool alarm7State  = false;
  bool alarm8State  = false;
  bool alarm9State  = false;
  bool alarm10State = false;
  int  alarmBeingCalibrated = 0;

//Alarm Calibration
  bool repState = false;
  bool alarmTypeNameState = false;
  bool alarmDayState = false;
  bool alarmWeekDayState = false;
  bool HourMinState = false;
  bool alarmHourState = false;
  bool alarmMinuteState = false;
  bool durationState = false;
  bool alarmHourDurationState = false;
  bool alarmMinuteDurationState = false;
  bool valveState = false;
  bool alarmValveState = false;
  bool alarmYesState = false;
  bool alarmNoState = false;
  int  alarmTry = 0;
  bool okState = false;

//Menu
  int MenuState = 0;  // 0  = HOME                      || 1  = CLOCK SETTINGS            || 2  = SAVE QUESTION FOR CLOCK AND CALLENDAR
                      // 3  = MAIN MENU                 || 4  = MANUAL TIMER MENU         || 5  = TIMER CALIBRATION
                      // 6  = TIMER TESTING             || 7  = ALARMS 1-4                || 8  = ALARMS 2-5
                      // 9  = ALARMS 3-6                || 10 = ALARMS 4-7                || 11 = ALARMS 5-8
                      // 12 = ALARMS 6-9                || 13 = ALARMS 7-10               || 14 = ALARM CALIBRATION PART 1
                      // 15 = ALARM CALIBRATION PART 2  || 16 = ALARM CALIBRATION PART 3  || 17 = SAVE QUESTION FOR ALARMS
                      // 18 = CHECK IF ALARM IS ON(OK)

class Alarm {
  public:
//    Alarm (int wd, int h, int m, int s, int v, int d):
//      weekDay(wd), Hour(h), Minute(m), Second(s), valve(v), duration(d){}

    int getWeekDay(){
      return weekDay;
    }

    int getHour(){
      return Hour;
    }

    int getMinute(){
      return Minute;
    }

    int getValve(){
      return valve;
    }

    int getAlarmType(){
      return alarmType;
    }

    bool enabled(){
      return ENABLED;
    } 

    unsigned long getTimer(){
      return timer;
    }

    unsigned long getDuration(){
      return duration/1000;
    }

    bool ON(){
      return ONOFF;
    }

    void setAlarm(int wd, int h, int m, int v, unsigned long d, int t){
      weekDay = wd;
      Hour = h;
      Minute = m;
      valve = v;
      duration = d * 1000;
      alarmType = t;
    }

    void updateTimer(){
      timer = (millis() - startingMillis)/1000;
    }

    void turnON(){
      resetTimers();
      startingMillis = millis();
      ONOFF = true;
      digitalWrite(valve, HIGH);
    }

    void turnOFF(){
      resetTimers();
      ONOFF = false;
      digitalWrite(valve, LOW);
    }

    void changeAlarmType(int t){
      alarmType = t;
    }

    void setEnabled(bool e){
      ENABLED = e;
    }
  
  private:
    unsigned long duration = 0;
    int weekDay = 1;
    int Hour = 0;
    int Minute = 0;
    int valve = 1;

    unsigned long startingMillis = 0;
    unsigned long timer = 0;

    bool ONOFF = false;
    bool ENABLED = false;

    int alarmType = 0; // 0 = ONCE A WEEK(DAY)  || 1 = EVERYDAY  || 2 = EVERY 2ND DAY  || 3 = EVERY 3RD DAY

    void resetTimers(){
      timer = 0;
      startingMillis = 0;
    }
        
};

class Scheduler {
  public:
  
    Alarm getAlarm (int i){
      return alarms[i];
    }

    void enable (int a){
      alarms[a].setEnabled(true);
    }

    void disable (int a){
      alarms[a].setEnabled(false);
    }

    void addAlarm (int wd, int h, int m, int v, unsigned long d, int alarm, int alarmType){
      alarms[alarm].setAlarm(wd, h, m, v, d, alarmType);
    }
    
    void checkAlarms(){
      updateTimers();
      t = rtc.getTime();
      for (int i = 0; i < 10; i++){
        if (alarms[i].enabled()){
          if (!alarms[i].ON()){
            if (t.dow  == alarms[i].getWeekDay() and
                t.hour == alarms[i].getHour()    and
                t.min  == alarms[i].getMinute()){
                  alarms[i].turnON(); 
            }
          }
          else{
            if (alarms[i].getTimer() == alarms[i].getDuration()){
              alarms[i].turnOFF();
            }
          }
        }
      }
    }

  private:
    Alarm alarms[10];

    void updateTimers (){
      for (int i = 0; i < 10; i++){
        if (alarms[i].ON()){
          alarms[i].updateTimer();
        }
      }
    }
    
};

Scheduler scheduler;

Alarm tempAlarm;
int tempAlarmHourDuration = 0;
int tempAlarmMinuteDuration = 0;
int tempWeekDay = 0;
int tempAlarmHour = 0;
int tempAlarmMinute = 0;
int tempAlarmValve = 0;

void copyAlarm(int a){
  tempAlarm.setAlarm((scheduler.getAlarm(a)).getWeekDay(), (scheduler.getAlarm(a)).getHour(), (scheduler.getAlarm(a)).getMinute(), (scheduler.getAlarm(a)).getValve(), (scheduler.getAlarm(a)).getDuration(), (scheduler.getAlarm(a)).getAlarmType());
  tempAlarm.changeAlarmType((scheduler.getAlarm(a)).getAlarmType());
  //tempAlarm.setEnabled((scheduler.getAlarm(a)).enabled());
  tempAlarmHourDuration = (int)((((scheduler.getAlarm(a)).getDuration())/60)/60);
  tempAlarmMinuteDuration = (int)(((scheduler.getAlarm(a)).getDuration())/60) - (((int)((((scheduler.getAlarm(a)).getDuration())/60)/60)) * 60);
  tempWeekDay = tempAlarm.getWeekDay();
  tempAlarmHour = tempAlarm.getHour();
  tempAlarmMinute = tempAlarm.getMinute();
  int Valve = 1;
  switch (tempAlarm.getValve()){
    case 10: Valve = 1; break;
    case 11: Valve = 2; break;
    case 12: Valve = 3; break;
    case 13: Valve = 4; break;
    case 15: Valve = 5; break;
  }
  tempAlarmValve = Valve;
}
                     
void setup() {

  pinMode(LED5, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(TIMERLED, OUTPUT);
  pinMode(8, OUTPUT);
  lcd.begin(20,4);
  lcd.createChar(3, upArrow);
  lcd.createChar(4, downArrow);
  rtc.begin();
  lcd.clear();
  finalTime = EEPROM.read(0);
  readEEPROM();
  
  Serial.begin(9600);

}

void loop() {

  checkTimer();
  scheduler.checkAlarms();
  checkButtons();
  checkSleepMode();
  menuDisplay();

  //Serial.println(millis());

//  Serial.print("Alarm 1: ");
//  Serial.println(scheduler.getAlarm(0).getTimer());
//  Serial.print("Alarm 2: ");
//  Serial.println(scheduler.getAlarm(1).getTimer());
   
}
