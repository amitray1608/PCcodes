
#include<bits/stdc++.h>

using namespace std;

struct Node {
  string name;
  int count, siz, uid;
  vector<Node*> child;
  Node *par;
  map<int, int> mp;
  Node (string name) {
    this -> name = name;
    this -> par = NULL;
    this -> uid = -1;
    this -> count = 0;
    this -> siz = 0;
  }
  
  bool isItLocked(Node *s) {
    return s -> uid != -1;
  }

  bool lock(Node *s, int by) {
    if (isItLocked(s) or count) 
      return false;
    Node *curr = s -> par;
    while (curr != NULL) {
      if (isItLocked(curr))
        return false;
      curr = curr -> par;
    }
    s -> uid = by;
    mp[by]++;
    curr = s -> par;
    while (curr != NULL) {
      curr -> count++;
      curr -> mp[by]++;
      curr = curr -> par;
    }
    s -> count++;
    return true;
  }

  bool unLock(Node *s, int by) {
    if (s -> uid != by or !isItLocked(s))
      return false;
    s -> uid = -1;
    s -> mp[by]--;
    if (s -> mp[by] == 0) {
      mp.erase(by);
    }
    Node * curr = s -> par;
    s -> count--;
    while (curr != NULL) {
      curr -> count--;
      curr -> mp[by]--;
      if (curr -> mp[by] == 0) {
        mp.erase(by);
      }
      curr = curr -> par;
    }
    return true;
  }
    
  int recc(Node *s) {
    int k = 0;
    for (auto &i : s -> child) {
      k += recc(i);
    }
    s -> siz = k++;
    return k;
  }

  void recc2(Node *s, int by) {
    if (isItLocked(s)) {
      unLock(s, by);
    }
    for (auto &i : s -> child) {
      recc2(i, by);
    }
  }

  bool upgrade(Node *s, int by) {
    if (isItLocked(s)) 
      return false;
    if (s -> count == 0)
      return false;
    if (s -> mp[by] != s -> count) {
      return false;
    }
    recc2(s, by);
    lock(s, by);
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, m, q;
  cin >> n >> m >> q;
  vector<string> s(n);
  for (string &i : s) {
    cin >> i;
  }
  Node *root = new Node(s[0]);
  queue<Node *> pq;
  map<string, Node *> mp;
  mp[s[0]] = root;
  pq.push(root);
  for (int i = 1; i < n; i++) {
    Node *x = pq.front();
    if (x -> child.size() == m) {
      pq.pop();
      x = pq.front();
    }
    Node *tmp = new Node(s[i]);
    tmp -> par = x;
    mp[s[i]] = tmp;
    pq.push(tmp);
    x -> child.push_back(tmp);
  }
  root -> recc(root);
  while (q--) {
    cout << fixed << boolalpha;
    int tp, by;
    string name;
    cin >> tp >> name >> by;
    Node *curr = mp[name];
    if (tp == 1) {
      cout << curr -> lock(curr, by) << '\n';
    } else if (tp == 2) {
      cout << curr -> unLock(curr, by) << '\n';
    } else {
      cout << curr -> upgrade(curr, by) << '\n';
    }
  }
  return 0;
}

