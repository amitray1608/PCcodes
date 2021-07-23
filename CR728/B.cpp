
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int maxn = 2e5 + 1;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  vector<set<int>> f(maxn + 1);
  for (int i = 1; i <= maxn; i++) {
    for (int j = i; j <= maxn; j += i) 
      f[j].insert(i);
  }
  vector<int> factor[maxn + 1];
  for (int j = 1; j <= maxn; j++) 
    for (int i : f[j]) factor[j].push_back(i);
  
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> fre(1e6, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      fre[a[i]] = i + 1;
    }
    int res = 0;
    for (int mul = 3; mul < 2 * n; mul++) {
      int maxi = factor[mul].size();
      maxi /= 2;
      for (int div = 0; div < maxi; div++) {
        int curr = factor[mul][div];
        int req = mul / curr;
        if (!fre[curr] or !fre[req]) continue;
        if (fre[curr] + fre[req] == mul) {
          res++;
        }
      }
    }
    cout << res << '\n';
  }	
  return 0;
} //Hajimemashite

