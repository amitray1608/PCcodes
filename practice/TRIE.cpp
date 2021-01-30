#include <bits/stdc++.h>

using namespace std;

const int siz = 26;

struct Node {
  struct Node *child[26];
  bool end;
};

struct Node * newnode() {
  struct Node * node = new Node;
  node -> end = false;
  for (int i = 0; i < siz; i++) {
    node -> child[i] = NULL;
  }
  return node;
}

void insert(struct Node *root, string s) {
  struct Node * node = root;
  for(char c : s) {
    int val = c - 'a';
    if(node -> child[val] == NULL)
      node -> child[val] = newnode();

    node = node -> child[val];
  }
  node -> end = true;
}

bool search(struct Node * root, string s) {
  struct Node * node = root;
  for (char c : s) {
    int val = c - 'a';
    if(!node -> child[val]) return false;

    node = node -> child[val];
  }
  return (node != NULL and node -> end);
}

void solve() {
  int n, q;
  cin >> n >> q;
  
  vector<string> v(n);
  for(string &i : v) cin >> i;
  
  struct Node * root = newnode();

  for(int i = 0; i < n; i++) 
    insert(root, v[i]);

  while(q--) {
    string s;
    cin >> s;
    cout << (search(root, s) ? "Present" : "Not Present") << '\n';
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

