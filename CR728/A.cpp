
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
    iota(a.begin(), a.end(), 1);
    if (n & 1) {
      a[0] = 3;
      a[1] = 1;
      a[2] = 2;
      for (int i = 3; i < n; i += 2) {
        swap(a[i], a[i + 1]);
      }
    } else {
      for (int i = 0; i < n; i += 2) {
        swap(a[i], a[i + 1]);
      }
    }
    for (int i : a) {
      cout << i << ' ';
    } cout << '\n';
  }	
  return 0;
} //Hajimemashite

