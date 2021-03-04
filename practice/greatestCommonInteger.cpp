
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> st;
  for (int &i : a) cin >> i, st.insert(i);
  int m;
  cin >> m;
  vector<int> b(m);
  for (int &i : b) cin >> i;
  sort(b.rbegin(), b.rend());
  for (int i = 0; i < m; i++) {
    if (st.find(b[i]) != st.end()) {
      cout << b[i] << '\n';
      return 0;
    }
  }
  cout << "NO common integer in two array." << '\n';
  return 0;
} //Hajimemashite
