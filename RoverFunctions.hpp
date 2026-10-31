#ifndef __ROVER_FUNCTIONS_H_
#define __ROVER_FUNCTIONS_H_

#include "Arduino.h"

#define MAX_DELAY 5

#define BUTTON 12

#define LEFT false
#define RIGHT true
#define left false
#define right true

#define FORWARD LOW
#define BACKWARD !FORWARD

void DelaySeconds(float time);

bool ButtonPressed(void);

void InitializeRover(void);

void Forward(float time);
void forward(float time);

void Backward(float time);
void backward(float time);

void Spin(bool dir, float time);
void spin(bool dir, float time);

void Stop(void);
void stop(void);

#endif