#include<stdio.h>
#include<graphics.h>
int X,Y;
void putPixel(int x,int y,int c)
{
    putpixel(x+X/2,-y+Y/2,c);
}
void circleSymmetry(int cx,int cy,int x,int y)
{
    putPixel(x+cx,y+cy,15);
    putPixel(x+cx,-y+cy,15);
    putPixel(-x+cx,y+cy,15);
    putPixel(-x+cx,-y+cy,15);
    putPixel(y+cx,x+cy,15);
    putPixel(y+cx,-x+cy,15);
    putPixel(-y+cx,x+cy,15);
    putPixel(-y+cx,-x+cy,15);
}
void mCircle(int cx,int cy,int r,int c)
{
    int x=0,y=r;
    int d=1-r;
    int dele=3;
    int delse=5-2*r;
    circleSymmetry(cx,cy,x,y);
    while(x<=y)
    {
        if(d<0)
        {
            d+=dele;
            dele+=2;
            delse+=2;
        }
        else{
             d+=delse;
            dele+=2;
            delse+=4;
            y--;
        }
        x++;
        circleSymmetry(cx,cy,x,y);
    }
}
int main()
{
    int gd = DETECT, gm =0 ;
  initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();

   int yc;
   for(int i=0;i<3;i++)
   {
      mCircle(0,yc,50,15);
      yc+=50;
   }

  /*
   mCircle(0,0,50,15);
   mCircle(0,100,50,15);
   mCircle(0,-100,50,15);
   mCircle(0,50,100,15);
   mCircle(0,-50,100,15);
   mCircle(0,0,150,15);
   mCircle(-119.3,0,30.7,15);
   mCircle(119.3,0,30.7,15);
   */
   getch();
   closegraph();
   return(0);
}

     getch();
   closegraph();

}
