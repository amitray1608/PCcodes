#include<bits/stdc++.h>

using namespace std;

int main() {
  int d, m, n;
  cin >> d >> m >> n;
  vector<int> a(n+1);
  for(int i = 0; i < n; i++) cin >> a[i];
  a[n] = d;
  int curr = m, count = 0, flag = true;
  for(int i = 0; i < n; i++) {
    if(a[i] > curr) {
      flag = false;
      break;
    }
    if(a[i + 1] > curr) count++, curr = a[i] + m;
  }
  if(curr < a[n]) flag = false;
  cout << (!flag ? -1 : count) << '\n';
  return 0;
}
