
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    for (int i = 0; i < n; i++) {
      while (a[i] and k) {
        a[i]--;
        a[n - 1]++;
        k--;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }	
  return 0;
} //Hajimemashite

