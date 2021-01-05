#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    long long suma = 0, sumb = 0;
    for(int &i : a) cin >> i, suma += i;
    for(int &i : b) cin >> i, sumb += i;
    sort(a.begin(), a.end()); 
    sort(b.rbegin(), b.rend());
    int i = 0, j = 0, count = 0;
    while(suma <= sumb and i < n and j < m) {
      if(a[i] == b[j]) {
        i++, j++;
        continue;
      }
      if(b[j] > a[i]) {
        sumb -= b[j];
        suma -= a[i];
        suma += b[j];
        sumb += a[i];
        i++, j++;
        count++;
      }
      if(suma > sumb) break;
    }
    if(suma > sumb)
      cout << count << '\n';
    else 
      cout << -1 << '\n';
  }
  return 0;
}
