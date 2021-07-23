
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
    long long count = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      count += mp[x - i]++;
    }
    cout << count << '\n';
  }	
  return 0;
} //Hajimemashite

