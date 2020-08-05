#include <stdio.h>
#include <math.h>
#include <X11/Xlib.h>
#include <string.h>
#include <X11/Xutil.h>
#include <unistd.h>
#define BORDER 2
#define WIDTH  500
#define HIGHT 500
int main(int argc, char **argv)
{
  int screen,j=0,k,x,y,flag=0,xx,yy;
  float v0,kaku,g=-9.8,pi=3.14159265,h,i,highest=0,sub[256];
  char moji[256],hyouji[256],ji1[256],ji2[256],ji3[256],po[256];
  printf("初速度と投げ上げ角を入力");
  scanf("%f",&v0);
  scanf("%f",&kaku);
  printf("初速度=%4.1f[m/s] 投げ上げ角=%4.1f° \n",v0,kaku);
  Display *dpy;
  Window w,quit;
  Window root;
  unsigned long black, white;
  GC gc;
  XEvent e;
  XFontSet fs;
  char **miss,*def;
  int n_miss;
  Colormap cmap;
  XColor c0,c1;
  dpy = XOpenDisplay("");
  fs=XCreateFontSet(dpy,"-*-*-medium-r-normal-*-16-*",&miss,&n_miss,&def);
  root = DefaultRootWindow (dpy);
  screen = DefaultScreen (dpy);
  white = WhitePixel (dpy, screen);
  black = BlackPixel (dpy, screen);
  cmap = DefaultColormap(dpy,0);
  XAllocNamedColor(dpy,cmap,"green",&c1,&c0);
  w = XCreateSimpleWindow(dpy,root,100,100,WIDTH,HIGHT,BORDER,black,white);
  quit = XCreateSimpleWindow(dpy, w, 10, 3, 30, 12, BORDER, black, white);
  gc = XCreateGC(dpy, w, 0, NULL);
  XSelectInput(dpy, w, ButtonPressMask);
  XSelectInput(dpy, quit, ButtonPressMask);
  XMapWindow(dpy, w);
  XMapSubwindows(dpy, w);
  XSetForeground(dpy,gc,black);
  while(1){
	if(XEventsQueued(dpy,QueuedAfterReading))
  	{
	XNextEvent(dpy, &e);
	switch(e.type){
	case ButtonPress :
  	if(e.xbutton.button==3){
    	xx=e.xbutton.x;
    	yy=e.xbutton.y;
    	sprintf(po,"Point");
    	XDrawString(dpy,w,gc,xx,yy,po,strlen(po));     	 
    	i=0;
    	while(i<8){
      	h=398.0-(((xx-50)*i*sin((tan(400-yy/xx-50)*pi)/180.0))+((1.0/2.0)*g*i*i))*50;  
      	XFillArc(dpy,w,gc,49+((xx-50)*cos((tan(400-yy/xx-50)*pi)/180)*i),h,6,6,0*64,360*64);
      	i=i+0.1;
      	sub[j]=h;
      	j++;
      	if(j>1000)j=0;
      	if(h>500){
    	highest=sub[0];
    	for(k=1;k<j;k++){
      	if(highest>sub[k])highest=sub[k];    	 
    	}
    	if(flag==0){
      	sprintf(hyouji,"Highest Point = %4.1f ",398.0-highest);
      	XDrawString(dpy,w,gc,180,highest-15,hyouji,strlen(hyouji));     	 
      	flag=1;
    	}
      	}
      	usleep(50000);
      	XFlush(dpy);
    	}
  	}
  	if(e.xany.window==quit)return 0;
  	if(e.xbutton.button==2)XClearWindow(dpy,w);     	 
  	if(e.xbutton.button==1){
    	i=0;
    	while(i<20.0){
      	h=398.0-((v0*i*sin((kaku*pi)/180.0))+((1.0/2.0)*g*i*i));     	 
      	XFillArc(dpy,w,gc,49+(v0*cos((kaku*pi)/180.0)*i),h,6,6,0*64,360*64);
      	i=i+0.5;
      	sub[j]=h;
      	j++;
      	if(j>50)j=0;
      	if(h>500){
    	highest=sub[0];
    	for(k=1;k<j;k++){
      	if(highest>sub[k])highest=sub[k];
    	}
    	if(flag==0){
      	sprintf(hyouji,"Highest Point = %4.1f ",398.0-highest);
      	XDrawString(dpy,w,gc,180,highest-15,hyouji,strlen(hyouji));
      	flag=1;
    	}
      	}
      	usleep(50000);
      	XFlush(dpy);
    	}
  	}
  	flag=0;
	}
  	}
	else{
  	XDrawString(dpy,quit,gc,4,10,"Exit",4);
  	XFillRectangle(dpy,w,gc,0,403,50,100);
  	sprintf(ji1,"left click = first input data");
  	XDrawString(dpy,w,gc,60,15,ji1,strlen(ji1));
  	sprintf(ji2,"center click = clear window");
  	XDrawString(dpy,w,gc,60,27,ji2,strlen(ji2));
  	sprintf(ji3,"right click = throw to there");
  	XDrawString(dpy,w,gc,60,39,ji3,strlen(ji3));
	}
  }
}
