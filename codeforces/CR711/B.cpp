
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    multiset<int> st;
    for (int &i : a) {
      cin >> i;
    }
    sort(a.rbegin(), a.rend());
    int count = 0; 
    for (int i = 0; i < n; i++) {
      auto x = st.lower_bound(a[i]);
      if (x != st.end()) {
        st.erase(x);
        if (*x - a[i]) 
          st.insert(*x - a[i]);
      } else {
        count++;
        if (w - a[i]) 
          st.insert(w - a[i]);
      }
    }
    cout << count << '\n';
  }
  return 0;
} //Hajimemashite

