#include<graphics.h>
int main()
{
int x1=260,y1=250,x2=292,y2=224;
int gd = DETECT, gm =0 ;
int dx=x2-x1,dy=y2-y1,d;

initgraph(&gd,&gm,"");
line(x1,y1,x2,y2);
  d= -2*dy+dx;
 int x=x1,y=y1;
 putpixel(x,y,15);
 printf("%d %d dy=%d dx=%d d=%d ",x2,y2,dy,dx,d);
 while(x<x2)
 {

     if(d<0)
        d-=2*dy;
     else{
        d-=2*(dy-dx);
        y--;
     }
     x++;
     putpixel(x,y,15);
 }
 printf("%d %d ",x,y);
getch();
closegraph();
return 0;
}
