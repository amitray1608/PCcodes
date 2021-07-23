
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> f(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    f[x].push_back(i + 1);
  }
  for (int i = 0; i <= n; i++) {
    f[i].push_back(0);
    f[i].push_back(n + 1);
    sort(f[i].begin(), f[i].end());
    for (int j = 0; j + 1 < (int)f[i].size(); j++) {
      if (f[i][j + 1] - f[i][j] > m) {
        cout << i << '\n';
        return 0;
      }
    }
  }
  return 0;
} //Hajimemashite

