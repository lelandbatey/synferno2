/**
This class abstracts control of a group of buttons.
Provide an array of button pins and then call update() to be notified of a new press.
When the `toggle` flag is true, pressing a selected button will deselect it,
whereas if the flag is false a repress will cause no state change.
*/
#ifndef ButtonGroup_h
#define ButtonGroup_h

#define BRIGHTNESS_DIM_WHITE 10
#define BRIGHTNESS_BRIGHT_WHITE 205

#include <Arduino.h>
#include <Bounce2.h>
#include <Metro.h>

class ButtonGroup{
  public:
    void begin(byte numPins, byte button_pins[], byte led_pins[], boolean toggle=true);

    boolean update();

    byte getValue();

    boolean hasSelection();
    
  private:
    byte numPins, toggle, currentSelected=255;
    byte* led_pins;
    Bounce* buttons;

    void writeLEDs();
};

#endif
