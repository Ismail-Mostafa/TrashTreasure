#include <glcd.h>
#include "fonts/allFonts.h"         
#include "bitmaps/besm.h"
#include "bitmaps/allah.h"
#include "bitmaps/glcd.h"
void setup()
{
  GLCD.Init();
  GLCD.DrawBitmap(besm, 0,  0);
 delay(1000);
 GLCD.DrawBitmap(allah, 0,  0);
  delay(1000);
 GLCD.DrawBitmap(glcd, 0,  0);
 
}
void loop()
{
}
