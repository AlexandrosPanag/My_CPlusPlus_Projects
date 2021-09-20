// This code was designed by Alexandros Panagiotakopoulos
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#define N 248

int main()
{
string Country[N];
string Short[N];
long Popul[N][57];
int k=0;
int i=0;  
fstream inFile;
inFile.open("population-figures-easy");
fstream cin;
string line,word;
getline(cin,line);
while(! inFile.eof())
{
  stringstream ss(line);
   while(getline(ss,word,','))
   {
       if(k==0)
       {
       Country[i]=word;
       }
       else if(k==1)
       {
        Short[i]=word;
       }
       else
       {
             if (word=="")
             {
               Popul[i][k]=0;
             }
             else
             {
                Popul[i][k]=stol(word);
             }
             k++; 
       }
   }
   i++;
}
inFile.close();
for(int i=0;i<5;i++)
  cout<<Country[i];
 return 0;
}
