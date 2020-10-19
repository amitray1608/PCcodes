#include<bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  int mini = 0;
  if(n&1) {
    string r = "", b = "";
    for(int i = 0; i < n/2; i++) {
      r += "wb";
      b += "bw";
    }
    
  } else {

  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}  
