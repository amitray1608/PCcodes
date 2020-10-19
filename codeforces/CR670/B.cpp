#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  int a[n];
  for(int &i : a) {
    cin >> i;
  }
  sort(a, a+n);
  ll maxi = max(a[0] * a[1] * a[2] * a[3] * a[n - 1], a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5]); 
  cout << maxi << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  