#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  string s;
  cin >> s;
  int n = (int)s.length();
  if(n == 1) {
    cout << 0 << endl;
    return;
  }
  vector<int> pre(n+1, 0), suf(n+1, 0);
  for(int i = 0; i < n; i++) {
    if(isupper(s[i]))
      suf[i+1] = 1;
    else
      pre[i+1] = 1;
  }
  for(int i = 2; i <= n; i++) pre[i] += pre[i-1];
  for(int i = n-1; i >= 1; i--) suf[i] += suf[i+1];
  int mini = INT_MAX;
  for(int i = 1; i <= n; i++) {
    mini = min({mini, suf[i]+pre[i-1], pre[i]+suf[i+1]});
  }
  cout << mini << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
