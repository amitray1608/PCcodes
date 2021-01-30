#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int maxn = 2e5 + 1;

map<int, int> epos;
vector<vector<int>> adj;
ll val[maxn];
int tin[maxn], tout[maxn], tim = 0;
vector<int> euler, child;

class SegTree {
  int N;
  vector<ll> tree, lazy;
  
  SegTree(int n) {
    N = n;
    lazy.resize(n * 4 + 1);
    tree.resize(n * 4 + 1);
  }

  void push(int n) {
    if(lazy[n] != 0) {
      tree[n + n] += lazy[n];
      lazy[n + n] += lazy[n];
      tree[n + n + 1] += lazy[n];
      lazy[n + n + 1] += lazy[n];
      lazy[n] = 0;
    }
  }

  void update(int n, int s, int e, int l, int r, int x) {
    if(s > e or s > r or e < l) return;
    if(l <= s or e <= r) {
      tree[n] += x;
      lazy[n] += x;
      return;
    }
    push(n);
    int mid = s + e >> 1;
    update(n + n, s, mid, l, r, x);
    update(n + n + 1, mid + 1, e, l, r, x);
    tree[n] = tree[n + n] + tree[n + n + 1];
  }

  int query(int n, int s, int e, int p) {
    if(s > e) return;
    if(s == p) return tree[n];
    push(n);
    int mid = s + e >> 1;
    if(p <= mid) return query(n + n, s, mid, p);
    else return query(n + n + 1, mid + 1, e, p);
  }

  void update(int l, int r, int x) {
    update(1, 0, N - 1, l, r, x);
  }

  int query(int p) {
    return query(1, 0, N - 1, p);
  }
};

//euler tour
void dfs(int s, int p) {
  euler.push_back(s);
  child[s] = 1;
  tin[s] = ++tim;
	for(auto i : adj[s]) {
		if(i != p) dfs(i, s), child[s] += child[i] + 1;
	}
  tout[s] = ++tim;
}

void solve() {
	int n;
	cin >> n;
	adj.resize(n);
  child.resize(n);
	vector<pair<int, int>> arr;
	for(int i = 0; i < n - 1; i++) {
		int a, b;
    cin >> a >> b;
    a--, b--;
		arr.push_back({a, b});
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
  
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    epos[euler[i]] = i;
    //cout << euler[i] << ' ' << child[euler[i]] << '\n';
  } 

  SegTree st(n);

  int q;
	cin >> q;
	while(q--) {
    int t, e, x;
		cin >> t >> e >> x; e--;
    auto pos = arr[e];
    if(t == 2) swap(pos.first, pos.second);
    int up1l = epos[pos.first], up1r = child[up1l] + 1;
    int up2l = epos[pos.second], up2r = child[up2r] + 1;
    st.update(0, n - 1, x);
    if(up1l < up2l) {
      if(tin[
      st.update(
    }
	}
	for(int i = 0; i < n; i++) {
		cout << st.query(epos[i]) << endl;
	}
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
