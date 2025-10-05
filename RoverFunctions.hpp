#ifndef __ROVER_FUNCTIONS_H_
#define __ROVER_FUNCTIONS_H_

#include "Arduino.h"

#define MAX_DELAY 5

#define BUTTON 12

#define LEFT false
#define RIGHT true

#define FORWARD LOW
#define BACKWARD !FORWARD

void DelaySeconds(float time);

bool ButtonPressed(void);

void InitializeRover(void);

void Forward(float time);

void Backward(float time);

void Spin(bool dir, float time);

void Stop(void);

#endif