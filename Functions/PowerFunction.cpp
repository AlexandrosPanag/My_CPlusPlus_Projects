#include<iostream>
#include<cstdio>

using namespace std;

int power(int x, int y){
    int power=x;
    cout<<"power is "<<y;
    cout<<"number is "<<x;
    while(y>0){
    power=power*x;
    y--;
    }
    power=power/x;
    return power;
}

int main(){
    int number=0;
    int power_number=0;
    int power_result=0;
    cout<<"Give a number:"<<endl;
    scanf("%d",&number);
    cout<<"Give the value of power"<<endl;
    scanf("%d",&power_number);
    power_result=power(number,power_number);
    cout<<">The power result is:"<<power_result<<endl;;
}