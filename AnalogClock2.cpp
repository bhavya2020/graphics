#include<stdio.h>
#include<graphics.h>
#include<time.h>
int X,Y;
void putPixel(int x,int y,int c)
{
    putpixel(x+X/2,-y+Y/3,c);
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
   mLine(-80,-105,-80,-260,15);
   mLine(80,-105,80,-260,15);
   mLine(-80,-260,-60,-290,15);
   mLine(80,-260,60,-290,15);
   mLine(-60,-290,60,-290,15);

   outtextxy(0+X/2,-136+10+Y/3,"12");
   outtextxy(40+25+X/2,-(77+25)+Y/3,"1");
   outtextxy(77+25+X/2,-(40+25)+Y/3,"2");
   outtextxy(126-12+X/2,0+Y/3,"3");
   outtextxy(72+25+X/2,40+25+Y/3,"4");
   outtextxy(36+25+X/2,76+25+Y/3,"5");
   outtextxy(0+X/2, 133-14+Y/3,"6");
   outtextxy(-40-25+X/2,76+25+Y/3,"7");
   outtextxy(-80-25+X/2,40+25+Y/3,"8");
   outtextxy(-135+12+X/2,0+Y/3,"9");
   outtextxy(-88-25+X/2,-(40+25)+Y/3,"10");
   outtextxy(-40-25+X/2,-(82+25)+Y/3,"11");
   circle(X/2,Y/3,130);
   circle(X/2,Y/3,110);

   int r=5;
   while(r--)
    circle(X/2,Y/3,r);


}
int main()
{
  int gd = DETECT, gm =0 ;
  initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();
   printAnalogClock();
   int gamma=-270;

    //mLine(0,-130,110*cos(gamma*3.14/180),-240*sin(gamma*3.14/180),15);
    int delGammma=-2;

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

          mLine(0,0,70*cos(beta*3.14/180),70*sin(beta*3.14/180),15);
          mLine(0,0,90*cos(alpha*3.14/180),90*sin(alpha*3.14/180),15);
          mLine(0,0,100*cos(theeta*3.14/180),100*sin(theeta*3.14/180),15);
          for(int l=0;l<2;l++)
          {
               mLine(-2,-130,-2+110*cos(gamma*3.14/180),-270*sin(gamma*3.14/180),15);
               mLine(2,-130,2+110*cos(gamma*3.14/180),-270*sin(gamma*3.14/180),15);
               int R=10;
               while(R--)
               {
                 circle(110*cos(gamma*3.14/180)+X/2,270*sin(gamma*3.14/180)+Y/3,R);
               }
               delay(1000/2);
               mLine(-2,-130,-2+110*cos(gamma*3.14/180),-270*sin(gamma*3.14/180),0);
               mLine(2,-130,2+110*cos(gamma*3.14/180),-270*sin(gamma*3.14/180),0);
               setcolor(0);
               R=10;
                while(R--)
               {
                 circle(110*cos(gamma*3.14/180)+X/2,270*sin(gamma*3.14/180)+Y/3,R);
               }
               setcolor(15);
               gamma+=delGammma;
               if(gamma==-300 || gamma==-240)
                {
                    delGammma*=-1;
                }
          }

          if((i+1)%10==0){
          mLine(0,0,90*cos(alpha*3.14/180),90*sin(alpha*3.14/180),0);
          alpha-=1;
          }
          mLine(0,0,100*cos(theeta*3.14/180),100*sin(theeta*3.14/180),0);
          theeta-=6;
      }
      mLine(0,0,70*cos(beta*3.14/180),70*sin(beta*3.14/180),0);
      beta-=0.5;
     }
    }
    }

   getch();
   closegraph();
  return 0;
}

