int GREEN_LED = 13;
int RED_LED = 12;
int larm_status=0;
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

// THIS FUNCTION IS GOING TO COMPARE THE 2 CODES IT WILL GET FROM INPUT.
// IF THEY ARE THE SAME IT WILL INVERT THE larm_status.
void check_code(int *correct_code, int *compare_code, int *larm_status) {
  int i=0;
  for(;*correct_code==*compare_code;i++,*correct_code++,*compare_code++) {  }
  if(i==4) {
    *larm_status=!*larm_status;
    delay(1);
  } else {
    int ix=0;
    for(;ix<10;ix++) {
      digitalWrite(GREEN_LED,HIGH);
      delay(100);
      digitalWrite(GREEN_LED,LOW);
      delay(100);
    }
  }
}

void loop() {
  int larm_code[4]={1,3,3,7};
  int right_code[4]={1,3,3,7};
  int wrong_code[4]={5,4,1,7};
  if(!(digitalRead(3))) {
    check_code(larm_code,right_code,&larm_status);
  }
  if(!(digitalRead(4))) {
    check_code(larm_code,wrong_code,&larm_status);
  }
  if(larm_status) {
    digitalWrite(GREEN_LED,HIGH);
  }
  else if (!(larm_status))  {
    digitalWrite(GREEN_LED,LOW);
  }
}
