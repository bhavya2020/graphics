#include<graphics.h>
#include<bits/stdc++.h>
#define xwmin -60
#define ywmin -30
#define xwmax 60
#define ywmax 30
using namespace std;
int X,Y;
struct point{
    int x;
    int y;
    bool inOut;  // in=> true
};
struct clippedPoint{
   point p;
   bool io;
   bool visit;
};
bool compare0(clippedPoint p1,clippedPoint p2)
{
    if(p1.p.y<=p2.p.y)
        return true;
    else
        return false;
}
bool compare1(clippedPoint p1,clippedPoint p2)
{
    if(p1.p.x<=p2.p.x)
        return true;
    else
        return false;
}
bool compare2(clippedPoint p1,clippedPoint p2)
{
    if(p1.p.y>=p2.p.y)
        return true;
    else
        return false;
}
bool compare3(clippedPoint p1,clippedPoint p2)
{
    if(p1.p.x>=p2.p.x)
        return true;
    else
        return false;
}
point calcIntersectionPoint (point p1,point p2,int edge)
{
    double m=((double)(p1.y-p2.y))/(p1.x-p2.x);
    point pi;
    if(edge==0)
    {
        pi.x=xwmin;
        pi.y=p1.y+m*(xwmin-p1.x);
    }
    else if(edge==1)
    {
        pi.y=ywmax;
        pi.x=p1.x+(ywmax-p1.y)/m;
    }else if(edge==2)
    {
        pi.x=xwmax;
        pi.y=p1.y+m*(xwmax-p1.x);
    }else{
         pi.y=ywmin;
        pi.x=p1.x+(ywmin-p1.y)/m;
    }

    return pi;
}
void checkInOut(point &p,int edge)
{
    switch(edge)
    {
        case 0: if(p.x<xwmin)
                 p.inOut=false;
                else
                 p.inOut=true;
                break;
        case 1: if(p.y>ywmax)
                 p.inOut=false;
                else
                 p.inOut=true;
                break;
        case 2: if(p.x>xwmax)
                 p.inOut=false;
                else
                 p.inOut=true;
                break;
        case 3: if(p.y<ywmin)
                 p.inOut=false;
                else
                 p.inOut=true;
                break;
    }
}
void Sort(vector<clippedPoint> intersectionPoints,int edge)
{
    switch(edge)
    {
     case 0: sort(intersectionPoints.begin(),intersectionPoints.end(),compare0); break;
     case 1: sort(intersectionPoints.begin(),intersectionPoints.end(),compare1); break;
     case 2: sort(intersectionPoints.begin(),intersectionPoints.end(),compare2); break;
     case 3: sort(intersectionPoints.begin(),intersectionPoints.end(),compare3); break;

    }
}
vector<clippedPoint> sutherlandHodgmanEdge(vector<clippedPoint> polygon,int edge)
{
    vector<clippedPoint> points;
    vector<clippedPoint> intersectionPoints;
    for(int i=0;i<7;i++)
    {
        checkInOut(polygon[i],edge);
    }
    for(int i=0;i<6;i++)
    {
        if(polygon[i].inOut && !(polygon[i+1].inOut))
        {
            clippedPoint p;
            p.point=calcIntersectionPoint(polygon[i],polygon[i+1],edge);
            p.io=true;
            p.visit=false;
            points.push_back(p);
            intersectionPoints.push_back(p);
        }
        else if(!(polygon[i].inOut) && polygon[i+1].inOut)
        {
            clippedPoint p;

            p.point=calcIntersectionPoint(polygon[i],polygon[i+1],edge);
            p.io=false;
            p.visit=false;
            points.push_back(p);
            intersectionPoints.push_back(p);

            p.point=polygon[i+1];
            p.io=false;
            p.visit=false;
            points.push_back(p);
        }
        else if(polygon[i].inOut && polygon[i+1].inOut)
        {
            clippedPoint p;
            p.point=polygon[i+1];
            p.io=false;
            p.visit=false;
            points.push_back(p);
        }
    }
    Sort(intersectionPoints,edge);
}
int main()
{
   int gd = DETECT, gm =0 ;
   initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();

    points polygonPoints[7];

    polygonPoints[0].x=90;
    polygonPoints[0].y=20;

    polygonPoints[1].x=40;
    polygonPoints[1].y=-20;

    polygonPoints[2].x=70;
    polygonPoints[2].y=25;

    polygonPoints[3].x=30;
    polygonPoints[3].y=40;

    polygonPoints[4].x=-10;
    polygonPoints[4].y=10;

    polygonPoints[5].x=20;
    polygonPoints[5].y=50;

    polygonPoints[6].x=90;
    polygonPoints[6].y=20;

   mLine(xwmin,ywmin,xwmax,ywmin,1);
   mLine(xwmin,ywmin,xwmin,ywmax,1);
   mLine(xwmax,ywmax,xwmax,ywmin,1);
   mLine(xwmax,ywmax,xwmin,ywmax,1);
   cohenSutherland(p1,p2);
   getch();
   closegraph();
   return 0;
}
