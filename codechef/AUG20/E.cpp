//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const int INF = 1e9;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> f(n);
  for(int &i : f)
    cin >> i;
  vector<int> count(102, 0), dp(n, INF);
  dp[n-1] = k;
  for(int i = n-2; i >= 0; i--) {
    fill(count.begin(), count.end(), 0);
    int cost = k;
    for(int j = i; j < n; j++) {
      int x = f[j];
      if(count[x] == 1) {
        cost += 2;
      } else if(count[x] > 1) {
        cost++;
      }
      count[x]++;
      if(j == n-1) 
        dp[i] = min(dp[i], cost);
      else
        dp[i] = min(dp[i], cost+dp[j+1]);
    }
  }
  cout << dp[0] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
4
9 5
1 2 3 1 2 3 1 2 3
8 2
3 5 4 4 5 1 5 4
7 2
1 2 2 1 2 2 1
5 5
1 1 1 1 1

14
6
8
10

*/
