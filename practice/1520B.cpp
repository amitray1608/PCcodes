
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    long long n;
    cin >> n;
    long long res = 0;
    long long curr = 1;
    if (n <= 9) {
      cout << n << '\n';
      continue;
    }
    for (int i = 1; i <= 9; i++) {
      curr = i; 
      for (int j = 1; j <= 10; j++) {
        if (curr <= n) res++;
        curr *= 10;
        curr += i;
      }
    }
    cout << res << '\n';
  }	
  return 0;
} //Hajimemashite

