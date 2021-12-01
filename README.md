## Irrigation Control System

An autonomous irrigation control system on Arduino with an 4x20 LCD screen, real time clock, custom resistor button controller and custom menu with blinking items when selected. It’s fully programmable from the user and completely expandable.

<img src="images/circuit.png">

In this Demo the valves are simulated with led's. In an actual system instead of led's you would have relay's, and external power, powering actual valves.

### Points of interest

* You can navigate the menu with a six button controller (Up, Down, Right, Left, Enter, Back). The exciting part is that only 1 GPIO pin is used. The circuit is shown above.

* The selected item in the menu (where the cursor is) is indicated with blinking of the item. This is achieved with the function Blinkable in [Blinking.ino](source/irrigation_control_system/Blinking.ino). This function either displays a string on the screen constantly or (if it's state parameter is true) the string blinks with a constant interval.

* Whenever an alarm is created by the user, the key information is saved to the EEPROM. In case of power outage or a force reset of the system, the saved alarms are automatically restored.

* The user can set the local time to the clock through an awesome menu.

* There is also a power save feature. Whenever the screen is inactive (when there is no input from the buttons) for more than 30 seconds, the lcd backlight is turned of.

* You can navigate the menu and make changes to alarms or other settings while an alarm is active.

* You can adjust the contrast of the screen through the potentiometer.
