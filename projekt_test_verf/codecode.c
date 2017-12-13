int GREEN_LED=13,RED_LED=12;
int larm_status=0,thief_detected=0;
void setup() {
  Serial.begin(9600);
  // WILL BE USED INSTEAD OF SENSOR
  pinMode(2, INPUT_PULLUP);

  // WILL BE USED INSTEAD OF USING CODE TO TURN ON OR OFF THE ALARM. (THIS IS THE CORRECT CODE)
  pinMode(3, INPUT_PULLUP);

  // WILL BE USED INSTEAD OF USING CODE TO TURN ON OR OFF THE ALARM. (THIS IS WRONG CODE)
  pinMode(4, INPUT_PULLUP);

  // WILL BE GREEN IF THE ALARM IS ON, BLINK 5 TIMES IF THE CODE IS WRONG
  pinMode(GREEN_LED, OUTPUT);

  // WILL BLINK IF SOMEONE/SOMETHING IS IN THE HOUSE WITHOUT TURNING THE ALARM OFF.
  pinMode(RED_LED, OUTPUT);
}

/**
 * [blink_light description]
 * function to blink x-output y-times.
 * @param light [will use this port to toggle high and low]
 * @param num   [how many times this will be repeated]
 */
void blink_light(int light,int num) {
  for(;num>0;num--) {
    digitalWrite(light,HIGH);
    delay(100);
    digitalWrite(light,LOW);
    delay(100);
  }
}

/**
 * [check_code description]
 * function to compare 2 codes with each other
 * if they match it will invert larm_status
 * @param correct_code [this input should be the correct code for the larm]
 * @param compare_code [this input is the code entered with the numpad]
 * @param larm_status  [a pointer to larm_status so it can be toggled]
 */
void check_code(int *correct_code, int *compare_code, int *larm_status) {
  int i=0;
  for(;*correct_code==*compare_code;i++,*correct_code++,*compare_code++) {  }
  if(i==4) {
    *larm_status=!*larm_status;
    thief_detected=0;
  } else {
    blink_light(GREEN_LED,10);
  }
  delay(500);
}

/**
 * [larm_triggered description]
 * this function is used when sensor is triggered and the larm is on]
 */
void larm_triggered() {
  digitalWrite(GREEN_LED,LOW);
  thief_detected=1;
}
void loop() {
  int larm_code[4]={1,3,3,7};
  int right_code[4]={1,3,3,7};
  int wrong_code[4]={5,4,1,7};
  // WILL SET THE LARM OFF. INSTEAD OF USING SENSOR
  if(!(digitalRead(2)) && larm_status) {
    larm_triggered();
    Serial.println("SENSOR ACTIVATED");
  }
  if(!(digitalRead(3))) {
    check_code(larm_code,right_code,&larm_status);
    Serial.println("CODE: 1337");
  }
  if(!(digitalRead(4))) {
    check_code(larm_code,wrong_code,&larm_status);
    Serial.println("CODE: 5417");
  }
  if(!(thief_detected)) {
    if(larm_status) {
      digitalWrite(GREEN_LED,HIGH);
    }
    else if (!(larm_status))  {
      digitalWrite(GREEN_LED,LOW);
    }
  }
  else {
    Serial.println("THIEF DETECTED");
    blink_light(RED_LED,1);
  }
  delay(10);
}
