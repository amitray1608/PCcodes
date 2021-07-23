
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  int n, m, q;
  cin >> n >> m >> q;
  priority_queue<array<int, 3>> val, siz;
  for (int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;
    array<int, 3> x = {v, w, i};
    val.push(x);
  }
  vector<int> w(m);
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    w[i] = v;
    array<int, 3> x = {v, i, -1};
    siz.push(x);
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    priority_queue<array<int, 3>> valcp, sizcp;
    valcp = val;
    sizcp = siz;
    int sum = 0;
    vector<int> wc = w;
    while (!valcp.empty()) {
      if (sizcp.empty()) break;
      auto v = valcp.top();
      valcp.pop();
      int maxi = 0, prev = INT_MAX, pos = -1;
      for (int i = 0; i < m; i++) {
        if ((i >= l and i <= r) or wc[i] == -1) continue; 
        if (wc[i] >= v[1]) {
          if (prev > wc[i]) {
            maxi = v[0];
            pos = i;
            prev = wc[i];
          }
        }
      }
      if (pos != -1) wc[pos] = -1;
      sum += maxi;
    }
    cout << sum << '\n';
  }


  return 0;
} //Hajimemashite



