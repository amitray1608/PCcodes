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
  vector<vector<int>>g(n+1);
  for(int i = 0; i < n-1; i++){
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int a[n], order[n+1] = {0};
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    order[a[i]]  = i;
  }
  for(int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end(), cmp);
  }
  bool vis]n+1] = {false};
  queue<int>q;
  q.push(1);
  vector<int>ans;
  while(!q.empty()) {
    int x = 
  }
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