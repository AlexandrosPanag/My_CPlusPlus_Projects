#include <iostream>
#include <fstream>
#include<fstream>
#include<map>
#include<vector>
#include <algorithm>

using namespace std;


int occurrences;
  struct wo{
      string word;
      int occurrences;
      bool operator<(wo&other)const{
          return occurrences<other.occurrences;
      }
};
string capitalize (string s){
    string ns;
    for(char c:s){
        ns.push_back(toupper(c));
    }
    return ns;
}
int main(){
fstream fin;
fin.open("1984.txt",ios::in);
string word;
map<string,int>dictionairy;
while(fin>>word){
    word=capitalize(word);
    if(dictionairy.find(word)==dictionairy.end())
    {
        dictionairy[word]=1;
    }
    else
    { 
    dictionairy[word]++;
    }
}
vector<wo>items;
for(auto kv:dictionairy)
{
    wo item;
    item.word=kv.first;
    item.occurrences=kv.second;
    items.push_back(item);
}
sort(items.begin(),items.end());
for(auto item:items)
{
    cout<<" "<<item.word<<" "<<item.occurrences<<endl;
}
return 0;
}