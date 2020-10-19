//Amit Kumar
//18BCS2059
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  string s;
  cin >> s;
  map<char, int>c;
  for(char &i : s)
    c[i]++;
  
  for(auto i : c) {
    cout << i.first << " occurred : " << i.second << " times." << endl;
  }
 return 0;
}