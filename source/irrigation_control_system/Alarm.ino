
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

    int getSecond(){
      return Second;
    }

    int getValve(){
      return valve;
    }

    int getTimer(){
      return timer;
    }

    int getDuration(){
      return duration;
    }

    bool ON(){
      return ONOFF;
    }

    void setAlarm(int wd, int h, int m, int s, int v, int d){
      weekDay = wd;
      Hour = h;
      Minute = m;
      Second = s;
      valve = v;
      duration = d;
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
  
  private:
    int duration = 0;
    int weekDay = 0;
    int Hour = 0;
    int Minute = 0;
    int Second = 0;
    int valve = 0;

    int startingMillis = 0;
    int timer = 0;

    bool ONOFF = false;

    void resetTimers(){
      timer = 0;
      startingMillis = 0;
    }
        
};
