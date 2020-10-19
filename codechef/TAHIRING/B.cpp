//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int  ull;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ull bitcheck(ull N,int POS){return (N & (1ULL<<POS));}

vector<ull>v;
ull solve2(){
  int n = (int)v.size(), pos = 0; 
  for(int bit = (int)log2(v[0]); bit >= 0; bit--) {
      int x = pos;
      while(x < n and bitcheck(v[x], bit) == 0)
        x++;
      if(x == n) continue;
      swap(v[pos], v[x]);
      for(int j=0; j < n; j++){
        if(j != pos and bitcheck(v[j],bit))
            v[j] ^= v[pos];
      }
      pos++;
  }
  ull ans = v[0];
  for(int i = 1; i < n; i++)
    ans = max(ans, ans^v[i]);
  return ans;
}

void solve() {
  int n;
  cin >> n;
  ull x;
  for(int i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
  }
  sort(v.rbegin(),v.rend());
  cout << solve2() << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  
