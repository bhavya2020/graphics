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

vector<point> sutherlandHodgmanEdge(vector<point> inputPolygon,int edge)
{

    vector<point> outputPolygon;
    for(int i=0;i<inputPolygon.size();i++)
    {
        checkInOut(inputPolygon[i],edge);
    }
    for(int i=0;i<inputPolygon.size()-1;i++)
    {
        if(inputPolygon[i].inOut && !(inputPolygon[i+1].inOut))
        {
            outputPolygon.push_back(calcIntersectionPoint(inputPolygon[i],inputPolygon[i+1],edge));
        }
        else if(!(inputPolygon[i].inOut) && inputPolygon[i+1].inOut)
        {

            outputPolygon.push_back(calcIntersectionPoint(inputPolygon[i],inputPolygon[i+1],edge));
            outputPolygon.push_back(inputPolygon[i+1]);
        }
        else if(inputPolygon[i].inOut && inputPolygon[i+1].inOut)
        {
            outputPolygon.push_back(inputPolygon[i+1]);
        }
    }

    outputPolygon.push_back(outputPolygon[0]);
   return outputPolygon;
}

vector<point> sutherlandHodgman(vector<point> initialPolygon)
{
    vector<point> leftClipped=sutherlandHodgmanEdge(initialPolygon,0);
    vector<point> topClipped=sutherlandHodgmanEdge(leftClipped,1);
    vector<point> rightClipped=sutherlandHodgmanEdge(topClipped,2);
    vector<point> clippedPolygon=sutherlandHodgmanEdge(rightClipped,3);

    return clippedPolygon;
}

void drawPolygon(vector<point> polygon,int color)
{
    for(int i=0;i<polygon.size()-1;i++)
    {
        mLine(polygon[i].x,polygon[i].y,polygon[i+1].x,polygon[i+1].y,color);
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
    vector<point> initialPolygon;

    point polygonPoint;

    polygonPoint.x=0;
    polygonPoint.y=20;

    initialPolygon.push_back(polygonPoint);

    polygonPoint.x=-20;
    polygonPoint.y=-10;

    initialPolygon.push_back(polygonPoint);

    polygonPoint.x=-90;
    polygonPoint.y=10;

    initialPolygon.push_back(polygonPoint);

    polygonPoint.x=-70;
    polygonPoint.y=40;

    initialPolygon.push_back(polygonPoint);

    polygonPoint.x=0;
    polygonPoint.y=20;

    initialPolygon.push_back(polygonPoint);


   drawPolygon(initialPolygon,4);

   vector<point> clippedPolygon=sutherlandHodgman(initialPolygon);

   drawPolygon(clippedPolygon,1);



   getch();
   closegraph();
   return 0;
}

