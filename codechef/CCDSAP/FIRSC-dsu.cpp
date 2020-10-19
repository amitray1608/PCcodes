//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<int>root;
vector<int>w;
int roots(int x){
  if(root[x] == x)
    return x;
  return roots(root[x]);
}

void unions(int x, int y) {
  int n = roots(x);
  int m = roots(y);
  if(n == m) return;
  if(w[m] > w[n])
    root[n] = root[m], w[m] += w[n];
  else
    root[m] = root[n], w[n] += w[m];
}

void solve(){
  int n, m;
  cin >> n >> m;
  root.resize(n+1);
  w.resize(n+1);
  for(int i = 1; i <= n; i++) w[i] = 1, root[i] = i;
  for(int i = 1; i <= m; i++) {
    int x,  y;
    cin >> x >> y;
    unions(x, y);
  }
  ll ans = 1, count = 0;
  for(int i = 1; i <= n; i++) {
    if(i == root[i]){
      count++;
      ans = (ans*w[i])%MOD;
    }
  }
  cout << count << ' ' << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  