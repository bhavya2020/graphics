#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
struct point
{
    int x;
    int y;
};
point calcEdges(point p1,point p2)
{
    point edge;
    edge.y=p2.y-p1.y;
    edge.x=p2.x-p1.x;
    return edge;
}
int calcDeterminant(point p1,point p2)
{
    int determinant=(p1.x*p2.y -p1.y*p2.x);
    return determinant;
}
/*
void drawPolygon(vector<point> polygon,int color)
{
    for(int i=0;i<polygon.size()-1;i++)
    {
        mLine(polygon[i].x,polygon[i].y,polygon[i+1].x,polygon[i+1].y,color);
    }
}
*/
int main()
{
    vector<point> polygon;

    point p;

    p.x=90;
    p.y=20;

    polygon.push_back(p);

    p.x=40;
    p.y=-20;

    polygon.push_back(p);

    p.x=70;
    p.y=25;

    polygon.push_back(p);

    p.x=30;
    p.y=40;

    polygon.push_back(p);

    p.x=-10;
    p.y=-10;


    polygon.push_back(p);

    p.x=20;
    p.y=50;

    polygon.push_back(p);


    p.x=90;
    p.y=20;

    polygon.push_back(p);

    vector<point> edge;
    vector<int> determinants;
    .for(int i=0;i<polygon.size()-1;i++)
    {
        edge.push_back(calcEdges(polygon[i],polygon[i+1]));
    }

    for(int i=0;i<edge.size();i++)
    {
        determinants.push_back(calcDeterminant(edge[i],edge[(i+1)% (edge.size())]));
    }

    for(int i=0;i<determinants.size();i++)
    {
        if(determinants[i]*determinants[(i+1)% (determinants.size())] <0)
            cout<<polygon[i].x<<" "<<polygon[i].y<<"\n";
    }
    return 0;
}
