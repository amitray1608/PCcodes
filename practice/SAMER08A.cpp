//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
#define pi pair<int, int>

const int inf = 1e9;
//int ans = 0, pre = -1;
vector<vector<int>>g;
vector<vector<pair<int, int>>>adj;
int n, m;
vector<int>parent;
int dijk(int s, int d) {
  vector<int>dis(n, inf);
  dis[s] = 0;
  priority_queue<pi, vector<pi>, greater<pi>>pq;
  pq.push({0, s});
  while(!pq.empty()) {
    auto x = pq.top();
    int u = x.second, w = x.first;
    pq.pop();
   // if(u == d) break;
    //if(w == inf) continue;
    for(auto i : adj[u]) {
      int v = i.first, ww = i.second;
      if(dis[v] > dis[u] + ww and g[u][v]) {
        dis[v] = dis[u] + ww;
        parent[v] = u;
        pq.push({dis[v], v});
      }
    }
  }
  return dis[d];
}


void solve(){
  cin >> n >> m;
  if(!n and !m)
    exit(0);
  int s, d;
  cin >> s >> d;
  adj.resize(n);
  g.resize(n, vector<int>(n, 0));
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    g[u][v] = 1;
  }
  int count = 3, j = 0;
  array<int, 3>ans;
  while(count--) {
   parent.resize(n, -1);
   ans[j++] = dijk(s, d);
   if((j-1 == 0 or j-1 == 1) and ans[j-1] == inf) {
    cout << -1 << endl;
    for(int i = 0; i < n; i++) {
      adj[i].clear();
      g[i].clear();
    }
    parent.clear(); return;
   }
   for(int i = d; parent[i] != -1; i = parent[i]) {
   //  deb(i);
   // deb(parent[i]);
     g[parent[i]][i] = 0;
   }
  }
  if(ans[0] == inf or ans[1] == inf or (ans[0] ==  ans[1] and  ans[1] == ans[2]))
    cout << -1 << endl;
  else if(ans[0] != ans[1])
    cout << ans[1] << endl;
  else if(ans[2] != inf)
    cout << ans[2] << endl;
  else
    cout << -1 << endl;
  for(int i = 0; i < n; i++) {
    adj[i].clear();
    g[i].clear();
  }
  parent.clear();
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
	//cin >> t;
		while(true){
			//tt++;
			//cout << "Case #" << t << ": ";
      solve();
    }
	return 0;
}
