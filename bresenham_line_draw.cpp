//bresenham line draw
#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void plotgraph(int screenWidth,int screenHeight)
{
	int i,j;
	
	for(i=screenWidth/2;i<=screenWidth;i=i+10)
	{
		for(j=screenHeight/2;j<=screenHeight;j=j+10)
		{
			setcolor(MAGENTA);
			line(i,0,i,screenHeight);
			line(0,j,screenWidth,j);
		}
	}
		for(i=screenWidth/2;i>=0;i=i-10)
	{
		for(j=screenHeight/2;j>=0;j=j-10)
		{
			setcolor(MAGENTA);
			line(i,0,i,screenHeight);
			line(0,j,screenWidth,j);
		}
	}
	
	setcolor(YELLOW);
	line(0,screenHeight/2,screenWidth,screenHeight/2);
	line(screenWidth/2,0,screenWidth/2,screenHeight);
}
int main()
{
	int gd=DETECT,gm,i;
	
	int screenWidth=GetSystemMetrics(SM_CXSCREEN);
	int screenHeight=GetSystemMetrics(SM_CYSCREEN);
	
	initwindow(screenWidth,screenHeight,"window",5,5);
	plotgraph(screenWidth,screenHeight);
	
	float x,y,x0,y0,x1,y1,dx,dy,xInc,yInc,p=0;
	int step;
	
	cout<<"Enter the starting point: (x0,y0): ";
	cin>>x0>>y0;
	cout<<"Enter the ending point: (x1,y1): ";
	cin>>x1>>y1;
	
	dx=abs(x1-x0);
	dy=abs(y1-y0);
	
	if((y1-y0)/(x1-x0)<1){
	
	
	if(x0<x1){
		x=x0;
		y=y0;
		step=x1;
	}
	else
	{
		x=x1;
		y=y1;
		step=x0;
	}
    
    p=2*dy-dx;
	for(int i=x;i<step;i++)
	{
	//	setlinestyle(0,0,3);
		putpixel((screenWidth)/2+x,(screenHeight)/2-y,YELLOW);
		
		if(p<0)
		{
			y=y;
			p=p+2*dy;
		}
		else
		{
			y=y+1;
			p=p+2*dy-2*dx;
		}
		x=x+1;
		
	}
	outtextxy((screenWidth)/2+x+5,(screenHeight)/2-y-5,"Ending point");
	outtextxy((screenWidth)/2+x0+5,(screenHeight)/2-y0-5,"start point");
   }
   else
  {
		
	if(x0<x1){
		x=x0;
		y=y0;
		step=y1;
	}
	else
	{
		x=x1;
		y=y1;
		step=y0;
	}
    
    p=2*dx-dy;
	for(int i=y;i<step;i++)
	{
		//setlinestyle(0,0,3);
		putpixel((screenWidth)/2+x,(screenHeight)/2-y,YELLOW);
		
		if(p<0)
		{
			x=x;
			p=p+2*dx;
		}
		else
		{
			x=x+1;
			p=p+2*dx-2*dy;
		}
		y=y+1;
		
	}
	outtextxy((screenWidth)/2+x+5,(screenHeight)/2-y-5,"Ending point");
	outtextxy((screenWidth)/2+x0+5,(screenHeight)/2-y0-5,"start point");
   }

	getch();
}
