
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
    long long res = (int)log2(n);
    res = pow(2LL, res) - 1;
    cout << res << '\n';
  }	
  return 0;
} //Hajimemashite

