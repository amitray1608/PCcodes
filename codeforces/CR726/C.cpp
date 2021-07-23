
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
    int count = 0;
    bool ok = (n & 1);
    while (~n & 1) {
      count++;
      n >>= 1;
    }
    ok |= (n == 1 and count & 1);
    cout << (ok ? "Bob" : "Alice") << '\n';
  }	
  return 0;
} //Hajimemashite

