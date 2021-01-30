#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> s(n, vector<char>(m));
  vector<string> row, col;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> s[i][j];
    }
  }
  string x = "", y = "";
  int bit = 0;
  for(int i = 0; i < m; i++) { 
    if(bit&1) x += '*', y += '.';
    else x += '.', y += '*';
    bit++;
  }
  bit = 0;
  for(int i = 0; i < n; i++) {
    if(bit&1) {
      row.push_back(x);
      col.push_back(y);
    } else {
      row.push_back(y);
      col.push_back(x);
    }
    bit++;
  }

  for(int i = 0; i < n; i++) cout << row[i] << '\n';
  cout << '\n';
  for(int i = 0; i < n; i++) cout << col[i] << '\n';
  cout << '\n';
  int mini = INT_MAX, count = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      if(s[i][j] != row[i][j]) count++;
  }
  mini = min(count, mini);
  count = 0;
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
    if(s[i][j] != col[i][j]) count++;
  } 
  cout << min(count, mini) << '\n';
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

