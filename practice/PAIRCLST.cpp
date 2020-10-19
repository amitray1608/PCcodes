#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
#define ii pair<int, int>

const int inf = 1e9;
int n, m, k, mini = inf;
vector<int>s, dis, isspecial;
vector<vector<pair<int, int>>>adj;

void dijk(int ss) {
  priority_queue<ii, vector<ii>, greater<ii>>pq;
  pq.push({0, ss});
  dis.assign(n, -1);
  dis[ss] = 0;
  while(!pq.empty()) {
    auto x = pq.top();
    pq.pop();
    int u = x.second;
    if(dis[u] > mini) return;
    for(auto i : adj[u]) {
      int v = i.first, ww = i.second;
      if(dis[v] > dis[u] + ww or dis[v] == -1) {
        dis[v] = dis[u] + ww;
        pq.push({dis[v], v});
        if(dis[v] < mini and isspecial[v] == 1)
          mini = dis[v];
      }
    }
  }
}

void solve(){
  cin >> n >> m >> k;
  adj.resize(n);
  s.assign(k, 0);
  isspecial.resize(n, 0);
  for(int &i : s) cin >> i, i--, isspecial[i] = 1;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  for(int i = 0; i < k; i++) {
    dijk(s[i]);
  }
  cout << mini << endl;
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
