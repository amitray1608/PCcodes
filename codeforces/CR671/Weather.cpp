#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  vector<int>pre(n, 0), suff(n, 0), a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] == 0) pre[i] = suff[i] = 1;
    else if(a[i] < 0) suff[i] = 1;
    else 
      pre[i] = 1;
  }
  for(int i = 1; i < n; i++)
    pre[i] += pre[i-1];
  for(int i = n-2; i >= 0; i--)
    suff[i] += suff[i+1];
  int mini = INT_MAX;
  for(int i = 0; i < n-1; i++) {
    mini = min({mini, suff[i]+pre[i+1], pre[i] + suff[i+1]});
  }
  cout << mini << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
