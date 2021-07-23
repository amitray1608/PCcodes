
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    ll n;
    cin >> n;
    ll given = 2050;
    ll rem = n % given;
    ll tiems = n / given;
    if (rem) {
      cout << -1 << '\n';
    } else {
      ll count = 0;
      while (tiems) {
        count += tiems % 10;
        tiems /= 10;
      }
      cout << count << '\n';
    }
  }	
  return 0;
} //Hajimemashite

