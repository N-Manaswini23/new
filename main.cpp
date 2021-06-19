#include<iostream>
#include<string>
#include"ray.h"
#include<ncurses.h>










int main()
{
  initscr();
  
  
if(has_colors() == FALSE)
	{	endwin();
		printw("Failed to add colors\n");
		exit(1);
	}
	start_color();			
	init_pair(3,COLOR_BLACK +16,COLOR_WHITE+8);
  wbkgd(stdscr,COLOR_PAIR(3));


  
  std::string *arr=static_cast<std::string*>(malloc(2000));
  std::string s;
  int i=0;
  
  for(i=0;i <17;i++)
  { 
    if (1==2||i==9||i==4||i==11||i==6||i==14||i==5||i==16||i==15)
    {
      arr[4]="   S  ";
      arr[6]="  M2  ";
      arr[2]="  M1  ";
      arr[9]="  M3  ";
      arr[14]="  M4  ";
      arr[15]="  M5  ";
      arr[11]="   E  ";
      arr[5]="......";
      arr[16]="hr";
    }
    else
    {
      arr[i]="      ";
    }
    
  }
  
  
  
  char will='Y';
  int choice=0;
  
  int y=1;
 i=1;
  while(y==1 && (will=='Y'|| will=='y'))
  {
   printinstructions();
  refresh();
  level1 pl1(arr,0,s);
  pl1.printboard();
  refresh();
  
  
  if (i==1)
  {
    s="  M1  ";
  }
  else if (i==2)
  {
    s="  M2  ";
  }
  else if (i==3)
  {
    s="  M3  ";
  }
  else if (i==4)
  {
    s="  M4  ";
  }
  else if (i==5)
  {
    s="  M5  ";
  }
  printw("\nChoose mirror M%d orientation\n",i);
  refresh();
  scanw("%d",&choice);
  refresh();
  clear();
  refresh();
  printinstructions();
  refresh();
  level1 pl2(arr,choice,s);
  arr=pl2.orient(0,4,arr,choice,s);
  pl2.arr=arr;
  pl2.printboard();
  refresh();
  y=pl2.resultant();
  
  
  if(y==0)
  {
   printw("Congrats,This level is cleared");
     refresh();
    break;
  }
  
  else if(i==5&&y==1&&(choice<=4 && choice >0))
  {
    printw("you lost this game");
     refresh();
    break;
  
  }
  if(choice==1||choice==2||choice==3||choice==4)
  {i++;}
  
  refresh();
  clear();
  refresh();
  }
  
  
  getch();
 endwin();
  return 0;
}
