
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
    vector<int> a(n);
    for (int &i : a) cin >> i;
    for (int i : a) {
      if (i&1)
        cout << i << ' ';
    }
    for (int i : a) {
      if (~i&1)
        cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
} //Hajimemashite

