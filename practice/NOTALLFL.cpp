//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  int n, k;
  cin >> n >> k;
  int a[n], freq[k + 1];
  memset(freq, 0, sizeof freq);
  for(int &i : a) cin >> i;
  int i = 0, j = 0, uniq = 0, maxi = 1;
  while(i < n) {
    if(!freq[a[i]]) uniq++;
    freq[a[i]]++;
    if(uniq < k)
      maxi = max(maxi, i - j + 1);
    while(uniq == k) {
      freq[a[j]]--;
      if(freq[a[j]] == 0)
        uniq--;
      j++;
    }
    i++;
  }
  cout << maxi << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  