//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const int INF = 1e9;
vector<int> mp[10];
vector<int> dist;
int n;
string s;
void bfs(int ss) {
  vector<bool> vis(n, false);
  queue<int>q;
  dist[ss] = 0;
  q.push(ss);
  vis[ss] = true;
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    if(x == n-1) {
      return;
    }
    if(x != 0 and !vis[x - 1]) {
      vis[x - 1] = true;
      dist[x - 1] = dist[x] + 1;
      q.push(x - 1);
    }
    if(x != n-1 and !vis[x + 1]) {
      vis[x + 1] = true;
      dist[x + 1] = dist[x] + 1;
      q.push(x + 1);
    }
    for(auto i : mp[s[x] - '0']) {
      if(!vis[i]) {
        vis[i] = true;
        dist[i] = dist[x] + 1;
        q.push(i);
      }
    }
    mp[s[x]-'0'].clear();
  }
}

void solve() {
  cin >> s;
  n = (int)s.size();
  dist.resize(n, INF);
  for(int i = 0; i < n; i++) {
    mp[s[i]-'0'].push_back(i);
  }
  dist[0] = 0;
  bfs(0);
  cout << dist[n-1] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  