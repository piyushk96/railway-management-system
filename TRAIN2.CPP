#include"EXTRA_FN.CPP"
int Passwordscreen()
{
   int i=0,j,Passcur,Usercur;
   char p[20],u[20],a[1],r;
   for(j=0;j<20;j++)
   p[j]=0,u[j]=0;
   closegraph();
   Repeat:
    int gdriver=VGA,gmode=VGAHI;
    initgraph(&gdriver,&gmode,"");

    cleardevice();
    gotoxy(15,25);
    cout<<"Press Escape Button To Exit This Screen..............";
    setcolor(RED);
    rectangle(170,120,470,360);          //red out
    rectangle(180,130,460,350);          //red in
    setfillstyle(SOLID_FILL,RED);
    floodfill(171,151,RED);
    setcolor(BLUE);
    rectangle(181,131,459,349);         //gray box
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(182,132,BLUE);
    setcolor(WHITE);
    rectangle(220,220,421,240);          //white box up
    rectangle(220,280,421,300);          //white box down
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(221,221,WHITE);
    floodfill(221,281,WHITE);
    setcolor(GREEN);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    outtextxy(260,145,"LOGIN");
    setcolor(YELLOW);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
    outtextxy(220,195,"USERNAME:");
    outtextxy(220,255,"PASSWORD:");
    for(i=0,Usercur=230;i<20;i++,Usercur+=9)   //enter username
    {
      Cursor(Usercur,230);
      u[i]=getch();
      u[i]=toupper(u[i]);
      if(u[i]==13)
      {
	u[i]='\0';
	break;
      }
      if(u[i]==27)   //exit
	return 0;
      else if(u[i]==8)
      {
	if(i<=0)
	{
	  i--;
	  Usercur-=9;
	  continue;
	}
	else
	{
	  i--;
	  Usercur-=9;
	  a[0]=u[i];
	  a[1]='\0';
	  setcolor(WHITE);
	  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	  outtextxy(Usercur,228,a);
	  u[i]=0;
	  i--;
	  Usercur-=9;
	}
      }
      else
      {
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(Usercur,230,"_");
	 a[0]=u[i];
	 a[1]='\0';
	setcolor(BLACK);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(Usercur,228,a);
      }
    }
    for(i=0,Passcur=230;i<20;i++,Passcur+=9)   //enter password
    {
      Cursor(Passcur,290);
      p[i]=getch();
      p[i]=toupper(p[i]);
      if(p[i]==13)
      {
	p[i]='\0';
	break;
      }
      if(p[i]==27)   //exit
	return 0;
      else if(p[i]==8)
      {
	if(i<=0)
	{
	  i--;
	  Passcur-=9;
	  continue;
	}
	else
	{
	  i--;
	  Passcur-=9;
	  setcolor(WHITE);
	  settextstyle(3,HORIZ_DIR,3);
	  outtextxy(Passcur,276,"*");
	  p[i]=0;
	  i--;
	  Passcur-=9;
	}
      }
      else
      {
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(Passcur,290,"_");
	setcolor(BLACK);
	settextstyle(3,HORIZ_DIR,3);
	outtextxy(Passcur,276,"*");
      }
    }
    if(strcmp(p,"TRAIN")==0&&strcmp(u,"TRAIN")==0)    //checking password
      return 1;  			     //and username
    else
    {
      setcolor(LIGHTCYAN);
      outtextxy(220,315,"WRONG_USERNAME_OR_PASSWORD");
      outtextxy(220,330,"PRESS_ENTER_TO_CONTINUE");
      getch();
      goto Repeat;
    }                      //password screen end
}
int Mainscreen()
{
   cleardevice();
   setbkcolor(BLACK);        //for data box
   setcolor(YELLOW);
   rectangle(0,30,639,479);
   setfillstyle(SOLID_FILL,YELLOW);
   floodfill(3,33,YELLOW);
   setcolor(LIGHTBLUE);
   setlinestyle(SOLID_LINE,SOLID_LINE,3);
   rectangle(1,2,638,30);
   setfillstyle(SOLID_FILL,BLUE);
   floodfill(5,5,LIGHTBLUE);

   Close_button(16);
   setcolor(MAGENTA);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
   outtextxy(210,30,"SERVICES");
   setfillstyle(SOLID_FILL,MAGENTA);
   bar(205,80,395,82);
   setcolor(GREEN);
   rectangle(60,100,460,140);
   rectangle(160,160,570,200);
   rectangle(60,220,460,260);
   rectangle(160,280,570,320);
   rectangle(60,340,460,380);
   rectangle(160,400,570,440);
   rectangle(500,40,630,70);   //admin login
   setfillstyle(SOLID_FILL,LIGHTCYAN);
   floodfill(64,104,GREEN);
   floodfill(164,164,GREEN);
   floodfill(64,224,GREEN);
   floodfill(164,284,GREEN);
   floodfill(164,344,GREEN);
   floodfill(164,404,GREEN);
   setfillstyle(SOLID_FILL,LIGHTMAGENTA);
   floodfill(504,44,GREEN);
   setcolor(BLUE);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
   outtextxy(75,100,"1. TICKET RESERVATION");
   outtextxy(175,160,"2. TRAIN SCHEDULE");
   outtextxy(75,220,"3. TICKET FARE DETAILS");
   outtextxy(175,280,"4. TRAIN NAME & NUMBER");
   outtextxy(75,340,"5. BOOKING STATUS");
   outtextxy(175,400,"6. TICKET CANCELLATION");
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   outtextxy(505,40,"ADMIN LOGIN");
   for(;;)
   {
     Showmouse();
     Restrictmouse();
     out=Mousecontrol();
     x=out.x.cx;
     y=out.x.dx;
     Hide_mouse();
     if(x>=60 && x<=460 && y>=100 && y<=140)
       return 1;
     else if(x>=160 && x<=570 && y>=160 && y<=200)
       return 2;
     else if(x>=60 && x<=460 && y>=220 && y<=260)
       return 3;
     else if(x>=160 && x<=570 && y>=280 && y<=320)
       return 4;
     else if(x>=60 && x<=460 && y>=340 && y<=380)
       return 5;
     else if(x>=160 && x<=570 && y>=400 && y<=440)
       return 6;
     else if(x>=500 && x<=630 && y>=40 && y<=70)   //ADMIN LOGIN
       return 7;
     else if(x>=595 && x<=634 && y>=6 && y<=26)
       exit(0);
   }
}
int Adminscreen()
{
   int gdriver,gmode;
   gdriver=installuserdriver("VGA256",detectEGA);  //install a user written device driver
   gdriver=DETECT;      //must force use of detection routine
   initgraph(&gdriver, &gmode,"");
   cleardevice();
   setcolor(YELLOW);
   int p[8]={0,1,317,1,317,15,0,15};  //polygon
   setfillstyle(SOLID_FILL,34);    //purple
   fillpoly(4,p);

   p[0]=0,p[1]=15,p[2]=317,p[3]=15,p[4]=317,p[5]=199,p[6]=0,p[7]=199;
   setfillstyle(SOLID_FILL,65);     //orange back
   fillpoly(4,p);

   setcolor(6);
   settextstyle(10,HORIZ_DIR,1);
   outtextxy(120,10,"MENU");
   Close_button(256);

   setcolor(104);
   p[0]=255,p[1]=20,p[2]=310,p[3]=20,p[4]=310,p[5]=32,p[6]=255,p[7]=32;
   setfillstyle(SOLID_FILL,85);    //pink sign out
   fillpoly(4,p);
   setcolor(RED);
   settextstyle(2,HORIZ_DIR,5);
   setusercharsize(1,1,1,1);
   outtextxy(260,20,"SIGN OUT");

   setcolor(32);
   p[0]=55,p[1]=55,p[2]=255,p[3]=55,p[4]=255,p[5]=70,p[6]=55,p[7]=70;
   setfillstyle(SOLID_FILL,50);
   fillpoly(4,p);
   outtextxy(63,57,"1:TO ADD A TRAIN");

   p[0]=55,p[1]=85,p[2]=255,p[3]=85,p[4]=255,p[5]=100,p[6]=55,p[7]=100;
   setfillstyle(SOLID_FILL,50);
   fillpoly(4,p);
   outtextxy(63,87,"2:TO DISPLAY DETAILS OF A TRAIN");

   p[0]=55,p[1]=115,p[2]=255,p[3]=115,p[4]=255,p[5]=130,p[6]=55,p[7]=130;
   setfillstyle(SOLID_FILL,50);
   fillpoly(4,p);
   outtextxy(63,117,"3:TO DELETE DETAILS OF A TRAIN");

   p[0]=55,p[1]=145,p[2]=255,p[3]=145,p[4]=255,p[5]=160,p[6]=55,p[7]=160;
   setfillstyle(SOLID_FILL,50);
   fillpoly(4,p);
   outtextxy(63,147,"4:TO MODIFY DETAILS OF A TRAIN");

   p[0]=55,p[1]=175,p[2]=255,p[3]=175,p[4]=255,p[5]=190,p[6]=55,p[7]=190;
   setfillstyle(SOLID_FILL,50);
   fillpoly(4,p);
   outtextxy(63,177,"5:TO RESET ALL THE DATA");

   Showmouse();
   for(;;)
   {
     out=Mousecontrol();
     x=out.x.cx;
     y=out.x.dx;
     if(x>=110 && x<=508 && y>=55 && y<=70)
     {
       closegraph();
       return 1;
     }
     else if(x>=110 && x<=508 && y>=85 && y<=100)
     {
       closegraph();
       return 2;
     }
     else if(x>=110 && x<=508 && y>=115 && y<=130)
     {
       closegraph();
       return 3;
     }
     else if(x>=110 && x<=508 && y>=145 && y<=160)
     {
       //closegraph();
       return 4;
     }
     else if(x>=110 && x<=508 && y>=175 && y<=190)
     {
       closegraph();
       return 5;
     }
     else if(x>=510 && x<=618 && y>=20 && y<=32)   //sign out
     {
       closegraph();
       return 6;
     }
     else if(x>=580 && x<=620 && y>=4 && y<=12)    //close
       exit(0);
   }
}
int Modifyscreen()
{
   Hide_mouse();
   cleardevice();
   setcolor(60);
   int p[8]={0,1,317,1,317,15,0,15};  //polygon
   setfillstyle(SOLID_FILL,34);    //purple
   fillpoly(4,p);

   p[0]=0,p[1]=16,p[2]=317,p[3]=16,p[4]=317,p[5]=199,p[6]=0,p[7]=199;
   setfillstyle(SOLID_FILL,70);     //green back
   fillpoly(4,p);

   setcolor(6);
   settextstyle(10,HORIZ_DIR,1);
   setusercharsize(1,2,1,2);
   outtextxy(110,15,"MODIFY");
   setfillstyle(SOLID_FILL,6);
   bar(104,49,197,51);
   Close_button(256);
   Back_button(256);

   settextstyle(2,HORIZ_DIR,1);
   setusercharsize(1,1,1,1);
   setcolor(41);
   p[0]=35,p[1]=68,p[2]=275,p[3]=68,p[4]=275,p[5]=83,p[6]=35,p[7]=83;
   setfillstyle(SOLID_FILL,68);
   fillpoly(4,p);
   outtextxy(41,70,"1:TO MODIFY TRAIN NAME OR TRAIN NUMBER");

   p[0]=35,p[1]=98,p[2]=275,p[3]=98,p[4]=275,p[5]=113,p[6]=35,p[7]=113;
   setfillstyle(SOLID_FILL,68);
   fillpoly(4,p);
   outtextxy(41,100,"2:TO MODIFY DETAILS OF STATION IN ROUTE");

   p[0]=35,p[1]=128,p[2]=275,p[3]=128,p[4]=275,p[5]=143,p[6]=35,p[7]=143;
   setfillstyle(SOLID_FILL,68);
   fillpoly(4,p);
   outtextxy(42,130,"3:TO MODIFY DETAILS OF BOGGE IN A TRAIN");

   Showmouse();
   for(;;)
   {
     out=Mousecontrol();
     x=out.x.cx;
     y=out.x.dx;
     if(x>=70 && x<=548 && y>=68 && y<=83)
       return 1;
     else if(x>=70 && x<=548 && y>=98 && y<=113)
       return 2;
     else if(x>=70 && x<=548 && y>=128 && y<=143)
       return 3;
     else if(x>=4 && x<=60 && y>=4 && y<=13)   //back
       return 4;
     else if(x>=580 && x<=620 && y>=4 && y<=12)    //close
       exit(0);
   }
}

