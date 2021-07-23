
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zeroCount = 0, oneCount = 0;
    for (char c : s) {
      if (c == '0') zeroCount++;
      else oneCount++;
    }
    if (zeroCount == 0) {
      cout << "DRAW" << "\n";
    } else {
      if (zeroCount > 1 and zeroCount&1 and s[n/2] == '0') {
        cout << "ALICE" << '\n';
      } else {
        cout << "BOB" << '\n';
      }
    }
  }	
  return 0;
} //Hajimemashite

