#include <iostream>
#include <string>
#include <cstdio>
#include <ctime> 
#include <unistd.h>

using namespace std;

string WaitForEvent(){
 string event="";
 cout<<"-> Type something (we assume the sender sent it using the Sender Site Algorithm ARQ of stop and wait ) (or did not sent anything) to send a packet to the receiver! "<<endl;
 getline(cin, event);
 if(event.empty()){
     cout<<" < The system will wait until an event occurs > "<<endl<<endl;
 }
 else{
     cout<<" < The system will procceed to receive the frame > "<<endl<<endl;
     return event;
 }
}

int checkcorrupted(){
 string event="";
 cout<<"-> The Frame is being processed to check if it has been corrupted <- "<<endl<<endl;
 int x=0;
   x = rand() % 101;
   if(x>70){
   return 1; //30% chance that the package is corrupted
   }
   else{
       return 0;
   }
}

void ReceiveFrame(){
    cout<<"Receiving the frame.... the Stop-And-Wait-ARQ Protocol will now check if the the frame is corrupted..."<<endl<<endl;
}

void ExtractData(){
    cout<<"> The protocol will now extract the data to your device <"<<endl<<endl;
}

void DeliverData(){
    cout<<"> The protocol will now deliver the data to your device..... <"<<endl<<endl;
}

int SendFrame(int ReceiverNumber){
     cout<<" ACK sent :"<<ReceiverNumber<<endl;
 }

int main(){

int frame=0;
int data_frame_arrives=1;
string package="";
int ReceiverNumber=0;
int SequenceNumber=0;

while(true){
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    int corruption=0;
    srand(time(0));
    package=WaitForEvent();
    if(data_frame_arrives==1) {
        ReceiveFrame();
        corruption=checkcorrupted(); //if corrupted frame line 8 statement
        if(corruption==1){ //the package is corrupted
        cout<<" !! Warning: the protocol found a corrupted frame the system will sleep until a new frame arrives !! "<<endl<<endl;
        cout<<"-----------------------------------------------------------------------";
        sleep(10); //sleep for 10 seconds
        }
        else{  //the package isn't corrupted
        if(SequenceNumber==ReceiverNumber) //if SeqNo == Rn
        ExtractData();
        DeliverData();
        ReceiverNumber=ReceiverNumber+1;
        SequenceNumber-SequenceNumber++;
        }
        SendFrame(ReceiverNumber);
    }
  }
}