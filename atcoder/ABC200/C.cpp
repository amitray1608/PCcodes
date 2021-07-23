
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<long long> a(n);
  map<long long, long long> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= 200;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += mp[a[i]]++;
  }
  cout << ans << '\n';
  return 0;
} //Hajimemashite


