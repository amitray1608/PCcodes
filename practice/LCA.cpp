//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

template<typename T>
class LCA {
  public:
    T n;
    vector<vector<T>> adj;
    vector<vector<pair<T, T>>>dp;
    vector<T>euler, first, height, logs;
    vector<bool>vis;
    
    LCA(T _n) : n(_n) {
      adj.resize(n);
      euler.reserve(n*2);
      first.resize(n);
      height.resize(n);
      vis.assign(n, false);
     // dfs(0, 0);
    }
    
    void dfs(T s, T h = 0) {
      vis[s] = true;
      height[s] = h;
      first[s] = (int)euler.size();
      euler.push_back(s);
      for(auto i : adj[s]) {
        if(!vis[i]) {
          dfs(i, h+1);
          euler.push_back(s);
        }
      }
    }

    void print() {
      cout << "Height:" << endl;
      for(T i : height)
        cout << i << ' ';
      cout << endl;
      cout << "First visit:" << endl;
      for(T i :first)
        cout << i << ' ';
      cout << endl;
      cout << "Euler Tour:" << endl;
      for(T i : euler)
        cout << i << ' ';
      cout << endl;
    }

    void Sparsedp() {
      T m = (int)euler.size();
      logs.resize(m+1);
      logs[1] = 0;
      for(T i = 2; i <= m; i++)
        logs[i] = logs[i/2]+1;
      dp.resize(m, vector<pair<T, T>>(logs[m]+1));
      for(int i = 0; i < m; i++) { 
        dp[i][0].first = height[euler[i]];
        dp[i][0].second = euler[i];
      }
      int k = logs[m];
      for(T j = 1; j <= k; j++) {
        for(T i = 0; i + (1 << j) <= m; i++)
          if(dp[i][j-1].first < dp[i+(1 << (j-1))][j-1].first)
            dp[i][j] = dp[i][j-1];
          else 
            dp[i][j] = dp[i+(1 << (j-1))][j-1];
      }
    }
    T query(T l, T r) {
      T j = logs[r-l+1];
      T ind;
      if(dp[l][j].first < dp[r-(1 << (j))][j].first)
        ind = dp[l][j].second;
      else 
        ind = dp[r-(1 << (j)) ][j].second;
      return euler[ind];
    }
};

void solve(){
	int n;
  cin >> n;
  LCA<int> l(n);
  for(int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    l.adj[u].push_back(v);
    l.adj[v].push_back(u);
  }
  l.dfs(0, 0);
  l.print();
  l.Sparsedp();
  for(auto i : l.dp) {
    for(auto j : i) {
      cout << '(' <<  j.first << ' ' << j.second << ')' << ' ';
    }
    cout << endl;
  }
  int q;
  cin >> q;
  while(q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    //continue;
    cout << l.query(u, v) << endl;
  }
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
//		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
/*
8
1 2
2 5
2 6
1 3
1 4
4 7
4 8
6
1 7
7 8 
5 6
5 7
2 4
5 3
*/
