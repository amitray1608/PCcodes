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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = a[0], sum = 0;
  for(int i = 1; i < n; i++) {
    if(a[i]) sum++;
    else
      ans += sum/3, sum = 0;
  }
  ans += sum/3;
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
