# MCP
Micro-Controller Project Lab

##InputLibrary
Inputs are taken as an interrupt. The pins are P3.7 to P3.4.

###UpdateInput()
When an interrupt occurs, the bit data variables for UP,DOWN,RIGHT,LEFT are assigned to the value at the pins.
The InputFlag is set to 1. The data variables will not be updated irrespective of the changes at the pins until the InputFlag is cleared.


##Display Library

This library contains all the generic functions for showing an output and clearing the display and counter.

###delay(time)
Takes an int input, and Creates a delay.

###ResetCounter()
Resets the IC4017 decade counter.

###ClearDisplay()
Cleares the display, makes it blank.

###c2b_all(byte coord[], byte databyte[])
Converts all the rows and modifies the value of the byte data array.

##Ports

ClockPin = P2.7

ResetPin = P2.6

LedOutput = P0

External Input interrupt = P3.3

##UpdateCoordinate Library

This Library contains functions to manipulate the bits of the x,y 2D array.
Top left corner is (0,0) and bottom right corner is (8,10).

###UpdateBit(int x, int y, bit value)
Can update a single bit, its location defined by the x, y input.

###UpdateRow(int y, bit value)
Can update a single row, its location defined by the y input.

###UpdateColoumn(int x, bit value)
Can update a single Coloumn, its location defined by the x input.

###ClearData()
Resets all frame data to 0.

###UpdateBorder(bit value)
Creates a border, value switches it on or off.
