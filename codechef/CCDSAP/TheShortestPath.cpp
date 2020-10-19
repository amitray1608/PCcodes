//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const ll INF = 100000000;
unordered_map<string, ll>convert;
vector<vector<pair<ll, ll>>>adj;
vector<ll> dis;
vector<vector<ll>>ans;

void dijkstra(ll s, ll t) {
  dis[s] = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.push({0, s});
  while(!q.empty()) {
    auto x = q.top();
    ll c = x.first;
    ll u = x.second;  
    q.pop();
    if(u == t) {
      cout << c << endl;
      return;
    }
    for(auto i : adj[u]) {
      ll v = i.first,  cc = i.second;
      if(dis[u] + cc < dis[v]) {
        dis[v] = dis[u] + cc;
        q.push({dis[v], v});
      }
    }
  }
}


void solve(){
  ll n;
  cin >> n;
  adj.resize(n);
  for(ll i = 0; i < n; i++) {
    string s;
    cin >> s;
    convert[s] = i;
    ll m;
    cin >> m;
    while(m--) {
      ll v, c;
      cin >> v >> c;
      v--;
      adj[i].push_back({v, c});
    }
  }
  dis.resize(n, LONG_MAX);
  // cout << "ok" << endl;
  // ans.resize(n);
  // for(ll i = 0; i < n; i++) {
  //   dis.resize(n, INF);
  //   dijkstra(i);
  //   ans[i] = dis;
  //   dis.clear();
  // }
  // for(ll i = 0; i < n; i++) {
  //   for(ll j = 0; j < n; j++) {
  //     cout << ans[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  ll q;
  cin >> q;
  while(q--) {
    string a, b;
    cin >> a >> b;
    ll u = convert[a];
    ll v = convert[b];
    dijkstra(u , v);
    dis.resize(n, LONG_MAX);
  }
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

