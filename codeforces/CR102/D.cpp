#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 3;
int pre[maxn], minip[maxn], maxip[maxn];
int suf[maxn], minis[maxn], maxis[maxn];

void solve() {
  int n, q;
  cin >> n >> q;
  string s; cin >> s;
  int maxi = n;
  maxi += 1;
  for(int i = 0; i < n + 3; i++) {
    pre[i] = suf[i] = 0;
    minip[i] = minis[i] = maxi;
    maxip[i] = maxis[i] = 0;
  }
  for(int i = 1; i < n + 1; i++) {
    int tmp;
    if(s[i - 1] == '+') tmp = 1;
    else tmp = -1;
    pre[i] = pre[i - 1] + tmp;
    minip[i] = min(pre[i], minip[i - 1]);
    maxip[i] = max(pre[i], maxip[i - 1]);
  }
  for (int i = n; i > 0; i--) {
    minis[i] = min(pre[i], minis[i + 1]);
    maxis[i] = max(pre[i], maxis[i + 1]);
  }

  auto query = [&](int u, int v) {
    int l = 0, r = 0;
    if (u > 1) l = min(l, minip[u - 1]);
    if (u > 1) r = max(r, maxip[u - 1]);
    if (v < n) l = min(l, pre[u - 1] - pre[v] + minis[v + 1]);
    if (v < n) r = max(r, pre[u - 1] - pre[v] + maxis[v + 1]);  
    int res = r - l + 1;
    return res;
  };

  while(q--) {
    int u, v;
    cin >> u >> v;
    int ans = query(u, v);
    cout << ans << '\n';
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite

