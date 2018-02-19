#include<graphics.h>
#include<bits/stdc++.h>
#define xwmin -60
#define ywmin -30
#define xwmax 60
#define ywmax 30

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

struct point{
    int x;
    int y;
};
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
void nln(point p1,point p2)
{
    int part,corner,edge;
    if(xwmin<=p1.x && p1.x<=xwmax && ywmin<=p1.y && p1.y<=ywmax)
    {
        part=1;
    }
    else if(p1.x<=xwmin && p1.y>=ywmax)
    {
        part=3;
        corner=0;
    }
    else if(p1.x>=xwmax && p1.y>=ywmax)
    {
        part=3;
        corner=1;
    }
    else if(p1.x>=xwmax && p1.y<=ywmin)
    {
        part=3;
        corner=2;
    }
    else if(p1.x<=xwmin && p1.y<=ywmin)
    {
        part=3;
        corner=3;
    }
    else if(p1.x<=xwmin)
    {
        part=2;
        edge=0;
    }
    else if(p1.y>=ywmax)
    {
        part=2;
        edge=1;
    }
    else if(p1.x>=xwmax)
    {
        part=2;
        edge=2;

    }
    else
    {
        part=2;
        edge=3;
    }
    double m=((double)(p1.y-p2.y))/(p1.x-p2.x);
    double m1=((double)(p1.y-ywmin))/(p1.x-xwmin);
    double m2=((double)(p1.y-ywmax))/(p1.x-xwmin);
    double m3=((double)(p1.y-ywmax))/(p1.x-xwmax);
    double m4=((double)(p1.y-ywmin))/(p1.x-xwmax);

   // cout<<"m="<<m<<"\nm1="<<m1<<"\nm2="<<m2<<"\nm3="<<m3<<"\nm4="<<m4;
    if(part==1)

    {

        if((m<=0 && m>=m2) || (m>0 && m<=m1))
        {
            //region 1
            if(p2.x<=xwmin)
            {
                cout<<"Clipping from left"<<endl;
                point pi=calcIntersectionPoint(p2,0,m);
                mLine(p1.x,p1.y,pi.x,pi.y,14);
            }else
            if(p2.x>=xwmax)
            {
                cout<<"Clipping from right"<<endl;
                point pi=calcIntersectionPoint(p2,2,m);
                mLine(p1.x,p1.y,pi.x,pi.y,14);
            }
        }
        else if((m<0 && m<=m2) || (m>=0 && m>=m3) )
        {
            if(p2.y>=ywmax)
            {
                cout<<"Clipping from top"<<endl;
                point pi=calcIntersectionPoint(p2,1,m);
                mLine(p1.x,p1.y,pi.x,pi.y,14);
            }
            else{
            if(p2.y<=ywmin)
            {
                cout<<"Clipping from bottom"<<endl;
                point pi=calcIntersectionPoint(p2,3,m);
                mLine(p1.x,p1.y,pi.x,pi.y,14);
            }
        }
        }
        else if(m>=m4 && m<=m3)
        {
            //region 1
            if(p2.x>=xwmax)
            {
                cout<<"Clipping from right"<<endl;
                point pi=calcIntersectionPoint(p2,1,m);
                mLine(p1.x,p1.y,pi.x,pi.y,14);
            }
        }
        else{
            if(p2.y<=ywmin)
            {
                cout<<"Clipping from bottom"<<endl;
                point pi=calcIntersectionPoint(p2,3,m);
                mLine(p1.x,p1.y,pi.x,pi.y,14);
            }
        }
    }

    else if(part==2)
    {
        if(edge==0)
        {
            //left edge
            if(m3<=m && m<=m2)
            {
                if(p2.x>=xwmin)
                {
                    if(p2.y>=ywmax)
                    {
                        cout<<"clipping from left top"<<endl;
                        point pi1=calcIntersectionPoint(p1,0,m);
                        point pi2=calcIntersectionPoint(p2,1,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from left"<<endl;
                        point pi=calcIntersectionPoint(p1,0,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }
            }
            else if(m4<=m && m<=m3)
            {
                if(p2.x>=xwmax)
                {
                    cout<<"clipping from left right"<<endl;
                     point pi1=calcIntersectionPoint(p1,0,m);
                     point pi2=calcIntersectionPoint(p2,2,m);
                     mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);

                }
                else if(p2.x>=xwmin)
                {
                    cout<<"clipping from left"<<endl;
                    point pi=calcIntersectionPoint(p1,0,m);
                    mLine(pi.x,pi.y,p2.x,p2.y,14);
                }

            } else if(m1<=m && m<=m4)
               {
                if(p2.x>=xwmin)
                {
                    if(p2.y>=ywmin)
                    {
                        cout<<"clipping from left"<<endl;
                        point pi=calcIntersectionPoint(p1,0,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from left bottom"<<endl;
                        point pi1=calcIntersectionPoint(p1,0,m);
                        point pi2=calcIntersectionPoint(p2,3,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }

                }
               }

        }
         else if(edge==1)
        {
            //top edge
            if(m<=m1 && m>=m2)
            {
                if(p2.y<=ywmax)
                {
                    //cout<<"*"<<endl;
                    if(p2.x>=xwmin)
                    {
                        cout<<"clipping from top"<<endl;
                        point pi=calcIntersectionPoint(p1,1,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from top left"<<endl;
                        point pi1=calcIntersectionPoint(p1,1,m);
                        point pi2=calcIntersectionPoint(p2,0,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }

                }
            }
            else if((m<0 && m<=m4) || (m>0 && m>=m1))
            {
                if(p2.y<=ywmin)
                {
                    cout<<"clipping from top bottom"<<endl;
                    point pi1=calcIntersectionPoint(p1,1,m);
                    point pi2=calcIntersectionPoint(p2,3,m);
                    mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                }
                else if(p2.y<=ywmax)
                {
                    cout<<"clipping from top"<<endl;
                    point pi=calcIntersectionPoint(p1,1,m);
                    mLine(pi.x,pi.y,p2.x,p2.y,14);
                }

            } else if(m<=m3 && m>=m4)
               {
                if(p2.y<=ywmax)
                {
                    if(p2.x>=xwmax)
                    {
                        cout<<"clipping from top right"<<endl;
                        point pi1=calcIntersectionPoint(p1,1,m);
                        point pi2=calcIntersectionPoint(p2,2,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from top"<<endl;
                        point pi=calcIntersectionPoint(p1,1,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }

                }
               }
        }
        else if(edge==2)
        {
            //right edge
             if(m3<=m && m<=m2)
            {
                if(p2.x<=xwmax)
                {
                    //cout<<"*"<<endl;
                    if(p2.y>=ywmax)
                    {
                        cout<<"clipping from right top"<<endl;
                        point pi1=calcIntersectionPoint(p1,2,m);
                        point pi2=calcIntersectionPoint(p2,1,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from right"<<endl;
                        point pi=calcIntersectionPoint(p1,2,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }

                }
            }
            else if(m>=m2 && m<=m1)
            {
                if(p2.x<=xwmin)
                {
                    cout<<"clipping from right left"<<endl;
                    point pi1=calcIntersectionPoint(p1,2,m);
                    point pi2=calcIntersectionPoint(p2,0,m);
                    mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                }
                else if(p2.x<=xwmax)
                {
                    cout<<"clipping from right"<<endl;
                    point pi=calcIntersectionPoint(p1,2,m);
                    mLine(pi.x,pi.y,p2.x,p2.y,14);
                }

            } else if(m1<=m && m<=m4)
               {
                if(p2.x<=xwmax)
                {
                    if(p2.y>=ywmin)
                    {
                        cout<<"clipping from right"<<endl;
                        point pi=calcIntersectionPoint(p1,2,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from right bottom"<<endl;
                        point pi1=calcIntersectionPoint(p1,2,m);
                        point pi2=calcIntersectionPoint(p2,3,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }

                }
               }

        }
        else
        {
            //bottom edge
         if(m<=m1 && m>=m2)
            {
                if(p2.y>=ywmin)
                {
                    if(p2.x>=xwmin)
                    {
                        cout<<"clipping from bottom"<<endl;
                        point pi=calcIntersectionPoint(p1,3,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from bottom left"<<endl;
                        point pi1=calcIntersectionPoint(p1,3,m);
                        point pi2=calcIntersectionPoint(p2,0,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }

                }
            }
            else if((m<0 && m<=m2) || (m>0 && m>=m3))
            {
                if(p2.y>=ywmax)
                {
                    cout<<"clipping from bottom top"<<endl;
                    point pi1=calcIntersectionPoint(p1,3,m);
                    point pi2=calcIntersectionPoint(p2,1,m);
                    mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                }
                else if(p2.y>=ywmin)
                {
                    cout<<"clipping from bottom"<<endl;
                    point pi=calcIntersectionPoint(p1,3,m);
                    mLine(pi.x,pi.y,p2.x,p2.y,14);
                }

            } else if(m<=m3 && m>=m4)
               {
                if(p2.y>=ywmin)
                {
                    if(p2.x>=xwmax)
                    {
                        cout<<"clipping from bottom right"<<endl;
                        point pi1=calcIntersectionPoint(p1,3,m);
                        point pi2=calcIntersectionPoint(p2,2,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from bottom"<<endl;
                        point pi=calcIntersectionPoint(p1,3,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }

                }
               }
        }

    }
    else
    {
        if(corner==0)
        {
            // corner top left
            if(p1.y>=abs(p1.x))
            {

                if(m>=m1 && m<=m2)
                {
                  if(p2.x>=xwmin){
                    if(p2.y<=ywmin)
                    {
                        cout<<"clipping from left bottom";
                        point pi1=calcIntersectionPoint(p1,0,m);
                        point pi2=calcIntersectionPoint(p2,3,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else if(p2.y<=ywmax)
                    {
                        cout<<"clipping from left";
                        point pi=calcIntersectionPoint(p1,0,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                  }
                }else if(m>=m2 && m<=m4)
                {
                   if(p2.x>=xwmin){
                    if(p2.y<=ywmin)
                    {
                        cout<<"clipping from top bottom";
                        point pi1=calcIntersectionPoint(p1,1,m);
                        point pi2=calcIntersectionPoint(p2,3,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else if(p2.y<ywmax)
                    {
                        cout<<"clipping from top";
                        point pi=calcIntersectionPoint(p1,1,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                   }
                }else if(m>=m4 && m<=m3)
                {
                 if(p2.y<=ywmax)
                 {
                    if(p2.x>=xwmax)
                    {
                        cout<<"clipping from top right";
                        point pi1=calcIntersectionPoint(p1,1,m);
                        point pi2=calcIntersectionPoint(p2,2,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from top";
                        point pi=calcIntersectionPoint(p1,1,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }
                }
            } else{
             if(m>=m1 && m<=m4)
                {

                  if(p2.x>=xwmin){
                    if(p2.y<=ywmin)
                    {
                        cout<<"clipping from left bottom";
                        point pi1=calcIntersectionPoint(p1,0,m);
                        point pi2=calcIntersectionPoint(p2,3,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else if(p2.y<=ywmax)
                    {
                        cout<<"clipping from left";
                        point pi=calcIntersectionPoint(p1,0,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                  }
                }else if(m>=m4 && m<=m2)
                {
                    if(p2.x>=xwmax)
                    {
                        cout<<"clipping from left right";
                        point pi1=calcIntersectionPoint(p1,0,m);
                        point pi2=calcIntersectionPoint(p2,2,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else if(p2.x>=xwmin)
                    {
                        cout<<"clipping from left";
                        point pi=calcIntersectionPoint(p1,0,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }else if(m>=m2 && m<=m3)
                {
                 if(p2.y<=ywmax)
                 {
                    if(p2.x>=xwmax)
                    {
                        cout<<"clipping from top right";
                        point pi1=calcIntersectionPoint(p1,1,m);
                        point pi2=calcIntersectionPoint(p2,2,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from top";
                        point pi=calcIntersectionPoint(p1,1,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                 }
                }
            }
        }
    else if(corner==1)
    {
         // corner top right
            if(p1.y>=p1.x)
            {
                if(m<=m1 && m>=m2)
                {
                  if(p2.y<=ywmax){
                    if(p2.x<=xwmin)
                    {
                        cout<<"clipping from top left";
                        point pi1=calcIntersectionPoint(p1,1,m);
                        point pi2=calcIntersectionPoint(p2,0,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from top";
                        point pi=calcIntersectionPoint(p1,1,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                  }
                }else if(m>=m1 && m<=m3)
                {
                    if(p2.y<=ywmin)
                    {
                        cout<<"clipping from top bottom";
                        point pi1=calcIntersectionPoint(p1,1,m);
                        point pi2=calcIntersectionPoint(p2,3,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else if(p2.y<=ywmax)
                    {
                        cout<<"clipping from top";
                        point pi=calcIntersectionPoint(p1,1,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }else if(m>=m3 && m<=m4)
                {
                 if(p2.x<=xwmax)
                 {
                    if(p2.y<=ywmin)
                    {
                        cout<<"clipping from right bottom";
                        point pi1=calcIntersectionPoint(p1,2,m);
                        point pi2=calcIntersectionPoint(p2,3,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from right";
                        point pi=calcIntersectionPoint(p1,2,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }
                }
            } else{
             if(m<=m3 && m>=m2)
                {
                  if(p2.y<=ywmax){
                    if(p2.x<=xwmin)
                    {
                        cout<<"clipping from top left";
                        point pi1=calcIntersectionPoint(p1,1,m);
                        point pi2=calcIntersectionPoint(p2,0,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from top";
                        point pi=calcIntersectionPoint(p1,1,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                  }
                }else if(m>=m3 && m<=m1)
                {
                    if(p2.x<=xwmin)
                    {
                        cout<<"clipping from right left";
                        point pi1=calcIntersectionPoint(p1,2,m);
                        point pi2=calcIntersectionPoint(p2,0,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else if(p2.x<=xwmax)
                    {
                        cout<<"clipping from right";
                        point pi=calcIntersectionPoint(p1,2,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }else if(m>=m1 && m<=m4)
                {
                 if(p2.x<=xwmax)
                 {
                    if(p2.y<=ywmin)
                    {
                        cout<<"clipping from right bottom";
                        point pi1=calcIntersectionPoint(p1,2,m);
                        point pi2=calcIntersectionPoint(p2,3,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from right";
                        point pi=calcIntersectionPoint(p1,2,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                 }
                }
            }
    }
    else if(corner==2)
    {
        // corner bottom right
        if(abs(p1.y)>=p1.x)
            {
                if(m<=m1 && m>=m2)
                {
                  if(p2.y>=ywmin){
                    if(p2.x<=xwmin)
                    {
                        cout<<"clipping from bottom left";
                        point pi1=calcIntersectionPoint(p1,3,m);
                        point pi2=calcIntersectionPoint(p2,0,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from bottom";
                        point pi=calcIntersectionPoint(p1,3,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                  }
                }else if(m>=m4 && m<=m2)
                {
                    if(p2.y>=ywmax)
                    {
                        cout<<"clipping from bottom top";
                        point pi1=calcIntersectionPoint(p1,3,m);
                        point pi2=calcIntersectionPoint(p2,1,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else if(p2.y>=ywmin)
                    {
                        cout<<"clipping from bottom";
                        point pi=calcIntersectionPoint(p1,3,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }else if(m>=m3 && m<=m4)
                {
                 if(p2.x<=xwmax)
                 {
                    if(p2.y>=ywmax)
                    {
                        cout<<"clipping from right top";
                        point pi1=calcIntersectionPoint(p1,2,m);
                        point pi2=calcIntersectionPoint(p2,1,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from right";
                        point pi=calcIntersectionPoint(p1,2,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }
                }
            }
        else{
             if(m<=m1 && m>=m4)
                {
                  if(p2.y>=ywmin){
                    if(p2.x<=xwmin)
                    {
                        cout<<"clipping from bottom left";
                        point pi1=calcIntersectionPoint(p1,3,m);
                        point pi2=calcIntersectionPoint(p2,0,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from bottom";
                        point pi=calcIntersectionPoint(p1,3,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                  }
                }else if(m>=m2 && m<=m4)
                {
                    if(p2.x<=xwmin)
                    {
                        cout<<"clipping from right left";
                        point pi1=calcIntersectionPoint(p1,2,m);
                        point pi2=calcIntersectionPoint(p2,0,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else if(p2.x<=xwmax)
                    {
                        cout<<"clipping from right";
                        point pi=calcIntersectionPoint(p1,2,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }else if(m>=m3 && m<=m2)
                {
                 if(p2.x<=xwmax)
                 {
                    if(p2.y>=ywmax)
                    {
                        cout<<"clipping from right top";
                        point pi1=calcIntersectionPoint(p1,2,m);
                        point pi2=calcIntersectionPoint(p2,1,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from right";
                        point pi=calcIntersectionPoint(p1,2,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                 }
                }
            }
    }
    else {

    // corner bottom left
            if(p1.y>=p1.x)
            {
                if(m>=m1 && m<=m2)
                {
                  if(p2.x>=xwmin){
                    if(p2.y>=ywmax)
                    {
                        cout<<"clipping from left top";
                        point pi1=calcIntersectionPoint(p1,0,m);
                        point pi2=calcIntersectionPoint(p2,1,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else if(p2.y>=ywmin)
                    {
                        cout<<"clipping from left";
                        point pi=calcIntersectionPoint(p1,0,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                  }
                }else if(m>=m3 && m<=m1)
                {
                    if(p2.y>=ywmax)
                    {
                        cout<<"clipping from bottom top";
                        point pi1=calcIntersectionPoint(p1,3,m);
                        point pi2=calcIntersectionPoint(p2,1,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else if(p2.y>=ywmin)
                    {
                        cout<<"clipping from bottom";
                        point pi=calcIntersectionPoint(p1,3,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }else if(m>=m4 && m<=m3)
                {
                 if(p2.y>=ywmin)
                 {
                    if(p2.x>=xwmax)
                    {
                        cout<<"clipping from bottom right";
                        point pi1=calcIntersectionPoint(p1,3,m);
                        point pi2=calcIntersectionPoint(p2,2,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from bottom";
                        point pi=calcIntersectionPoint(p1,3,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }
                }
            }
         else{
             if(m>=m3 && m<=m2)
                {
                  if(p2.x>=xwmin){
                    if(p2.y>=ywmax)
                    {
                        cout<<"clipping from left top";
                        point pi1=calcIntersectionPoint(p1,0,m);
                        point pi2=calcIntersectionPoint(p2,1,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from left";
                        point pi=calcIntersectionPoint(p1,0,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                  }
                }else if(m>=m1 && m<=m3)
                {
                    if(p2.x>=xwmax)
                    {
                        cout<<"clipping from left right";
                        point pi1=calcIntersectionPoint(p1,0,m);
                        point pi2=calcIntersectionPoint(p2,2,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else if(p2.x>=xwmin)
                    {
                        cout<<"clipping from left";
                        point pi=calcIntersectionPoint(p1,0,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                }else if(m>=m4 && m<=m1)
                {
                 if(p2.y>=ywmin)
                 {
                    if(p2.x>=xwmax)
                    {
                        cout<<"clipping from bottom right";
                        point pi1=calcIntersectionPoint(p1,3,m);
                        point pi2=calcIntersectionPoint(p2,2,m);
                        mLine(pi1.x,pi1.y,pi2.x,pi2.y,14);
                    }
                    else
                    {
                        cout<<"clipping from bottom";
                        point pi=calcIntersectionPoint(p1,3,m);
                        mLine(pi.x,pi.y,p2.x,p2.y,14);
                    }
                 }
                }
            }
    }
    }

}

int main(){
  int gd = DETECT, gm =0 ;
   initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();
point p1,p2,p3,p4;
p1.x=80;
p1.y=60;

p2.x=-22;
p2.y=20;

p3.x=-90;
p3.y=10;

p4.x=200;
p4.y=-11;
mLine(p1.x,p1.y,p2.x,p2.y,4);
mLine(p3.x,p3.y,p4.x,p4.y,5);
   nln(p1,p2);
   nln(p3,p4);

   mLine(xwmin,ywmin,xwmax,ywmin,15);
   mLine(xwmin,ywmin,xwmin,ywmax,15);
   mLine(xwmax,ywmax,xwmax,ywmin,15);
   mLine(xwmax,ywmax,xwmin,ywmax,15);
     getch();
  closegraph();

  return 0;

  }
