#include <bits/stdc++.h>

using namespace std;

const int siz = 26;

struct Node {
  struct Node *child[siz];
  int maxi = 0;
  bool end;
};

struct Node * newnode() {
  struct Node *node = new Node;
  for (int i = 0; i < siz; i++) {
    node -> child[i] = NULL;
  }
  node -> maxi = 0;
  node -> end = false;
  return node;
}

void insert(struct Node * root, pair<string, int> s) {
  struct Node * node = root;
  string c = s.first;
  int val = s.second;
  for(char i : c) {
    int ind = i - 'a';
    if(node -> child[ind] == NULL)
      node -> child[ind] = newnode();
    node -> maxi = max(val, node -> maxi);
    node = node -> child[ind];
  }
  node -> end = true;
};

int search(struct Node *root, string p) {
  struct Node * node = root;
  for(char c : p) {
    int ind = c - 'a';
    if(node -> child[ind] == NULL) return -1;
    node = node -> child[ind];
  }
  return node -> maxi;
}

void solve() {
  int n, q;
  cin >> n >> q;
  
  vector<pair<string, int>> v(n);
  for(auto &i : v) {
    cin >> i.first >> i.second;
  }
  
  struct Node * root = newnode();
  for(auto i : v)
    insert(root, i);

  while(q--) {
    string s;
    cin >> s;
    cout << search(root, s) << '\n';
  }

}

int main() {
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

