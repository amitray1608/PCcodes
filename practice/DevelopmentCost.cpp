#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

int dx[]={1, 0, -1, 0};int dy[]={0, 1, 0, -1}; //4 Direction

void solve(){
  int n, m, q, k;
  cin >> n >> m >> q >> k;
  vector<vector<int>> adj(n, vector<int>(m, 0));
  for(auto &i : adj)
    for(auto &j : i) cin >> i;
  while(q--) {
    int x, y, X, Y;
    x--, y--, X--, Y--;

  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
 // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
