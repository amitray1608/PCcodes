#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long usm = 0;
    for(int &i : a) cin >> i, usm += i;
    if(usm % k) cout << 1 << '\n';
    else  cout << 0 << '\n';
  }
  return 0;
}
