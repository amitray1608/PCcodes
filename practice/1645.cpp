
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  vector<int> res(n, 0);
  stack<array<int, 2>> st;
  for (int i = 0; i < n; i++) {
    if (st.empty()) {
      st.push({a[i], i});
      res[i] = 0;
    } else {
      while (!st.empty()) {
        auto [val, pos] = st.top();
        if (val < a[i]) {
          res[i] = pos + 1;   
          break;
        } else 
          st.pop();
      }
      st.push({a[i], i});
    }
  }
  for (int &i : res) {
    cout << i << ' ';
  }
  return 0;
} //Hajimemashite

