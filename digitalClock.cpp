#include<stdio.h>
#include<graphics.h>
#include<time.h>
int X,Y;
void putPixel(int x,int y,int c)
{
    putpixel(x+X/2,-y+Y/2,c);
}
void octetOne(int x1,int y1,int x2,int y2,int c)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int d=2*dy-dx;
    int x=x1,y=y1;
    putPixel(x,y,c);
    while(x<x2)
    {
        if(d<0)
            d+=2*dy;
        else{
            d+=2*(dy-dx);
            y++;
        }
        x++;
        putPixel(x,y,c);
    }
}
void octetTwo(int x1,int y1,int x2,int y2,int c)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int d=2*dx-dy;
    int x=x1,y=y1;
    putPixel(x,y,c);
    while(y<y2)
    {
        if(d<0)
            d+=2*dx;
        else{
            d+=2*(dx-dy);
            x++;
        }
        y++;
        putPixel(x,y,c);
    }
}
void octetThree(int x1,int y1,int x2,int y2,int c)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int d=-2*dx-dy;
    int x=x1,y=y1;
    putPixel(x,y,c);
    while(y<y2)
    {
        if(d<0)
            d-=2*dx;
        else{
            d+=2*(-dx-dy);
            x--;
        }
        y++;
        putPixel(x,y,c);
    }
}
void octetFour(int x1,int y1,int x2,int y2,int c)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int d=-2*dy-dx;
    int x=x1,y=y1;
    putPixel(x,y,c);
    while(x>x2)
    {
        if(d>0)
            d-=2*dy;
        else{
            d+=2*(-dy-dx);
            y++;
        }
        x--;
        putPixel(x,y,c);
    }
}
void octetFive(int x1,int y1,int x2,int y2,int c)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int d=-2*dy+dx;
    int x=x1,y=y1;
    putPixel(x,y,c);
    while(x>x2)
    {
        if(d<0)
            d-=2*dy;
        else{
            d+=2*(-dy+dx);
            y--;
        }
        x--;
        putPixel(x,y,c);
    }

}
void octetSix(int x1,int y1,int x2,int y2,int c)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int d=-2*dx+dy;
    int x=x1,y=y1;
    putPixel(x,y,c);
    while(y>y2)
    {
        if(d<0)
            d-=2*dx;
        else{
            d-=2*(dx-dy);
            x--;
        }
        y--;
        putPixel(x,y,c);
    }
}
void octetSeven(int x1,int y1,int x2,int y2,int c)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int d=2*dx+dy;
    int x=x1,y=y1;
    putPixel(x,y,c);
    while(y>y2)
    {
        if(d<0)
            d+=2*dx;
        else{
            d+=2*(dx+dy);
            x++;
        }
        y--;
        putPixel(x,y,c);
    }
}
void octetEight(int x1,int y1,int x2,int y2,int c)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int d=2*dy+dx;
    int x=x1,y=y1;
    putPixel(x,y,c);
    while(x<x2)
    {
        if(d>0)
            d+=2*dy;
        else{
            d+=2*(dy+dx);
            y--;
        }
        x++;
        putPixel(x,y,c);
    }
}
void mLine(int x1,int y1,int x2,int y2,int c)
{
    int dx=x2-x1;
    int dy=y2-y1;
    if(dx>=dy && dx>0 && dy>=0)
        octetOne(x1,y1,x2,y2,c);
    else
        if(dy>=dx && dx>=0 && dy>0)
            octetTwo(x1,y1,x2,y2,c);
    else
        if(dy>=abs(dx) && dx<=0 && dy>0)
            octetThree(x1,y1,x2,y2,c);
    else
        if(abs(dx)>=dy && dx<0 && dy>=0)
            octetFour(x1,y1,x2,y2,c);
    else
        if(abs(dx)>=abs(dy) && dx<0 && dy<=0)
            octetFive(x1,y1,x2,y2,c);
    else
        if(abs(dy)>=abs(dx) && dx<=0 && dy<0)
            octetSix(x1,y1,x2,y2,c);
    else
        if(abs(dy)>=dx && dx>=0 && dy<0)
            octetSeven(x1,y1,x2,y2,c);
    else
        if(dx>=dy && dx>0 && dy<=0)
            octetEight(x1,y1,x2,y2,c);
}
void sevenSegment(int x,int y,int digit)
{
    switch(digit)
    {
        case 0:mLine(x,y,x+60,y,15);
               mLine(x,y,x,y-60,15);
               mLine(x,y-60,x+60,y-60,0);
               mLine(x+60,y,x+60,y-60,15);
               mLine(x,y-60,x,y-120,15);
               mLine(x,y-120,x+60,y-120,15);
               mLine(x+60,y-60,x+60,y-120,15);
               break;
        case 1:mLine(x,y,x+60,y,0);
               mLine(x,y,x,y-60,0);
               mLine(x+60,y,x+60,y-60,15);
               mLine(x,y-60,x,y-120,0);
               mLine(x,y-60,x+60,y-60,0);
               mLine(x,y-120,x+60,y-120,0);
               mLine(x+60,y-60,x+60,y-120,15);
               break;
        case 2:mLine(x,y,x+60,y,15);
               mLine(x,y,x,y-60,0);
               mLine(x+60,y-60,x+60,y-120,0);
               mLine(x+60,y,x+60,y-60,15);
               mLine(x,y-60,x,y-120,15);
               mLine(x,y-60,x+60,y-60,15);
               mLine(x,y-120,x+60,y-120,15);
               break;
        case 3:mLine(x,y,x+60,y,15);
               mLine(x,y,x,y-60,0);
               mLine(x+60,y,x+60,y-60,15);
               mLine(x,y-60,x,y-120,0);
               mLine(x,y-60,x+60,y-60,15);
               mLine(x,y-120,x+60,y-120,15);
               mLine(x+60,y-60,x+60,y-120,15);
               break;
        case 4:mLine(x,y,x+60,y,0);
               mLine(x,y,x,y-60,15);
               mLine(x+60,y,x+60,y-60,15);
               mLine(x,y-60,x,y-120,0);
               mLine(x,y-60,x+60,y-60,15);
               mLine(x,y-120,x+60,y-120,0);
               mLine(x+60,y-60,x+60,y-120,15);
               break;
        case 5:mLine(x,y,x+60,y,15);
               mLine(x,y,x,y-60,15);
               mLine(x+60,y,x+60,y-60,0);
               mLine(x,y-60,x,y-120,0);
               mLine(x,y-60,x+60,y-60,15);
               mLine(x,y-120,x+60,y-120,15);
               mLine(x+60,y-60,x+60,y-120,15);
               break;
        case 6:mLine(x,y,x+60,y,15);
               mLine(x,y,x,y-60,15);
               mLine(x+60,y,x+60,y-60,0);
               mLine(x,y-60,x,y-120,15);
               mLine(x,y-60,x+60,y-60,15);
               mLine(x,y-120,x+60,y-120,15);
               mLine(x+60,y-60,x+60,y-120,15);
               break;
        case 7:mLine(x,y,x+60,y,15);
               mLine(x,y,x,y-60,0);
               mLine(x+60,y,x+60,y-60,15);
               mLine(x,y-60,x,y-120,0);
               mLine(x,y-60,x+60,y-60,0);
               mLine(x,y-120,x+60,y-120,0);
               mLine(x+60,y-60,x+60,y-120,15);
               break;
        case 8:mLine(x,y,x+60,y,15);
               mLine(x,y,x,y-60,15);
               mLine(x+60,y,x+60,y-60,15);
               mLine(x,y-60,x,y-120,15);
               mLine(x,y-60,x+60,y-60,15);
               mLine(x,y-120,x+60,y-120,15);
               mLine(x+60,y-60,x+60,y-120,15);
               break;
        case 9:mLine(x,y,x+60,y,15);
               mLine(x,y,x,y-60,15);
               mLine(x+60,y,x+60,y-60,15);
               mLine(x,y-60,x,y-120,0);
               mLine(x,y-60,x+60,y-60,15);
               mLine(x,y-120,x+60,y-120,15);
               mLine(x+60,y-60,x+60,y-120,15);
               break;
    }
}
void startDigitalClock()
{
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    sevenSegment(-240,200,tm.tm_hour/10);
    sevenSegment(-160,200,tm.tm_hour%10);
    sevenSegment(-70,200,tm.tm_min/10);
    sevenSegment(10,200,tm.tm_min%10);
    sevenSegment(100,200,tm.tm_sec/10);
    sevenSegment(180,200,tm.tm_sec%10);
}
int main()
{
  int gd = DETECT, gm =0 ;
  initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();
   putPixel(-85,120,15);
   putPixel(-85,160,15);
   putPixel(85,120,15);
   putPixel(85,160,15);
   while(true)
   {
       startDigitalClock();
       delay(1);
   }
  getch();
  closegraph();
  return 0;
}
