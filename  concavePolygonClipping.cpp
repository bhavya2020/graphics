#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<bits/stdc++.h>
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


struct Vector
{
    int i;
    int j;
};
Vector CalcNormal(Vector e)
{
    Vector n;
    if(e.i >0 && e.j >0)
    {
        n.i=e.j;
        n.j=-e.i;
    }
    else if(e.i>0 && e.j<0)
    {
        n.i=e.j;
        n.j=-e.i;
    }else if(e.i<0 && e.j >0)
    {
        n.i=e.j;
        n.j=-e.i;
    }
    else{
        n.i=e.j;
        n.j=-e.i;
    }
    return n;
}
Vector addVector(Vector p1,Vector p2)
{
    Vector e;
    e.i=p2.i+p1.i;
    e.j=p2.j+p1.j;
    return e;
}
Vector subVector(Vector p1,Vector p2)
{
    Vector e;
    e.i=p2.i-p1.i;
    e.j=p2.j-p1.j;
    return e;
}
int dotProduct(Vector v1,Vector v2)
{
    int dp;
    dp=(v1.i*v2.i)+(v1.j*v2.j);
    return dp;
}
struct intersection{
 double t;
 bool entryExit;
};
bool compare(intersection i1,intersection i2)
{
    if(i1.t<=i2.t)
        return true;
    else
        return false;
}
Vector calcPoints(Vector p1,Vector p2,double t)
{
    Vector p2MinusP1;
    p2MinusP1=subVector(p1,p2);
    p2MinusP1.i*=t;
    p2MinusP1.j*=t;
    Vector Point;
    Point=addVector(p1,p2MinusP1);
    return Point;

}
int main()
{
  int gd = DETECT, gm =0 ;

   Vector PolygonPoints[6];
   Vector normals[6];
   Vector edges[6];
   int numeratorOfT[6];
   int denominatorOfT[6];
   intersection Intersection[6];

   PolygonPoints[0].i=-40;
   PolygonPoints[0].j=10;
   PolygonPoints[1].i=30;
   PolygonPoints[1].j=-10;
   PolygonPoints[2].i=-10;
   PolygonPoints[2].j=-60;
   PolygonPoints[3].i=80;
   PolygonPoints[3].j=10;
   PolygonPoints[4].i=10;
   PolygonPoints[4].j=8;
   PolygonPoints[5].i=20;
   PolygonPoints[5].j=70;



    for(int k=0;k<6;k++)
    {
        if(k!=5)
        edges[k]=subVector(PolygonPoints[k],PolygonPoints[k+1]);
        else
        edges[5]=subVector(PolygonPoints[5],PolygonPoints[0]);
    }

    for(int k=0;k<6;k++)
    {
        normals[k]=CalcNormal(edges[k]);
    }


    Vector p1,p2;

    p1.i=0;
    p1.j=80;
    p2.i=35;
    p2.j=-70;



       Vector p1MinusPei;
       for(int k=0;k<6;k++)
       {
           p1MinusPei=subVector(PolygonPoints[k],p1);
           numeratorOfT[k]= dotProduct(p1MinusPei,normals[k]);
       }


    Vector p2MinusP1;
    p2MinusP1=subVector(p1,p2);
       for(int k=0;k<6;k++)
       {
           denominatorOfT[k]= dotProduct(p2MinusP1,normals[k]);
           if(denominatorOfT[k]<0)
             {
                 Intersection[k].entryExit=true;
             }
           else
            {
                 Intersection[k].entryExit=false;
            }

       }
        for(int k=0;k<6;k++)
        {
            Intersection[k].t=-((double)(numeratorOfT[k])/denominatorOfT[k]);
        }

    sort(Intersection,Intersection+6,compare);



 initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();
    for(int k=0;k<5;k++)
    {

        if(Intersection[k].entryExit && !Intersection[k+1].entryExit)
        {
            Vector point1=calcPoints(p1,p2,Intersection[k].t);
            Vector point2=calcPoints(p1,p2,Intersection[k+1].t);
            mLine(point1.i,point1.j,point2.i,point2.j,14);
        }
    }



   mLine(-40,10,30,-10,15);
   mLine(30,-10,-10,-60,15);
   mLine(-10,-60,80,10,15);
   mLine(80,10,10,8,15);
   mLine(10,8,20,70,15);
   mLine(20,70,-40,10,15);

   //mLine(0,80,35,-70,15);
  getch();
  closegraph();


  return 0;
}
