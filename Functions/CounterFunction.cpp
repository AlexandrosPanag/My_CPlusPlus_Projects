#include<iostream>

using namespace std;

int addition (int i)
{
  return i;
}

int main ()
{
  int counter;
  for(int i=0;i<=5;i++){
  counter = addition (i);
  cout << "The result is " << counter<<endl;
  }
}