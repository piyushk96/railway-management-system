void Cursor(int cur_x,int cur_y)    //blinking cursor
{
    while(!kbhit())
    {
      setcolor(RED);
      settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
      outtextxy(cur_x,cur_y,"_");
      delay(150);
      setcolor(WHITE);
      settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
      outtextxy(cur_x,cur_y,"_");
      delay(150);
    }
}
void Loading()
{
        int gdriver=VGA,gmode=VGAHI;
        initgraph(&gdriver,&gmode,""); 
	cleardevice();
	int i,j;
	setcolor(RED);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	outtextxy(90,150,"WELCOME TO INDIAN RAILWAYS");
	setcolor(WHITE);
	rectangle(100,250,500,260);
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tLOADING";
	for(i=100,j=110;j<=500;i+=10,j+=10)
	{
	delay(200);
	setcolor(14);
	rectangle(i,250,j,260);
	setfillstyle(1,14);
	floodfill(i+1,255,14);
	}
        closegraph();
}

//////////////////////////////////////////////////////////
int huge detectEGA(void)
{
   int driver, mode, sugmode = 0;
   detectgraph(&driver, &mode);
   if ((driver == EGA) || (driver == VGA))
      return sugmode;   // return suggested video mode number
}
//////////////////////////////////////////////////////////
int x,y;
union REGS in,out;

void Showmouse()
{
   in.x.ax = 1;
   int86 (0X33,&in,&out);
}
//////////////////////////////////////////////////////////
void Hide_mouse ()    //hiding mouse
{
	in.x.ax = 2;
	int86 (0X33,&in,&out);
}
/////////////////////////////////////////////////////////
REGS Mousecontrol(char c='o')
{
 if(c=='k')        //for kbhit loop
 {
   while (!kbhit())
   {
      in.x.ax = 3;
      int86 (0X33,&in,&out);
      if(out.x.bx==1)
	  return out;
   }
 }
 else if(c=='o')            //for 1 loop
 {
   while (1)
   {
      in.x.ax = 3;
      int86 (0X33,&in,&out);
      if(out.x.bx==1)
	  return out;
   }
 }
}
//////////////////////////////////////////////////////////
void Restrictmouse ()
{
	in.x.ax=7;
	in.x.cx=0;
	in.x.dx=getmaxx();
	int86 (0X33,&in,&out);
	in.x.ax=8;
	in.x.cx=0;
	in.x.dx=getmaxy();
	int86 (0X33,&in,&out);
}
/////////////////////////////////////////////////////////
inline void Close_button(int n)
{
  if(n==256)           //256 color screen
  {
   setcolor(4);
   int p[8];
   p[0]=290,p[1]=4,p[2]=310,p[3]=4,p[4]=310,p[5]=12,p[6]=290,p[7]=12;
   setfillstyle(SOLID_FILL,4);
   fillpoly(4,p);
   setcolor(15);
   settextstyle(2,HORIZ_DIR,1);
   setusercharsize(1,1,1,1);
   outtextxy(297,2,"X");
  }
  else if(n==16)       //16 color screen
  {
   setcolor(RED);
   rectangle(595,5,635,27);
   setfillstyle(SOLID_FILL,LIGHTRED);
   floodfill(598,8,RED);
   setcolor(WHITE);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(609,9,"X");
  }
}
void Back_button(int n)
{
  if(n==256)           //256 color screen
  {
   setcolor(2);
   int p[8];
   p[0]=2,p[1]=4,p[2]=30,p[3]=4,p[4]=30,p[5]=12,p[6]=2,p[7]=12;
   setfillstyle(SOLID_FILL,2);
   fillpoly(4,p);
   setcolor(15);
   settextstyle(2,HORIZ_DIR,1);
   setusercharsize(1,1,1,1);
   outtextxy(5,2,"BACK");
  }
  else if(n==16)
  {
   setcolor(GREEN);
   rectangle(3,5,55,27);
   setfillstyle(SOLID_FILL,LIGHTGREEN);
   floodfill(5,8,GREEN);
   setcolor(BLACK);
   settextstyle(SMALL_FONT,HORIZ_DIR,6);
   outtextxy(12,6,"BACK");
  }
}
