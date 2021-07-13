#include <iostream>
#include <cstdlib>

int rolldice(int dice){
    int dice=0;
    x = rand() % 6;
    return dice;
}


int main(){
cout<<"-----CREATED BY ALEXANDROS PANAGIOTAKOPOULOS-------------"<<endl;
cout<<"Welcome to my dice rolling mini game"<<endl<<endl<<endl;



while(true){
    int dice=0;    
    int diceresult=0;
    cout<<"The banker will now roll the dice..."<<endl;
    diceresult=rolldice(dice);
    cout<<"The game rolled a %d",dice<<endl;
    break;
}

}
