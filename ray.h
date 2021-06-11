#ifndef __RAY_H
#define __RAY_H

#include<iostream>
#include<string>


void printinstructions()
{
  std::cout<<" S-starting point of light"<<std::endl;
  std::cout<<" E-end point of light"<<std::endl;
  std::cout<<" M1-mirror 1"<<std::endl;
  std::cout<<" M2-mirror 2"<<std::endl;
  std::cout<<" 1- \\ orientation"<<std::endl;
  std::cout<<" 2- / orientation"<<std::endl;
  std::cout<<" 3- __ orientation"<<std::endl;
  std::cout<<" 4- | orientation"<<std::endl;
  std::cout<<"orientation of mirror can only be changed once"<<std::endl;
  std::cout<<"All mirrors must be used"<<std::endl;
}


class raystriker
{

  public :
  std::string *arr=static_cast<std::string*>(malloc(2000));
  int choice;
  std::string s;
  virtual void printboard()
  {
    std::cout<<"base function"<<std::endl;
  }
  virtual int resultarr()
  {
    return 1;
  }
};

class level1 :public raystriker
{
public :
  level1(std::string *_arr,int _choice,std::string _s)
  {
    
    for (int i=0;i<17;i++)
    {
      arr[i]=_arr[i];
    }
    choice=_choice;
    s=_s;
  }
 
void printboard()
{
  std::cout<<" ______ ______ ______ ______"<<std::endl;
  std::cout<<"|"<<arr[0]<<"|"<<arr[1]<<"|"<<arr[2]<<"|"<<arr[3]<<"|"<<std::endl;
  std::cout<<"|______|______|______|______|"<<std::endl;
  std::cout<<"|"<<arr[4]<<"|"<<arr[5]<<"|"<<arr[6]<<"|"<<arr[7]<<"|"<<std::endl;
  std::cout<<"|______|______|______|______|"<<std::endl;
  std::cout<<"|"<<arr[8]<<"|"<<arr[9]<<"|"<<arr[10]<<"|"<<arr[11]<<"|"<<std::endl;
  std::cout<<"|______|______|______|______|"<<std::endl;
  std::cout<<"|"<<arr[12]<<"|"<<arr[13]<<"|"<<arr[14]<<"|"<<arr[15]<<"|"<<std::endl;
  std::cout<<"|______|______|______|______|"<<std::endl;
  
}








int resultarr()
{
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
};





std::string* orientation(int _i,int side,std::string *arr,int choice,std::string s)
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
      std::cout<<i<<std::endl;
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




#endif


            























             

