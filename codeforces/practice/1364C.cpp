//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n;
  cin >> n;
  int a[n+1], b[n+1], vis[n+1];
  memset(a, 0, sizeof a);
  memset(vis, 0, sizeof vis);
  memset(b, -1, sizeof b);
  for(int i = 1; i <= n; i++)
      cin >> a[i];
  for(int i = 1; i <= n; i++){
    if(a[i] != a[i-1])
        b[i] = a[i-1], vis[b[i]] = 1;
  }
  vis[a[n]] = 1;
  int m = 0;
  for(int i = 1; i <= n; i++){
    while(vis[m]) m++;
    if(b[i] == -1)
        b[i] = m, vis[b[i]] = 1;
    cout << b[i] << ' ';
  }
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  