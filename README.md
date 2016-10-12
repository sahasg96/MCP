# MCP
Micro-Controller Project Lab


##Display Library

This library contains all the generic functions for showing an output and clearing the display and counter.

###delay(time)
Takes an int input, and cretaes a delay.

###ResetCounter()
Resets the IC4017 decade counter.

###ClearDisplay()
Cleares the display, makes it blank.

###c2b_all(byte coord[], byte databyte[])
Converts all the rows and modifies the value of the byte data array.

##Ports

ClockPin = P3.7

ResetPin = P3.6

LedOutput = P0

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
