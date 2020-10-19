//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n, a, b;
  cin >> n >> a >> b;
  int par[n + 1];
  for (int i = 0; i <= n; i++)
   par[i] = -1;
  for (int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    par[i] = u;
  }

  double ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      set<int>ss;
      int cd = i;
      while (cd != -1) {
        ss.insert(cd);
        int count = 0;
        while (cd != -1 && count < a) {
          cd = par[cd];
          count++;
        }
      }
      cd = j;
      while (cd != -1) {
        ss.insert(cd);
        int count = 0;
        while (cd != -1 && count < b) {
          cd = par[cd];
          count++;
        }
      }
      int x = (int)ss.size();
      ans += (double)x;
    }
  }
  ans = (double) (ans / (n*n*1.0));
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  cout << fixed << setprecision(10);
  while(t--){
    tt++;
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

