#include<stdio.h>
#include<graphics.h>
int X,Y;
void putPixel(int x,int y,int c)
{
    putpixel(x+X/2,-y+Y/2,c);
}
void circleSymmetry(int cx,int cy,int x,int y,int c)
{
    putPixel(x+cx,y+cy,c);
    putPixel(x+cx,-y+cy,c);
    putPixel(-x+cx,y+cy,c);
    putPixel(-x+cx,-y+cy,c);
    putPixel(y+cx,x+cy,c);
    putPixel(y+cx,-x+cy,c);
    putPixel(-y+cx,x+cy,c);
    putPixel(-y+cx,-x+cy,c);
}
void mCircle(int cx,int cy,int r,int c)
{
    int x=0,y=r;
    int d=1-r;
    int dele=3;
    int delse=5-2*r;
    circleSymmetry(cx,cy,x,y,c);
    while(x<=y)
    {
        if(d<0)
        {
            d+=dele;
            dele+=2;
            delse+=2;
        }
        else{
             d+=delse;
            dele+=2;
            delse+=4;
            y--;
        }
        x++;
        circleSymmetry(cx,cy,x,y,c);
    }
}
int main()
{
    int gd = DETECT, gm =0 ;
  initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();

   /*
   int y1=-100;
   for(int i=0;i<3;i++)
   {
      mCircle(0,y1,50,15);
      y1+=100;
   }
   int y2=-50;
     for(int i=0;i<2;i++)
   {
      mCircle(0,y2,100,15);
      y2+=100;
   }
   int x1=-119.3;
   for(int i=0;i<2;i++)
   {
      mCircle(x1,0,30.7,15);
      x1+=119.3*2;
   }
   mCircle(0,0,150,15);

  */
  float theeta =90*3.14/180;
  while(true)
  {

   mCircle(0,0,50,15);
   mCircle(100*cos(theeta),100*sin(theeta),50,15);
   mCircle(-100*cos(theeta ),100*sin(-theeta ),50,15);
   mCircle(100*cos(theeta )/2,100*sin(theeta )/2,100,15);
   mCircle(-100*cos(theeta )/2,100*sin(-theeta )/2,100,15);
   mCircle(-119.3*cos(theeta-3.14/2),-119.3*sin(theeta-3.14/2 ),30.7,15);
   mCircle(-119.3*cos(theeta+3.14/2),-119.3*sin(theeta+3.14/2 ),30.7,15);
   mCircle(0,0,150,15);

   delay(1000);

   mCircle(100*cos(theeta),100*sin(theeta),50,0);
   mCircle(-100*cos(theeta ),100*sin(-theeta ),50,0);
   mCircle(100*cos(theeta )/2,100*sin(theeta )/2,100,0);
   mCircle(-100*cos(theeta )/2,100*sin(-theeta )/2,100,0);
   mCircle(-119.3*cos(theeta-3.14/2),-119.3*sin(theeta-3.14/2 ),30.7,0);
   mCircle(-119.3*cos(theeta+3.14/2 ),-119.3*sin(theeta+3.14/2 ),30.7,0);
   mCircle(0,0,150,15);
   theeta+=0.1;
  }

   getch();
   closegraph();
   return(0);
}
