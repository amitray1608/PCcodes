#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;


template<typename T>
string to_string(vector<T> v) {
  string res;
  for(auto &i : v)
    res += char('0'+i), res += ' ';
  return res;
}

template<class A> void vbug(A x) {
  cout << to_string(x) << endl;
}


map<int, int>check;
vector<vector<int>>adj;
vector<bool>vis;
vector<int> from, to, pos, child;
int curr = 0;

vector<int>tree;

void update(int n, int s, int e, int pos, int val) {
  //not able to upadte, 
  if(s == e) {
    if(!val) {
      tree[n] = -1*(int)child[check[s]];
      deb(child[check[s]]);
    } else {
      tree[n] = child[check[s]];
    }
    return;
  } else {
    int mid = (s+e) / 2;
    if(pos <= mid)
      update(n+n, s, mid, pos, val);
    else
      update(n+n+1, mid+1, e, pos, val);
    tree[n] = (tree[n+n] + tree[n+n+1]);
  }
}

int query(int n, int s, int e, int l, int r) {
    if(l > r)
      return 0;
    if(s >= l and e <= r)
      return tree[n];
    int mid = (s+e)/2;
    
  int x = query(n+n, s, mid, l, min(mid, r));
  int y = query(n+n+1, mid+1, e, max(l, mid+1), r);
  return x+y;
}

void dfs(int s) {
  vis[s] = true;
  pos[s] = ++curr;
  from[s] = curr;
  to[s] = curr;
  child[s] = 1;
  for(int i : adj[s]) {
    if(!vis[i]) {
      dfs(i);
      child[s] += child[i];
      to[s] = max(to[s], to[i]);
    }
  }
}


void solve(){
  int n, q;
  cin >> n >> q;
  adj.resize(n);
  vis.assign(n, false);
  pos.resize(n, 0);
  from.resize(n, 0);
  to.resize(n, 0);
  child.resize(n, 0);
  for(int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  vbug(child);
  vbug(pos);
  vbug(from);
  vbug(to);
  vector<int> xo(n, 0);
  tree.resize(n*4, 0);
  for(int i = 0; i < n; i++) {
    check[pos[i]-1] = i;
    xo[i] = 1;
    update(1, 0, n-1, i, 1);
  }
  vbug(tree);
  while(q--) {
    int tp, p;
    cin >> tp >> p;
    p--;
    if(tp == 1){
      xo[p] ^= 1;
      update(1, 0, n-1, pos[p] - 1, xo[p]);
      //vbug(tree);
      int x = query(1, 0, n-1, 0, p);
      for(int &i : tree)
        cout << i << ' ';
      cout << endl;
    } else {
      int l = from[p], r = to[p];
      //deb(l);
      //deb(r);
      cout << query(1, 0, n-1, l-1, r-1) << endl;
    }
  }
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
	//	cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}

