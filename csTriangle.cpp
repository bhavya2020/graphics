#include<graphics.h>
#include<bits/stdc++.h>
#define l1 0x1
#define l2 0x2
#define l4 0x4
using namespace std;
int X,Y;
struct point{
    double x;
    double y;
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
struct equation{

    int cx;
    int cy;
    int c;

};
int calcValue(equation e,point p)
{
    double value=(e.cx*p.x)+(e.cy*p.y)+e.c;
    return value;
}
bool check(equation e,point p)
{
     if(calcValue(e,p)>=0)
            return true;
     else
        return false;
}
int gencode(point p,equation e[3])
{
   int code=0x0;
   if(!check(e[0],p))
        code |=l1;
   if(!check(e[1],p))
        code |=l2;
   if(!check(e[2],p))
        code |=l4;

   return code;
}

point calcIntersectionPoint (point p,equation e,double m)
{
    point pi;
   // cout<<e.cx<<" "<<e.cy<<" "<<e.c<<" "<<p.x<<" "<<p.y<<" "<<m<<"\n";
    double c2=-(m*p.x)+p.y;
   // cout<<c2<<" ";
    pi.x=-((double)(e.cy*c2+e.c)/(e.cx+e.cy*m));
    //cout<<pi.x<<" ";
    pi.y=m*pi.x+c2;
    //cout<<pi.y<<"\n";
    return pi;
}
void cohenSutherland(point p1,point p2,equation e[3])
{
    double m=((double)(p1.y-p2.y))/(p1.x-p2.x);
    bool flag=0,done=0;
    int Count=0;
    do{


        int code1=gencode(p1,e);
        int code2=gencode(p2,e);

        cout<<code1<<" "<<code2<<" "<<(code1 & code2)<<" "<<(code1 | code2)<<"\n";
        if(((code1 & code2) == 0) && ((code1 | code2) == 0))
           {
               cout<<"true\n";
               flag=1;
               done=1;
               break;
           }
        if((code1 & code2) !=0)
        {
            cout<<"false\n";
            done=1;
            break;
        }

        if(((code1 & code2) == 0) && ((code1 | code2) != 0))
        {


           // cout<<(l1 & code2)<<" "<<(l2 & code2)<<" "<<(l4 & code2)<<"\n";
           if(Count%2==0)
           {

            if((l1 & code1 )!=0)
            {
              p1=calcIntersectionPoint(p1,e[0],m);
            }
            if((l2 & code1) !=0)
            {
              p1=calcIntersectionPoint(p1,e[1],m);
            }
            if((l4 & code1) !=0)
            {

              p1=calcIntersectionPoint(p1,e[2],m);
            }

           }else{
            if((l1 & code2) !=0)
            {

              p2=calcIntersectionPoint(p2,e[0],m);
            }
            if((l2 & code2) !=0)
            {
              p2=calcIntersectionPoint(p2,e[1],m);
            }
            if((l4 & code2 )!=0)
            {
              p2=calcIntersectionPoint(p2,e[2],m);
            }
          }
        }
        Count++;
        cout<<p1.x<<" "<<p1.y<<" "<<p2.x<<" "<<p2.y<<"\n";
    }while(!done);

    if(flag)
    {
       // cout<<p1.x<<" "<<p1.y<<" "<<p2.x<<" "<<p2.y<<"\n";
        mLine(p1.x,p1.y,p2.x,p2.y,4);
    }
}


int main()
{


    point triangle[4];

    triangle[0].x=50;
    triangle[0].y=90;
    triangle[1].x=-40;
    triangle[1].y=-30;
    triangle[2].x=30;
    triangle[2].y=-20;
    triangle[3].x=50;
    triangle[3].y=90;
/*
    triangle[0].x=11;
    triangle[0].y=15;
    triangle[1].x=2;
    triangle[1].y=1;
    triangle[2].x=9;
    triangle[2].y=3;
    triangle[3].x=11;
    triangle[3].y=15;
*/
    equation e[3];
    point p1,p2;
     p1.x=0;
     p1.y=0;
     p2.x=100;
     p2.y=40;

     for(int i=0;i<3;i++)
     {
         e[i].cy=-(triangle[i].x-triangle[i+1].x);
         e[i].cx=(triangle[i].y-triangle[i+1].y);
         e[i].c=(triangle[i].y*(triangle[i].x-triangle[i+1].x))-(triangle[i].x*(triangle[i].y-triangle[i+1].y));

         if(i!=2)
         {
         if(!check(e[i],triangle[2+i]))
         {
             e[i].cx*=-1;
             e[i].cy*=-1;
             e[i].c*=-1;
         }
         }
         else
         {
         if(!check(e[i],triangle[1]))
         {
             e[i].cx*=-1;
             e[i].cy*=-1;
             e[i].c*=-1;
         }
         }
     }


    int gd = DETECT, gm =0 ;
   initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();
     mLine(50,90,-40,-30,15);
     mLine(-40,-30,30,-20,15);
     mLine(30,-20,50,90,15);

     mLine(p1.x,p1.y,p2.x,p2.y,1);

     cohenSutherland(p1,p2,e);
   getch();
    closegraph();
    return 0;
}
