
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    long long n;
    cin >> n;
    while (true) {
      string s = to_string(n);
      long long sum = 0;
      for (char c : s) {
        sum += c - '0';
      }
      long long ans = __gcd(n, sum);
      if (ans > 1) {
        cout << n << '\n';
        break;
      }
      n++;
    }
  }
  return 0;
} //Hajimemashite

