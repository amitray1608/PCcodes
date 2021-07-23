
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  vector<int> res(n + 2, 0);
  int curr = 1;
  for (int i = 0; i < n; i++) {
    if (res[a[i]] == 0) {
      res[a[i]] = curr++;
    }
    if (res[a[i] + 1] == 0)
      res[a[i] + 1] = res[a[i]];
  }
  cout << *max_element(res.begin(), res.end()) << '\n';
  return 0;
} //Hajimemashite

