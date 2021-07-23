
#include<bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x << " = " << x << endl;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int maxi = 1;

  auto calculate = [&](int x, int y, int X, int Y) {
    int count = 0;
//    for (int i = x; i <= X; i++) {
//      for (int j = y; j <= Y; j++) {
//        if (i == x or i == X or j == Y or j == y) {
//          if (s[i][j] == '1') return;
//          count++;
//        } else {
//          if (s[i][j] == '0') count++;
//        }
//      }
//    }
    if (s[x][y] == '0' and s[X][Y] == '0')
      count = (X - x + 1) * (Y - y + 1);
    maxi = max(maxi, count);
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = i + 1; k < n; k++) {
        for (int l = j + 1; l < m; l++) {
          calculate(i, j, k, l);         
        }
      }
    }
  }
  cout << maxi << '\n';
  return 0;
} //Hajimemashite

