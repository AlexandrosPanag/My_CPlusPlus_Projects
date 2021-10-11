#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

//If we wanted to make the program run infinitely we remove the save++ statement on line 36 
int success(){
   int x;
   x = rand() % 101;
   return x;
}
void WaitForEvent(){
    printf("< An event occurs..>\n");
}
void GetData(){
    printf("< Getting data..>\n");
}
void MakeFrame(){
    printf("< Making the frame.>\n");
}
void SendFrame(){
    printf("< Sending the frame..>\n");
}
void ReceiveFrame(){
    printf("< The frame was successfully received ending the process..>\n");
}

int main(){
    int save=0;
    int y=1;
    int x;
    x=success();


    while(y==1){
    save++;
    int canSend=1;
    WaitForEvent();
    if(canSend==1){
    GetData();
    MakeFrame();
    SendFrame();
    canSend=0;
    printf("Checking if acknowledgement is received (ACK).....\n");
    srand(time(0));
        if(x>20){
        printf("Success: Acknowledgement received!\n");
        x+=-10;
        ReceiveFrame();
        }
        else{
            printf("ERROR: Acknowledgement was not received!\n");
            x+=45;
        }
        printf("----------------------------------------------------------------------------------------\n\n\n");
        if(save==5){
         y++;
        }
    }
 }
    return 0;
}