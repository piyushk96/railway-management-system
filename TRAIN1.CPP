#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>
#include<ctype.h>
#include"TRAIN2.CPP"
struct Time
{
   char Hr[3],Min[3];
   Time()
   {
       Hr[0],Min[0],Hr[1],Min[1],Hr[2],Min[2]='\0';
   }
};
struct Date
{
   int dd[2],mm[2],yy[4];
   Date()
   {
      dd[0]=0,mm[0]=0,yy[0]=0;
   }
};
struct Station_det
{
   char Dayno[2];   // day no. train started from source stn.
   float Distance;  // distance from source stn.
   char Stn_name[20];
   Time Arr_time,Dep_time;
   Station_det()
   {
      Dayno[0]=0,Distance=0;
      strcpy(Stn_name,"NULL");
   }
   int St_input(int Stn_no);
   void St_display(int no);
};
int Station_det::St_input(int Stn_no)
{
   char ch;
   int i;
   Dep_time.Hr[0]=Dep_time.Min[0]=Dep_time.Hr[1]=Dep_time.Min[1]=Dep_time.Hr[2]=Dep_time.Min[2]='\0';
   Arr_time.Hr[0]=Arr_time.Min[0]=Arr_time.Hr[1]=Arr_time.Min[1]=Arr_time.Hr[2]=Arr_time.Min[2]='\0';
   if(Stn_no==0)
   {
     gotoxy(1,10);
     cout<<" Source Station Name=";
     gets(Stn_name);
     for(i=0;Stn_name[i]!='\0';i++)
	Stn_name[i]=toupper(Stn_name[i]);
     cout<<" Departure Time:-";
     gotoxy(25,11);
     cout<<" Hour=";
     gets(Dep_time.Hr);
     if(Dep_time.Hr[1]=='\0')
     {
       Dep_time.Hr[1]=Dep_time.Hr[0];
       Dep_time.Hr[0]='0';
     }
     gotoxy(45,11);
     cout<<" Minutes=";
     gets(Dep_time.Min);
     if(Dep_time.Min[1]=='\0')
     {
       Dep_time.Min[1]=Dep_time.Min[0];
       Dep_time.Min[0]='0';
     }
     return 1;
   }
   else if(Stn_no==1)
   {
     gotoxy(1,12);
     cout<<" Destination Station Name=";
     gets(Stn_name);
     for(i=0;Stn_name[i]!='\0';i++)
	Stn_name[i]=toupper(Stn_name[i]);
     cout<<" Arrival Time:-";
     gotoxy(25,13);
     cout<<" Hour=";
     gets(Arr_time.Hr);
     if(Arr_time.Hr[1]=='\0')
     {
       Arr_time.Hr[1]=Arr_time.Hr[0];
       Arr_time.Hr[0]='0';
     }
     gotoxy(45,13);
     cout<<" Minutes=";
     gets(Arr_time.Min);
     if(Arr_time.Min[1]=='\0')
     {
       Arr_time.Min[1]=Arr_time.Min[0];
       Arr_time.Min[0]='0';
     }
     cout<<" Distance From Source Station(in km)=";
     cin>>Distance;
     cout<<" Days Passed From Start Of Train=";
     gets(Dayno);
     gotoxy(1,18);
     cout<<" PRESS ANY KEY TO CONTINUE..................";
     getch();
     gotoxy(1,18);
     cout<<"                                            ";
     return 1;
   }
   else
   {
     gotoxy(1,15);
     cout<<"\n ENTER DETAILS OF STATION NUMBER "<<Stn_no+1<<":-"
	 <<"\n Station Name=";
     gets(Stn_name);
     for(i=0;Stn_name[i]!='\0';i++)
	Stn_name[i]=toupper(Stn_name[i]);
     cout<<" Arrival Time:-";
     gotoxy(25,18);
     cout<<" Hour=";
     gets(Arr_time.Hr);
     if(Arr_time.Hr[1]=='\0')
     {
       Arr_time.Hr[1]=Arr_time.Hr[0];
       Arr_time.Hr[0]='0';
     }
     gotoxy(45,18);
     cout<<" Minutes=";
     gets(Arr_time.Min);
     if(Arr_time.Min[1]=='\0')
     {
       Arr_time.Min[1]=Arr_time.Min[0];
       Arr_time.Min[0]='0';
     }
     cout<<" Departure Time:-";
     gotoxy(25,19);
     cout<<" Hour=";
     gets(Dep_time.Hr);
     if(Dep_time.Hr[1]=='\0')
     {
       Dep_time.Hr[1]=Dep_time.Hr[0];
       Dep_time.Hr[0]='0';
     }
     gotoxy(45,19);
     cout<<" Minutes=";
     gets(Dep_time.Min);
     if(Dep_time.Min[1]=='\0')
     {
       Dep_time.Min[1]=Dep_time.Min[0];
       Dep_time.Min[0]='0';
     }
     cout<<" Distance From Source Station(in km)=";
     cin>>Distance;
     cout<<" Days Passed From Start Of Train=";
     gets(Dayno);
   }
}
void Station_det::St_display(int no)
{
   if(no==0)
   {
     gotoxy(1,10);
     cout<<" Source Station Name="<<Stn_name
	 <<"\n Departure Time:-";
     gotoxy(25,11);
     cout<<" Hour="<<Dep_time.Hr;
     gotoxy(45,11);
     cout<<" Minutes="<<Dep_time.Min;
   }
   else if(no==1)
   {
     gotoxy(1,12);
     cout<<" Destination Station Name="<<Stn_name
	 <<"\n Arrival Time:-";
     gotoxy(25,13);
     cout<<" Hour="<<Arr_time.Hr;
     gotoxy(45,13);
     cout<<" Minutes="<<Arr_time.Min;
     cout<<"\n Distance From Source Station(in km)="<<Distance;
     cout<<"\n Days Passed From Start Of Train="<<Dayno;
   }
   else
   {
     setcolor(YELLOW);
     setfillstyle(SOLID_FILL,YELLOW);
     outtextxy(10,203,"DETAILS OF ROUTE(Except Source & Destination):-");
     bar(8,233,565,235);
     gotoxy(1,15);
     cout<<"\n DETAILS OF STATION NUMBER "<<no+1<<":-"
	 <<"\n Station Name="<<Stn_name
	 <<"\n Arrival Time:-";
     gotoxy(25,18);
     cout<<" Hour="<<Arr_time.Hr;
     gotoxy(45,18);
     cout<<" Minutes="<<Arr_time.Min;
     cout<<"\n Departure Time:-";
     gotoxy(25,19);
     cout<<" Hour="<<Dep_time.Hr;
     gotoxy(45,19);
     cout<<" Minutes="<<Dep_time.Min;
     cout<<"\n Distance From Source Station(in km)="<<Distance;
     cout<<"\n Days Passed From Start Of Train="<<Dayno;
   }
}
struct Seat_det
{
   int Bogge_no,Total_seats,Seats_bkd;
   char Bogge_type[10];
   float Rate;
   Seat_det()
   {
       Rate=0,Bogge_no=0,Total_seats=0,Seats_bkd=0;
       strcpy(Bogge_type,"NULL");
   }
   void Se_input();
   void Se_display();
};
void Seat_det::Se_input()
{
   char ch;
   int i;
   gotoxy(1,15);
   cout<<"\n Bogge Number=";
   cin>>Bogge_no;
   cout<<" Bogge Type=";
   gets(Bogge_type);
   for(i=0;Bogge_type[i]!='\0';i++)
      Bogge_type[i]=toupper(Bogge_type[i]);
   cout<<" Total Number Of Seats in bogge=";
   cin>>Total_seats;
   cout<<" Rate of the seat=";
   cin>>Rate;
}
void Seat_det::Se_display()
{
   setcolor(YELLOW);
   setfillstyle(SOLID_FILL,YELLOW);
   outtextxy(10,203,"DETAILS OF SEAT:-");
   bar(8,233,195,235);
   gotoxy(1,15);

   cout<<"\n Bogge Number="<<Bogge_no
       <<"\n Bogge Type="<<Bogge_type
       <<"\n Total Number Of Seats in bogge="<<Total_seats
       <<"\n Rate of the seat="<<Rate;
}
class Train_det    //class for details of a train
{
   char Train_name[20],Train_no[7];
   public:
   int Stationno,Seatno;
   Station_det Route[25];
   Seat_det Seat[20];
   Train_det()
   {
     strcpy(Train_no,'\0'),strcpy(Train_name,'\0');
   }
   void T_input();
   void T_display();
   char* Ret_name()
   {
       return Train_name;
   }
   char* Ret_number()
   {
       return Train_no;
   }
};
void Train_det::T_input()
{
   gotoxy(1,8);
   cout<<" Train Number=";
   gets(Train_no);
   cout<<" Train Name=";
   gets(Train_name);
   for(int i=0;Train_name[i]!='\0';i++)
      Train_name[i]=toupper(Train_name[i]);
}
void Train_det::T_display()
{
   setcolor(YELLOW);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   setusercharsize(3,4,3,4);
   outtextxy(10,78,"DETAILS OF TRAIN:-");
   setfillstyle(SOLID_FILL,YELLOW);
   bar(8,108,225,110);

   gotoxy(1,8);
   cout<<" Train Number="<<Train_no
       <<"\n Train Name="<<Train_name;
}
class Booking
{
   public:
   char Train_no[7],Seat_type[10],Train_name[20],Board_stn[20],Deboard_stn[20];
   char Name[20],Address[20],Pincode[10];
   char Status[20],Contactno[15],Sex[10];
   long Ticketno;
   Booking()
   {
     strcpy(Train_no,"NULL");
     strcpy(Train_name,"NULL");
     strcpy(Board_stn,"NULL");
     strcpy(Deboard_stn,"NULL");
     strcpy(Seat_type,"NULL");
     strcpy(Name,"NULL");
     strcpy(Address,"NULL");
     strcpy(Pincode,"NULL");
     strcpy(Contactno,"NULL");
     strcpy(Sex,"NULL");
     strcpy(Status,"NULL");
     Ticketno=10000;
   }
};
void Create()
{
  int gdriver=VGA,gmode=VGAHI,a,b;
  initgraph(&gdriver,&gmode,"");
  Train_det Train;
  char ch;
  fstream fout("TRN_DET.DAT",ios::app|ios::binary);
  do
  {
    cleardevice();
    setbkcolor(BLUE);
    setcolor(LIGHTRED);
    settextstyle(7,HORIZ_DIR,4);
    outtextxy(200,5,"ENTER DETAILS");
    setfillstyle(SOLID_FILL,LIGHTRED);
    bar(195,40,470,42);

    setcolor(YELLOW);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    setusercharsize(3,4,3,4);
    outtextxy(10,78,"DETAILS OF TRAIN:-");
    setfillstyle(SOLID_FILL,YELLOW);
    bar(8,108,225,110);
    Train.T_input();
    int Stn_no=0,Tot_seat=0;
    do
    {
      if(Stn_no>1)
      {
	setcolor(BLUE);
	int p[8]={5,205,570,205,570,475,5,475};
	setfillstyle(SOLID_FILL,BLUE);
	fillpoly(4,p);
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	outtextxy(10,203,"DETAILS OF ROUTE(Except Source & Destination):-");
	bar(8,233,565,235);
      }
      a=Train.Route[Stn_no].St_input(Stn_no);
      if(Stn_no>1)
      {
	gotoxy(1,24);
	cout<<" WANT TO ADD MORE STATIONS IN ROUTE(Y/N)..............";
	ch=getch();
	gotoxy(1,24);
	cout<<"                                                      ";
	if((ch=='y'||ch=='Y')&&Stn_no<25)
	  a=1;
	else
	  a=0;
      }
      Stn_no++;
    }while(a==1);
    Train.Stationno=Stn_no;
    do
    {
      setcolor(BLUE);
      int p[8]={5,205,570,205,570,475,5,475};
      setfillstyle(SOLID_FILL,BLUE);
      fillpoly(4,p);
      setcolor(YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      outtextxy(10,203,"DETAILS OF SEAT:-");
      bar(8,233,225,235);

      Train.Seat[Tot_seat].Se_input();
      gotoxy(1,24);
      cout<<" WANT TO ADD MORE TYPES OF SEATS(Y/N)..............";
      ch=getch();
      gotoxy(1,24);
      cout<<"                                                   ";
      if((ch=='y'||ch=='Y')&&Tot_seat<20)
	b=1;
      else
	b=0;
      Tot_seat++;
    }while(b==1);
    Train.Seatno=Tot_seat;
    fout.write((char*)&Train,sizeof(Train));
    gotoxy(1,25);
    cout<<" WANT TO ADD MORE TRAINS(Y/N).............";
    gotoxy(1,25);
    ch=getch();
    cout<<"                                          ";
  }while(ch=='Y'||ch=='y');
  fout.close();
}
void Show()
{
  int gdriver=VGA,gmode=VGAHI,flag=0,no,sno;
  initgraph(&gdriver,&gmode,"");
  char ch,Inquiry[20];
  Train_det Train;
  do
  {
    ifstream fin("TRN_DET.DAT",ios::binary);
    cleardevice();
    setbkcolor(BLUE);
    setcolor(LIGHTRED);
    settextstyle(7,HORIZ_DIR,4);
    outtextxy(200,5,"SEE DETAILS");
    setfillstyle(SOLID_FILL,LIGHTRED);
    bar(195,40,420,42);
    gotoxy(1,4);
    cout<<"\n ENTER THE TRAIN NAME OR TRAIN NUMBER TO SEE DETAILS=";
    gets(Inquiry);
    flag=0;
    while(fin.read((char*)&Train,sizeof(Train)))
    {
     if(strcmpi(Train.Ret_number(),Inquiry)==0||strcmpi(Train.Ret_name(),Inquiry)==0)
     {
       no=0,sno=0;
       Train.T_display();
       do
       {
	 setcolor(BLUE);
	 int p[8]={5,205,570,205,570,475,5,475};
	 setfillstyle(SOLID_FILL,BLUE);
	 fillpoly(4,p);
	 Train.Route[no].St_display(no);
	 if(no==1||no==0)
	 {
	   gotoxy(1,18);
	   cout<<" PRESS ANY KEY TO CONTINUE..................";
	   getch();
	   gotoxy(1,18);
	   cout<<"                                            ";
	 }
	 else if(no>1)
	 {
	   gotoxy(1,24);
	   cout<<" PRESS ANY KEY TO SEE NEXT............";
	   getch();
	   gotoxy(1,24);
	   cout<<"                                      ";
	 }
	 no++;
       }while(no<Train.Stationno&&no<25);
       do
       {
	 setcolor(BLUE);
	 int p[8]={5,205,570,205,570,475,5,475};
	 setfillstyle(SOLID_FILL,BLUE);
	 fillpoly(4,p);

	 Train.Seat[sno].Se_display();
	 gotoxy(1,24);
	 cout<<" PRESS ANY KEY TO SEE NEXT............";
	 getch();
	 gotoxy(1,24);
	 cout<<"                                      ";
	 sno++;
       }while(sno<Train.Seatno&&sno<20);
       flag=1;
       break;
     }
    }
    fin.close();
    if(flag==0)
      cout<<"\n\n Entered Train name or Train number is not valid.";
    cout<<"\n\n WANT TO SEE DETAILS OF MORE TRAINS(Y/N).............";
    ch=getch();
  }while(ch=='Y'||ch=='y');
}
void Delete()
{
  int gdriver=VGA,gmode=VGAHI;
  initgraph(&gdriver,&gmode,"");
  char ch,Inquiry[20];
  Train_det Train;
  do
  {
    ifstream fin("TRN_DET.DAT",ios::binary);
    ofstream fout("Temporary.dat",ios::binary);

    cleardevice();
    setbkcolor(RED);
    setcolor(LIGHTGREEN);
    settextstyle(7,HORIZ_DIR,4);
    outtextxy(200,5,"DELETE TRAIN");
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    bar(195,40,445,42);
    gotoxy(1,4);
    cout<<" ENTER THE TRAIN NAME OR TRAIN NUMBER TO DELETE RECORDS=";
    gets(Inquiry);
    int flag=0,no,sno;
    while(fin.read((char*)&Train,sizeof(Train)))
    {
     if(strcmpi(Train.Ret_number(),Inquiry)==0||strcmpi(Train.Ret_name(),Inquiry)==0)
     {
       no=0,sno=0;
       Train.T_display();
       do
       {
	 setcolor(RED);
	 int p[8]={5,205,570,205,570,475,5,475};
	 setfillstyle(SOLID_FILL,RED);
	 fillpoly(4,p);
	 Train.Route[no].St_display(no);
	 if(no==1||no==0)
	 {
	   gotoxy(1,18);
	   cout<<" PRESS ANY KEY TO CONTINUE..................";
	   getch();
	   gotoxy(1,18);
	   cout<<"                                            ";
	 }
	 else if(no>1)
	 {
	   gotoxy(1,24);
	   cout<<" PRESS ANY KEY TO SEE NEXT............";
	   getch();
	   gotoxy(1,24);
	   cout<<"                                      ";
	 }
	 no++;
       }while(no<Train.Stationno&&no<25);
       do
       {
	 setcolor(RED);
	 int p[8]={5,205,570,205,570,475,5,475};
	 setfillstyle(SOLID_FILL,RED);
	 fillpoly(4,p);

	 Train.Seat[sno].Se_display();
	 gotoxy(1,24);
	 cout<<" PRESS ANY KEY TO SEE NEXT............";
	 getch();
	 gotoxy(1,24);
	 cout<<"                                      ";
	 sno++;
       }while(sno<Train.Seatno&&sno<20);
       flag=1;

       gotoxy(1,24);
       cout<<" ARE YOU SURE YOU WANT DELETE(Y/N).........";
       ch=getch();
       if(ch=='N'||ch=='n')
	 fout.write((char*)&Train,sizeof(Train));
       else
	 cout<<"\n DATA DELETED SUCCESSFULLY";
     }
     else
       fout.write((char*)&Train,sizeof(Train));
    }
    fout.close();
    fin.close();
    remove("TRN_DET.DAT");
    rename("Temporary.dat","TRN_DET.DAT");
    if(flag==0)
      cout<<"\n Entered Train name or Train number is not valid.";
    cout<<"\n WANT TO DELETE DETAILS OF MORE TRAINS(Y/N).............";
    ch=getch();
  }while(ch=='Y'||ch=='y');
}
void Reset()
{
  int gdriver=VGA,gmode=VGAHI;
  char ch;
  initgraph(&gdriver,&gmode,"");
  cleardevice();
  setbkcolor(RED);
  setcolor(LIGHTGREEN);
  settextstyle(7,HORIZ_DIR,4);
  outtextxy(200,5,"RESET DATA");
  setfillstyle(SOLID_FILL,LIGHTGREEN);
  bar(195,40,410,42);
  gotoxy(1,5);
  cout<<" Are you sure you want to reset all the data(y/n)........";
  do
  {
    ch=getch();
  }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
  if(ch=='y'||ch=='Y')
  {
    rename("TRN_DET.DAT","T_BACKUP.DAT");
    remove("TRN_DET.DAT");
    gotoxy(1,8);
    cout<<"File has been successfully reseted"
	<<"\n\nBackup of your file has been created named as T_BACKUP.DAT";
  }
  gotoxy(1,12);
  cout<<"PRESS ANY KEY TO RETURN.............";
  getch();
}
void Edit(int b)
{
  closegraph();
  int gdriver=VGA,gmode=VGAHI;
  initgraph(&gdriver,&gmode,"");
  cleardevice();
  Train_det Train,Temptrain;
  char ch,ch2,ch3,ch4,Inquiry[20],name[20],num[7];
  int flag,p[8],no=2,n=0;

  setbkcolor(BROWN);
  setcolor(YELLOW);
  p[0]=0,p[1]=450,p[2]=639,p[3]=450,p[4]=639,p[5]=479,p[6]=0,p[7]=479;
  setfillstyle(SOLID_FILL,LIGHTGRAY);
  fillpoly(4,p);
  rectangle(1,451,638,478);
  setcolor(LIGHTGREEN);
  settextstyle(7,HORIZ_DIR,4);
  outtextxy(200,5,"MODIFY DETAILS");
  setfillstyle(SOLID_FILL,LIGHTGREEN);
  bar(195,40,480,42);

  setcolor(BLUE);
  settextstyle(1,HORIZ_DIR,2);
  outtextxy(10,451,"ENTER NEW DATA:");
  outtextxy(283,451,"SEE NEXT:");
  outtextxy(503,451,"SAVE:");
  setcolor(RED);
  outtextxy(200,451,"Alt-N");
  outtextxy(393,451,"Alt-E");
  outtextxy(563,451,"Alt-S");
  switch(b)
  {
    case 1:do
      {
	ifstream fin("TRN_DET.DAT",ios::binary);
	ofstream fout("Temporary.DAT",ios::binary);
	setcolor(BROWN);
	p[0]=1,p[1]=50,p[2]=639,p[3]=50,p[4]=639,p[5]=447,p[6]=1,p[7]=447;
	setfillstyle(SOLID_FILL,6);
	fillpoly(4,p);
	gotoxy(1,4);
	cout<<"\n ENTER THE TRAIN NAME OR TRAIN NUMBER TO MODIFY DETAILS=";
	gets(Inquiry);
	flag=0;
	while(fin.read((char*)&Train,sizeof(Train)))
	{
	 if(strcmpi(Train.Ret_number(),Inquiry)==0||strcmpi(Train.Ret_name(),Inquiry)==0)
	 {
	   Train.T_display();
	   Temptrain=Train;
	  againenter1:
	   gotoxy(1,13);
	   cout<<" PRESS ANY OF THESE KEYS TO CONTINUE..................";
	   ch=getch();
	   cout<<"                                                      ";

	   if(ch==49)
	   {
	     setcolor(BROWN);
	     p[0]=1,p[1]=50,p[2]=639,p[3]=50,p[4]=639,p[5]=400,p[6]=1,p[7]=400;
	     setfillstyle(SOLID_FILL,6);
	     fillpoly(4,p);
	     setcolor(YELLOW);
	     settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	     setusercharsize(3,4,3,4);
	     outtextxy(10,78,"ENTER NEW DATA:-");
	     setfillstyle(SOLID_FILL,YELLOW);
	     bar(8,108,225,110);

	     Temptrain.T_input();
	   }
	   else if(ch==31)
	   {
	     cout<<"\n\n ARE YOU SURE YOU WANT SAVE CHANGES(Y/N).........";
	     ch=getch();
	     if(ch=='Y'||ch=='y')
	     {
	      fout.write((char*)&Temptrain,sizeof(Temptrain));
	      cout<<"\n DATA SAVED SUCCESSFULLY";
	     }
	     else if(ch=='N'||ch=='n')
	      fout.write((char*)&Train,sizeof(Train));
	     flag=1;
	     break;
	   }
	   goto againenter1;
	 }
	 else
	   fout.write((char*)&Train,sizeof(Train));
	}
	fout.close();
	fin.close();
	remove("TRN_DET.DAT");
	rename("Temporary.dat","TRN_DET.DAT");

	if(flag==0)
	  cout<<"\n\n Entered Train name or Train number is not valid.";
	cout<<"\n\n WANT TO MODIFY DETAILS OF MORE TRAINS(Y/N).............";
	ch=getch();
      }while(ch=='Y'||ch=='y');
    break;
    case 2:do
      {
	ifstream fin("TRN_DET.DAT",ios::binary);
	ofstream fout("Temporary.DAT",ios::binary);
	setcolor(BROWN);
	p[0]=1,p[1]=50,p[2]=639,p[3]=50,p[4]=639,p[5]=447,p[6]=1,p[7]=447;
	setfillstyle(SOLID_FILL,6);
	fillpoly(4,p);
	gotoxy(1,4);
	cout<<"\n ENTER THE TRAIN NAME OR TRAIN NUMBER TO MODIFY DETAILS=";
	gets(Inquiry);
	flag=0,no=2;
	while(fin.read((char*)&Train,sizeof(Train)))
	{
	 if(strcmpi(Train.Ret_number(),Inquiry)==0||strcmpi(Train.Ret_name(),Inquiry)==0)
	 {
	   setcolor(YELLOW);
	   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	   setusercharsize(3,4,3,4);
	   outtextxy(10,98,"DETAILS OF STATION:-");
	   setfillstyle(SOLID_FILL,YELLOW);
	   bar(8,128,235,130);

	   Train.Route[0].St_display(0);
	   Temptrain=Train;
	  againenter2:
	   gotoxy(1,18);
	   cout<<" PRESS ANY OF THESE KEYS TO CONTINUE..................";
	   ch=getch();
	   gotoxy(1,18);
	   cout<<"                                                      ";

	   if(ch==49)
	   {
	     setcolor(BROWN);
	     p[0]=1,p[1]=50,p[2]=639,p[3]=50,p[4]=639,p[5]=400,p[6]=1,p[7]=400;
	     setfillstyle(SOLID_FILL,6);
	     fillpoly(4,p);
	     setcolor(YELLOW);
	     settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	     setusercharsize(3,4,3,4);
	     outtextxy(10,78,"ENTER NEW DATA:-");
	     setfillstyle(SOLID_FILL,YELLOW);
	     bar(8,108,225,110);

	     Temptrain.Route[0].St_input(0);
	   }
	   else if(ch==31)
	   {
	     cout<<"\n\n ARE YOU SURE YOU WANT SAVE CHANGES(Y/N).........";
	     ch=getch();
	     if(ch=='Y'||ch=='y')
	     {
	      fout.write((char*)&Temptrain,sizeof(Temptrain));
	      cout<<"\n DATA SAVED SUCCESSFULLY";
	     }
	     else if(ch=='N'||ch=='n')
	      fout.write((char*)&Train,sizeof(Train));
	     flag=1;
	     break;
	   }
	   else if(ch==18)
	     goto next1;
	   goto againenter2;

	  next1:
	   Train.Route[1].St_display(1);
	   Temptrain=Train;
	  againenter3:
	   gotoxy(1,16);
	   cout<<" PRESS ANY OF THESE KEYS TO CONTINUE..................";
	   ch2=getch();
	   gotoxy(1,16);
	   cout<<"                                                      ";

	   if(ch2==49)
	   {
	     setcolor(BROWN);
	     p[0]=1,p[1]=50,p[2]=639,p[3]=50,p[4]=639,p[5]=400,p[6]=1,p[7]=400;
	     setfillstyle(SOLID_FILL,6);
	     fillpoly(4,p);
	     setcolor(YELLOW);
	     settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	     setusercharsize(3,4,3,4);
	     outtextxy(10,78,"ENTER NEW DATA:-");
	     setfillstyle(SOLID_FILL,YELLOW);
	     bar(8,108,225,110);

	     Temptrain.Route[1].St_input(1);
	   }
	   else if(ch2==31)
	   {
	     cout<<"\n\n ARE YOU SURE YOU WANT SAVE CHANGES(Y/N).........";
	     ch3=getch();
	     if(ch3=='Y'||ch3=='y')
	     {
	      fout.write((char*)&Temptrain,sizeof(Temptrain));
	      cout<<"\n DATA SAVED SUCCESSFULLY";
	     }
	     else if(ch3=='N'||ch3=='n')
	      fout.write((char*)&Train,sizeof(Train));
	     flag=1;
	     break;
	   }
	   else if(ch2==18)
	     goto next2;
	   goto againenter3;

	   next2:
	   setcolor(BROWN);
	   int p[8]={5,205,570,205,570,400,5,400};
	   setfillstyle(SOLID_FILL,BROWN);
	   fillpoly(4,p);
	   Train.Route[no].St_display(no);
	   Temptrain=Train;
	  againenter4:
	   gotoxy(1,24);
	   cout<<" PRESS ANY OF THESE KEYS TO CONTINUE..................";
	   ch3=getch();
	   gotoxy(1,24);
	   cout<<"                                                      ";

	   if(ch3==49)
	   {
	     setcolor(BROWN);
	     p[0]=1,p[1]=50,p[2]=639,p[3]=50,p[4]=639,p[5]=400,p[6]=1,p[7]=400;
	     setfillstyle(SOLID_FILL,6);
	     fillpoly(4,p);
	     setcolor(YELLOW);
	     settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	     setusercharsize(3,4,3,4);
	     outtextxy(10,203,"ENTER NEW DATA:-");
	     setfillstyle(SOLID_FILL,YELLOW);
	     bar(8,233,225,235);

	     Temptrain.Route[no].St_input(no);
	   }
	   else if(ch3==31)
	   {
	     cout<<"\n\n ARE YOU SURE YOU WANT SAVE CHANGES(Y/N).........";
	     ch4=getch();
	     if(ch4=='Y'||ch4=='y')
	     {
	      fout.write((char*)&Temptrain,sizeof(Temptrain));
	      cout<<"\n DATA SAVED SUCCESSFULLY";
	     }
	     else if(ch4=='N'||ch4=='n')
	      fout.write((char*)&Train,sizeof(Train));
	     flag=1;
	     break;
	   }
	   else if(ch3==18&&(no+1)<Train.Stationno)
	   {
	     no++;
	     goto next2;
	   }
	   goto againenter4;
	 }
	 else
	   fout.write((char*)&Train,sizeof(Train));
	}
	fout.close();
	fin.close();
	remove("TRN_DET.DAT");
	rename("Temporary.dat","TRN_DET.DAT");

	if(flag==0)
	  cout<<"\n\n Entered Train name or Train number is not valid.";
	cout<<"\n WANT TO MODIFY DETAILS OF MORE TRAINS(Y/N).............";
	ch=getch();
      }while(ch=='Y'||ch=='y');
    break;
    case 3:do
      {
	ifstream fin("TRN_DET.DAT",ios::binary);
	ofstream fout("Temporary.DAT",ios::binary);
	setcolor(BROWN);
	p[0]=1,p[1]=50,p[2]=639,p[3]=50,p[4]=639,p[5]=447,p[6]=1,p[7]=447;
	setfillstyle(SOLID_FILL,6);
	fillpoly(4,p);
	gotoxy(1,4);
	cout<<"\n ENTER THE TRAIN NAME OR TRAIN NUMBER TO MODIFY DETAILS=";
	gets(Inquiry);
	flag=0,n=0;
	while(fin.read((char*)&Train,sizeof(Train)))
	{
	 if(strcmpi(Train.Ret_number(),Inquiry)==0||strcmpi(Train.Ret_name(),Inquiry)==0)
	 {
	   nexts:
	   setcolor(BROWN);
	   int p[8]={5,205,570,205,570,400,5,400};
	   setfillstyle(SOLID_FILL,BROWN);
	   fillpoly(4,p);
	   Train.Seat[n].Se_display();
	   Temptrain=Train;
	  againent:
	   gotoxy(1,24);
	   cout<<" PRESS ANY OF THESE KEYS TO CONTINUE..................";
	   ch3=getch();
	   gotoxy(1,24);
	   cout<<"                                                      ";

	   if(ch3==49)
	   {
	     setcolor(BROWN);
	     p[0]=1,p[1]=50,p[2]=639,p[3]=50,p[4]=639,p[5]=400,p[6]=1,p[7]=400;
	     setfillstyle(SOLID_FILL,6);
	     fillpoly(4,p);
	     setcolor(YELLOW);
	     settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	     setusercharsize(3,4,3,4);
	     outtextxy(10,203,"ENTER NEW DATA:-");
	     setfillstyle(SOLID_FILL,YELLOW);
	     bar(8,233,225,235);

	     Temptrain.Seat[n].Se_input();
	   }
	   else if(ch3==31)
	   {
	     cout<<"\n\n ARE YOU SURE YOU WANT SAVE CHANGES(Y/N).........";
	     ch4=getch();
	     if(ch4=='Y'||ch4=='y')
	     {
	      fout.write((char*)&Temptrain,sizeof(Temptrain));
	      cout<<"\n DATA SAVED SUCCESSFULLY";
	     }
	     else if(ch4=='N'||ch4=='n')
	      fout.write((char*)&Train,sizeof(Train));
	     flag=1;
	     break;
	   }
	   else if(ch3==18&&(n+1)<Train.Seatno)
	   {
	     n++;
	     goto nexts;
	   }
	   goto againent;
	 }
	 else
	   fout.write((char*)&Train,sizeof(Train));
	}
	fout.close();
	fin.close();
	remove("TRN_DET.DAT");
	rename("Temporary.dat","TRN_DET.DAT");

	if(flag==0)
	  cout<<"\n\n Entered Train name or Train number is not valid.";
	cout<<"\n WANT TO MODIFY DETAILS OF MORE TRAINS(Y/N).............";
	ch=getch();
      }while(ch=='Y'||ch=='y');
    break;
  }
}
void Train_schedule()
{
 again:
 Train_det Train;
 char r='1',e[20];
 int p[8];

 cleardevice();
 setbkcolor(LIGHTRED);        //for data box
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
 Back_button(16);
 setcolor(MAGENTA);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
 outtextxy(210,60,"TRAIN SCHEDULE");
 setfillstyle(SOLID_FILL,MAGENTA);
 bar(210,100,470,102);

 setcolor(GREEN);
 settextstyle(3,HORIZ_DIR,1);
 outtextxy(10,138," ENTER TRAIN NAME OR TRAIN NUMBER :");
 setcolor(LIGHTRED);
 rectangle(400,138,580,165);
 setfillstyle(SOLID_FILL,LIGHTRED);
 floodfill(404,142,LIGHTRED);
 setcolor(BLUE);
 rectangle(235,200,395,230);
 setfillstyle(SOLID_FILL,LIGHTBLUE);
 floodfill(245,205,BLUE);
 setcolor(LIGHTRED);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
 outtextxy(245,202,"GET SCHEDULE");
 int i=0,x3=52,x1=408,x2=413;

 int flag=0;
 for(int l=0;l<20;l++)
   e[l]='\0';
 gotoxy(52,10);
 do
 {
   magain:
    Showmouse();
    Restrictmouse();
    out=Mousecontrol('k');
    if(out.x.bx==1)
    {
      x=out.x.cx;
      y=out.x.dx;
      Hide_mouse();
      if(x>=595 && x<=634 && y>=6 && y<=26)
	exit(0);
      else if(x>=3 && x<=55 && y>=5 && y<=27)
	return;
      else if(x>=236 && x<=394 && y>=201 && y<=229)
	break;     //schedule
      else
	goto magain;
    }
    else
    {
      Hide_mouse();
      setcolor(LIGHTRED);
      rectangle(400,138,580,165);
      setfillstyle(SOLID_FILL,LIGHTRED);
      floodfill(404,142,LIGHTRED);
      gotoxy(x3,10);
      e[i]=getch();
      if(e[i]==8&&i>0)
      {
	e[i]=e[i-1]='\0';
	x1-=8,x2-=8;
	p[0]=x1,p[1]=142,p[2]=x2,p[3]=142,p[4]=x2,p[5]=161,p[6]=x1,p[7]=161;
	setfillstyle(SOLID_FILL,LIGHTRED);
	fillpoly(4,p);
	i-=1;
	x3-=1;
      }
      else if(isalnum(e[i]))
      {
	cout<<e[i];
	i++,x3++,x1+=8,x2+=8;
      }
      else if(e[i]==13)
      {
	 e[i]='\0';
	 break;
      }
      else
	continue;
    }
 }while(1);
 e[i]='\0';
 ifstream fin("TRN_DET.DAT",ios::binary);
 while(fin.read((char*)&Train,sizeof(Train)))
 {
   if(strcmpi(Train.Ret_name(),e)==0||strcmpi(Train.Ret_number(),e)==0)
   {
     flag=1;
     setbkcolor(BLACK);
     cleardevice();
     setcolor(YELLOW);
     rectangle(0,30,639,479);
     setfillstyle(SOLID_FILL,YELLOW);
     floodfill(3,33,YELLOW);
     setcolor(LIGHTBLUE);
     setlinestyle(SOLID_LINE,SOLID_LINE,3);
     rectangle(1,2,638,30);
     setfillstyle(SOLID_FILL,BLUE);
     floodfill(5,5,LIGHTBLUE);
     setlinestyle(SOLID_LINE,SOLID_LINE,2);
     setcolor(GREEN);
     settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
     outtextxy(248,30,"TRAIN ROUTE");
     setfillstyle(SOLID_FILL,GREEN);
     bar(246,59,399,61);
     rectangle(144,79,504,126);
     line(144,103,504,103);
     setfillstyle(SOLID_FILL,LIGHTRED);
     floodfill(147,82,GREEN);
     setfillstyle(SOLID_FILL,WHITE);
     floodfill(147,106,GREEN);
     line(300,79,300,126);

     rectangle(22,143,500,173);
     setfillstyle(SOLID_FILL,LIGHTRED);
     floodfill(24,145,GREEN);
     line(55,143,55,173);
     line(276,143,276,173);
     line(346,143,346,173);
     line(416,143,416,173);
     line(500,143,500,173);
     setcolor(BLACK);
     settextstyle(SMALL_FONT,HORIZ_DIR,6);
     outtextxy(165,82,"TRAIN NUMBER");
     outtextxy(355,82,"TRAIN NAME");
     settextstyle(SMALL_FONT,HORIZ_DIR,5);
     outtextxy(27,150,"SNo.");
     outtextxy(115,150,"STATION NAME");
     outtextxy(285,144,"ARRIVAL");
     outtextxy(297,156,"TIME");
     outtextxy(358,144,"DEPART.");
     outtextxy(367,156,"TIME");
     outtextxy(448,150,"DAY");

     setcolor(BLACK);
     outtextxy(195,107,Train.Ret_number());
     outtextxy(325,107,Train.Ret_name());
     int y1=25;
     char r1[2];
     for(int j=0,tyup=173,tydown=193;j<Train.Stationno;j++,tyup+=20,tydown+=20)
     {
       setcolor(GREEN);
       rectangle(22,tyup,500,tydown);
       setfillstyle(SOLID_FILL,WHITE);
       floodfill(25,tyup+3,GREEN);
       line(55,tyup,55,tydown);
       line(276,tyup,276,tydown);
       line(346,tyup,346,tydown);
       line(416,tyup,416,tydown);
       line(500,tyup,500,tydown);
       setcolor(BLACK);
       if(j==1)
       {
	 tyup-=20,tydown-=20;
	 continue;
       }
       else if(j==0)
       {
	  outtextxy(35,tyup+3,"1");
	  setcolor(MAGENTA);
	  outtextxy(288,tyup+3,"SOURCE");
	  setcolor(BLACK);
	  outtextxy(450,tyup+3,"0");
       }
       else
       {
	  r1[0]=++r,r1[1]='\0';
	  outtextxy(35,tyup+3,r1);
	  outtextxy(290,tyup+3,Train.Route[j].Arr_time.Hr);
	  outtextxy(300,tyup+2," : ");
	  outtextxy(315,tyup+3,Train.Route[j].Arr_time.Min);
	  outtextxy(450,tyup+3,Train.Route[j].Dayno);
       }
       outtextxy(75,tyup+3,Train.Route[j].Stn_name);
       outtextxy(360,tyup+3,Train.Route[j].Dep_time.Hr);
       outtextxy(370,tyup+2," : ");
       outtextxy(385,tyup+3,Train.Route[j].Dep_time.Min);
     }
     setcolor(GREEN);
     rectangle(22,tyup,500,tydown);
     setfillstyle(SOLID_FILL,WHITE);
     floodfill(25,tyup+3,GREEN);
     line(55,tyup,55,tydown);
     line(276,tyup,276,tydown);
     line(346,tyup,346,tydown);
     line(416,tyup,416,tydown);
     setcolor(BLACK);
     r1[0]=++r,r1[1]='\0';
     outtextxy(35,tyup+3,r1);
     outtextxy(75,tyup+3,Train.Route[1].Stn_name);
     outtextxy(290,tyup+3,Train.Route[1].Arr_time.Hr);
     outtextxy(300,tyup+2," : ");
     outtextxy(315,tyup+3,Train.Route[1].Arr_time.Min);
     outtextxy(450,tyup+3,Train.Route[1].Dayno);
     setcolor(MAGENTA);
     outtextxy(349,tyup+3,"DESTINAT.");

     Close_button(16);
     Back_button(16);
     Showmouse();
     while(1)
     {
       out=Mousecontrol('o');
       x=out.x.cx;
       y=out.x.dx;
       if(x>=595 && x<=634 && y>=6 && y<=26)
	 exit(0);
       else if(x>=5 && x<=54 && y>=7 && y<=26)
       {
	 Hide_mouse();
	 break;
       }
     }
   }
   else
     continue;
 }
 if(flag==0)
 {
   setcolor(BLUE);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
   outtextxy(100,250,"SORRY, NO MATCH FOUND.");
   outtextxy(100,270,"PRESS ANY KEY TO RE ENTER.");
   getch();
   goto again;
 }
 else if(flag==1)
   goto again;
 fin.close();
}
void Fare()
{
  Train_det Train;
  int i=0,j=0,g=0;
 again2:
  char num[7],board[20],deboard[20],type[10];
  cleardevice();
  setbkcolor(RED);        //for data box
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
  Back_button(16);
  setcolor(MAGENTA);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(210,60,"FARE ENQUIRY");
  setfillstyle(SOLID_FILL,MAGENTA);
  bar(210,100,430,102);

  setcolor(GREEN);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  outtextxy(170,120,"ENTER FOLLOWING DETAILS:");
  setcolor(BLUE);
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(85,183,"           TRAIN NUMBER :");
  outtextxy(70,216,"  BOARDING STATION NAME :");
  outtextxy(68,250,"DEBOARDING STATION NAME :");
  outtextxy(82,281,"             BOGGE TYPE :");
  setcolor(RED);
  rectangle(364,189,579,211);
  rectangle(364,222,579,242);
  rectangle(364,254,579,275);
  rectangle(364,285,579,306);
  setfillstyle(SOLID_FILL,RED);
  floodfill(367,192,RED);
  floodfill(367,227,RED);
  floodfill(367,257,RED);
  floodfill(367,288,RED);
  setcolor(BLUE);
  rectangle(227,341,346,368);
  setfillstyle(SOLID_FILL,BLUE);
  floodfill(230,345,BLUE);
  setcolor(WHITE);
  outtextxy(240,341,"GET FARE");

  while(1)
  {
    Showmouse();
    Restrictmouse();
    out=Mousecontrol();
    x=out.x.cx;
    y=out.x.dx;
    Hide_mouse();
    if(x>=595 && x<=634 && y>=6 && y<=26)
	 exit(0);
    else if(x>=3 && x<=55 && y>=5 && y<=27)
       return;
    else if(x>=364 && x<=579 && y>=189 && y<=211)
    {
      setcolor(BLUE);
      rectangle(364,189,579,211);
      gotoxy(47,13);
      gets(num);
      setcolor(RED);
      rectangle(364,189,579,211);
    }
    else if(x>=364 && x<=579 && y>=222 && y<=242)
    {
      setcolor(BLUE);
      rectangle(364,222,579,242);
      gotoxy(47,15);
      gets(board);
      setcolor(RED);
      rectangle(364,222,579,242);
    }
    else if(x>=364 && x<=579 && y>=254 && y<=275)
    {
      setcolor(BLUE);
      rectangle(364,254,579,275);
      gotoxy(47,17);
      gets(deboard);
      setcolor(RED);
      rectangle(364,254,579,275);
    }
    else if(x>=364 && x<=579 && y>=285 && y<=306)
    {
      setcolor(BLUE);
      rectangle(364,285,579,306);
      gotoxy(47,19);
      gets(type);
      setcolor(RED);
      rectangle(364,285,579,306);
    }
    else if(x>=227 && x<=346 && y>=341 && y<=384)
      break;
    else
      continue;
  }
  ifstream fin("TRN_DET.DAT",ios::binary);
  int flag=0;
  while(fin.read((char*)&Train,sizeof(Train)))
  {
   if(strcmpi(Train.Ret_number(),num)==0)
   {
    for(i=0;i<Train.Stationno;i++)
    {
     if(strcmpi(Train.Route[i].Stn_name,board)==0)
     {
      for(j=i+1;j<Train.Stationno;j++)
      {
	if(strcmpi(Train.Route[j].Stn_name,deboard)==0)
	{
	  for(g=0;g<Train.Seatno;g++)
	  {
	    if(strcmpi(Train.Seat[g].Bogge_type,type)==0)
	    {
	      flag=1;
	      break;
	    }
	    if(flag==1)
	      break;
	  }
	  if(flag==1)
	    break;
	}
      if(flag==1)
	break;
      }
      if(flag==1)
	break;
     }
     if(flag==1)
      break;
    }
    if(flag==1)
      break;
   }
   else
     continue;
  }
  if(flag==0)
  {
    setcolor(BLUE);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
    outtextxy(100,380,"SORRY, NO MATCH FOUND.");
    outtextxy(100,400,"PRESS ANY KEY TO RE ENTER.");
    getch();
    goto again2;
  }
  else if(flag==1)
  {
    setbkcolor(BLACK);
    cleardevice();
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
    Back_button(16);
    setcolor(MAGENTA);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
    outtextxy(270,40,"FARE");
    setfillstyle(SOLID_FILL,MAGENTA);
    bar(265,75,350,77);

    setlinestyle(SOLID_LINE,SOLID_LINE,2);
    setcolor(GREEN);
    rectangle(144,99,504,146);
    line(144,123,504,123);
    setfillstyle(SOLID_FILL,LIGHTRED);
    floodfill(147,102,GREEN);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(147,126,GREEN);
    line(300,99,300,146);
    setcolor(BLACK);
    settextstyle(SMALL_FONT,HORIZ_DIR,6);
    outtextxy(165,100,"TRAIN NUMBER");
    outtextxy(355,100,"TRAIN NAME");
    setcolor(BLACK);
    outtextxy(195,122,Train.Ret_number());
    outtextxy(325,122,Train.Ret_name());

    setcolor(GREEN);
    rectangle(200,195,430,375);
    line(200,220,430,220);
    setfillstyle(SOLID_FILL,LIGHTRED);
    floodfill(203,203,GREEN);
    line(315,195,315,375);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(203,228,GREEN);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(318,228,GREEN);

    line(200,250,430,250);
    line(200,275,430,275);
    line(200,300,430,300);
    line(200,325,430,325);
    line(200,350,430,350);
    setcolor(BLACK);

    settextstyle(SMALL_FONT,HORIZ_DIR,5);
    outtextxy(214,199,"CHARGE TYPE");
    outtextxy(334,199,"COST(In Rs.)");
    outtextxy(220,224,"BASE FARE");
    outtextxy(210,254,"DISTANCE FARE");
    outtextxy(210,279,"FOOD CHARGES");
    outtextxy(214,299,"RESERVATION");
    outtextxy(214,309,"  CHARGE");
    outtextxy(214,329,"SERVICE TAX");
    outtextxy(214,354," TOTAL FARE");
    setcolor(WHITE);
    int r=0,t=0;
    float d=0;
      gotoxy(45,15);
    cout<<Train.Seat[g].Rate;

    d=Train.Route[j].Distance-Train.Route[i].Distance;
    r=d*4;
      gotoxy(45,17);
    cout<<r;
    outtextxy(350,279,"250");
    outtextxy(350,304,"50");
    outtextxy(350,329,"50");

    t=Train.Seat[g].Rate+r+350;
      gotoxy(45,23);
    cout<<t;
    fin.close();

    Showmouse();
    Restrictmouse();
    while(1)
    {
       out=Mousecontrol('o');
       x=out.x.cx;
       y=out.x.dx;
       if(x>=595 && x<=634 && y>=6 && y<=26)
	 exit(0);
       else if(x>=5 && x<=54 && y>=7 && y<=26)
       {
	 Hide_mouse();
	 break;
       }
     }
     goto again2;
  }
}
void Book()
{
 again3:
  Booking B;
  Train_det Train;
  int i=0,j=0,g=0;
  char num[7],board[20],deboard[20],type[10];
  cleardevice();
  setbkcolor(RED);        //for data box
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
  Back_button(16);
  setcolor(MAGENTA);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(210,40,"TICKET BOOKING");
  setfillstyle(SOLID_FILL,MAGENTA);
  bar(210,80,455,82);

  setcolor(GREEN);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  outtextxy(170,120,"ENTER FOLLOWING DETAILS:");
  setcolor(BLUE);
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(85,183,"           TRAIN NUMBER :");
  outtextxy(70,216,"  BOARDING STATION NAME :");
  outtextxy(68,250,"DEBOARDING STATION NAME :");
  outtextxy(82,281,"             BOGGE TYPE :");
  setcolor(RED);
  rectangle(364,189,579,211);
  rectangle(364,222,579,242);
  rectangle(364,254,579,275);
  rectangle(364,285,579,306);
  setfillstyle(SOLID_FILL,RED);
  floodfill(367,192,RED);
  floodfill(367,227,RED);
  floodfill(367,257,RED);
  floodfill(367,288,RED);
  setcolor(BLUE);
  rectangle(227,341,346,368);
  setfillstyle(SOLID_FILL,BLUE);
  floodfill(230,345,BLUE);
  setcolor(WHITE);
  outtextxy(240,341,"  BOOK  ");

  while(1)
  {
    Showmouse();
    Restrictmouse();
    out=Mousecontrol();
    x=out.x.cx;
    y=out.x.dx;
    Hide_mouse();
    if(x>=595 && x<=634 && y>=6 && y<=26)
	 exit(0);
    else if(x>=3 && x<=55 && y>=5 && y<=27)
       return;
    else if(x>=364 && x<=579 && y>=189 && y<=211)
    {
      setcolor(BLUE);
      rectangle(364,189,579,211);
      gotoxy(47,13);
      gets(num);
      setcolor(RED);
      rectangle(364,189,579,211);
    }
    else if(x>=364 && x<=579 && y>=222 && y<=242)
    {
      setcolor(BLUE);
      rectangle(364,222,579,242);
      gotoxy(47,15);
      gets(board);
      setcolor(RED);
      rectangle(364,222,579,242);
    }
    else if(x>=364 && x<=579 && y>=254 && y<=275)
    {
      setcolor(BLUE);
      rectangle(364,254,579,275);
      gotoxy(47,17);
      gets(deboard);
      setcolor(RED);
      rectangle(364,254,579,275);
    }
    else if(x>=364 && x<=579 && y>=285 && y<=306)
    {
      setcolor(BLUE);
      rectangle(364,285,579,306);
      gotoxy(47,19);
      gets(type);
      setcolor(RED);
      rectangle(364,285,579,306);
    }
    else if(x>=227 && x<=346 && y>=341 && y<=384)
      break;
    else
      continue;
  }
  ifstream fin("TRN_DET.DAT",ios::binary);
  int flag=0;
  while(fin.read((char*)&Train,sizeof(Train)))
  {
   if(strcmpi(Train.Ret_number(),num)==0)
   {
    for(i=0;i<Train.Stationno;i++)
    {
     if(strcmpi(Train.Route[i].Stn_name,board)==0)
     {
      for(j=i+1;j<Train.Stationno;j++)
      {
	if(strcmpi(Train.Route[j].Stn_name,deboard)==0)
	{
	  for(g=0;g<Train.Seatno;g++)
	  {
	    if(strcmpi(Train.Seat[g].Bogge_type,type)==0)
	    {
	      flag=1;
	      if(Train.Seat[g].Seats_bkd<Train.Seat[g].Total_seats)
	      {
		flag=2;
		  break;
	      }
	      if (flag==2)
		break;
	    }
	    if(flag==1||flag==2)
	      break;
	  }
	  if(flag==1||flag==2)
	    break;
	}
      if(flag==1||flag==2)
	break;
      }
      if(flag==1||flag==2)
	break;
     }
     if(flag==1||flag==2)
      break;
    }
    if(flag==1||flag==2)
      break;
   }
   else
     continue;
  }
  if(flag==0)
  {
    setcolor(BLUE);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
    outtextxy(100,380,"SORRY, NO MATCH FOUND.");
    outtextxy(100,400,"PRESS ANY KEY TO RE ENTER.");
    getch();
    goto again3;
  }
  else if(flag==1)
  {
    setcolor(BLUE);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
    outtextxy(100,380,"SORRY, TICKETS ARE NOT AVAILABLE.");
    outtextxy(100,400,"PRESS ANY KEY TO RE ENTER.");
    getch();
    goto again3;
  }
  else if(flag==2);
  {
    setbkcolor(BLUE);
    cleardevice();
    setcolor(BLUE);
    rectangle(0,30,639,479);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(3,33,BLUE);
    setcolor(YELLOW);
    setlinestyle(SOLID_LINE,SOLID_LINE,3);
    rectangle(1,2,638,30);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(5,5,YELLOW);

    Close_button(16);
    Back_button(16);
    setcolor(LIGHTMAGENTA);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
    outtextxy(210,40,"TICKET BOOKING");
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    bar(210,80,455,82);
    setcolor(LIGHTGREEN);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
    outtextxy(190,90,"ENTER YOUR DETAILS:");

    setcolor(YELLOW);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    outtextxy(140,153,"NAME : ");
    while(1)
    {
      Showmouse();
      Restrictmouse();
      out=Mousecontrol('k');
      x=out.x.cx;
      y=out.x.dx;
      if(out.x.bx==1)
      {
	Hide_mouse();
	if(x>=595 && x<=634 && y>=6 && y<=26)
	  exit(0);
	else if(x>=3 && x<=55 && y>=5 && y<=27)
	  goto again3;
	else
	  continue;
      }
      else if(kbhit())
      {
	Hide_mouse();
	goto out;
      }
      else
	continue;
    }
  out:
    gotoxy(30,11);
    gets(B.Name);
    outtextxy(107,185,"ADDRESS : ");
    gotoxy(30,13);
    gets(B.Address);
    outtextxy(113,218,"PINCODE : ");
    gotoxy(30,15);
    gets(B.Pincode);
    outtextxy(66,248,"CONTACT NO. : ");
    gotoxy(30,17);
    gets(B.Contactno);
    outtextxy(100,280,"SEX(M/F) : ");
    gotoxy(30,19);
    gets(B.Sex);

    int d=0,r=0,t=0;
    d=Train.Route[j].Distance-Train.Route[i].Distance;
    r=d*4;
    t=Train.Seat[g].Rate+r+350;

    outtextxy(100,346,"Cost Of Ticket :");
    gotoxy(32,23);
    cout<<t;
    outtextxy(10,377,"Enter Credit Card Number For Payment :");
    gotoxy(49,25);
    char c[20];
    gets(c);

    strcpy(B.Train_name,Train.Ret_name());
    strcpy(B.Train_no,Train.Ret_number());
    strcpy(B.Seat_type,Train.Seat[g].Bogge_type);
    strcpy(B.Board_stn,board);
    strcpy(B.Deboard_stn,deboard);
    strcpy(B.Status,"CONFIRM");
    fin.close();
    Train_det Temptrain;
    /////////////////////////updating booked seats///////////////////
    fstream fin("TRN_DET.DAT",ios::in|ios::out|ios::binary);
    long offset=0;
    while(fin.read((char*)&Temptrain,sizeof(Temptrain)))
    {
       offset=fin.tellg();
       if(Temptrain.Ret_number()==B.Train_no)
       {
	  Temptrain.Seat[g].Seats_bkd++;
	  fin.seekp(offset-sizeof(Temptrain));
	  fin.write((char*)&Temptrain,sizeof(Temptrain));
       }
    }
    /////////////////////////////////////////////////////////
    Booking B1;
    ifstream fin1("BOOKING.DAT",ios::binary);
    while(fin1.read((char*)&B1,sizeof(B1)))
    {
       B.Ticketno=B1.Ticketno;
    }
    B.Ticketno++;
    fin1.close();

    fstream fout("BOOKING.DAT",ios::app|ios::binary);
    fout.write((char*)&B,sizeof(B));
    fout.close();
    setcolor(BLUE);
    int p[8]={10,87,610,87,610,470,10,470};
    setfillstyle(SOLID_FILL,BLUE);
    fillpoly(4,p);
    setcolor(LIGHTRED);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    outtextxy(50,110,"DETAILS OF THE PASSENGER :");
    outtextxy(50,290,"DETAILS OF THE TRAIN :");

    setcolor(YELLOW);
    outtextxy(50,85,"YOUR TICKET HAS BEEN BOOKED.");
    outtextxy(140,137,"NAME : ");
    gotoxy(30,10);
      cout<<B.Name;
    outtextxy(107,169,"ADDRESS : ");
    gotoxy(30,12);
      cout<<B.Address;
    outtextxy(113,200,"PINCODE : ");
    gotoxy(30,14);
      cout<<B.Pincode;
    outtextxy(66,232,"CONTACT NO. : ");
    gotoxy(30,16);
      cout<<B.Contactno;
    outtextxy(100,265,"SEX(M/F) : ");
    gotoxy(30,18);
      cout<<B.Sex;
    outtextxy(33,312,"Train Number : ");
    gotoxy(24,21);
      cout<<B.Train_no;
    outtextxy(51,343,"Train Name : ");
    gotoxy(24,23);
      cout<<B.Train_name;
   outtextxy(10,376,"Boarding Station : ");
   gotoxy(24,25);
      cout<<B.Board_stn;
   outtextxy(300,312,"Deboarding Station : ");
   gotoxy(61,21);
      cout<<B.Deboard_stn;
   outtextxy(338,343,"Ticket Number : ");
   gotoxy(61,23);
      cout<<B.Ticketno;
   outtextxy(373,376,"Seat Type : ");
   gotoxy(61,25);
      cout<<B.Seat_type;

   Showmouse();
   Restrictmouse();
   while(1)
   {
     out=Mousecontrol();
     x=out.x.cx;
     y=out.x.dx;
    if(x>=595 && x<=634 && y>=6 && y<=26)
	 exit(0);
    else if(x>=3 && x<=55 && y>=5 && y<=27)
    {
       Hide_mouse();
       return;
    }
    else
       continue;
  }
 }
}
void Trn_namenum()
{
  setbkcolor(BLACK);
  cleardevice();
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
  Back_button(16);
  setcolor(MAGENTA);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(150,60,"TRAIN NAME & NUMBER");
  setfillstyle(SOLID_FILL,MAGENTA);
  bar(148,100,520,102);

  setlinestyle(SOLID_LINE,SOLID_LINE,2);
  setcolor(GREEN);
  rectangle(144,123,504,146);
  setfillstyle(SOLID_FILL,LIGHTRED);
  floodfill(147,126,GREEN);
  line(300,123,300,146);
  setcolor(BLACK);
  settextstyle(SMALL_FONT,HORIZ_DIR,6);
  outtextxy(165,125,"TRAIN NUMBER");
  outtextxy(355,125,"TRAIN NAME");
  Train_det T;
  int up=146,dow=169;
  ifstream fin("TRN_DET.DAT",ios::binary);
  while(fin.read((char*)&T,sizeof(T)))
  {
    setcolor(GREEN);
    rectangle(144,up,504,dow);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(147,up+3,GREEN);
    line(300,up,300,dow);

    setcolor(BLACK);
    outtextxy(195,up-1,T.Ret_number());
    outtextxy(325,up-1,T.Ret_name());
    up+=23,dow+=23;
  }
  fin.close();
  Showmouse();
  Restrictmouse();
  while(1)
  {
    out=Mousecontrol();
    x=out.x.cx;
    y=out.x.dx;
    if(x>=595 && x<=634 && y>=6 && y<=26)
	 exit(0);
    else if(x>=3 && x<=55 && y>=5 && y<=27)
    {
       Hide_mouse();
       return;
    }
    else
       continue;
  }
}
void Bookstatus()
{
 statusagain:
  long e;
  Booking B;
  cleardevice();
  setbkcolor(LIGHTRED);        //for data box
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
  Back_button(16);
  setcolor(MAGENTA);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(210,60,"BOOKING STATUS");
  setfillstyle(SOLID_FILL,MAGENTA);
  bar(210,100,470,102);

  setcolor(GREEN);
  settextstyle(3,HORIZ_DIR,1);
  outtextxy(10,138," ENTER YOUR TRAIN TICKET NUMBER :");
  setcolor(LIGHTRED);
  rectangle(400,138,580,165);
  setfillstyle(SOLID_FILL,LIGHTRED);
  floodfill(404,142,LIGHTRED);
  setcolor(BLUE);
  rectangle(235,200,375,230);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
  floodfill(245,205,BLUE);
  setcolor(LIGHTRED);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  outtextxy(245,202,"GET STATUS");

  while(1)
  {
    Showmouse();
    Restrictmouse();
    out=Mousecontrol();
    x=out.x.cx;
    y=out.x.dx;
    Hide_mouse();
    if(x>=595 && x<=634 && y>=6 && y<=26)
      exit(0);
    else if(x>=3 && x<=55 && y>=5 && y<=27)
      return;
    else if(x>=400 && x<=580 && y>=138 && y<=165)
    {
      setcolor(RED);
      rectangle(400,138,580,165);
      gotoxy(52,10);
      cin>>e;
      setcolor(LIGHTRED);
      rectangle(400,138,580,165);
      continue;
    }
    else if(x>=235 && x<=375 && y>=200 && y<=230)
      break;     //status
 }
 int flag=0;
 ifstream fin("BOOKING.DAT",ios::binary);
 while(fin.read((char*)&B,sizeof(B)))
 {
   if(B.Ticketno==e)
   {
     flag=1;
     break;
   }
 }
 if(flag!=1)
 {
   setcolor(BLUE);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
   outtextxy(100,380,"SORRY, NO MATCH FOUND.");
   outtextxy(100,400,"PRESS ANY KEY TO RE ENTER.");
   getch();
   goto statusagain;
 }
 else
 {
   setbkcolor(BLUE);
   cleardevice();
   setcolor(BLUE);
   rectangle(0,30,639,479);
   setfillstyle(SOLID_FILL,BLUE);
   floodfill(3,33,BLUE);
   setcolor(YELLOW);
   setlinestyle(SOLID_LINE,SOLID_LINE,3);
   rectangle(1,2,638,30);
   setfillstyle(SOLID_FILL,YELLOW);
   floodfill(5,5,YELLOW);

   Close_button(16);
   Back_button(16);
   setcolor(LIGHTMAGENTA);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
   outtextxy(210,40,"TICKET STATUS");
   setfillstyle(SOLID_FILL,LIGHTMAGENTA);
   bar(210,80,445,82);
   setcolor(LIGHTRED);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   outtextxy(50,110,"DETAILS OF THE PASSENGER :");
   outtextxy(50,290,"DETAILS OF THE TRAIN :");

   setcolor(YELLOW);
   outtextxy(140,137,"NAME : ");
   gotoxy(30,10);
     cout<<B.Name;
   outtextxy(107,169,"ADDRESS : ");
   gotoxy(30,12);
     cout<<B.Address;
   outtextxy(113,200,"PINCODE : ");
   gotoxy(30,14);
     cout<<B.Pincode;
   outtextxy(66,232,"CONTACT NO. : ");
   gotoxy(30,16);
     cout<<B.Contactno;
   outtextxy(100,265,"SEX(M/F) : ");
   gotoxy(30,18);
     cout<<B.Sex;
   outtextxy(33,312,"Train Number : ");
   gotoxy(24,21);
     cout<<B.Train_no;
   outtextxy(51,343,"Train Name : ");
   gotoxy(24,23);
     cout<<B.Train_name;
   outtextxy(10,376,"Boarding Station : ");
   gotoxy(24,25);
     cout<<B.Board_stn;
   outtextxy(300,312,"Deboarding Station : ");
   gotoxy(61,21);
     cout<<B.Deboard_stn;
   outtextxy(338,343,"Ticket Number : ");
   gotoxy(61,23);
      cout<<B.Ticketno;
   outtextxy(373,376,"Seat Type : ");
   gotoxy(61,25);
      cout<<B.Seat_type;

   outtextxy(310,85,":");
   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(200,93,"STATUS");
   setcolor(LIGHTGREEN);
   outtextxy(330,93,B.Status);
   fin.close();

   while(1)
   {
     Showmouse();
     Restrictmouse();
     out=Mousecontrol();
     x=out.x.cx;
     y=out.x.dx;
     Hide_mouse();
     if(x>=595 && x<=634 && y>=6 && y<=26)
       exit(0);
     else if(x>=3 && x<=55 && y>=5 && y<=27)
       goto statusagain;
   }
 }
}
void Cancellation()
{
 cancelagain:
  long e;
  Booking B;
  cleardevice();
  setbkcolor(LIGHTRED);        //for data box
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
  Back_button(16);
  setcolor(MAGENTA);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(150,60,"TICKET CANCELLATION");
  setfillstyle(SOLID_FILL,MAGENTA);
  bar(150,100,485,102);

  setcolor(GREEN);
  settextstyle(3,HORIZ_DIR,1);
  outtextxy(10,138," ENTER YOUR TRAIN TICKET NUMBER :");
  setcolor(LIGHTRED);
  rectangle(400,138,580,165);
  setfillstyle(SOLID_FILL,LIGHTRED);
  floodfill(404,142,LIGHTRED);
  setcolor(BLUE);
  rectangle(230,200,400,230);
  setfillstyle(SOLID_FILL,LIGHTBLUE);
  floodfill(235,205,BLUE);
  setcolor(LIGHTRED);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  outtextxy(240,202,"GET CANCELLED");

  while(1)
  {
    Showmouse();
    Restrictmouse();
    out=Mousecontrol();
    x=out.x.cx;
    y=out.x.dx;
    Hide_mouse();
    if(x>=595 && x<=634 && y>=6 && y<=26)
      exit(0);
    else if(x>=3 && x<=55 && y>=5 && y<=27)
      return;
    else if(x>=400 && x<=580 && y>=138 && y<=165)
    {
      setcolor(RED);
      rectangle(400,138,580,165);
      gotoxy(52,10);
      cin>>e;
      setcolor(LIGHTRED);
      rectangle(400,138,580,165);
      continue;
    }
    else if(x>=230 && x<=400 && y>=200 && y<=230)
      break;     //cancel
 }
 int flag=0 , flag1=0;
 long offset;
 fstream fin("BOOKING.DAT",ios::in|ios::out|ios::binary);
 while(fin.read((char*)&B,sizeof(B)))
 {
   offset=fin.tellg();
   if(B.Ticketno==e && strcmpi(B.Status,"CONFIRM")==0)
   {
     flag=1;
     break;
   }
 }
 if(flag!=1)
 {
   setcolor(BLUE);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
   outtextxy(100,380,"SORRY, NO MATCH FOUND.");
   outtextxy(100,400,"PRESS ANY KEY TO RE ENTER.");
   getch();
   goto cancelagain;
 }
 else
 {
   setbkcolor(BLUE);
   cleardevice();
   setcolor(BLUE);
   rectangle(0,30,639,479);
   setfillstyle(SOLID_FILL,BLUE);
   floodfill(3,33,BLUE);
   setcolor(YELLOW);
   setlinestyle(SOLID_LINE,SOLID_LINE,3);
   rectangle(1,2,638,30);
   setfillstyle(SOLID_FILL,YELLOW);
   floodfill(5,5,YELLOW);

   Close_button(16);
   Back_button(16);
   setcolor(LIGHTMAGENTA);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
   outtextxy(210,40,"TICKET STATUS");
   setfillstyle(SOLID_FILL,LIGHTMAGENTA);
   bar(210,80,445,82);

   setcolor(YELLOW);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(200,93,"STATUS");
   setcolor(LIGHTGREEN);
   outtextxy(330,93,B.Status);
   setcolor(LIGHTRED);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   outtextxy(310,85,":");
   outtextxy(50,110,"DETAILS OF THE PASSENGER :");
   outtextxy(50,290,"DETAILS OF THE TRAIN :");

   setcolor(YELLOW);
   outtextxy(140,137,"NAME : ");
   gotoxy(30,10);
     cout<<B.Name;
   outtextxy(107,169,"ADDRESS : ");
   gotoxy(30,12);
     cout<<B.Address;
   outtextxy(113,200,"PINCODE : ");
   gotoxy(30,14);
     cout<<B.Pincode;
   outtextxy(66,232,"CONTACT NO. : ");
   gotoxy(30,16);
     cout<<B.Contactno;
   outtextxy(100,265,"SEX(M/F) : ");
   gotoxy(30,18);
     cout<<B.Sex;
   outtextxy(33,312,"Train Number : ");
   gotoxy(24,21);
     cout<<B.Train_no;
   outtextxy(51,343,"Train Name : ");
   gotoxy(24,23);
     cout<<B.Train_name;
   outtextxy(10,376,"Boarding Station : ");
   gotoxy(24,25);
     cout<<B.Board_stn;
   outtextxy(300,312,"Deboarding Station : ");
   gotoxy(61,21);
     cout<<B.Deboard_stn;
   outtextxy(338,343,"Ticket Number : ");
   gotoxy(61,23);
      cout<<B.Ticketno;
   outtextxy(373,376,"Seat Type : ");
   gotoxy(61,25);
      cout<<B.Seat_type;

   if(flag1==0)
   {
     setcolor(LIGHTGREEN);
     settextstyle(3,HORIZ_DIR,2);
     outtextxy(10,400,"ARE YOU SURE YOU WNAT TO CANCEL TICKET.............");
     rectangle(160,435,220,465);
     rectangle(330,435,390,465);

     floodfill(164,440,LIGHTGREEN);
     floodfill(334,440,LIGHTGREEN);
     setcolor(BLUE);
     settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
     outtextxy(167,443,"YES");
     outtextxy(346,443,"NO");
   }

   while(1)
   {
     Showmouse();
     Restrictmouse();
     out=Mousecontrol();
     x=out.x.cx;
     y=out.x.dx;
     Hide_mouse();
     if(x>=595 && x<=634 && y>=6 && y<=26)
       exit(0);
     else if(x>=3 && x<=55 && y>=5 && y<=27)
       goto cancelagain;
     else if(x>=160 && x<=220 && y>=435 && y<=465 && flag1==0) //yes
     {
	strcpy(B.Status,"CANCELLED");
	fin.seekp(offset-sizeof(B));
	fin.write((char*)&B,sizeof(B));
	/////////////////////////updating booked seats///////////////////
	Train_det Temptrain;
	fstream fin1("TRN_DET.DAT",ios::in|ios::out|ios::binary);
	long offset1=0;
	int g;
	while(fin1.read((char*)&Temptrain,sizeof(Temptrain)))
	{
	   offset1=fin1.tellg();
	   if(Temptrain.Ret_number()==B.Train_no)
	   {
	      for(g=0;g<=Temptrain.Seatno;g++)
		if(strcmpi(Temptrain.Seat[g].Bogge_type,B.Seat_type)==0)
		  break;
	      break;
	   }
	}
	Temptrain.Seat[g].Seats_bkd;
	fin1.seekp(offset1-sizeof(Temptrain));
	fin1.write((char*)&Temptrain,sizeof(Temptrain));
	fin1.close();
	int p[8];
	setcolor(BLUE);
	p[0]=320,p[1]=88,p[2]=600,p[3]=88,p[4]=600,p[5]=113,p[6]=320,p[7]=113;
	setfillstyle(SOLID_FILL,BLUE);
	fillpoly(4,p);
	p[0]=5,p[1]=400,p[2]=600,p[3]=400,p[4]=600,p[5]=470,p[6]=5,p[7]=470;
	fillpoly(4,p);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(LIGHTGREEN);
	outtextxy(330,93,B.Status);
	flag1=1;
     }
     /////////////////////////////////////////////////////////
     else if(x>=330 && x<=390 && y>=435 && y<=465 && flag1==0) //no
     {
	int p[8];
	setcolor(BLUE);
	p[0]=5,p[1]=400,p[2]=600,p[3]=400,p[4]=600,p[5]=470,p[6]=5,p[7]=470;
	setfillstyle(SOLID_FILL,BLUE);
	fillpoly(4,p);
	flag1=1;
     }
   }
 }
 fin.close();
}
void main()
{
  Loading();
 MAIN1:
  int gdriver=VGA,gmode=VGAHI,a,b,m1,p;
  initgraph(&gdriver,&gmode,"");
 MAIN:
  m1=Mainscreen();
  if(m1==1)
  {
    Book();
    goto MAIN;
  }
  else if(m1==2)
  {
    Train_schedule();
    goto MAIN;
  }
  else if(m1==3)
  {
    Fare();
    goto MAIN;
  }
  else if(m1==4)
  {
    Trn_namenum();
    goto MAIN;
  }
  else if(m1==5)
  {
    Bookstatus();
    goto MAIN;
  }
  else if(m1==6)
  {
    Cancellation();
    goto MAIN;
  }
  else if(m1==7)
  {
    p=Passwordscreen();
    if(p==0)
      goto MAIN;
  }

  while(1)
  {
    closegraph();
    ADM:
    a=Adminscreen();
    if(a==1)
      Create();
    else if(a==2)
      Show();
    else if(a==3)
      Delete();
    else if(a==4)
    {
      b=Modifyscreen();
      if(b==4)
	goto ADM;
      else
	Edit(b);
    }
    else if(a==5)
      Reset();
    else if(a==6)
      goto MAIN1;
  }
  closegraph();
}



