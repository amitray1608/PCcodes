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
  int B = (int)sqrt(n + 0.0) + 1;
  vector<int>b[B];
  for(int i = 0; i < n; i++) {
    b[i/B].push_back(a[i]);
  }
  for(int i = 0; i < ceil(n/B); i++)
    sort(b[i].begin(), b[i].end());
  int q;
  cin >> q;
  while(q--) {
    int type;
    cin >> type;
    if(type) {
      int pos, val;
      cin >> pos >> val;
      pos--;
      int block = pos/B, curr = a[pos];
      int l = 0, h = B-1;
      while(l <= h) {
        int mid = l + (h-l)/2;
        if(b[block][mid] == curr) {
            b[block][mid] = val;
            break;
        } else if(b[block][mid] > curr)
          h = mid - 1;
        else 
          l = mid + 1;
      }
      a[pos] = val;
      sort(b[block].begin(), b[block].end());
    } else {
      int l, r, c;
      cin >> l >> r >> c;
      l--, r--;
      int ans = 0;
      int lblock = l/B, rblock = r/B;
      if(lblock == rblock) {
        for(int i = l; i <= r; i++)
          if(a[i] >= c) ans++;
        cout << ans << endl;
      } else {
        if(l%B)
          lblock++;
        int i = 0;
        for(i = l; i < lblock*B; i++) 
          if(a[i] >= c) ans++;
        while(i + B - 1 < r) {
          int bb = i/B;
          ans += b[bb].end() - lower_bound(b[bb].begin(), b[bb].end(), c);
          i += B;
        }
        while(i <= r) {
          ans += (a[i] >= c);
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
