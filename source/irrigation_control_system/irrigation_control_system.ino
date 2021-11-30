#include <LiquidCrystal.h>
#include <DS3231.h>
#include <EEPROM.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
DS3231 rtc(SDA, SCL);
Time t;

 // Scheduler scheduler;
 
//Clock and Callendar Settings
  int  Year = 0;
  bool YearState = false;
  int  Month = 0;
  bool MonthState = false;
  int  MonthDay = 0;
  bool MonthDayState = false;
  int  Day = 0;
  bool DayState = false;
  int  Hours = 0;
  bool HoursState = false;
  int  Minutes = 0;
  bool MinutesState = false;
  int  Seconds = 0;
  bool SecondsState = false;

  int  ClockAndCallendarState = 0;
  bool DateSetting = false;
  bool DaySetting = false;
  bool TimeSetting = false;

  bool YesState = false;
  bool NoState = false;

//Constants
  String Days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  String Months[12] = {"January",  "February" , "March", "April" , "May", "June", "July", "August", "September", "October", "November", "December"};
  const int LED1 = 9;
  const int LED2 = 10;
  

//Blinking
  bool WRITE = false;
  bool WRITE1 = false;
  bool WRITE2 = false;
  unsigned long previousMillis = 0;
  unsigned long previousMillis1 = 0;
  unsigned long previousMillis2 = 0;
  int interval = 200;

//Buttons
  int  resistorValue = 0;
  bool buttonPressed = false;
  int  buttonNumber = 0; // 1 = UP || 2 = RIGHT || 3 = DOWN || 4 = LEFT || 5 = ENTER || 6 = ESC/RESET
  bool actionDone = true;

//SleepMode
  int sleepWait = 30 * 1000;
  unsigned long previousMillis3 = 0;
  bool sleepMode = false;

//Main Menu
  bool dateTimeSettingState = false;
  bool alarmSettingState = false;
  bool manualTimerSettingState = false; 
  bool calibrateTimerSettingState = false;
  bool testTimerSettingState = false; 

//Timer Calibration
  unsigned long previousMillis4 = 0;
  bool startState = false;
  bool stopState = false;
  bool resetState = false;
  int tempTime = 0; 
  int tempTime2 = 0;
  int finalTime = 0;
  int timerState = 0;

//Timer Test 
  unsigned long previousMillis5 = 0;
  int timer = 0;
  bool start2State = false; 
  bool timerOn = false; 

//Menu
  int MenuState = 0; // 0 = HOME             || 1 = CLOCK SETTINGS       || 2 = SAVE QUESTION FOR CLOCK AND CALLENDAR
                     // 3 = MAIN MENU        || 4 = MANUAL TIMER MENU    || 5 = TIMER CALIBRATION
                     // 6 = TIMER TESTING
                     
void setup() {

  pinMode(LED1, OUTPUT);
  pinMode(8, OUTPUT);
  lcd.begin(20,4);
  rtc.begin();
  lcd.clear();
  finalTime = EEPROM.read(0);
  //scheduler.addAlarm(7, 20, 3, 0, LED1, 1);

  //Serial.begin(9600);

}

void loop() {

  checkTimer();
  checkButtons();
  checkSleepMode();
  menuDisplay();

  //Serial.println(millis());
   
}
