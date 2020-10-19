//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll Count(string S, string pre)  { 
  ll m = pre.size(), n = S.size(); 
  if (m > n) 
    return 0; 
  ll dp[m + 1][n + 1]; 
  for (ll i = 1; i <= m; i++) 
      dp[i][0] = 0; 
  for (ll j = 0; j <= n; j++) 
      dp[0][j] = 1; 
  for (ll i = 1; i <= m; i++) { 
    for (ll j = 1; j <= n; j++) { 
      if (pre[i - 1] != S[j - 1]) 
        dp[i][j] = dp[i][j - 1]; 
      else
        dp[i][j] = dp[i][j-1] + dp[i-1][j-1]; 
    } 
  } 
  return dp[m][n]; 
} 

void solve(){
  string s; 
  cin >> s;
  ll q;  
  cin >> q;
  while(q--){
    char type;  
    cin >> type;
    ll L; 
    cin >> L;
    ll n;
    if(type == 'p') 
        n = 0;
    else  
      n = s.size() - L;
    string sub = s.substr(n, L);
    cout << Count(sub, "ninjas") << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  