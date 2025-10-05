#include "RoverFunctions.hpp"

#define MOTOR1B_PWM_PIN 11
#define MOTOR1B_PHASE_PIN 8
#define MOTOR1A_PWM_PIN 10
#define MOTOR1A_PHASE_PIN 7
#define MOTOR1_MODE_PIN 5

#define MOTOR2B_PWM_PIN 9
#define MOTOR2B_PHASE_PIN 4
#define MOTOR2A_PWM_PIN 6
#define MOTOR2A_PHASE_PIN 3
#define MOTOR2_MODE_PIN 2

#define DEFAULT_SPEED 220
#define DEFAULT_SPEED_SLOW 210

int motor1BSpeed = 0;
int motor1ASpeed = 0;
int motor2BSpeed = 0;
int motor2ASpeed = 0;

static inline bool ReachTarget(int* current, int target){
  bool ret = false;
  if(*current < target){
    (*current)++;
    ret = true;
  }
  else if (*current > target){
    (*current)--;
    ret = true;
  }

  return ret;
}

void DelaySeconds(float time){
  if(time < 0) time = -1*time;
  if(time>MAX_DELAY) time = MAX_DELAY;
  delay(time*1000);
}

bool ButtonPressed(void){
  if(digitalRead(BUTTON)){
    return false;
  } else {
    return true;
  }
}

static void SetSpeeds(int M1BTarget,int M1ATarget,int M2BTarget,int M2ATarget){
  int expirationCnt = 0;
  bool refresh = true;
  while(refresh && (expirationCnt<255)){
    refresh = false;
    if(ReachTarget(&motor1BSpeed,M1BTarget)){
      analogWrite(MOTOR1B_PWM_PIN, motor1BSpeed);
      refresh = true;
    }
    if(ReachTarget(&motor1ASpeed,M1ATarget)){
      analogWrite(MOTOR1A_PWM_PIN, motor1ASpeed);
      refresh = true;
    }
    if(ReachTarget(&motor2BSpeed,M2BTarget)){
      analogWrite(MOTOR2B_PWM_PIN, motor2BSpeed);
      refresh = true;
    }
    if(ReachTarget(&motor2ASpeed,M2ATarget)){
      analogWrite(MOTOR2A_PWM_PIN, motor2ASpeed);
      refresh = true;
    }
    delay(2);
    expirationCnt++;
  }
}

void Stop(void){
  SetSpeeds(0,0,0,0);
  /*analogWrite(MOTOR1B_PWM_PIN, 0);
  analogWrite(MOTOR1A_PWM_PIN, 0);
  analogWrite(MOTOR2B_PWM_PIN, 0);
  analogWrite(MOTOR2A_PWM_PIN, 0);*/
}

void Forward(float time){
  digitalWrite(MOTOR1B_PHASE_PIN, FORWARD);
  digitalWrite(MOTOR1A_PHASE_PIN, FORWARD);
  digitalWrite(MOTOR2B_PHASE_PIN, FORWARD);
  digitalWrite(MOTOR2A_PHASE_PIN, FORWARD);
  SetSpeeds(DEFAULT_SPEED,DEFAULT_SPEED,DEFAULT_SPEED,DEFAULT_SPEED);
  /*analogWrite(MOTOR1B_PWM_PIN, DEFAULT_SPEED);
  analogWrite(MOTOR1A_PWM_PIN, DEFAULT_SPEED);
  analogWrite(MOTOR2B_PWM_PIN, DEFAULT_SPEED);
  analogWrite(MOTOR2A_PWM_PIN, DEFAULT_SPEED);*/
  DelaySeconds(time);
  Stop();
}

void Backward(float time){
  digitalWrite(MOTOR1B_PHASE_PIN, BACKWARD);
  digitalWrite(MOTOR1A_PHASE_PIN, BACKWARD);
  digitalWrite(MOTOR2B_PHASE_PIN, BACKWARD);
  digitalWrite(MOTOR2A_PHASE_PIN, BACKWARD);
  SetSpeeds(DEFAULT_SPEED,DEFAULT_SPEED,DEFAULT_SPEED,DEFAULT_SPEED);
  /*analogWrite(MOTOR1B_PWM_PIN, DEFAULT_SPEED);
  analogWrite(MOTOR1A_PWM_PIN, DEFAULT_SPEED);
  analogWrite(MOTOR2B_PWM_PIN, DEFAULT_SPEED);
  analogWrite(MOTOR2A_PWM_PIN, DEFAULT_SPEED);*/
  DelaySeconds(time);
  Stop();
}



void Spin(bool dir, float time){
  digitalWrite(MOTOR1B_PHASE_PIN, dir);
  digitalWrite(MOTOR1A_PHASE_PIN, !dir);
  digitalWrite(MOTOR2B_PHASE_PIN, dir);
  digitalWrite(MOTOR2A_PHASE_PIN, !dir);
  SetSpeeds(DEFAULT_SPEED,DEFAULT_SPEED,DEFAULT_SPEED,DEFAULT_SPEED);
  /*analogWrite(MOTOR1B_PWM_PIN, DEFAULT_SPEED);
  analogWrite(MOTOR1A_PWM_PIN, DEFAULT_SPEED);
  analogWrite(MOTOR2B_PWM_PIN, DEFAULT_SPEED);
  analogWrite(MOTOR2A_PWM_PIN, DEFAULT_SPEED);*/
  DelaySeconds(time);
  Stop();
}

void InitializeRover(void){
  pinMode(MOTOR1B_PWM_PIN, OUTPUT);
  pinMode(MOTOR1B_PHASE_PIN, OUTPUT);
  pinMode(MOTOR1A_PWM_PIN, OUTPUT);
  pinMode(MOTOR1A_PHASE_PIN, OUTPUT);
  pinMode(MOTOR1_MODE_PIN, OUTPUT);

  pinMode(MOTOR2B_PWM_PIN, OUTPUT);
  pinMode(MOTOR2B_PHASE_PIN, OUTPUT);
  pinMode(MOTOR2A_PWM_PIN, OUTPUT);
  pinMode(MOTOR2A_PHASE_PIN, OUTPUT);
  pinMode(MOTOR2_MODE_PIN, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

  digitalWrite(MOTOR1_MODE_PIN, HIGH);
  digitalWrite(MOTOR1B_PHASE_PIN, HIGH);
  digitalWrite(MOTOR1A_PHASE_PIN, HIGH);

  digitalWrite(MOTOR2_MODE_PIN, HIGH);
  digitalWrite(MOTOR2B_PHASE_PIN, HIGH);
  digitalWrite(MOTOR2A_PHASE_PIN, HIGH);
}