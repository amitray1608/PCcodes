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
  int n, x;
  cin >> n >> x;
  int a[n], pre[n] = {0}, suf[n] = {0};
  for(int &i : a) cin >> i;
  for(int i = 0; i < n; i++){
    if(i == 0){
      pre[i] = a[i];
    }else{
      pre[i] += a[i] + pre[i-1];
    }
  }
  for(int i = n-1; i >= 0; i--){
    if(i == n-1){
      suf[i] = a[i];
    }else{
      suf[i] = a[i] + suf[i+1];
    }
  }

  int maxi = (pre[n-1]%x ? n : 0), l = 0, r = n-1;
  while(l < r){
    if(pre[l]%x)
        maxi = max(maxi, l+1);
    if((pre[n-1]-pre[l])%x)
        maxi = max(maxi, n-l-1);
    if(suf[r]%x)
        maxi = max(maxi, n-l-1);
    if((suf[0] - suf[r]) % x)
        maxi = max(maxi, n-l-1);
    l++, r--;
  }
  if(maxi)
      cout << maxi << endl;
  else
      cout << -1 << endl;
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