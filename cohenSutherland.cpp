#include<graphics.h>
#include<bits/stdc++.h>
#define xwmin -60
#define ywmin -30
#define xwmax 60
#define ywmax 30
#define left 0x1
#define bottom 0x2
#define top 0x8
#define right 0x4
using namespace std;
int X,Y;
struct point{
    int x;
    int y;
};
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
int genCode(point p)
{
    int code=0x0;
    if(p.x<xwmin)
    {
        code|=left;
    }
    if(p.x>xwmax)
    {
        code|=right;
    }
    if(p.y<ywmin)
    {
        code|=bottom;
    }
    if(p.y>ywmax)
    {
        code|=top;
    }
    return code;
}
point calcIntersectionPoint (point p,int edge,double m)
{
    point pi;
    if(edge==0)
    {
        pi.x=xwmin;
        pi.y=p.y+m*(xwmin-p.x);
    }
    else if(edge==1)
    {
        pi.y=ywmax;
        pi.x=p.x+(ywmax-p.y)/m;
    }else if(edge==2)
    {
        pi.x=xwmax;
        pi.y=p.y+m*(xwmax-p.x);
    }else{
         pi.y=ywmin;
        pi.x=p.x+(ywmin-p.y)/m;
    }

    return pi;
}
void cohenSutherland(point p1,point p2)
{
    double m=((double)(p1.y-p2.y))/(p1.x-p2.x);
    bool flag=0,done=0;
    int Count=0;
    do{

        int code1=genCode(p1);
        int code2=genCode(p2);

       // cout<<code1<<" "<<code2<<" "<<(code1 & code2)<<" "<<(code1 | code2)<<"\n";
        if(((code1 & code2) == 0) && ((code1 | code2) == 0))
           {
               flag=1;
               done=1;
               break;
           }
        if((code1 & code2) !=0)
        {
            done=1;
            break;
        }

        if(((code1 & code2) == 0) && ((code1 | code2) != 0))
        {
            if(Count%2==0){
            if((left & code1 )!=0)
            {
              p1=calcIntersectionPoint(p1,0,m);
            }
            if((top & code1) !=0)
            {
              p1=calcIntersectionPoint(p1,1,m);
            }
            if((right & code1) !=0)
            {
              p1=calcIntersectionPoint(p1,2,m);
            }
            if((bottom & code1) !=0)
            {
              p1=calcIntersectionPoint(p1,3,m);
            }
            }else{
            if((left & code2) !=0)
            {
              p2=calcIntersectionPoint(p2,0,m);
            }
            if((top & code2) !=0)
            {
              p2=calcIntersectionPoint(p2,1,m);
            }
            if((right & code2 )!=0)
            {
              p2=calcIntersectionPoint(p2,2,m);
            }
            if((bottom & code2) !=0)
            {
              p2=calcIntersectionPoint(p2,3,m);
            }
            }
       // cout<<p1.x<<" "<<p1.y<<" "<<p2.x<<" "<<p2.y<<"\n";
        }
        Count++;
    }while(done!=1);


    if(flag)
    {
        mLine(p1.x,p1.y,p2.x,p2.y,14);
    }
}


int main()
{
   int gd = DETECT, gm =0 ;
   initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();
    point p1;
    p1.x=-90;
    p1.y=-70;
    point p2;
    p2.x=70;
    p2.y=0;
    mLine(p1.x,p1.y,p2.x,p2.y,4);

   mLine(xwmin,ywmin,xwmax,ywmin,1);
   mLine(xwmin,ywmin,xwmin,ywmax,1);
   mLine(xwmax,ywmax,xwmax,ywmin,1);
   mLine(xwmax,ywmax,xwmin,ywmax,1);
   cohenSutherland(p1,p2);
   getch();
   closegraph();
   return 0;
}

