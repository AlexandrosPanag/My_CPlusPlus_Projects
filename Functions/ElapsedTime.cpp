//original code was found https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c 
#include <iostream>
#include <chrono>
#include <ctime>    

using namespace std;

void GetTimeElapsed(){
    auto start = chrono::system_clock::now();
    // Some computation here
    auto end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "finished computation at " << ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
int main()
{
    GetTimeElapsed();
}