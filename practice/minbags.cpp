#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  multiset<int> st;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    st.insert(a[i]);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int x = a[i] * 2;
    multiset<int> :: iterator pos;
    pos = st.lower_bound(x);
    if(pos != st.end()) 
      st.erase(st.find(*pos));
    else
      ans++;
  }
  cout << ans << '\n';
  return 0;
}
