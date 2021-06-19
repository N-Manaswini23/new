

#include<iostream>
#include<string>
#include<cstring>
#include<ncurses.h>
#include"ray.h"


void printinstructions()
{

  waddstr(stdscr," S-starting point of light\n");
  waddstr(stdscr," E-end point of light\n");
  waddstr(stdscr," M1-mirror 1\n");
  waddstr(stdscr," M2-mirror 2\n");
  waddstr(stdscr," 1- \\ orientation\n");
  waddstr(stdscr," 2- / orientation\n");
  waddstr(stdscr," 3- __ orientation\n");
  waddstr(stdscr," 4- | orientation\n");
  waddstr(stdscr,"orientation of mirror can only be changed once\n");
 
  
  
}



  void raystriker:: printboard()
  {
    printw("base function");
  }
  int raystriker::resultarr()
  {
    return 1;
  }



  level1::level1(std::string *_arr,int _choice,std::string _s)
  {
    
    for (int i=0;i<17;i++)
    {
      arr[i]=_arr[i];
    }
    choice=_choice;
    s=_s;
  }
 
void level1::printboard()
{
  if(has_colors() == FALSE)
	{	endwin();
		printw("Failed to add colors\n");
		exit(1);
	}

	start_color();
  use_default_colors();
	init_pair(2,COLOR_BLACK+16,COLOR_YELLOW+8);
  
  attron(COLOR_PAIR(2));
  printw(" ______ ______ ______ ______ \n");
  refresh();
  printw("|");
  wprintw(stdscr,(arr+0)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3)->data());
  printw("|\n");
  refresh();
  printw("|______|______|______|______|\n");
   refresh();
  printw("|");
  wprintw(stdscr,(arr+4)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+5)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+6)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+7)->data());
  printw("|\n");
  refresh();
  printw("|______|______|______|______|\n");
   refresh();
   printw("|");
  wprintw(stdscr,(arr+8)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+9)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+10)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+11)->data());
  printw("|\n");
  refresh();
   printw("|______|______|______|______|\n");
   refresh();
   printw("|");
  wprintw(stdscr,(arr+12)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+13)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+14)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+15)->data());
  printw("|\n");
  refresh();
  printw("|______|______|______|______|\n");
   refresh();
  attroff(COLOR_PAIR(2));
}








int level1::resultarr()
{
  // i is array index
  //y represesnts if the level is cleared or not
  std::string* result=static_cast<std::string*>(malloc(2000));
  int i=0;
  int y=1;
   for(i=0;i <17;i++)
  { 
    if (i==4||i==6||i==14||i==5||i==16||i==15||i==11||i==10)
    {
      result[4]="   S  ";
      result[6]="   \\  ";
      result[14]="   \\  ";
      result[15]="   /  ";
      result[11]="   E  ";
      result[5]="......";
      result[16]="vu";
      result[10]="   :  ";
      
    }
    else
    {
      result[i]="      ";
    }
  }
  for(i=0;i <17;i++)
  {
    if (i==4||i==5||i==6||i==10||i==11||i==14||i==15||i==16)
    {
    if(result[i]==arr[i])
    {
      y=0;
    }
    else if (result[i]!=arr[i])
    {
      y=1;
      break;
    }
    }
  }
  return y;
}


int level1::resultant()
{
return resultarr();
}



