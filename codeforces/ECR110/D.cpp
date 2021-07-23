
#include<bits/stdc++.h>

using namespace std;

template<class T, int SZ> struct Seg { // SZ should be power of 2
  T seg[2 * SZ], ID = 0;

  Seg() {
    for(int i = 0; i < 2 * SZ; ++i) seg[i] = ID;
  }

  T comb(T a, T b) {
      return (a + b);
  }
  // easily change this to min or max
  // comb(ID,b) must equal b

  void build() { for(int i = SZ - 1; i >= 0; --i) { seg[i] = comb(seg[2*i],seg[2*i+1]); } }

  void upd(int p, T value) {  // set value at position p
    for (seg[p += SZ] = value; p > 1; p >>= 1)
      seg[p >> 1] = comb(seg[(p|1)^1],seg[p|1]);
      // make sure non-commutative operations work
  }

  T query(int l, int r) {  // query on interval [l, r]
    T res1 = ID, res2 = ID; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
      if (l&1) res1 = comb(res1,seg[l++]);
      if (r&1) res2 = comb(seg[--r],res2);
    }
    return comb(res1,res2);
  }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n; 
  int N = (1 << n) - 1;
  string s;
  cin >> s;
  Seg<int, 262145> sg;
  for (int i = 1; i <= N; i++) {
    if (s[i - 1] == '0') {
      sg.upd((1 << i), 1);
    } else if (s[i - 1] == '1') {
      sg.upd((1 << i) + 1, 1);
    } else {
      sg.upd((1 << i) + 1, 1);
      sg.upd((1 << i), 1);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int p;
    char x;
    cin >> p >> x;
    if (x == '0') {
      sg.upd((1 << p), 1);
    } else if (x == '1') {
      sg.upd((1 << p) + 1, 1);
    } else {
      sg.upd((1 << p) + 1, 1);
      sg.upd((1 << p), 1);
    }
    cout << sg.query(0, (1 << n)) << '\n';
  }
  return 0;
} //Hajimemashite

