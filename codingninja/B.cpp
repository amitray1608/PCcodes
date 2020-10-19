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
  int n;
  cin >> n;
  int a[n+1] = {0};
  for(int i = 1; i <= n; i++) 
    cin >> a[i];
  int suf[n+1] = {0};
  for(int i = n; i > 0; i--)
    if(a[i+1] == 1) 
      suf[i] = suf[i+1] + 1;
    else 
      suf[i] = 0;
  int pre[n+1] = {0};
  for(int i = 1; i <= n; i++)
    if(a[i-1] == 1) 
      pre[i] = pre[i-1] + 1;
    else  
      pre[i] = 0;
  int ans = 0;
  for(int i = 1; i < n; i++)
      ans = max(ans, pre[i] + suf[i+1]);
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  