std::string* raystriker::orientation(int _i,int side,std::string *arr,int choice,std::string s)
{
  
  int i=_i,j=0;
  int n=side*side;
  int w=side;
  for(i=_i;i < n;i++)
  {
    if (arr[i]==s)
    {
      
    if (choice==1)
    {
      arr[i]="   \\  ";
      if (arr[n]=="hr" && (arr[i-1]=="......"||arr[i-1]=="   \\  "||arr[i-1]=="   /  "||arr[i-1]=="  __  "||arr[i-1]=="   |  ") && (i-1)%w != w-1 && (i-1)>=0)
      {
        arr[n]="vd";
         
          j=i+w;
    while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n)
           {
            if (arr[j]=="   \\  ")
            {
              s=arr[j];
              choice=1;
              
              orientation(j,w,arr,choice,s);
              
              break;
            }
            else if (arr[j]=="   /  ")
            {
              s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {
              s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {
              s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            
            j=j+w;
            }
            
          }
        
        
      }



      else if (arr[n]=="hl"&&(arr[i+1]=="......"||arr[i+1]=="   \\  "||arr[i+1]=="   /  "||arr[i+1]=="  __  "||arr[i+1]=="   |  ")&& (i+1)%w!=0 && (i+1)<n)
      { 
         arr[n]="vu";
       j=i-w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " && arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j>=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            j=j-w;
            }
            
         }
         
      }

    


      else if (arr[n]=="vu"&&(arr[i+w]=="   :  "||arr[i+w]=="   \\  "||arr[i+w]=="   /  "||arr[i+w]=="  __  "||arr[i+w]=="   |  ")&& (i)%w!=0&&(i+w)<n)
      { 
         arr[n]="hl";
       j=i-1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&  arr[j]!="   S  "&& arr[j]!="   E  ")&&j>=0&& j%w!=w-1)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="......";
            
            j=j-1;
            }
         }
         
      }


      else if (arr[n]=="vd"&&(arr[i-w]=="   :  "||arr[i-w]=="   \\  "||arr[i-w]=="   /  "||arr[i-w]=="  __  "||arr[i-w]=="   |  ")&& (i)%w!=w-1&&(i-w)>=0)
      { 
        arr[n]="hr";
       j=i+1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " && arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n && j%w!=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="......";
            
            j=j+1;
            }
         }
          
      }
    }











     else if (choice==2)
    {
      arr[i]="   /  ";
      if (arr[n]=="hr" && (arr[i-1]=="......"||arr[i-1]=="   \\  "||arr[i-1]=="   /  "||arr[i-1]=="  __  "||arr[i-1]=="   |  ") && (i-1)%w != w-1 && (i-1)>=0)
      {
        arr[n]="vu";
         
          j=i-w;
          while(arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " && arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  "&&j>=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {
              s=arr[j];
              choice=2;
              
              orientation(j,w,arr,choice,s);
              
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              std::cout<<"m3 "<<j<< choice<<arr[n]<<" "<<arr[6]<<" "<<arr[14]<<" "<<arr[15]<<std::endl;
              orientation(j,w,arr,choice,s);
              std::cout<<"m3"<<j<< choice<<arr[n]<<" "<<arr[6]<<" "<<arr[14]<<" "<<arr[15]<<std::endl;
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            
            j=j-w;
            }
          }
        
        
      }



      else if (arr[n]=="hl"&&(arr[i+1]=="......"||arr[i+1]=="   \\  "||arr[i+1]=="   /  "||arr[i+1]=="  __  "||arr[i+1]=="   |  ")&& (i+1)%w!=0 && (i+1)<n)
      { 
        arr[n]="vd";
       j=i+w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&  arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            
            j=j+w;
            }
         }
          
      }

    


      else if (arr[n]=="vu"&&(arr[i+w]=="   :  "||arr[i+w]=="   \\  "||arr[i+w]=="   /  "||arr[i+w]=="  __  "||arr[i+w]=="   |  ")&& (i)%w!=0&&(i+w)<n)
      { 
        arr[n]="hr";
       j=i+1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " && arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n&& j%w!=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="......";
            
            j=j+1;
            }
         }
          
      }


      else if (arr[n]=="vd"&&(arr[i-w]=="   :  "||arr[i-w]=="   \\  "||arr[i-w]=="   /  "||arr[i-w]=="  __  "||arr[i-w]=="   |  ")&& (i)%w!=w-1&&(i-w)>=0)
      { 
        arr[n]="hl";
       j=i-1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " && arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j>=0 && j%w!=w-1)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="......";
            
            j=j-1;
            }
         }
          
      }
    }









    else if (choice==4)
    {
      arr[i]="   |  ";
      if (arr[n]=="hr" && (arr[i-1]=="......" ||arr[i-1]=="   \\  "||arr[i-1]=="   /  "||arr[i-1]=="  __  "||arr[i-1]=="   |  ")&& (i-1)%w != w-1 && (i-1)>=0)
      {
        arr[n]="hl";
         
          j=i-1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&  arr[j]!="   S  "&& arr[j]!="   E  "&& arr[j]!="   \\  "&&arr[j]!="   /  "&&arr[j]!="  __  "&&arr[j]!="   |  ")&&j>=0&& j%w!=w-1)
          {
            
            arr[j]="......";
            
            j=j-1;
            
          }
        
        
      }



      else if (arr[n]=="hl"&&(arr[i+1]=="......"||arr[i+1]=="   \\  "||arr[i+1]=="   /  "||arr[i+1]=="  __  "||arr[i+1]=="   |  ")&& (i+1)%w!=0 && (i+1)<n)
      { 
        arr[n]="hr";
       j=i+1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " && arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  "&& arr[j]!="   \\  "&&arr[j]!="   /  "&&arr[j]!="  __  "&&arr[j]!="   |  ")&&j<n&&j%w!=0)
          {
            
            arr[j]="......";
            
            j=j+1;
            
         }
          
      }

    


      else if (arr[n]=="vu"&&(arr[i+w]=="   :  "||arr[i+w]=="   \\  "||arr[i+w]=="   /  "||arr[i+w]=="  __  "||arr[i+w]=="   |  ")&& (i)%w!=0&&(i+w)<n)
      { 
        arr[n]="vu";
       j=i-w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " && arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j>=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            
            j=j-w;
            }
         }
          
      }


      else if (arr[n]=="vd"&&(arr[i-w]=="   :  "||arr[i-w]=="   \\  "||arr[i-w]=="   /  "||arr[i-w]=="  __  "||arr[i-w]=="   |  ")&& (i)%w!=w-1&&(i-w)>=0)
      { 
        arr[n]="vd";
       j=i+w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " && arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="   :  ";
            
            j=j+w;
            }
         }
          
      }
    }





    else if (choice==3)
    {
      
      arr[i]="  __  ";
      if (arr[n]=="hr" && (arr[i-1]=="......"||arr[i-1]=="   \\  "||arr[i-1]=="   /  "||arr[i-1]=="  __  "||arr[i-1]=="   |  ") && (i-1)%w != w-1 && (i-1)>=0)
      {
        arr[n]="hr";
         
          j=i+1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " &&arr[j]!="  M4  "&& arr[j]!="  M5  "&&  arr[j]!="   S  "&& arr[j]!="   E  ")&&j<n&& j%w!=0)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="......";
            
            j=j+1;
            }
          }
        
        
      }



      else if (arr[n]=="hl"&&(arr[i+1]=="......"||arr[i+1]=="   \\  "||arr[i+1]=="   /  "||arr[i+1]=="  __  "||arr[i+1]=="   |  ")&& (i+1)%w!=0 && (i+1)<n)
      { 
        arr[n]="hl";
       j=i-1;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " && arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  ")&&j>=0&&j%w!=w-1)
          {
            if (arr[j]=="   \\  ")
            {s=arr[j];
              choice=1;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   /  ")
            {s=arr[j];
              choice=2;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="  __  ")
            {s=arr[j];
              choice=3;
              orientation(j,w,arr,choice,s);
              break;
            }
            else if (arr[j]=="   |  ")
            {s=arr[j];
              choice=4;
              orientation(j,w,arr,choice,s);
              break;
            }
            else
            {
            arr[j]="......";
            
            j=j-1;
            }
         }
          
      }

    


      else if (arr[n]=="vu"&&(arr[i+w]=="   :  "||arr[i+w]=="   \\  "||arr[i+w]=="   /  "||arr[i+w]=="  __  "||arr[i+w]=="   |  ")&& (i)%w!=0&&(i+w)<n)
      { 
        arr[n]="vd";
        
       j=i+w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " && arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  "&& arr[j]!="   \\  "&&arr[j]!="   /  "&&arr[j]!="  __  "&&arr[j]!="   |  ")&&j<n)
          {
           
            

            arr[j]="   :  ";
            
            j=j+w;
            
         }
          
      }


      else if (arr[n]=="vd"&&(arr[i-w]=="   :  "||arr[i-w]=="   \\  "||arr[i-w]=="   /  "||arr[i-w]=="  __  "||arr[i-w]=="   |  ")&& (i)%w!=w-1&&(i-w)>=0)
      { 
         arr[n]="vu";
       j=i-w;
          while((arr[j]!="  M2  "&& arr[j]!="  M1  "&& arr[j]!="  M3  " && arr[j]!="  M4  "&& arr[j]!="  M5  "&& arr[j]!="   S  "&& arr[j]!="   E  "&& arr[j]!="   \\  "&&arr[j]!="   /  "&&arr[j]!="  __  "&&arr[j]!="   |  ")&&j>=0)
          {
            

            arr[j]="   :  ";
            
            j=j-w;
            
         }
         
      }
    }





  break;
  } 
  }
 
 return arr;
}


std::string* raystriker::orient(int _i,int side,std::string *arr,int choice,std::string s)
{
  return orientation(_i,side,arr,choice,s);
}




            























             

