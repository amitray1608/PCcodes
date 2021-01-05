#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s[n];
  map<string, int> mp, mpp;
  for(string &i : s) {
    cin >> i;
    if(i[0] == '!') mpp[i]++;
    else mp[i]++;
  }
  for(auto i : mp) {
    string t = "!" + i.first;
    if(mpp.find(t) != mpp.end()) {
      cout << i.first;
      return 0;
    }
  }
  cout << "satisfiable" << '\n';
  return 0;
}
