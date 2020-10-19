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
  int a[n];
  for(int &i : a) cin >> i;
  sort(a, a+n);
  ll sum = a[n-1], k = n-2;
  for(int i = n-2; k > 0; i--){
    if(k == 1)
      sum += a[i], k--;
    else
      sum += 2*a[i], k-=2;
  }
  cout << sum << endl;
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