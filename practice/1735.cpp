
#include<bits/stdc++.h>

using namespace std;
#define int int64_t


class SegTree {
  int N;
  vector<int> tree;
  public:
  SegTree(int n) : N(n) {
    tree.resize(N * 4);
  }
  
  void update(int n, int s, int e, int l, int r, int x) {
    if (s > e or l > e or r < s) return;
    if (l <= s and e <= r) 
  }
};

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  	
  return 0;
} //Hajimemashite

