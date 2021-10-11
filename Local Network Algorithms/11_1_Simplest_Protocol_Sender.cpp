#include <iostream>
#include <string>

using namespace std;


string WaitForEvent(){ //the system will check whether or not an event has occured basically if the user types something then an event occurs
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

void GetData(){ //get data function is called on line 37
    cout<<"< The system is receiving data..>"<<endl;
}
void MakeFrame(){ //make frame function is called on line 38
    cout<<"< The sender is making the frame... >"<<endl;
}

void SendFrame(){ //send frame function is called on line 39
    cout<<" < The package has been successfully sent to the receiver ! >"<<endl;
}

int main(){
   string package="";
   cout<<"This is a basic illustration of how the simplest protocol (from the sender side) works by AM1716 - ALEXANDROS PANAGIOTAKOPOULOS"<<endl;
   while(true){
   cout<<"-----------------------------------------------------------"<<endl;
   package=WaitForEvent();
   GetData();
   MakeFrame();
   SendFrame();
   if(package.empty()){
   cout<<"< No package was received !"<<endl<<endl;
   }
   else{  
    cout<<"< The package was successfully sent :"<<package<<" >"<<endl<<endl;
   }

   cout<<"< The system will repeat the proccess again >"<<endl;
   }
}