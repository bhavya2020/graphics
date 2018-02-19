#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void Circle(int radius)
{
    int n=radius+1;

    for(int i=260;i<260+n;i++)
        {
            for(int j=250;j<250+n;j++)
                {
                    if((i-260)*(i-260)+(j-250)*(j-250)==radius*radius)
                        putpixel(i,j,15);
                }
        }
    for(int i=260;i>260-n;i--)
        {
            for(int j=250;j<250+n;j++)
                {
                    if((i-260)*(i-260)+(j-250)*(j-250)>=radius*radius )
                        putpixel(i,j,15);
                }
        }
    for(int i=260;i<260+n;i++)
        {
            for(int j=250;j>250-n;j--)
                {
                    if((i-260)*(i-260)+(j-250)*(j-250)==radius*radius)
                        putpixel(i,j,15);
                }
        }
    for(int i=260;i>260-n;i--)
        {
            for(int j=250;j>250-n;j--)
                {
                    if((i-260)*(i-260)+(j-250)*(j-250)==radius*radius)
                        putpixel(i,j,15);
                }
        }
}

void mline(int x1,int x2,int y1,int y2,int c)
{

 int dx=x2-x1,dy=y2-y1,d;
 // printf("dy/dx=%d dy-dx=%d ",dy/dx,dy-dx);

 if(dx==0 && dy>0)
 {
     int x=x1,y=y1;
     putpixel(x,y,c);
 while(y<=y2)
 {
     y++;
     putpixel(x,y,c);
 }
 }else if(dx==0 && dy<0)
 {
          int x=x1,y=y1;
     putpixel(x,y,c);
 while(y>=y2)
 {
     y--;
     putpixel(x,y,c);
 }

 }
 else if(dy==0)
 {
     int x=x1,y=y1;
     putpixel(x,y,c);
 while(x<=x2)
 {
     x++;
     putpixel(x,y,c);
 }
 }
 else if (dy==dx)
 {
   int x=x1,y=y1;
     putpixel(x,y,c);
 while(x<=x2)
 {
     x++;y++;
     putpixel(x,y,c);
 }
 }else
 if (dy==-dx)
 {
      int x=x1,y=y1;
     putpixel(x,y,c);
 while(x<=x2)
 {
     x++;y--;
     putpixel(x,y,c);
 }

 }
 else
 if(dy<dx && dy>0)
 {
 d= 2*dy-dx;
 int x=x1,y=y1;
 putpixel(x,y,c);
 while(x<=x2)
 {

     if(d<0)
        d+=2*dy;
     else{
        d+=2*(dy-dx);
        y++;
     }
     x++;
     putpixel(x,y,c);
 }
 }
 else if(dy>dx)
 {

     d= -dy+2*dx;
 int x=x1,y=y1;
 putpixel(x,y,c );
 while(y<=y2)
 {

     if(d<0)
        d+=2*dx;
     else{
        d+=2*(dx-dy);
        x++;
     }
     y++;
     putpixel(x,y,c);
 }
 }else if((-dy)>dx){
     d= dy+2*dx;
 int x=x1,y=y1;
 putpixel(x,y,c);

 while(y>y2)
 {
     if(d<0)
        d+=2*dx;
     else{
        d+=2*(dy+dx);
        x++;
     }
     y--;
     putpixel(x,y,c);
 }
 }else{

  d= -2*dy+dx;
 int x=x1,y=y1;
 putpixel(x,y,15);
 printf("%d %d dy=%d dx=%d d=%d ",x2,y2,dy,dx,d);
 while(x<x2)
 {

     if(d<0)
        d-=2*dy;
     else{
        d-=2*(dy-dx);
        y--;
     }
     x++;
     putpixel(x,y,15);
 }
 }
}
void printAnalogClock()
{
        mline(240,260,160,180,15);
        mline(240,260,180,160,15);
        mline(270,270,160,180,15);
        mline(280,280,160,180,15);

        mline(360,360,240,260,15);
        mline(370,370,240,260,15);
        mline(380,380,240,260,15);

        mline(240,255,320,340,15);
        mline(255,270,340,320,15);
        mline(280,280,320,340,15);

        mline(130,130,240,260,15);
        mline(140,160,240,260,15);
        mline(140,160,260,240,15);


}
void sevenSegment(int x , int y, int digit)
{
    switch(digit)
     {
         case 0:mline(20+x,80+x,20+y,20+y,15);
        mline(20+x,20+x,20+y,80+y,15);
        mline(80+x,80+x,20+y,80+y,15);
        mline(20+x,80+x,80+y,80+y,0);
        mline(20+x,20+x,80+y,140+y,15);
        mline(80+x,80+x,80+y,140+y,15);
        mline(20+x,80+x,140+y,140+y,15);
        break;
        case 1:mline(20+x,80+x,20+y,20+y,0);
        mline(20+x,20+x,20+y,80+y,0);
        mline(80+x,80+x,20+y,80+y,15);
        mline(20+x,80+x,80+y,80+y,0);
        mline(20+x,20+x,80+y,140+y,0);
        mline(80+x,80+x,80+y,140+y,15);
        mline(20+x,80+x,140+y,140+y,0);
        break;
         case 2:mline(20+x,80+x,20+y,20+y,15);
        mline(20+x,20+x,20+y,80+y,0);
        mline(80+x,80+x,20+y,80+y,15);
        mline(20+x,80+x,80+y,80+y,15);
        mline(20+x,20+x,80+y,140+y,15);
        mline(80+x,80+x,80+y,140+y,0);
        mline(20+x,80+x,140+y,140+y,15);
        break;
         case 3:mline(20+x,80+x,20+y,20+y,15);
        mline(20+x,20+x,20+y,80+y,0);
        mline(80+x,80+x,20+y,80+y,15);
        mline(20+x,80+x,80+y,80+y,15);
        mline(20+x,20+x,80+y,140+y,0);
        mline(80+x,80+x,80+y,140+y,15);
        mline(20+x,80+x,140+y,140+y,15);
        break;
         case 4:mline(20+x,80+x,20+y,20+y,0);
        mline(20+x,20+x,20+y,80+y,15);
        mline(80+x,80+x,20+y,80+y,15);
        mline(20+x,80+x,80+y,80+y,15);
        mline(20+x,20+x,80+y,140+y,0);
        mline(80+x,80+x,80+y,140+y,15);
        mline(20+x,80+x,140+y,140+y,0);
        break;
         case 5:mline(20+x,80+x,20+y,20+y,15);
        mline(20+x,20+x,20+y,80+y,15);
        mline(80+x,80+x,20+y,80+y,0);
        mline(20+x,80+x,80+y,80+y,15);
        mline(20+x,20+x,80+y,140+y,0);
        mline(80+x,80+x,80+y,140+y,15);
        mline(20+x,80+x,140+y,140+y,15);
        break;
         case 6:mline(20+x,80+x,20+y,20+y,15);
        mline(20+x,20+x,20+y,80+y,15);
        mline(80+x,80+x,20+y,80+y,0);
        mline(20+x,80+x,80+y,80+y,15);
        mline(20+x,20+x,80+y,140+y,15);
        mline(80+x,80+x,80+y,140+y,15);
        mline(20+x,80+x,140+y,140+y,15);
        break;
        case 7:mline(20+x,80+x,20+y,20+y,15);
        mline(20+x,20+x,20+y,80+y,0);
        mline(80+x,80+x,20+y,80+y,15);
        mline(20+x,80+x,80+y,80+y,0);
        mline(20+x,20+x,80+y,140+y,0);
        mline(80+x,80+x,80+y,140+y,15);
        mline(20+x,80+x,140+y,140+y,0);
        break;
        case 8:mline(20+x,80+x,20+y,20+y,15);
        mline(20+x,20+x,20+y,80+y,15);
        mline(80+x,80+x,20+y,80+y,15);
        mline(20+x,80+x,80+y,80+y,15);
        mline(20+x,20+x,80+y,140+y,15);
        mline(80+x,80+x,80+y,140+y,15);
        mline(20+x,80+x,140+y,140+y,15);
        break;
        case 9:mline(20+x,80+x,20+y,20+y,15);
        mline(20+x,20+x,20+y,80+y,15);
        mline(80+x,80+x,20+y,80+y,15);
        mline(20+x,80+x,80+y,80+y,15);
        mline(20+x,20+x,80+y,140+y,0);
        mline(80+x,80+x,80+y,140+y,15);
        mline(20+x,80+x,140+y,140+y,15);
        break;
     }
}

