
class Scheduler {
  public:
    Alarm getAlarm (int i){
      return alarms[i];
    }

    void addAlarm (int wd, int h, int m, int s, int v, int d){
      alarms[addIndex].setAlarm(wd, h, m, s, v, d);
      addIndex++;
      numberOfAlarms++;
    }
    
    void checkAlarms(){
      updateTimers();
      t = rtc.getTime();
      for (int i = 0; i < numberOfAlarms; i++){
        if (!alarms[i].ON()){
          if (t.dow  == alarms[i].getWeekDay() and
              t.hour == alarms[i].getHour()    and
              t.min  == alarms[i].getMinute()  and
              t.sec  == alarms[i].getSecond()){
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

  private:
    int addIndex = 0;
    int numberOfAlarms = 0;
    Alarm alarms[100];

    void updateTimers (){
      for (int i = 0; i < numberOfAlarms; i++){
        alarms[i].updateTimer();
      }
    }
    
};
