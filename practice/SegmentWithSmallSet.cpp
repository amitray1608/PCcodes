#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int maxi = *max_element(a.begin(), a.end());
  vector<int> f(maxi + 1, 0);
  long long count = 0, curr = 0, j = 0;
  for (int i = 0; i < n; i++) {
    curr += (f[a[i]] == 0);
    f[a[i]]++;
    while (curr > k) {
      f[a[j]]--;
      if (f[a[j]] == 0) curr--;
      j++;
    }
    count += i - j + 1;
  }
  cout << count << '\n';

  return 0;
} //Hajimemashite
