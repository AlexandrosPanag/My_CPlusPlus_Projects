#include <iostream>
#include <string>
#include <cstdio>
#include <chrono>
#include <ctime> 

using namespace std;

void GetData(){
    cout<<"< The system is receiving data..>"<<endl;
}

int makeFrame(int n){
     cout<<"< Making the frame:"<<n<<" >"<<endl;
     return n;
 }
 
 int sendFrame(int n){
     cout<<"< Sending the frame:"<<n<<" >"<<endl;
     return n;
 }

 void StartTimer(int n){ //we need the chrono function to call the system timer to print the time
  auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "-- Start timer of package began on: " << ctime(&end_time)<<endl;
 }

 int Corrupted(int x){
     return 0;
 }

 int success(){ //Randomly we will check whether an ACK has arrived or not there is a 20% an ACK will fail to be received
   int x;
   x = rand() % 101;
   return x;
}

 void StopTimer(){
     auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "-- Timer stopped at: " << ctime(&end_time)<<endl;
 }

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

int main(){
    //declaration point
    string package="";
    srand(time(0)); //randomize the time
    int x=success(); //will be used to check whether ACK was received or not there is a 20% an ACK will fail
    int ACKcorrupted=0;
    int StoreFrame[30];
    int n=0;  //Sn
    int i=0; //StoreFramePosition
    int RequestToSend=1;
    int canSend=1;
    //end declaration point
  

    while(true){
        package=WaitForEvent();
        cout<<"-----------------------------------"<<endl;
        n++;
        if(canSend==1&&RequestToSend==1){
            GetData();
            makeFrame(n);
            StoreFrame[i]=n;
            sendFrame(n);
            StartTimer(n);
            n++; //Sn=Sn+1
            canSend=0;
            cout<<"Checking if acknowledgement is received (ACK)....."<<endl;
        }       
        if(x>20){
        cout<<"Success: Acknowledgement received!"<<endl;
        x+=-10;
        if(ACKcorrupted==0&&n!=0){
         StopTimer();
         //purgeFrame
         StoreFrame[i]=0;
         canSend=1;
        }
        }
        //failure the ACK frame was not received!
        else{
        int StartTimer=0;
        //we can manually alter what happens if the event times out by changing the value of the corrupted function in line 33;
        if(StartTimer==ACKcorrupted)
           cout<<"resending the frame:"<<StoreFrame[i]<<endl;
        }   
    }
}