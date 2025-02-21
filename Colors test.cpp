#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

void Color(int color)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

main(){
int x;

 for(x=1;x<=256;x++)
  {
   Color(x);
   cout<<x<<"| ="<<endl;
  }
}