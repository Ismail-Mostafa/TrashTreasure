/*
  GLCD Library - Hello World
 
 This sketch prints "Hello World!" to the LCD
 and shows the time in seconds since reset.
 
  The circuit:
  See the inlcuded documentation in glcd/doc directory for how to wire
  up the glcd module. glcd/doc/GLCDref.htm can be viewed in your browser
  by clicking on the file.
 
 */

// include the library header
#include <glcd.h>

// include the Fonts
#include <fonts/allFonts.h>

void setup() {
  // Initialize the GLCD 
  GLCD.Init();

 // Select the font for the default text area
  GLCD.SelectFont(System5x7);

  GLCD.print("hello, world!");
}

void loop() {

}
