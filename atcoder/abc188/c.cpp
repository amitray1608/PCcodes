#include <bits/stdc++.h>

using namespace std;

class SegTree {
public:
  struct Node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    int x = 0;
    int add = 0;
    void apply(int val){
      x = val;
    }
    void update(int val){
      x += val;
    }
  };
  vector<Node> tree;
  int N , n;

  // for lazy propogation
  inline void push(int x , int l , int r){
    if(tree[x].add != 0){
      tree[x].update(tree[x].add);
      if(l != r){
        int cover = (r - l + 1);
        tree[x << 1].add += (tree[x].add);
        tree[(x << 1)|1].add += (tree[x].add);
      }
      tree[x].add = 0;
    }
  }

  Node combine(const Node &A , const Node &B){
    Node ans;
    ans.x = max(A.x , B.x);
    return ans;
  }

  void build(int s , int e , int idx) {
    if(s == e){
      tree[idx].apply(0);
      return;
    }
    int mid = (s+e) >> 1;
    build(s , mid , (idx << 1));
    build(mid + 1 , e , ((idx << 1)|1));
    return;
  }

  template <typename T>
  void build(const vector < T > &ar , int s , int e , int idx) {
    if(s == e){
      tree[idx].apply(ar[s]);
      return;
    }
    int mid = (s+e) >> 1;
    build(ar , s , mid , (idx << 1));
    build(ar , mid + 1 , e , ((idx << 1)|1));
    tree[idx] = combine(tree[idx << 1] , tree[(idx << 1)|1]);
    return;
  }

  Node query(int s , int e , int lf , int rf , int idx) {
    push(idx , s , e);
    if(rf < s or e < lf) return Node();
    if(lf <= s and e <= rf){
     return tree[idx];
    }
    int mid = (s + e) >> 1;
    int l = idx << 1;
    int r =  (idx << 1) | 1;
    if(lf <= mid){
      if(rf <= mid){
        return query(s , mid , lf , rf , l);
      }else{
        return combine(query(s , mid , lf , rf , l) , query(mid + 1 , e , lf , rf , r));
      }
    }else{
      return query(mid + 1 , e , lf , rf , r);
    }
  }

  template <typename M>
  void update(int s , int e , int i , M val , int idx) {
    if(s > i or e < i) return;
    if(s == e){
      tree[idx].apply(val);
      return;
    }
    int mid = (s + e) >> 1;
    update(s , mid , i , val , (idx << 1));
    update(mid + 1 , e , i , val , (idx << 1)|1);
    tree[idx] = combine(tree[idx << 1] , tree[(idx << 1) | 1]);
    return;
  }

  template <typename M>
  void update(int s , int e , int l , int r , M val , int idx) {
    push(idx , s , e);
    if(s > r or e < l or s > e) return;
    if(l <= s && e <= r){
      tree[idx].add += val;
      push(idx , s , e);
      return;
    }
    int mid = (s + e) >> 1;
    update(s , mid , l , r , val , (idx << 1));
    update(mid + 1 , e , l , r , val , (idx << 1)|1);
    tree[idx] = combine(tree[idx << 1] , tree[(idx << 1) | 1]);
    return;
  }

public:
  template<typename T>
  SegTree(const vector<T> &ar) {
    n = (int) ar.size();
    N = 4*(n) + 1;
    tree.resize(N, {});
    build(ar , 0 , n - 1 , 1);
  }

  SegTree(int _n) : n (_n){
    N = 4 * (n) + 1;
    tree.resize(N , {});
    build(0 , n - 1 , 1);
  }

  SegTree(){
    n = 100000;
    N = 4 * n + 1;
    tree.resize(N , {});
  }

  void build(){
    build(0 , n - 1 , 1);
  }

  template<typename T>
  void build(const vector<T> &ar) {
    build(ar , 0 , n - 1 , 1);
  }

  Node query(int l ,int r){
    return query(0 , n - 1 , l , r , 1);
  }

  template<typename T>
  void update(int l , int r , T val){
    update(0 , n - 1 , l , r , val , 1);
  }

  template<typename M>
  void update(int i , M val) {
    update(0 , n - 1 , i , val , 1);
  }
};

void solve() {
  int n;
  cin >> n;
  int N = 1 << n;
  vector<int> a(N);
  map<int, int>mp;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    mp[a[i]] = i + 1;
  }
  SegTree st(a);
  cout << mp[min(st.tree[2].x, st.tree[3].x)] << '\n';
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

