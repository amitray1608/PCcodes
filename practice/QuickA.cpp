
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  ll n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  int k;
  cin >> k;
  vector<int> b(k);
  for (int &i : b) {
    cin >> i;
  }
  sort(b.begin(), b.end());
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (binary_search(b.begin(), b.end(), i + 1)) 
      continue;
    sum += a[i];
  }
  cout << sum + 1 << '\n';
  return 0;
} //Hajimemashite

