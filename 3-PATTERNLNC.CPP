#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>  //graphics.h is used to include graphical operater in a program.
#include <dos.h>

void DDALine(int x1, int y1, int x2, int y2, int color); // declare function

int main()
{
  int x1, y1, x2, y2, r, r1, Color;
  int gd, gm,errorcode;
  gd = DETECT,gm,errorcode; // initialize the varialble for the graphics mode
  // gm is graphic mode which is a computer display mode that genetates image using pixle
  // DETECT is a micro defined in "graphic.h" header file
  initgraph(&gd, &gm, "C:/TURBOC3/BGI"); // initgraph initialize the graphics system by loading a graphics driver from disk

  cleardevice();                  // the header file graphics.h contains cleardevice() function which clear the screem in graphics mode and set the current position to (0,0)
				  // call the functions
  DDALine(100, 113, 50, 200, 10); // x1,y1,x2,y2,color
  DDALine(50, 200, 150, 200, 10);
  DDALine(150, 200, 100, 113, 10);

  r = 50 / sqrt(3); // formulae to find out radius of small circle
  x1 = (100 + 50 + 150) / 3;
  y1 = (113 + 200 + 200) / 3;

  circle(x1, y1, r); // draw small circle

  r1 = 100 / sqrt(3);
  circle(x1, y1, r1); // draw outer circle
  delay(1000);       // delay() function is used to hold execution of program

  return 0;
}

void DDALine(int x1, int y1, int x2, int y2, int Color)
{
  float dX, dY, Steps;
  float xinc, yinc, i, x, y;

  dX = x2 - x1;
  dY = y2 - y1;

  if (abs(dX) > abs(dY))
  {

    Steps = abs(dX);
  }
  else
  {
    Steps = abs(dY);
  }
  xinc = dX / Steps;
  yinc = dY / Steps;

  x = x1;
  y = y1;

  for (i = 1; i <= Steps; i++)
  {
    putpixel(x, y, Color);
    x = x + xinc;
    y = y + yinc;
  }
getch();
}
