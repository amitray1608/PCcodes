
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long mini = LONG_MAX;
  for (int i = 0; i < n - 1; i++) {
    long long x = 0LL, y = 0LL;
    for (int j = 0; j <= i; j++) 
      x |= a[j];
    for (int j = i + 1; j < n; j++)
      y |= a[j];
    mini = min(mini, x ^ y);
  }
  cout << mini << '\n';
  return 0;
} //Hajimemashite


