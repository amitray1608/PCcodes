
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

struct Node {
  Node *child[2];
  bool end;
};

struct Node * newnode() {
  Node *node = new Node;
  node -> child[0] = node -> child[1] = nullptr;
  node -> end = false;
  return node;
}

void update(Node *root, string s) {
  Node * node = root;
  for(char c : s) {
    int ind = c - '0';
    if(node -> child[ind] == nullptr)
      node -> child[ind] = newnode();
    node = node -> child[ind];
  }
  node -> end = true;
}

int query(Node *root, string s) {
  Node *node = root;
  string ans = "";
  for(char c : s) {
    int ind = c - '0';
    if(c == '0') {
      if(node -> child[1] != nullptr) ans += '1', node = node -> child[1];
      else ans += '0', node = node -> child[0];
    } else {
      if(node -> child[0] != nullptr) ans += '1', node = node -> child[0];
      else ans += '1', node = node -> child[1];
    }
  }
  return (bitset<32>(ans).to_ullong());
}

void solve() {
  int n, q;
  cin >> n;
  vector<int> a(n);
  struct Node *root = newnode();
  update(root, bitset<32>(0).to_string());
  for(int &i : a) {
    cin >> i;
    update(root, bitset<32>(i).to_string());
  }
  cin >> q;
  while(q--) {
    int x;
    cin >> x;
    cout << query(root, bitset<32>(x).to_string()) << '\n';
  }
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

