#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> first, last;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    first[a[i]] = -1;
    last[a[i]] = -1;
  }
  for(int i = 0; i < n; i++) {
    if(first[a[i]] == -1)
      first[a[i]] = i;
    last[a[i]] = i;
  }
  int sum = 0;
  for(auto i : first) {
    sum += last[i.first] - i.second;
  }
  cout << sum << '\n';
  return 0;
}
