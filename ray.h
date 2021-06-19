#ifndef __RAY_H
#define __RAY_H


void printinstructions();


class raystriker
{
  protected :
  std::string* orientation(int _i,int side,std::string *arr,int choice,std::string s);

  public :
  std::string* arr=static_cast<std::string*>(malloc(2000));
  int choice;
  std::string s;
  virtual void printboard();
  virtual int resultarr();
  std::string* orient(int _i,int side,std::string *arr,int choice,std::string s);

};

class level1 :public raystriker
{
public :

level1(std::string *_arr,int _choice,std::string _s);

void printboard();
int resultant();
private :
int resultarr();

};




#endif
