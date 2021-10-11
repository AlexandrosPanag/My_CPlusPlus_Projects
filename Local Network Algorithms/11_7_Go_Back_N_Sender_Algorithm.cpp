#include <iostream>
#include <string>
#include <cstdio>
#include <ctime> 
#include <chrono>
#include <unistd.h>
#include <cmath>   

using namespace std;

void StartTimer(){
  auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "< Start timer of package began on: " << ctime(&end_time)<<" > ";
 }
 
 int success(){ //Randomly we will check whether an ACK has arrived or not there is a 20% an ACK will fail to be received
   int x;
   x = rand() % 101;
   return x;
}

int power(int x, int y){
    int power=0;
    for(int i=1;i<y;i++){
    power+=x*x;
    }
    return power;
}

void GetData(){
    cout<<"< The system is receiving data..>"<<endl<<endl;
}

void MakeFrame(int Sn){
    cout<<"< The sender is making the frame of "<<Sn<<"...."<<endl<<endl;
}

void SendFrame(int n){
     cout<<"< Sending the frame:"<<n<<" >"<<endl;
 }

string WaitForEvent(){
 string event="";
 cout<<"-> Type something (or dont) to send a packet to the receiver! "<<endl;
 getline(cin, event);
 if(event.empty()){
     cout<<" < The system will wait until an event occurs > "<<endl<<endl;
 }
 else{
     cout<<" < The system will procceed to make the frame > "<<endl<<endl;
     return event;
 }
}

 void StopTimer(){
     auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "< Timer stopped at: " << ctime(&end_time)<<" >"<<endl;
}

int main(){

    //declaration point
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"This is a basic illustration of how the Go-Back-N (Sender) Algorithm works"<<endl;
    string package="";
    
    srand(time(0));
    int TimeOut=0; //No time-out has occured
    int x=success(); //will be used to check whether ACK was received or not there is a 20% an ACK will fail
    
    int storeframeposition=0; //StoreFrame[1,2,3,4,5] where 1-5 is the frame position
    
    int power_result=0; //the result of 2^m for example 2^2=4 the power_result is 4
    
    int power_value=2; //the power value 2 ^ m where power value is 2 the function wont work if we change it!       
    
    int m;
    
    int Sf_value=0; //PackageArray[0] according to figure 11.15
    
    int Sn_value=1; //PackageArray[1] according to figure 11.15
    
    int timerisrunning=0; //line 17 of page 329
    
    int Sw=2; //the user will give the power of 
    cout<<"Give the value of (m is the size of the window Sw =[2^(m)]-1 to prevent errors according to page 328)"<<endl<<endl;
    scanf("%d",&m);
    power_result=power(2,m);
    //cout<<"the power result is:"<<power_result; in case we want to check 2(^m) was executed correctly 
    
    int EventRequestToSend=1;
    int StoreFrame[10];
    int PackageArray[4];
    for(int i=0;i<4;i++){  //making the package look like < 0 1 2 3 >
        PackageArray[i]=i;
    }


    while(true)
    {
        int Sf=PackageArray[Sf_value]; //PackageArray[0] it will change with every loop
        int Sn=PackageArray[Sn_value]; //PackageArray[1] it will change with every loop
        package=WaitForEvent();
        if(EventRequestToSend==1){
            if(Sn-Sf >= Sw){
                cout<<"< Sw is bigger than Sn-Sf the system will sleep... >"<<endl;
                cout<<"< The system will sleep for 10 seconds >"<<endl;
                sleep(10); //sleep for 10 seconds
            }
            else{
                GetData();
                MakeFrame(Sn);
                StoreFrame[storeframeposition];
                SendFrame(Sn);
                Sn=Sn+1;
                if(timerisrunning==0){
                StartTimer();
                timerisrunning=1;
                }
                //if event Arrival Notification
                        //receive ACK frame
        cout<<"Checking if acknowledgement is received (ACK)....."<<endl;
        
        if(x>20){ //success a valid ack has arrived
        int ackNo=1;
        cout<<"/n! Success: Acknowledgement received! "<<endl<<endl;
        while(Sf<=ackNo){
            StoreFrame[Sf_value]=0;
            Sf=Sf+1;
        }
        StopTimer();
        x+=-10;
        }
        //else 20% chance it failed / failure the ACK frame was not received! / Ack is corrupted
        else{
        cout<<"<! FAILURE: A corrupted ACK was received or failed to reach destination: The System will sleep !>"<<endl<<endl;
        cout<<"< The system will sleep for 10 seconds >"<<endl;
        TimeOut=1;
        sleep(10); //sleep for 10 seconds        
         }
        }
        //TimeOut
        //If Event==Time Out
        cout<<"< Checking if an event time out was received in your system...."<<endl;
        if(TimeOut==1){
        cout<<"< An event time out has occured in your system >"<<endl;
        StartTimer();
        int Temp=Sf;
        while(Temp<Sn){
        SendFrame(Sf);
        Sf=Sf+1;
        break; //note that break is there to eliminate any issues with the Temp < Sn
        }
        }
    }
  }
}