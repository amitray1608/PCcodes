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
    vector<T>euler, first, height;
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
      first[s] = euler.size();
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
    T queryLCA(T u, T v) {
      int mini = 1e9;
      pair<int, int>p{1e9, 0};
      int l = first[u], r = first[v];
      if(l > r)
        swap(l, r);
      for(int i = l; i < r; i++) {
        if(height[euler[i]] < p.first) 
          p = {height[euler[i]], euler[i]};
      }
      return p.second;
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
  int q;
  cin >> q;
  while(q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    cout << l.queryLCA(u, v) << endl;
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
