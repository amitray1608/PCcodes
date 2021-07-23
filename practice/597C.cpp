
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int maxn = 1e5 + 7;
const int maxm = 12;
int bit[maxm][maxn];
int n;

void update(int pos, int delta, int idx) {
  while (pos <= n) {
    bit[idx][pos] += delta;
    pos += pos & -pos;
  }
}

int sum(int pos, int idx) {
  int res = 0;
  while (pos > 0) {
    res += bit[idx][pos];
    pos -= pos & -pos;
  }
  return res;
}
    
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int k;
  cin >> n >> k;
  k++;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  for (int i = 1; i <= n; i++) {
    update(a[i - 1], 1, 1);
    vector<int> curr(maxm, 0);
    for (int j = 2; j < maxm; j++) {
      curr[j] = sum(a[i - 1] - 1, j - 1);
    }
    for (int j = 2; j < maxm; j++) {
      update(a[i - 1], curr[j], j);
    }
  }
  cout << sum(n, k) << '\n';
  return 0;
} //Hajimemashite

