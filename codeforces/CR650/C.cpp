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
  int n, k;
  cin >> n >> k; 
  string s;
  cin >> s;
  int arr[n] = {0};
  for(int i = 0; i < n; i++) {
    arr[i] = s[i] - '0';
  }
  int i = 1, ans = 0, count=0;
  if(arr[0] == 0){
    ans++;
    count = 0;
  }
  while(i < n){
    if(arr[i] == 1) {
      if(i-count-k <= 0) {
        ans--;
      }
      count = i;
    } else {
      if(i-count-k > 0){
        ans++;
        count = i;
      }
    }
    i++;
  }
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