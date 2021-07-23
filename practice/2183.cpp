
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  sort(a.begin(), a.end());
  int sum = 1;
  for (int i = 0; i < n and a[i] <= sum; i++) {
    sum += a[i];
  }
  cout << sum << '\n';
  return 0;
} //Hajimemashite


