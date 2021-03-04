#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  int pos = 0, curr = n;
  stack<int> st;
  multiset<int, greater<int>> mt;
  for (int i = 1; i < n + 1; i++) {
    mt.insert(i);
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == curr) {
     cout << a[i] << ' ';
     mt.erase(a[i]);
     while (!st.empty()) {
       int x = st.top();
       mt.erase(x);
      cout << x << ' ';
      st.pop();
     }
      curr = *mt.begin(); 
    } else {
      st.push(a[i]);
    }
  }
   while (!st.empty()) {
    cout << st.top() << ' ';
    st.pop();
   }

  cout << '\n';
}

int main() {
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


