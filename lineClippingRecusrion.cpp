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
void lineClippingRecursion(point p1,point p2)
{

    while(true)
    {
        int code1=genCode(p1);
        int code2=genCode(p2);

       // cout<<code1<<" "<<code2<<"\n";
        if(code1==0 && code2==0)
        {
            cout<<"drawn\n";
           // cout<<p1.x<<" "<<p1.y<<" "<<p2.x<<" "<<p2.y<<"\n";
            mLine(p1.x,p1.y,p2.x,p2.y,4);
            break;
        }

        if( (code1 & code2) !=0)
        {
            cout<<"outside\n";
            break;
        }

        point pm;
        pm.x=(p1.x+p2.x)/2;
        pm.y=(p1.y+p2.y)/2;

        int codem=genCode(pm);
        //cout<<codem<<"\n";

        if(codem!=0)
        {
            if((code1 & codem)!=0)
            {
                p1=pm;
                continue;
            }else if((code2 & codem)!=0)
            {
                p2=pm;
                continue;
            }
        }

        if(codem == 0)
        {
            if(code2 == 0)
            {
                do
                {
                  point pm1;
                  pm1.x=(p1.x+pm.x)/2;
                  pm1.y=(p1.y+pm.y)/2;

                  int codem1=genCode(pm1);

                  if(codem1 !=0)
                    p1=pm1;
                  else
                    pm=pm1;

                }while(pm.x != xwmax && pm.x != xwmin && pm.y != ywmax && pm.y != ywmin );

                p1=pm;
            }
            else if(code1 == 0)
            {
                do
                {
                  point pm1;
                  pm1.x=(p2.x+pm.x)/2;
                  pm1.y=(p2.y+pm.y)/2;

                  int codem1=genCode(pm1);

                  if(codem1 !=0)
                    p2=pm1;
                  else
                    pm=pm1;

                }while(pm.x != xwmax && pm.x != xwmin && pm.y != ywmax && pm.y != ywmin );

                p2=pm;

            }else {

              point ptemp=pm;
             do
                {
                  point pm1;
                  pm1.x=(p1.x+pm.x)/2;
                  pm1.y=(p1.y+pm.y)/2;

                  int codem1=genCode(pm1);

                  //cout<<codem1<<"\n";
                  if(codem1 !=0)
                    p1=pm1;
                  else
                    pm=pm1;

                }while(pm.x != xwmax && pm.x != xwmin && pm.y != ywmax && pm.y != ywmin );


                p1=pm;


                pm=ptemp;
            do
                {
                  point pm1;
                  pm1.x=(p2.x+pm.x)/2;
                  pm1.y=(p2.y+pm.y)/2;

                  int codem1=genCode(pm1);

                  if(codem1 !=0)
                    p2=pm1;
                  else
                    pm=pm1;

                }while(pm.x != xwmax && pm.x != xwmin && pm.y != ywmax && pm.y != ywmin );

                p2=pm;
               // cout<<pm.x<<" "<<pm.y<<"\n";

            }
        }
    }
}
int main()
{
   int gd = DETECT, gm =0 ;
   initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();
   mLine(xwmin,ywmin,xwmax,ywmin,15);
   mLine(xwmin,ywmin,xwmin,ywmax,15);
   mLine(xwmax,ywmax,xwmax,ywmin,15);
   mLine(xwmax,ywmax,xwmin,ywmax,15);

   point p1,p2;

   p1.x=0;
   p1.y=80;

   p2.x=0;
   p2.y=-80;

   mLine(p1.x,p1.y,p2.x,p2.y,1);

   lineClippingRecursion(p1,p2);
   getch();
   closegraph();
   return 0;

}
