
void updateEEPROM (int i){
  
  EEPROM.write(( (i + 1) * 10), scheduler.getAlarm(i).enabled());
  EEPROM.write((((i + 1) * 10) + 1), scheduler.getAlarm(i).getHour());
  EEPROM.write((((i + 1) * 10) + 2), scheduler.getAlarm(i).getMinute());
  EEPROM.write((((i + 1) * 10) + 3), scheduler.getAlarm(i).getValve());
  EEPROM.write((((i + 1) * 10) + 4), scheduler.getAlarm(i).getWeekDay());
  EEPROM.write((((i + 1) * 10) + 5), scheduler.getAlarm(i).getAlarmType());
  EEPROM.write((((i + 1) * 10) + 6), (int)((((scheduler.getAlarm(i).getDuration())/60))/60));
  EEPROM.write((((i + 1) * 10) + 7), (int)(((scheduler.getAlarm(i).getDuration())/60)) - (((int)((((scheduler.getAlarm(i).getDuration())/60))/60)) * 60));
  
}

void readEEPROM(){
  
  for (int i = 0; i < 10; i++){
    if (bool a = EEPROM.read(((i + 1) * 10))){
      scheduler.addAlarm(EEPROM.read((((i + 1) * 10) + 4)), EEPROM.read((((i + 1) * 10) + 1)), EEPROM.read((((i + 1) * 10) + 2)), EEPROM.read((((i + 1) * 10) + 3)),
                         (((EEPROM.read((((i + 1) * 10) + 6))) * 60) * 60) + ((EEPROM.read((((i + 1) * 10) + 7))) * 60), i, EEPROM.read((((i + 1) * 10) + 5)));
      scheduler.enable(i);                   
    }
  }
  
}
