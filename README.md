# MiniBot Outreach

## Setup

You will need the Arduino IDE to upload the program. It's available for [Windows](https://apps.microsoft.com/detail/xpddtbj80f8pc9?hl=en-US&gl=US), [Mac](https://www.arduino.cc/en/software/), and [Linux](https://flathub.org/apps/cc.arduino.IDE2/flatpakhttps).

Download the repository by clicking the green "<> Code" button at the top of the page and selecting Download ZIP, then extracting the ZIP file. Then open `Minibot.ino` with the Arduino IDE.

It's necessary to configure the Arduino IDE to use the ATMEGA328P board. Click on the Board Manager tab, search for ATMEGA328P, and install the package.

To program the bot to move around, write the intended commands in the `Code.h` tab, then upload to the bot.

If you are on Linux, you will need to have `avrdude` installed at the system level in order for udev to allow access to upload code to the bot.

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
