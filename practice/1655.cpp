#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int maxi = 0;

struct Node {
  struct Node * child[2];
  bool end;
};

struct Node * newnode() {
  struct Node * node = new Node;
  node -> child[0] = node -> child[1] = NULL;
  node -> end = false;
  return node;
}

void update(struct Node *root,  string s) {
  struct Node *node = root;
  for(char c : s) {
    int ind = c - '0';
    if(node -> child[ind] == NULL) 
      node -> child[ind] = newnode();
    node = node -> child[ind];
  }
}

int query(struct Node *root, string s) {
  string ans = "";
  Node *node = root;
  for(char c : s) {
    if(c == '0') {
      if(node -> child[1]) 
        ans += '1', node = node -> child[1];
      else ans += '0', node = node -> child[0];
    } else {
      if(node -> child[0]) 
        ans += '1', node = node -> child[0];
      else ans += '0', node = node -> child[1];
    }
  }
  return bitset<64>(ans).to_ullong();
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  int x = 0;
  struct Node *root = newnode();
  update(root, bitset<64>(0).to_string());
  for(int i = 0; i < n; i++) {
    x ^= a[i];
    bitset<64> bs(x);
    string s = bs.to_string();
    maxi = max(maxi, query(root, s)); 
    update(root, s);
  }
  cout << maxi << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite

