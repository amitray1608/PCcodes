//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int solve2(int a[], int n, int k) {
  int count = 0;
  for(int i = 0; i < pow(2, n); i++) {
    int sum = 0;
    for(int j = 0; j < n; j++){
      if(i&(1 << j)){
        cout << a[j] << ' ';
        sum += a[j];
      }
    }
    cout << endl;
    if(sum >= k)
      count++;
3  }
  return count;
}

void solve(){
  int n, k;
  cin >> n >> k;
  int a[n];
  for(int &i : a) cin >> i;
  int ans = solve2(a, n, k);
  cout << ans << endl;
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