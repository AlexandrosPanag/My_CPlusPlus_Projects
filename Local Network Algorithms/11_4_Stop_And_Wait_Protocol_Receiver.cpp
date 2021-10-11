#include <iostream>
#include <string>


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

void ReceiveFrame(){
    cout<<"< The system is receiving a frame..>"<<endl;
}
void ExtractData(){
    cout<<"< The receiver is extracting the data... >"<<endl;
}

void DevilerFrame(){
    cout<<" < The package has been successfully delivered ! >"<<endl;
}
void SendFrame(){
    cout<<" < Sending an Acknowledgment Frame ! >"<<endl;
}
int main(){
   string package="";
   cout<<"This is a basic illustration of how the simplest protocol (from the receiver side) works by AM1716 - ALEXANDROS PANAGIOTAKOPOULOS"<<endl;
   while(true){
   cout<<"-----------------------------------------------------------"<<endl;
   package=WaitForEvent();
   ReceiveFrame(); //we call the function on line 21
   ExtractData();  //we call the function on line 24
   DevilerFrame(); //we call the function on line 28
   if(package.empty()){ //if the package is empty then print no package was received
   cout<<"< No package was received !"<<endl<<endl;
   }
   else{   //the package has an input then send the frame
    cout<<"< The receiver successfully received the package :"<<package<<" >"<<endl<<endl;
    SendFrame();
   }
   cout<<"< The system will repeat the proccess again >"<<endl;
   }
}