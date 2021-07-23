
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n, vector<int>(m, 0));
    vector<array<int, 3>> a;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        res[i][j] = x;
      }
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
      vector<bool> vis(m, 0);
      int pos = 0, mini = INT_MAX;
      for (int j = 0; j < m; j++) {
        if (
      }
    }
    for (auto i : res) {
      for (auto j : i) {
        cout << j << ' ';
      } cout << '\n';
    }
  }	
  return 0;
} //Hajimemashite

