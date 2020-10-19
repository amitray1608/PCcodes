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
  int n, s;
  cin >> n >> s;
  int a[n];
  for(int &i : a) cin >> i;
  sort(a, a+n);
  ll cost = 0;
  for(int i = 0; i <= n/2; i++) {
    if(a[i] > s){
      cost += a[i]-s;
    }
  }  
  for(int i = n/2; i < n; i++) {
    if(a[i] < s){
      cost += s-a[i];
    }
  }
  cout << cost << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  