#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int X,Y;
struct point
{
    int x;
    int y;
    int tagging;
    bool traversal;
};
struct intersection
{
    double t;
    int tagging;
};

vector<point> calculation(vector<point> pEdge, vector<point> pComplete);
void print(vector<point> polygon);
int main()
{
  int gd = DETECT, gm =0 ;
  initgraph(&gd,&gm,"");
  X=getmaxx();
  Y=getmaxy();

  vector<point> subjectPolygonInitial;
  vector<point> clippingWindowInitial;
  vector<point> subjectPolygonFinal;
  vector<point> clippingWindowFinal;

  point p;

  p.x=12;
  p.y=18;
  p.tagging=-1;
  p.traversal=false;

  subjectPolygonInitial.push_back(p);

  p.x=16;
  p.y=8;
  p.tagging=-1;
  p.traversal=false;

  subjectPolygonInitial.push_back(p);

  p.x=11;
  p.y=10;
  p.tagging=-1;
  p.traversal=false;

  subjectPolygonInitial.push_back(p);

  p.x=3;
  p.y=6;
  p.tagging=-1;
  p.traversal=false;

  subjectPolygonInitial.push_back(p);

  p.x=4;
  p.y=12;
  p.tagging=-1;
  p.traversal=false;

  clippingWindowInitial.push_back(p);

  p.x=12;
  p.y=7;
  p.tagging=-1;
  p.traversal=false;

  clippingWindowInitial.push_back(p);

  p.x=23;
  p.y=15;
  p.tagging=-1;
  p.traversal=false;

  clippingWindowInitial.push_back(p);

  p.x=10;
  p.y=1;
  p.tagging=-1;
  p.traversal=false;

  clippingWindowInitial.push_back(p);

  subjectPolygonFinal=calculation(subjectPolygonInitial,clippingWindowInitial);
  subjectPolygonFinal.resize(subjectPolygonFinal.size()-1);

  clippingWindowFinal=calculation(clippingWindowInitial,subjectPolygonInitial);
  clippingWindowFinal.resize(clippingWindowFinal.size()-1);

  cout<<"subjectPolygonFinal"<<endl;
  print(subjectPolygonFinal);
  cout<<"clippingWindowFinal"<<endl;
  print(clippingWindowFinal);

  getch();
  closegraph();
  return 0;
}
bool compare(intersection i1,intersection i2)
{
    if(i1.t<i2.t)
        return true;
    else
        return false;

}
void print(vector<point> polygon)
{
    for(int i=0;i<polygon.size();i++)
    {
        cout<<polygon[i].x<<" "<<polygon[i].y<<" "<<polygon[i].tagging<<" "<<polygon[i].traversal<<endl;
    }
}
int dotProduct(point P1,point P2)
{
    return P1.x*P2.x+P1.y*P2.y;
}
vector<int> calcDen(point Edge,vector<point>normals)
{
    vector<int> denominators;
    int d;
    for(int i=0;i<normals.size();i++)
    {
        d=-dotProduct(Edge,normals[i]);
        denominators.push_back(d);
    }
    return denominators;
}
vector<int> calcNum(point Pt,vector<point> pComplete,vector<point> normals)
{
    vector<int> numerators;
    point p;
    int n;
    for(int i=0;i<pComplete.size();i++)
    {
        p.x=Pt.x-pComplete[i].x;
        p.y=Pt.y-pComplete[i].y;
        n=dotProduct(p,normals[i]);
        numerators.push_back(n);
    }
    return numerators;

}

vector<point> calcedges(vector<point> polygon)
{
    vector<point> edges;
    point p;
    int n=polygon.size();
    for(int i=0;i<n;i++)
    {
        p.x=polygon[(i+1)%n].x-polygon[i].x;
        p.y=polygon[(i+1)%n].y-polygon[i].y;
        //cout<<p.x<<" "<<p.y<<"\n";
        edges.push_back(p);
       // cout<<i<<" "<<edges[i].x<<" "<<edges[i].y<<"\n";
    }
    //cout<<"\n";
    return edges;
}
vector<point> calcnormals(vector<point> edges)
{
    vector<point> normals;
    point p;
    for(int i=0;i<edges.size();i++)
    {
       if(edges[i].x>=0 && edges[i].y>=0)
       {
           p.x=-edges[i].y;
           p.y=+edges[i].x;

       }
       else if(edges[i].x>=0 && edges[i].y<=0)
       {
           p.x=-edges[i].y;
           p.y=edges[i].x;


       }
       else if(edges[i].x<=0 && edges[i].y>=0)
       {
           p.x=-edges[i].y;
           p.y=edges[i].x;

       }
       else if(edges[i].x<=0 && edges[i].y<=0)
       {
           p.x=-edges[i].y;
           p.y=edges[i].x;

       }
       normals.push_back(p);

    }
    return normals;


}
point calcPoints(point p1,point p2,intersection inter)
{
    point p2MinusP1;
    p2MinusP1.x=p2.x-p1.x;
    p2MinusP1.y=p2.y-p1.y;
    p2MinusP1.x*=inter.t;
    p2MinusP1.y*=inter.t;
    point Point;
    Point.x=p1.x+p2MinusP1.x;
    Point.y=p1.y+p2MinusP1.y;
    Point.tagging=inter.tagging;
    Point.traversal=false;
    return Point;

}

void calcIntersection(point edgept1,point edgept2,vector<int> num,vector<int> den,vector<point> &finalPoints)
{
    vector<intersection> Inter;
    intersection intinst;
    for(int i=0;i<num.size();i++)
    {
        intinst.t=((double)num[i])/den[i];
        if(den[i]>0)
        {
            intinst.tagging=0;
        }
        else
        {
            intinst.tagging=1;

        }
        if(intinst.t>0 && intinst.t<=1)
          {
             // cout<<intinst.t<<" ";
              Inter.push_back(intinst);

          }
    }

    sort(Inter.begin(),Inter.end(),compare);

    point p;
    for(int i=0;i<Inter.size();i++)
    {
      p=calcPoints(edgept1,edgept2,Inter[i]);
      finalPoints.push_back(p);
    }
     finalPoints.push_back(edgept2);
}


vector<point> calculation(vector<point> pEdge, vector<point> pComplete)
{

    vector<point> pCompleteEdges;
    vector<point> pEdgeEdges;
    vector<point> pCompleteNormals;

    pCompleteEdges=calcedges(pComplete);
    pEdgeEdges=calcedges(pEdge);
    pCompleteNormals=calcnormals(pCompleteEdges);

    vector<point> finalPoints;
    finalPoints.push_back(pEdge[0]);
    int n=pEdge.size();
    for(int i=0;i<pEdgeEdges.size();i++)
    {
        vector<int>numerators;
        vector<int>denominators;
        numerators=calcNum(pEdge[i],pComplete,pCompleteNormals);
        denominators=calcDen(pEdgeEdges[i],pCompleteNormals);
        calcIntersection(pEdge[i],pEdge[(i+1)%n],numerators,denominators,finalPoints);

    }
   return finalPoints;
}
