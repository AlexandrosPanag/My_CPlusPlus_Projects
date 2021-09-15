#include <iostream>
#include <ctime>


using namespace std;

double parameter(int [],int);
 
int main()
{ 
    int cnt=1;
    cout<<"Welcome to the program!"<<endl;
    srand(time(NULL));;
    int A[100];
    cout<<"Oi times einai:"<<endl;
    for(int i=0;i<100;i++)
    {
        A[i]=rand() % 1001;
        cout<<A[i]<<endl; 
    }
    cout<<"The smallest element is : "<<parameter(A,cnt)<<endl;
    cnt++;
    cout<<"The biggest element is : "<<parameter(A,cnt)<<endl;
    cnt++;
    cout<<"The average is : "<<parameter(A,cnt)<<endl;
    cnt++;
    return 0;
}
double parameter(int A[], int cnt)
{
 int min,max,i;
 double mo,sum,apotel;
 min=A[0];
 max=A[0];
 sum=0;
 for(i=0;i<100;i++)
 {
   if(max<A[i])
   {
       max=A[i];
   }
   if(min>A[i])
   {
       min=A[i];
   } 
   sum+=A[i];
 }
 mo=(sum/100);
 if(cnt==1)
 {
 apotel=min;
 }
 else if(cnt==2)
 {
    apotel=max;
 }
 else if(cnt==3)
 {
  apotel=mo;
 }
 return apotel;
}
