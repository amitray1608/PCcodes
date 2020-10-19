#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  int n;
  cin >> n;
  char c[n][n];
  int row[n] = {0}, col[n] = {0}; 
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> c[i][j];
    }
  }
  int count = 0;
  for(int i = 0; i < n; i++) {
    // int count = 0;
    for(int j = 0; j < n; j++) {
      if(c[i][j] == 'D')
        count++;
    }
    row[i] = count;
  }
  for(int i = 0; i < n; i++) {
    int counts = 0;
    for(int j = 0; j < n; j++) {
      if(c[j][i] == 'C')
        counts++;
    }
      col[i] = counts;
  }
  int maxi = (int)sqrt(count);
  cout << maxi << endl;
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
4
C D C D
C C D C
D D D D
C D D D

2
CD
CC

7
C D D C D D D
C D D C D D D
D D D D D D C
D C D C D D D
D D D C D C D
C D D C D C C
C D C D C C C
7
C C C D C C C
C C C D C C C
C C C D C C C
D D D D D D D
C C C D C C C
C C C D C C C
C C C D C C C

5
D D C D D
D C D C D
C D D D C
D C D C D
D D C D D

*/