#include<bits/stdc++.h>

using namespace std;

const int inf = 1e4;
const short maxn = 4e3 + 1;
int dp1[maxn][maxn];
vector<int> a;
int n, k;

int recc(int i, int suma, int sumb) {
  if((suma <= 0 and sumb >= k)) return 0;
  if(i == 0) return inf;
  int &ans = dp1[i][suma];
  if(ans != -1) return ans;
  ans = inf;
  if(suma <= 0) {
    ans = min(ans, recc(i - 1, suma, sumb + a[i - 1])) + 1;
  } else if(sumb >= k) {
    ans = min(ans, recc(i - 1, suma - a[i - 1], sumb)) + 1;
  } else {
    ans = min({ans, recc(i - 1, suma - a[i - 1], sumb), recc(i - 1, suma, sumb + a[i - 1])}) + 1;
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> k;
    a.resize(n, 0);
    for(int &i : a) cin >> i;
    if(n < 2) {
      cout << -1 << '\n';
      continue;
    }
    sort(a.begin(), a.end());
    memset(dp1, -1, sizeof dp1);
    int res = recc(n, k, 0);
    cout << (res >= inf ? -1 : res) << '\n';
  }
  return 0;
}

