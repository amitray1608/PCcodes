#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

const int maxn = 1e5 + 1;
int dp[maxn][2];
int n, k;
vector<int> a;

int recc(int i, int curr) {
  int &ans = dp[i][curr];
  if(ans != -1) return ans;
  bool flag = false;
  for(int j = 0; j < n; j++) {
    if(a[j] <= i)
      flag |= (recc(i - a[j], curr ^ 1) == curr);
  }
  return (ans = (0 == flag) ^ curr);
}

void solve(){
  cin >> n >> k;
  a.resize(n);
  for(int &i : a) cin >> i;
  memset(dp, -1, sizeof dp);
  dp[0][1] = 0;
  dp[0][0] = 1;
  int ans = recc(k, 0);
  cout << (!ans ? "First" : "Second");
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
