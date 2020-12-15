#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for(int i = 0; i < n; i++) 
    cin >> a[i].first >> a[i].second;
  
  sort(a.begin(), a.end(), [&](const pair<int, int>& x, const pair<int, int>& y) {
    return x.first < y.first;
    });
//  for(int i = 0; i < n; i++) cout << a[i].first << ' ' << a[i].second << endl;
  int maxi = 0, curr = 0;
  for(int i = 0; i < n; i++) {
    curr += a[i].first;
    maxi += a[i].second - curr;
  }
  cout << maxi << '\n';   
  return 0;
}
