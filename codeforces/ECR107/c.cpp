
#include<bits/stdc++.h>

using namespace std;

const int maxn = 52;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<typename T, class cmp = std::less<T>>
using Tree = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, q;
    cin >> n >> q;
    vector<int>a(n);
    set<int> st[maxn];
    Tree<int> tree;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      tree.insert(i);
      st[a[i]].insert(i);
    }
    int neg = 0;
    auto make = [&](int p) {
      int x = *st[p].begin();
      int res = tree.order_of_key(x) + 1;
      tree.erase(tree.find(x));
      st[p].erase(st[p].begin());
      neg--;
      st[p].insert(neg);
      tree.insert(neg);
      return res;
    };
    while (q--) {
      int pos;
      cin >> pos;
      cout << make(pos) << ' ';
    }
  }
  return 0;
} //Hajimemashite

