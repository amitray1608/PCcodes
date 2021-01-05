#include<bits/stdc++.h>

using namespace std;

class SegTree { 
 public:
   int N;
   vector<int>tree;
   SegTree(int n) {
     N = n;
     tree.resize(n * 4 + 1, 0);
   }

   void update(int n, int s, int e, int p) {
      if(s > e) return;
      if(s == e) return void(tree[n] = 1);
      int mid = s + e >> 1;
      if(p <= mid) update(n + n, s, mid, p);
      else update(n + n + 1, mid + 1, e, p);
      tree[n] = tree[n + n] + tree[n + n + 1];
   }

   int query(int n, int s, int e, int l, int r) {
     if(s > e or s > r or e < l) return 0;
     if(l <= s and e <= r) return tree[n];
     int mid = s + e >> 1;
     return query(n + n, s, mid, l, r) + query(n + n + 1, mid + 1, e, l, r);
   }
   
   void update(int p) {
     update(1, 0, N - 1, p);
   }
   
   int query(int l, int r) {
     return query(1, 0, N - 1, l, r);
   }
};



int main() {
  int n;
  cin >> n;
  SegTree st(n);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cout << st.query(x, n - 1) << ' ';
    st.update(x - 1);
  }
  return 0;
}
