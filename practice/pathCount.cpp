
#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 1;
vector<int> res(maxn);

struct Node {
  int val;
  Node *l, *r;
  Node (int v) {
    val = v;
    l = r = NULL;
  }
};

void dfs(Node *root, int len) {
  if (root == NULL) {
    return;
  }
  if (root -> l == NULL and root -> r == NULL) {
    res[len]++;
    return;
  }
  dfs(root -> l, len + 1);
  dfs(root -> r, len + 1);
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
      res[i] = 0;
    }
    Node *root = NULL;
    Node *child;
    map<int, Node*> mp;
    for (int i = 0; i < n; i++) {
      int u, v;
      char ch;
      cin >> u >> v >> ch;
      Node *curr;
      if (mp.find(u) == mp.end()) {
        curr = new Node(u);
        mp[u] = curr;
        if (root == NULL) {
          root = curr;
        }
      } else {
        curr = mp[u];
      }
      child = new Node(v);
      if (ch == 'L') {
        curr -> l = child;
      } else {
        curr -> r = child;
      }
      mp[v] = child;
      
    }
    dfs(root, 1);
    vector<array<int, 2>> count;
    for (int i = 0; i <= n; i++) {
      if (res[i]) 
        count.push_back({res[i], i});
    }
    sort(count.begin(), count.end());
    for (auto i : count) {
      cout << i[1] << ' ' << i[0] << " $";
    } cout << '\n';
  }	
  return 0;
} 
