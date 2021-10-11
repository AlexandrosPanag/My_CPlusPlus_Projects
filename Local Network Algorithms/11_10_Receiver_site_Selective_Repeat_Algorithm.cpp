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

 int success(){ //Randomly we will check whether an ACK/NAK has arrived or not there is a 20% an ACK/NAK will fail to be received
   int x;
   x = rand() % 101;
   return x;
}

void ReceiveFrame(){
    cout<<"< An ACK or NAK has arrived "<<endl<<" >"<<endl;
}
void DeliverData(int Rn){
    cout<<"< Delivering Data of Rn.... "<<endl<<" >"<<endl;
}

 int checknaksent(){ //Randomly we will check whether an ACK/NAK has arrived or not there is a 20% an ACK/NAK will fail to be received
   int naksent;
   naksent = rand() % 101;
   return naksent;
}
void SendNak(int Rn){
    cout<<"< Sending Nak: "<<Rn<<" >"<<endl;
}



int checkmarkedsequencenumber(){ //we will check whether the sequence number has been marked or not with 60% chance it wasnt marked and 40% chance it was
int Mark;
   Mark = rand() % 101;
   return Mark;
}

int main(){
    //declaration point
    int Rn=0;
    srand(time(0));
    int StoreFrame[30];
    int x=success(); //will be used to check whether ACK/NAK was received or not there is a 20% an ACK/NAK will fail
    int AckNeeded=0;
    int RepeatAllSlots[30];
    int i=0; //Marked Slot = 0
    string package="";
    srand(time(0));
    int NakSent=checknaksent(); //we will check randomly whether the nak was sent 60 % chance it was sent 40% it failed
    int EventRequesToSend=1;
    srand(time(0));
    int Marked=checkmarkedsequencenumber(); // we will check whether the sequence number has been marked or not with 60% chance it wasnt marked and 40% chance it was
    //end of declaration point


    while(true){
        int seqNo=Rn;
        cout<<"----------------------------------------------"<<endl<<endl;
        cout<<"This is a basic illustration of how the algorithm Receiver-site Selective Repeat algorithm works by AM1716"<<endl;
        package=WaitForEvent();
         if(EventRequesToSend==1){ //if event arrival notification
          ReceiveFrame();
          if(x<20&&NakSent<40){ //if corupted(Frame) && NOT NakSent
           SendNak(Rn);
           NakSent=100; //nak sent = true
           cout<<"The system will sleep for 10 seconds "<<endl;
           sleep(10); //sleep for 10 seconds   
          }
          if(seqNo!=Rn&&NakSent<40){ //if seqNo !=Rn && NOT Nak Sent
            SendNak(Rn);
            NakSent=100; //nak sent = true
          }
          if(Marked<40){ //if seqNo in window && Marked seqNo
            StoreFrame[0]=Rn;
            Marked=100; //marked=true
            while(Marked>40){ 
                DeliverData(Rn);
                StoreFrame[0]=0; //Purge Rn;
                Rn=Rn + 1;
                AckNeeded=1;
                Marked=30; //after one loop the Mark will be removed for error protection purposes 
            }
            if(AckNeeded=1){
                SendAck(Rn);
                AckNeeded=0; //Ack needed = false
                NakSent=0; //Nack needed = false
            }
          }
         }
    }
}
