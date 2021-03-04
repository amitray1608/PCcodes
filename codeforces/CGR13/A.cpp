
#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<typename T, class cmp = std::less<T>>
using Tree = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  int o = 0, z = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    o += a[i];
  }
  while (q--) {
    int tp, x;
    cin >> tp >> x;
    if (tp == 1) {
      if (a[x]) o--;
      else o++;
      a[x] ^= 1;
    } else {
      bool ok = (o >= x);
      cout << (ok ? 1 : 0) << '\n';
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
//  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


