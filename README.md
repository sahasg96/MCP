# MCP
Micro-Controller Project Lab


##Display Library

This library contains all the generic functions for showing an output and clearing the display and counter.

###delay(time)
Takes an int input, and cretaes a delay.

###ResetCounter()
Resets the IC4017 decade counter.

###CLK()
Generates a pulse that triggers the IC 4017 decade counter.

###ClearDisplay()
Cleares the display, makes it blank.

###displayfunction(byte data[])
Takes an array input of the data to be displayed and dislpays it on Port0.

##Ports

ClockPin = P3.7

ResetPin = P3.6

LedOutput = P0

##UpdateCoordinate Library

This Library contains functions to manipulate the bits of the x,y 2D array.
Top left corner is (0,0) and bottom right corner is (8,10).

###UpdateBit( byte coord[][], int x, int y, int value =1)
Can update a single bit, its location defined by the x, y input.

###UpdateRow( byte coord[][],  int y, int value =1)
Can update a single row, its location defined by the y input.

###UpdateColoumn( byte coord[][],  int x, int value =1)
Can update a single Coloumn, its location defined by the x input.

###ClearData(byte coord[][])
Resets all frame data to 0.

##CoordinateToByte Library

###c2b(byte coord[][], int row)
Converts a single row of the coord 2D array to a byte and returns it.

###c2b_all(byte coord[][], byte databyte[])
Converts all the rows and modifies the value of the byte data array.
