#include "RoverFunctions.hpp"

void setup() {
  // put your setup code here, to run once:
  InitializeRover();
}
void loop() {
  // put your main code here, to run repeatedly:
  if(ButtonPressed()){
    DelaySeconds(1);
    #include "Code.h"
    Stop();
  }

}
