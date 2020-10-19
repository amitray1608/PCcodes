//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<pair<int, int>>>adj;
vector<bool>vis;
vector<int>order;

void dfs(int s) 
{}

void solve(){
  int n;
  cin >> n;
  adj.resize(n);
  vis.resize(n, false);
  for(int i = 0; i < n-1; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
  }
  dfs();
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