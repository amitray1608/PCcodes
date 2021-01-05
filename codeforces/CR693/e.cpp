#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
#define int int64_t

void solve() {
  int n; cin >> n;
  vector<array<int, 2>> a(n);
  pair<int, int> least = {MOD, MOD};
  pair<int, int> great = {0, 0};
  int lpos, gpos;
  for(int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    if(a[i][0] < least.first and a[i][1] < least.second) {
      lpos = i;
      least = {a[i][0], a[i][1]};
    } else if(a[i][0]  < least.second and a[i][1] < least.first) {
      gpos = i;
      least = {a[i][1], a[i][0]};
    }
    if(a[i][0] > great.first and a[i][1] > great.second) {
      lpos = i;
      great = {a[i][0], a[i][1]};
    } else if(a[i][0] > great.second and a[i][1] > great.first) {
      gpos = i;
      great = {a[i][1], a[i][0]};
    }
  }

  vector<int> res(n, -1);
  for(int i = 0; i < n; i++) {
    if(i != lpos) {
      if(a[i][0] > least.first and a[i][1] > least.second) res[i] = lpos + 1;
      else if(a[i][0] > least.second and a[i][1] > least.first) res[i] = lpos + 1;
    } else {
      if(a[i][0] != great.first and a[i][1] != great.first) res[i] = gpos + 1; 
    }
  }
  for(auto i : res) cout << i << ' ';
  cout << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
