//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

struct Edge{
  int u, v, c;
  void fill(int a, int b, int co) {
    u = a;
    v = b;
    c = co;
  }
};
const int INF = 1000000000;
vector<Edge>e;
vector<int>dis;

void solve(){
  int n, m;
  cin >> n >> m;
  dis.resize(n, INF);
  e.resize(m);
  for(int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    e[i].fill(u, v, c);
  }
  auto balmond = [&]() {
    dis[0] = 0;
    for(int i = 0; i < n-1; i++) {
      for(int j = 0; j < m; j++) {
        if(dis[e[j].u] < INF)
          dis[e[j].v] = min(dis[e[j].v], dis[e[j].u]+e[j].c);
      }
    }
  };

  auto balmondspeed = [&](){
    dis[0] = 0;
    while(true) {
      bool flag = false;
      for(int i = 0; i < m; i++) {
        if(dis[e[i].u] < INF)
          if(dis[e[i].u] + e[i].c < dis[e[i].v]) {
            dis[e[i].v] = dis[e[i].u] + e[i].c;
            flag = true;
          }
      }
      if(!flag)
        break;
    } 
  };
  balmondspeed();
  for(int i = 0; i < n; i++) {
    cout << dis[i] << ' '; 
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