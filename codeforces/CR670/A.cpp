#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  int count[101] = {0};
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    count[x]++;
  }
  int a = 0, b = 0;
  while(count[a]) a++;
  while(count[b] > 1) b++;
  cout << a + b << endl;
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