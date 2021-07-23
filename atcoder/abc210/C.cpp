
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  set<int> st;
  map<int, int> mp;
  for (int i = 0; i < k; i++) {
    st.insert(a[i]);
    mp[a[i]]++;
  }
  int maxi = st.size();
  int j = 0;
  for (int i = k; i < n; i++) {
    mp[a[i]]++; 
    st.insert(a[i]);
    mp[a[j]]--;
     if (mp[a[j]] == 0) {
       st.erase(a[j]);
     }
     j++;
     maxi = max(maxi, (int)st.size());
  }
  cout << maxi << '\n';
  return 0;
} //Hajimemashite

