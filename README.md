# MCP
Micro-Controller Project Lab


##Display Library

This library contains all the generic functions for showing an output and clearing the display and counter.

#delay(time)
Takes an int input, and cretaes a delay.

#ResetCounter()
Resets the IC4017 decade counter.

#CLK()
Generates a pulse that triggers the IC 4017 decade counter.

#ClearDisplay()
Cleares the display, makes it blank.

#displayfunction(byte dataa[])
Takes an array input of the data to be displayed and dislpays it on Port0.

##Ports

ClockPin = P3.7

ResetPin = P3.6

LedOutput = P0



