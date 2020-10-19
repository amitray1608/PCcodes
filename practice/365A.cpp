//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

// vector<int>tree((4*siz), -1);
// vector<int>ans(siz, -1);

// void push(int n) {
//   if(tree[n+n] == -1)
//     tree[n+n] = tree[n];
//   if(tree[n+n+1] == -1)
//     tree[n+n+1] = tree[n];
// }

// void update(int n, int s, int e, int l, int r, int w = 0) {
//   if(s > e or s > r or e < l)
//     return;
//   if(s >= l and e <= r) {
//     cout << w << endl;
//     if(tree[n] != -1) {
//       push(n);
//     }
//     tree[n] = w;
//     return;
//   } 
//   push(n);
//   int mid = (s+e) >> 1;
//   if(tree[n+n] == -1)
//     update(n+n, s, mid, l, r, w) ;
//   if(tree[n+n] == -1)
//     update(n+n+1, mid+1, e, l, r, w);
// }

void solve() {
  int n, q;
  cin >> n >> q;
  set<int>s;
  vector<int> ans(n+1, 0);
  for(int i = 1; i <= n; i++) s.insert(i);
  while(q--) {
    int l, r, w;
    cin >> l >> r >> w;
    auto it = s.lower_bound(l), itt = s.upper_bound(r);
    for(auto i = it; i != itt; i++) {
      ans[*i] = w;
    }
    s.erase(it, itt);
    ans[w] = 0;
    s.insert(w);
  }
  for(int i = 1; i <= n; i++) 
    cout << ans[i] << ' ';
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  