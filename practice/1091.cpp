
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, m;
  cin >> n >> m;
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.insert(x);
  }
  vector<int> res(m, -1);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    auto pos = st.upper_bound(x);
    if(pos == st.begin()) continue;
    res[i] = *(--pos);
    st.erase(pos);
  }
  for (int i : res) cout << i << '\n';
  return 0;
} //Hajimemashite

