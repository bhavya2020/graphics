#include<stdio.h>
#include<graphics.h>
int X,Y;
void putPixel(int x,int y,int c)
{
    putpixel(x+X/2,-y+Y/2,c);
}
void circleSymmetry(int cx,int cy,int x,int y,int c,int s)
{
    switch(s)
    {
        case 1:putPixel(x+cx,y+cy,c);
               putPixel(x+cx,-y+cy,0);
               putPixel(-x+cx,y+cy,c);
               putPixel(-x+cx,-y+cy,0);
               putPixel(y+cx,x+cy,c);
               putPixel(y+cx,-x+cy,0);
               putPixel(-y+cx,x+cy,c);
               putPixel(-y+cx,-x+cy,0);
               break;
        case 2:putPixel(x+cx,y+cy,c);
               putPixel(x+cx,-y+cy,c);
               putPixel(-x+cx,y+cy,0);
               putPixel(-x+cx,-y+cy,0);
               putPixel(y+cx,x+cy,c);
               putPixel(y+cx,-x+cy,c);
               putPixel(-y+cx,x+cy,0);
               putPixel(-y+cx,-x+cy,0);
               break;
        case 3:putPixel(x+cx,y+cy,0);
               putPixel(x+cx,-y+cy,c);
               putPixel(-x+cx,y+cy,0);
               putPixel(-x+cx,-y+cy,c);
               putPixel(y+cx,x+cy,0);
               putPixel(y+cx,-x+cy,c);
               putPixel(-y+cx,x+cy,0);
               putPixel(-y+cx,-x+cy,c);
               break;
        case 4:putPixel(x+cx,y+cy,0);
               putPixel(x+cx,-y+cy,0);
               putPixel(-x+cx,y+cy,c);
               putPixel(-x+cx,-y+cy,c);
               putPixel(y+cx,x+cy,0);
               putPixel(y+cx,-x+cy,0);
               putPixel(-y+cx,x+cy,c);
               putPixel(-y+cx,-x+cy,c);
               break;
    }

}
void mCircle(int cx,int cy,int r,int c,int s)
{
    int x=0,y=r;
    int d=1-r;
    int dele=3;
    int delse=5-2*r;
    circleSymmetry(cx,cy,x,y,c,s);
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
        circleSymmetry(cx,cy,x,y,c,s);
    }
}
int main()
{
    int gd = DETECT, gm =0 ;
  initgraph(&gd,&gm,"");
   X=getmaxx();
   Y=getmaxy();

   mCircle(0,-50,50,15,2);
   mCircle(0, 50,50,15,4);
   mCircle(0,-150,50,15,4);
   mCircle(0, 150,50,15,2);
   mCircle(-50,0,50,15,3);
   mCircle(50,0,50,15,1);
   mCircle(-150,0,50,15,1);
   mCircle(150,0,50,15,3);
   mCircle(0,100,100,15,4);
   mCircle(0,-100,100,15,2);
   mCircle(100,0,100,15,1);
   mCircle(-100,0,100,15,3);

   getch();
   closegraph();
   return(0);
}
