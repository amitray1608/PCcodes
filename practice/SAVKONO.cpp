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
  int n, z;
  cin >> n >> z;
  vector<int> a(n);
  priority_queue<int>pq;
  for(int &i : a) cin >> i, pq.push(i);
  int count = 0;
  while(z > 0 and !pq.empty()) {
    auto x = pq.top();
    pq.pop();
    z -= x;
    if(x/2 > 0)
      pq.push(x/2);
    count++;
  }
  if(z <= 0)
    cout << count << endl;
  else
    cout << "Evacuate" << endl;
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