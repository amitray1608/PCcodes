
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

  set<pair<int, int>> 
     pairs(vector<int>& arr)
{
    stack<int> st;
    set<pair<int, int>> pairs;
 
    // Push first element into stack
    st.push(arr[0]);
 
    // For each element 'X' in arr,
    // pop the stack while top Element
    // is smaller than 'X' and form a pair.
    // If the stack is not empty after
    // the previous operation, create
    // a pair. Push X into the stack.
 
    for (int i = 1; i < arr.size(); ++i) {
        while (!st.empty() &&
                arr[i] > st.top()) {
            pairs.insert(make_pair(st.top(),
                                    arr[i]));
            st.pop();
        }
        if (!st.empty()) {
            pairs.insert(make_pair(min(st.top(),
                                       arr[i]),
                                   max(st.top(),
                                      arr[i])));
        }
        st.push(arr[i]);
    }
    return pairs;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);  
  for (int &i : a) cin >> i;
  set<pair<int, int>> st = pairs(a);
  set<int> ans;
  for (auto i : st) {
    ans.insert(i.second - i.first);
  }
  cout << ans.size() << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


