//raystriker2D 
//Created by N.Manaswini 26-05-2021



#include<iostream>
#include<string>
#include"ray.h"











int main()
{
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
  
  printinstructions();
  level1 pl1(arr,0,s);
  pl1.printboard();
  char will='Y';
  int choice=0;
  
  int y=1;
 i=1;
  while(y==1 && (will=='Y'|| will=='y'))
  {
   
  
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
  std::cout<<"\nChoose mirror M" <<i<< " orientation"<<std::endl;
  std::cin>>choice;
  level1 pl2(arr,choice,s);
  arr=orientation(0,4,arr,choice,s);
  pl2.arr=arr;
  pl2.printboard();
  y=pl2.resultarr();
  
  
  if(y==0)
  {
    std::cout<<"Congrats,This level is cleared"<<std::endl;
    break;
  }
  
  else if(i==5&&y==1)
  {
    std::cout<<"you lost this game"<<std::endl;
    break;
  
  }
  i++;
  }
  
  free(arr);
 
  return 0;
}
