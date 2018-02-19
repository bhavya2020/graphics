#include<stdio.h>
#include<graphics.h>
int X,Y;
void putPixel(int x,int y,int c)
{
    putpixel(x+X/2,-y+Y/2,c);
}
void ellipseSymmetry(int xc,int yc,int x,int y)
{
    putPixel(x+xc,y+yc,15);
    putPixel(x+xc,-y+yc,15);
    putPixel(-x+xc,y+yc,15);
    putPixel(-x+xc,-y+yc,15);
}
void mEllipse(int xc,int yc,int a,int b,int c)
{
    int x=a,y=0;
    int d=b*b/4-b*b*a+a*a;
    int dels=3*a*a;
    int delsw=3*a*a+2*b*b-2*b*b*a;
    ellipseSymmetry(xc,yc,x,y);
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
        ellipseSymmetry(xc,yc,x,y);
    }

    int delw=3*b*b-2*b*x*b;
    delsw=3*b*b-2*b*b*x+2*a*a-2*a*a*y;
    ellipseSymmetry(xc,yc,x,y);
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
        ellipseSymmetry(xc,yc,x,y);
    }
}
int main()
{
    int gd = DETECT, gm =0 ;
  initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();
   putPixel(0,0,15);
  mEllipse(100,50,100,50,15);

     getch();
   closegraph();

}
