//g++ -std=c++0x penneyGame.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main(){
int t,x; string s;
cin>>t;
while(t--){
  map<string, int> m;
  vector<string> v = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT","HHH"};
  cin>>x>>s;
  for(int i =0; i<38; i++){
    m[s.substr(i,3)]+=1;
  }
  cout<<x<<" ";
for(int i=0; i<8; i++){
  cout<<m[v[i]]<<" ";
}
cout<<"\n";
}
return 0;
}
