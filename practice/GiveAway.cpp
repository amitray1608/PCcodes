#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int &i : a) cin >> i;
  int BLOCK = (int) sqrt(n + 0.0) + 1;
  vector<int> b[BLOCK];
  for(int i = 0; i < n; i++) {
    b[i/BLOCK].push_back(a[i]);
  }
  for(int i = 0; i < ceil(n/BLOCK); i++) {
    sort(b[i].begin(), b[i].end());
  }

  /*
  for(auto &i : b)
    for(int ii : i)
      cout << ii << ' ';
  cout << endl;
  */
  int q;
  cin >> q;
  while(q--) {
    int type;
    cin >> type;
    if(type) {
      int pos, val;
      cin >> pos >> val;
      pos--;
      int block = pos/BLOCK;
      int initval = a[pos];
      int lo = 0, hi = BLOCK-1;
      while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(b[block][mid] == initval) {
          b[block][mid] = val;
          break;
        } else if(b[block][mid] < initval)
          lo = mid + 1;
        else
          hi = mid - 1;
      }
      a[pos] = val;
      sort(b[block].begin(), b[block].end());
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      l--, r--;
      int lblock = l/BLOCK;
      int rblock = r/BLOCK;
      int ans = 0;
      if(lblock == rblock) {
        for(int i = l; i <= r; i++) {
            if(a[i] > x)
              ans++;
        }
        cout << ans << endl;
      } else {
        if(l%BLOCK)
          lblock++;
        int i;
        for(i = l; i < lblock*BLOCK; i++)
          if(a[i] >= x)
            ans++;
        while(i + BLOCK-1 <= r) {
          int bb = i/BLOCK;
          ans += b[bb].end() - lower_bound(b[bb].begin(), b[bb].end(), x);
          i += BLOCK;
        }
        while(i <= r) {
          if(a[i] >= x)
            ans++;
          i++;
        }
        cout << ans << endl;
      } 
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
