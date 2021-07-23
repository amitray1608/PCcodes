
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  string s[n];
  x--, y--;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int count = 0;
  int i = x - 1, j = y - 1;
  while (i >= 0) {
    if (s[i][y] == '.') count++;
    else break;
    i--;
  }
  while (j >= 0) {
    if (s[x][j] == '.') count++;
    else break;
    j--;
  }
  i = x + 1;
  j = y + 1;
  while (i < n) {
    if (s[i][y] == '.') count++;
    else break;
    i++;
  }
  while (j < m) {
    if (s[x][j] == '.') count++;
    else break;
    j++;
  }
  cout << count + 1 << '\n';
  return 0;
} //Hajimemashite