void getTime()
{
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    sevenSegment(0,0,tm.tm_hour/10);
    sevenSegment(90,0,tm.tm_hour%10);
    sevenSegment(180,0,tm.tm_min/10);
    sevenSegment(270,0,tm.tm_min%10);
    sevenSegment(360,0,tm.tm_sec/10);
    sevenSegment(450,0,tm.tm_sec%10);


}
int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
  //  Circle(40);
    /*
    putpixel(180,65,15);
    putpixel(180,85,15);
    putpixel(360,65,15);
    putpixel(360,85,15);*/

  // while(true)
   // {
      //getTime();
      //delay(1);


      // printAnalogClock();

        //mline(260,300,250,250,15);
        //mline(260,260,190,250,15);
        /*
        for(int i=0;i<15;i++)
        {
        delay(1000);
        mline(260,320-(i*4),250,250+(i*4),0);
        mline(260,320-((i+1)*4),250,250+((i+1)*4),15);
        }
        for(int i=0;i<15;i++)
        {
        delay(1000);
        mline(260,260-(i*4),250,310-(i*4),0);
        mline(260,260-((i+1)*4),250,310-((i+1)*4),15);
        }
        for(int i=0;i<15;i++)
        {
        delay(1000);
        mline(200+(i*4),260,250-(i*4),250,0);
        mline(200+((i+1)*4),260,250-((i+1)*4),250,15);
        }*/
        for(int i=0;i<15;i++)
        {
        delay(1000);
        mline(260,260+(i*4),250,190+(i*4),0);
        mline(260,260+((i+1)*4),250,190+((i+1)*4),15);
        }
   /*     delay(1);
        mline(260,320,244,250,0);
        mline(260,320,238,250,0);*/

  //  }
    getch();
    closegraph();
}

