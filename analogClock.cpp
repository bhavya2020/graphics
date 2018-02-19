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
void printAnalogClock()
{
   outtextxy(0+X/2,-200+10+Y/2,"12");
   outtextxy(66+25+X/2,-(133+25)+Y/2,"1");
   outtextxy(133+25+X/2,-(66+25)+Y/2,"2");
   outtextxy(200-12+X/2,0+Y/2,"3");
   outtextxy(133+25+X/2,66+25+Y/2,"4");
   outtextxy(66+25+X/2,133+25+Y/2,"5");
   outtextxy(0+X/2, 200-14+Y/2,"6");
   outtextxy(-66-25+X/2,133+25+Y/2,"7");
   outtextxy(-133-25+X/2,66+25+Y/2,"8");
   outtextxy(-200+12+X/2,0+Y/2,"9");
   outtextxy(-133-25+X/2,-(66+25)+Y/2,"10");
   outtextxy(-66-25+X/2,-(133+25)+Y/2,"11");
   circle(X/2,Y/2,200);
   circle(X/2,Y/2,160);
   int r=5;
   while(r--)
    circle(X/2,Y/2,r);

}
int main()
{
  int gd = DETECT, gm =0 ;
  initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();
   printAnalogClock();
    while(true){
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    float beta=-(tm.tm_hour*30+tm.tm_min*0.5-360+270);
    for(int k=0;k<60;k++)
    {
     float alpha=-(tm.tm_min*6+tm.tm_sec*0.1+270);
     for(int j=0;j<60;j++)
     {
      int theeta=-(tm.tm_sec*+270);
      for(int i=0;i<60;i++)
      {
          mLine(0,0,100*cos(beta*3.14/180),100*sin(beta*3.14/180),15);
          mLine(0,0,130*cos(alpha*3.14/180),130*sin(alpha*3.14/180),15);
          mLine(0,0,150*cos(theeta*3.14/180),150*sin(theeta*3.14/180),15);
          delay(1000);
          if((i+1)%10==0){
          mLine(0,0,130*cos(alpha*3.14/180),130*sin(alpha*3.14/180),0);
          alpha-=1;
          }
          mLine(0,0,150*cos(theeta*3.14/180),150*sin(theeta*3.14/180),0);
          theeta-=6;
      }
      mLine(0,0,100*cos(beta*3.14/180),100*sin(beta*3.14/180),0);
      beta-=0.5;
     }
    }
    }
   getch();
   closegraph();
  return 0;
}

