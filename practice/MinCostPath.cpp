#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int maxn = 1e5 + 1;
bool prime[maxn];
vector<int> primes;

void seive() {
  memset(prime, true, sizeof prime);
  prime[1] = false;
  for(int i = 2; i*i < maxn; i++) {
    if(!prime[i]) continue;
    primes.push_back(i);
    for(int j = i * i; j < maxn; j += i) prime[j] = false;
  }
}

int prime_fact(int n) {
  int ans = 0;
  int sqr = sqrt(n) + 1;
  for(int i = 0; i < (int)primes.size() and primes[i] <= sqr; i++) {
    while(n % primes[i] == 0)
      ans++, n /= primes[i];
  }
  if(n != 1) ans++;
  return ans;
}


int main() {
  int t;
  cin >> t;
  seive();
  vector<int> cost(maxn);
  for(int i = 1; i < maxn; i++) cost[i] = prime_fact(i);
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), dp(n, vector<int>(m)), costij(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> a[i][j];
        costij[i][j] = cost[a[i][j]];
      } 
    }
    
    dp[0][0] = 0;
    for(int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + costij[i][0];
    for(int i = 1; i < m; i++) dp[0][i] = dp[0][i - 1] + costij[0][i];

    for(int i = 1; i < n; i++) {
      for(int j = 1; j < m; j++) {
        dp[i][j] = costij[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    cout << dp[n - 1][m - 1] << '\n';
  }
  return 0;
}
