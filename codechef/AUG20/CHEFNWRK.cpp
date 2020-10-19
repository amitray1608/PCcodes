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
   int a[n];
   bool flag = false;
   for(int &i : a) {
    cin >> i;
    if(i > k)
       flag = true;
   }
   if(flag) {
    cout << -1 << endl;
    return;
   }
   int count = 0, w = 0;
   for(int i = 0; i < n; ) {
    while(w < k) {
       w += a[i];
       i++;
    }
    if(w > k) i--;
    w = 0;
    count++;
   }
   cout << count << endl;  
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
