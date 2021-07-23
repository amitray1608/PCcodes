
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    sort(a.begin(), a.end());
    int left = 0;
    vector<int> res;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (sum + a[i] == x) {
        left = a[i];
      } else {
        res.push_back(a[i]);
        sum += a[i];
      }
    }
    res.push_back(left);
    sum += left;
    if (sum == x) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
      } cout << '\n';
    }
  }	
  return 0;
} //Hajimemashite

