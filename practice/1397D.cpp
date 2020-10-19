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
  int n;
  cin >> n;
  priority_queue<int> pq, tmp;
  vector<int> a(n);
  for(int &i : a) {
    cin >> i;
    pq.push({i});
  }
  int player = 1, suma = 0, sumb = 0, T = 0, HL = 0;
  while(pq.top() != 0) {
    if(player) {
      T++;
      suma = pq.top();
      pq.pop();
      pq.push(max(sumb-1, 0));
      player ^= 1;
    } else {
      HL++;
      sumb = pq.top();
      pq.pop();
      pq.push(max(suma - 1, 0));
      player ^= 1;
    }
  }
  cout << (T > HL ? "T" : "HL") << endl;
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