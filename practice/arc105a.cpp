#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int a[4];
  ll sum = 0;
  for(int& i : a) cin >> i, sum += i;
  bool flag = false;
  sort(a, a+4);
  if(a[0] + a[1] == a[2] + a[3]) flag = true;
  else if(a[0] + a[1] + a[2] == a[3]) flag = true;
  else if(a[0] + a[2] == a[3] + a[1]) flag = true;
  else if(a[0] + a[3] == a[2] + a[1]) flag = true;
  cout << (flag ? "Yes" : "No") << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
