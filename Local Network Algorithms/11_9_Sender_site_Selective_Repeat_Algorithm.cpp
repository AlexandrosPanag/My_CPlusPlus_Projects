#include <iostream>
#include <string>
#include <cstdio>
#include <ctime> 
#include <chrono>
#include <unistd.h>
#include <cmath>   

using namespace std;

string WaitForEvent(){
 string event="";
 cout<<"-> Type something (we assume the sender sent it using the Stop_And_Wait from the sender point of view ) (or did not sent anything) to send a packet to the receiver! "<<endl;
 getline(cin, event);
 if(event.empty()){
     cout<<" < The system will wait until an event occurs > "<<endl<<endl;
 }
 else{
     cout<<" < The system will procceed to receive the frame > "<<endl<<endl;
     return event;
 }
}

 int success(){ //Randomly we will check whether an ACK/NAK has arrived or not there is a 20% an ACK/NAK will fail to be received
   int x;
   x = rand() % 101;
   return x;
}

 int windowfull(){ //Randomly we will whether the window is full or not 50% chance it is full and 50% chance it isnt full
   int x;
   x = rand() % 101;
   if(x>50){
   return 1; //the window is full
   }
   else{
   return 0; //the window isnt full
   }
}


 int CheckKnackOrAck(){ //Randomly we will check whether an ACK or NAK has arrived if the frame isnt corrupted
   int y;
   y = rand() % 101;
   return y;
}

void ReceiveFrame(){
    cout<<"< An ACK or NAK has arrived "<<endl<<endl;
}
void SendFrame(){
    cout<<"< Sending frame.... "<<endl<<endl;
}
void resend(int nakNo){
    cout<<"Resending the Nack Number..."<<endl<<endl;

}
void StartTimer(){
  auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "< Start timer of package began on: " << ctime(&end_time)<<" > ";
 }

void GetData(){
    cout<<"< The system is receiving data..>"<<endl<<endl;
}

void Purge(int Sf){
    cout<<"Purging the Sent Frame...."<<Sf<<endl;
}
void MakeFrame(int Sn){
    cout<<"< The sender is making the frame of "<<Sn<<"...."<<endl<<endl;
}

 void StopTimer(){
     auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "< Timer stopped at: " << ctime(&end_time)<<" >"<<endl;
}

int main(){
while(true){

srand(time(0));
int reply=windowfull(); //checking whether the window size is full or not

cout<<"------------------------------------------------------------------"<<endl<<endl;
cout<<"This is a basic illustration of how the algorithm Sender-site Selective Repeat algorithm works by AM1716"<<endl;
//declaration point
    srand(time(0));
    int x=success(); //will be used to check whether ACK/NAK was received or not there is a 20% an ACK/NAK will fail
    srand(time(0));
    int y=CheckKnackOrAck();
    int StoreFramePosition=0;
    int NakNo=0;
    int ackNo=100;
    int EventRequesToSend=1;
    int PackageArray[8]={0,1,2,3,4,5,6,7};
    int Sf=PackageArray[0]; // assume the package is <0 1 2 3> Sf is 0
    int Sn=PackageArray[1];// assume the package is <0 1 2 3> Sn is 0
    int window_is_full=0;
    int StoreFrame[10];
    int work=1; //An ACK will always arrive


    int Rn=PackageArray[0];
    string package="";
    package=WaitForEvent();
    cout<<"To solve problems with the maximum window size we use 2(^n)-1 otherwise, we might have a frame lost in transmission or discarded"<<endl;
    cout<<"However, for explanatory reason we will decide whether or not the window size is full ranomly!"<<endl<<endl;

    if(EventRequesToSend==1){
       //if window is full
        if(reply==1){
            cout<<"The window size is full the station will consider the frame as Lost and accept frame 0 as a new Frame"<<endl;
            cout<<"The system will now sleep"<<endl;
            sleep(10);
        }
        if(reply==0){
           GetData();
           MakeFrame(Sn);
           StoreFrame[StoreFramePosition]=Sn; //StoreFrame(sn)
           Sn=Sn+1;
           StartTimer();
        }
    }
    //If(Event{ArrivalNotification})
        ReceiveFrame();
         //if(currupted(frame))
          cout<<"Checking if acknowledgement is received (ACK) or negative-Acknowledgement (NAK)....."<<endl;

        //Receive ACK/NAK or a corrupted frame
        if(x>20){ //success a valid ack/nak has arrived
        //if(FrameType==NAK) if y is > 0-50 == NAK
        if(y<=50){
        cout<<"A negative acknowledgement has arrived (NAK) !"<<endl;
        //if nakNo between Sf and So is always true
        int nakNo=Sn;
        resend(nakNo);
        }
        //if(FrameType==Ack) if y is > 50-100=ACK
        else if(y>50){
         cout<<"An acknowledgement has arrived (ACK)"<<endl;
         //if (ackNo between Sf and So) will always be true and ackNo has the number 100
         while(Sf<ackNo){
             Purge(Sf);
             StopTimer();
             Sf=Sf+1;
             break;
         }
        }
        }
        //else 20% chance it failed / failure the ACK frame was not received! / Ack is corrupted
        if(x<=20){
        //Receive a corrupted Frame
        cout<<"<! FAILURE: A corrupted frame was received or failed to reach destination: The System will sleep !>"<<endl<<endl;
        cout<<"< The system will sleep for 10 seconds >"<<endl;
        sleep(10); //sleep for 10 seconds      
         }
         int TimeOut=1;   
         if(TimeOut==1)//The timer expired
         {
         StartTimer();
         SendFrame();
         }
}
}