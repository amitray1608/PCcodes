
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

struct Node {
  Node * child[2];
  bool end;
};

struct Node * newnode() {
  Node *node = new Node;
  node -> child[0] = node -> child[1] = nullptr;
  node -> end = false;
  return node;
}

void update(Node *root, string s) {
  Node *node = root;
  for(char c: s) {
    int ind = c - '0';
    if(!node -> child[ind]) 
      node -> child[ind] = newnode();
    node = node -> child[ind];
  }
  node -> end = true;
}

int query(Node *root, string s) {
  Node *node = root;
  string ans = "";
  for(char c: s) {
    if(c == '1') {
      if(node -> child[0]) ans += '1', node = node -> child[0];
      else ans += '0', node = node -> child[1];
    } else {
      if(node -> child[1]) ans += '1', node = node -> child[1];
      else ans += '0', node = node -> child[0];
    }
  }
  return bitset<64>(ans).to_ullong();
}

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  Node *root = newnode();
  update(root, bitset<64>(0).to_string());
  int X = 0;
  int maxi = 0;
  string s = bitset<64>(x).to_string();
  for(int &i : a) {
    X ^= i;
    update(root, bitset<64>(X).to_string());
    int c = X ^ x;
    int tmp = query(root, bitset<64>(c).to_string());
    int curr = X ^ tmp;
    if((x ^ curr) > (x ^ maxi)) maxi = curr;
  }
  cout << (maxi) << '\n';
  delete root;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite

