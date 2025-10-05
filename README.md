# MiniBot Outreach

## Setup

Clone the repository, then open it with the Arduino IDE. Write the intended commands in `Code.h` then deploy to the bot.

Remember, it's necessary to configure the Arduino IDE to use the old bootloader.

## List of Commands

All times are in seconds.

```cpp
void DelaySeconds(float time);

bool ButtonPressed(void);

void InitializeRover(void);

void Forward(float time);

void Backward(float time);

// Use LEFT or RIGHT for the dir
void Spin(bool dir, float time);

void Stop(void);
```
