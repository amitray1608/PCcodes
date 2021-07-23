
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;

  for (int tt = 1; tt <= t; ++tt) {
    long long L, R;
    cin >> L >> R;
    auto recc = [&](long long x) {
      long long count = 0;
      while (x) {
        count += x;
        x /= 10;
      }
      return count;
    };
    long long res = recc(R) - recc(L);
    cout << res << '\n';
  }	
  return 0;
} //Hajimemashite

