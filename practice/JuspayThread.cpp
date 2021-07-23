
#include <bits/stdc++.h>

using namespace std;

//The methods needs to be thread safe.

struct Node {
  string name;
  int count, siz, uid, isLocked;
  vector < Node * > child;
  Node * par;
  mutex mt;
  map < int, int > mp;
  Node(string name) {
    this -> name = name;
    par = NULL;
    uid = -1;
    count = 0;
    siz = 0;
    flag = 0;
    isLocked = 0;
  }
  
  bool isItLocked(Node * s) {
    return s -> uid != -1;
  }
  
  bool lock(Node * s, int by) {
    
    // Today's change : we will increment the count variable when the lock method is called.
    unique_lock<mutex> tmp(s -> mt);
    tmp.lock();
    count++;
    tmp.unlock();
    if (isItLocked(s) or count > 1) // we will check count > 1 because it will only be updated by itself once.
      return false;
    
    //We make the current locked
    s -> isLocked++; //
    if (s -> isLocked > 1) return false;
    s -> uid = by;  
    bool ok = true; 
    Node * curr = s -> par;
    //Keep incrementing the parent until it's the root or it is locked
    while (curr != NULL) {
      if (isItLocked(curr) or curr -> count > 0) {
        ok = false;
      	break;
      }
      unique_lock<mutex> lk(curr -> mt);
      lk.lock();
      int currCount = curr -> count;
      curr -> count++;
      lk.unlock();
      curr = curr -> par;
    }
    //it the lock was unsuccesfull then revert the changes that is decrement
    //the descendents count of all it's ancestor  
    if (!ok) {
    	s -> uid = -1;
      while (s != NULL) {
       	if (isItLocked(s)) break;
        unique_lock<mutex> lk(curr -> mt);
      	lk.lock();
      	s -> count--;
      	lk.unlock();
      }
      return false;
    }
    return true;
  }
  
  bool unLock(Node * s, int by) {
    unique_lock<mutex> lk(curr -> mt);
    lk.lock();
    s -> isLocked--;
    lk.unlock();
    if (s -> isLocked < 0) return false;
    if (s -> uid != by)
      return false;
    unique_lock<mutex> lk(curr -> m);
    lk.lock();
    s -> uid = -1;
    s -> mp[by]--; 
    if (s -> mp[by] == 0) {
      mp.erase(by);
    }
    //These are the critical section in unLock()
    Node * curr = s;
    while (curr != NULL) {
      unique_lock<mutex> lck(curr -> m);
      lck.lock();
      curr -> count--;
      curr -> mp[by]--;
      if (curr -> mp[by] == 0) {
        mp.erase(by);
      }
      lck.lock();
      curr = curr -> par;
    }
    return true;
  }
  
  int recc(Node * s) {
    int k = 0;
    for (auto & i: s -> child) {
      k += recc(i);
    }
    s -> siz = k++;
    return k;
  }
  
  void recc2(Node * s, int by) {
    if (isItLocked(s)) {
      unLock(s, by);
    }
    for (auto & i: s -> child) {
      recc2(i, by);
    }
  }
  
  bool upgrade(Node * s, int by) {
    if (isItLocked(s))
      return false;
    if (s -> count == 0) return false;
    if (s -> mp[by] != s -> count) {
      return false;
    }
    recc2(s, by);
    lock(s, by);
    return true;
  }
};

int main() {
  ios::sync_with_stdio();
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector < string > s(n);
  for (string & i: s) {
    cin >> i;
  }
  Node * root = new Node(s[0]);
  queue < Node * > pq;
  map < string, Node * > mp;
  mp[s[0]] = root;
  pq.push(root);
  for (int i = 1; i < n; i++) {
    Node * x = pq.front();
    if (x -> child.size() == m) {
      pq.pop();
      x = pq.front();
    }
    Node * tmp = new Node(s[i]);
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
    Node * curr = mp[name];
    if (tp == 1) {
      cout << curr -> lock(curr, by) << '\n';
    } else if (tp == 2) {
      cout << curr -> unLock(curr, by) << '\n';
    } else {
      cout << curr -> upgrade(curr, by) << '\n';
    }
  }
}
