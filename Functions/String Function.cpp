#include <iostream>
#include <string>

using namespace std;

string read_string()
{
string test ="I HAVE RETURNED";
return test;
}

int main() 
{
string word = "start";
cout << "The word starts out as : '" << word << "'" << endl;
word = read_string();
cout << "and becomes '" << word << "', after return from function." << endl << endl;
return 0;
}