
#include<bits/stdc++.h>

using namespace std;

int timer, logn;
int chainNo = 0, n, m, posBase, treeInd;
vector<int> chainHead, chainInd;
vector<int> subsize, parent, depth, newTree, a, tree;
vector<vector<int>> adj;


void updateTree(int n, int s, int e, int p, int v) {
  if (s > e) return;
  if (s == e and s == p) {
    tree[n] = v;
    return;
  }
  int mid = s + e >> 1;
  if (p <= mid) 
    updateTree(n + n, s, mid, p, v);
  else 
    updateTree(n + n + 1, mid + 1, e, p, v);
  tree[n] = max(tree[n + n], tree[n + n + 1]);
}

int queryTree(int n, int s, int e, int l, int r) {
  if (s > e or s > r or e < l) return 0;
  if (s <= l and r <= e) return tree[n];
  int mid = s + e >> 1;
  return max(queryTree(n + n, s, mid, l, r), queryTree(n + n + 1, mid + 1, e, l, r));
}

void dfs(int s, int p, int dep) {
  parent[s] = p;
  subsize[s] = 1;
  depth[s] = dep;
  for (int i : adj[s]) {
    if (i != p) dfs(i, s, dep + 1);
    subsize[s] += subsize[i];
  }
}

vector<int> tin, tout;
vector<vector<int>> dp;

void pre(int s, int p) {
  dp[s][0] = p;
  tin[s] = ++timer;
  for (int i = 1; i < logn; i++) {
    dp[s][i] = dp[dp[s][i - 1]][i - 1];
  }
  for (int v : adj[s]) {
    if (v != p) pre(v, s);
  }
  tout[s] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (int i = logn - 1; i >= 0; i--)
    if (!is_ancestor(dp[u][i], v))
      u = dp[u][i];
  return dp[u][0];
}

void hld(int curr, int par, int head) {
  chainHead[chainNo] = head;
  chainInd[curr] = treeInd;
  newTree[treeInd++] = a[curr];
  int ind = -1, mai = -1;
  for (int i : adj[curr]) {
    if (subsize[i] > mai) {
      mai = subsize[i];
      ind = i;
    }
  }
  if (ind != -1) {
    hld(ind, curr, head);
  }
  for (int i : adj[curr]) {
    if (i != ind and i != par) {
      chainNo++;
      hld(i, curr, i);
    }
  }
}

int queryUp(int l, int r) {
  if (l == r) {
    return 0;
  }
  int lchain, rchain = chainInd[v], res = -1;
  while (true) {
    lchain = chainInd[l];
    if (lchain == rchain) {
      if (l == r) break;
      res = max(res, queryTree(1, 0, n - 1, 

}

int query(int l, int r) {
  int lc = lca(l, r);
  return max(queryUp(l, lc), queryUp(r, lc));
}

void initialize() {
  chainHead.resize(n, -1);
  chainInd.resize(n);
  parent.resize(n);
  depth.resize(n);
  newTree.resize(n);
  tin.resize(n, 0);
  tout.resize(n, 0);
  dp.resize(n, vector<int>(logn));
  tree.resize(n * 4, 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int q;
  cin >> n >> q;
  initialize();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0, 0);
  pre(0, 0);
  hld(0, 0, 0);
  for (int i = 0; i < n; i++) {
    updateTree(1, 0, n - 1, i, a[newTree[i]]);
  }
  while (q--) {
    int tp, l, r;
    cin >> tp >> l >> r;
    if (tp == 1) {
      l--;
      updateTree(1, 0, n - 1, chainInd[l], r);
    } else {
      l--, r--;
      cout << query(l, r) << '\n';
    }
  }
  return 0;
} //Hajimemashite


