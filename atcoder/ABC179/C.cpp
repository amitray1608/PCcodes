#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

int div(int n) { 
  int cnt = 0; 
  for (int i = 1; i*i <= n; i++) { 
      if (n % i == 0) { 
        if (n / i == i) 
            cnt++; 
        else  
            cnt = cnt + 2; 
      } 
  } 
  return cnt; 
} 

void solve(){
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int a = n-i;
    ans += (div(a));
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
