
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
    set<array<int, 2>> unequal;
    for (int i = 0; i < n/2; i++) {

    }
    auto checkPalin = [&]() {
      for (int i = 0; i < n; i++) {
        if (s[i] != s[n - i - 1]) 
          return false;
      }
      return true;
    };

    int alice = 0, bob = 0;
    while (oneCount < n) {
      if ( 
    }
    if (alice == bob) {
      cout << "DRAW" << "\n";
    } else if (alice < bob) {
      cout << "ALICE" << '\n';
    } else {
      cout << "BOB" << '\n';
    }
  }	
  return 0;
} //Hajimemashite

