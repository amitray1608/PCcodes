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
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  if((a + b - c > n) or (a == 1 and b == 1 and c == 1 and n != 1)) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  int A, B, C, D;
  B = n - a - b + c;
  b -= c;
  a -= c;
  if(b > a) {
    A = (c + 1) / 2;
    C = c / 2;
    D = b;
  } else {
    A = (c) / 2;
    C = (c + 1) / 2;
    D = b;   
  }
  vector<int> x;
  int k = n - a;
  for(int i = 0; i < a; i++)
    x.push_back(k++);
  for(int i = 0; i < A; i++)
    x.push_back(k);
  for(int i = 0; i < B; i++)
    x.push_back(1);
  for(int i = 0; i < C; i++)
    x.push_back(k);
  for(int i = 0; i < D; i++)
    x.push_back(--k);
  
  for(int i : x)
    cout << i <<  ' ';
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  