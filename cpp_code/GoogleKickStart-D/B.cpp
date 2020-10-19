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
  vector<int>a(n);
  for(int &i : a) cin >> i;
  int ans = 0;
  int count = 0, count2 = 0;
  for(int i = 1; i < n; i++){
    if(a[i] > a[i-1]){
      count++;
      count2 = 0;
      if(count == 4){
        count = 0;
        ans++;
      }
    }
    else if(a[i] < a[i-1]){
      count2++;
      count = 0;
      if(count2 == 4){
        count2 = 0;
        ans++;
      }
    }
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    tt++;
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  