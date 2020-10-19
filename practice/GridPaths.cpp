//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int dp[49];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1}; //4 Direction
const int n = 7;
vector<vector<bool>>vis(n+1, vector<bool> (n+1, false)); 


void backtrack(int r, int c, int &count, int &len) {
  if(r == n-1 and c == 0) {
    count += (len == n*n-1);
    return;
  }
    if (((r + 1 == n || (vis[r - 1][c] && vis[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !vis[r][c - 1] && !vis[r][c + 1]) ||
        ((c + 1 == n || (vis[r][c - 1] && vis[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !vis[r - 1][c] && !vis[r + 1][c]) ||
        ((r == 0 || (vis[r + 1][c] && vis[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !vis[r][c - 1] && !vis[r][c + 1]) ||
        ((c == 0 || (vis[r][c + 1] && vis[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !vis[r - 1][c] && !vis[r + 1][c]))
        return;
  vis[r][c] = true;
 if (dp[len] != -1) {
  switch (dp[len]) {
    case 0:
      if (r - 1 >= 0) {
        if (!vis[r - 1][c]) {
          len++;
          backtrack(r - 1, c, count, len);
          len--;
        }
      }
      break;

  case 1:
    if (c + 1 < n) {
      if (!vis[r][c + 1]) {
        len++;
        backtrack(r, c + 1, count, len);
        len--;
      }
    }
    break;

  case 2:
    if (r + 1 < n) {
      if (!vis[r + 1][c]) {
        len++;
        backtrack(r + 1, c, count, len);
        len--;
      }
    }
    break;

  case 3:
    if (c - 1 >= 0) {
      if (!vis[r][c - 1]) {
        len++;
        backtrack(r, c - 1, count, len);
        len--;
      }
    }
    break;
  }
    vis[r][c] = false;
    return;
  }

  if (r + 1 < n) {
    if (!vis[r + 1][c]) {
      len++;
      backtrack(r + 1, c, count, len);
      len--;
    }
  }

  if (c + 1 < n) {
    if (!vis[r][c + 1]) {
      len++;
      backtrack(r, c + 1, count, len);
      len--;
    }
  }

  if (r - 1 >= 0) {
    if (!vis[r - 1][c]){
      len++;
      backtrack(r - 1, c, count, len);
      len--;
    }
  }

  if (c - 1 >= 0) {
    if (!vis[r][c - 1]) {
      len++;
      backtrack(r, c - 1, count, len);
      len--;
    }
  }
  vis[r][c] = false;

}

void solve() {
  int count , len;
  memset(dp, -1, sizeof dp);
  string s;
  cin >> s;
  int i = 0;
  for(char &c : s) {
      if(c == 'U')
        dp[i] =  0;
      else if(c == 'R')
        dp[i] =  1;
      else if(c == 'D')
        dp[i] =  2;
      else if(c == 'L')
        dp[i] =  3;
      i++;
  } 
  count  = 0; len = 0;
  // for(int &i : dp)
  //   cout << i << ' ';
  backtrack(0, 0, count , len);
  cout << count << endl;
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
??????R??????U??????????????????????????LD????D?
*/