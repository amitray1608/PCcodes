#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  int ans = accumulate(a.begin(), a.end(), 0LL), maxi = 0;
  maxi = *max_element(a.begin(), a.end());
  cout << (maxi > ans - maxi ? 2LL * maxi : ans) << endl;
  return 0;
}
