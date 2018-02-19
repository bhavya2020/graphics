#include<stdio.h>
#include<graphics.h>
#include<iostream>
using namespace std;
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
void ellipseSymmetry(int xc,int yc,int x,int y,int c)
{
    putPixel(x+xc,y+yc,c);
    putPixel(x+xc,-y+yc,c);
    putPixel(-x+xc,y+yc,c);
    putPixel(-x+xc,-y+yc,c);
}
void mEllipse(int xc,int yc,int a,int b,int c)
{
    int x=a,y=0;
    int d=b*b/4-b*b*a+a*a;
    int dels=3*a*a;
    int delsw=3*a*a+2*b*b-2*b*b*a;
    ellipseSymmetry(xc,yc,x,y,c);
    while(delsw<(2*b*b+3*a*a))
    {
        if(d<0)
        {
            d+=dels;
            dels+=2*a*a;
            delsw+=2*a*a;
        }
        else{
             d+=delsw;
            dels+=2*a*a;
            delsw+=2*a*a+2*b*b;
            x--;
        }
        y--;
        ellipseSymmetry(xc,yc,x,y,c);
    }

    int delw=3*b*b-2*b*x*b;
    delsw=3*b*b-2*b*b*x+2*a*a-2*a*a*y;
    ellipseSymmetry(xc,yc,x,y,c);
    while(x>0)
    {
        if(d>0)
        {
            d+=delw;
            delw+=2*b*b;
            delsw+=2*b*b;
        }
        else{
             d+=delsw;
            delw+=2*b*b;
            delsw+=2*b*b+2*a*a;
            y--;
        }
        x--;
        ellipseSymmetry(xc,yc,x,y,c);
    }
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
void mCircle(int cx,int cy,int r,int c,float theeta,int s)
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
    float alpha=360/(s-1);
    if(c==15)
    for(int i=1;i<=2*(s+1);i++)
    {
        mLine(cx,cy,cx+30*cos(theeta+i*alpha),cy+30*sin(theeta+i*alpha),i);
    }
    else{
        for(int i=1;i<=2*(s+1);i++)
    {
        mLine(cx,cy,cx+30*cos(theeta+i*alpha),cy+30*sin(theeta+i*alpha),c);
    }
    }

}
int main()
{
  int gd = DETECT, gm =0 ;
  initgraph(&gd,&gm,"");
  X=getmaxx();
  Y=getmaxy();
  float theeta=3.14/180;

  mEllipse(-160,0,120,20,15);
  mCircle(-200,-50,30,15,theeta,4);
  mCircle(-120,-50,30,15,theeta,4);


  int t=20;
  float delcx=0;
  while(true)
  {
      char ch=getch();
      if(ch=='d')
      {
      mEllipse(-160+delcx,0,120,20,0);
      mCircle(-120+delcx,-50,30,0,theeta,4);
      mCircle(-200+delcx,-50,30,0,theeta,4);
      delcx+=2*3.14*30*0.3/7.28;
      theeta-=0.3;
      mEllipse(-160+delcx,0,120,20,15);
      mCircle(-120+delcx,-50,30,15,theeta,4);
      mCircle(-200+delcx,-50,30,15,theeta,4);
      }
      else if(ch=='a')
      {
      mEllipse(-160+delcx,0,120,20,0);
      mCircle(-120+delcx,-50,30,0,theeta,4);
      mCircle(-200+delcx,-50,30,0,theeta,4);
      delcx-=2*3.14*30*0.3/7.28;
      theeta+=0.3;
      mEllipse(-160+delcx,0,120,20,15);
      mCircle(-120+delcx,-50,30,15,theeta,4);
      mCircle(-200+delcx,-50,30,15,theeta,4);
      }

  }

   closegraph();

}

