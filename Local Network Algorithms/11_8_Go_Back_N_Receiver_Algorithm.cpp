#include <iostream>
#include <string>
#include <cstdio>
#include <ctime> 
#include <unistd.h>


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

 int success(){ //Randomly we will check whether an ACK has arrived or not there is a 20% an ACK will fail to be received
   int x;
   x = rand() % 101;
   return x;
}
 int SendACK(int Rn){ //the system will send an ACKnowledgement
   cout<<"Request number:"<<Rn<<" has been ACKnowledged from receiver"<<endl;
}

void ReceiveFrame(){
    cout<<"< The system is receiving a frame..>"<<endl;
}

void DeliverData(){
    cout<<" < The data has been successfully delivered ! >"<<endl<<endl;;
}

int main(){
//declaration point
srand(time(0));
int x=success(); //will be used to check whether ACK was received or not there is a 20% an ACK will fail
int ArrivalOnNotification=1;
int Rn=0; 
int seqNo=0;

while(true){
cout<<"--------------------------------------------------------------------------"<<endl;
cout<<"This is an illustration of how the Go_Back_N (Receiver) Algorithm works by Alexandros Panagiotakopoulos/ AM1716"<<endl;
WaitForEvent();
if(ArrivalOnNotification==1){
    ReceiveFrame();
}
//if frame corrupted sleep else ...
       if(x<=20){ 
        sleep(10); //sleep for 10 seconds
        }
        //else 20% chance it failed / failure the ACK frame was not received! / Ack is corrupted
        else{
        if(seqNo==Rn){
            DeliverData();
            Rn=Rn+1;
            SendACK(Rn);
            seqNo++;
        }    
        }
}
}
