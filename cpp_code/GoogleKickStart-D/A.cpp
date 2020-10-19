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
  int count = 0, maxi = INT_MIN;
  for(int i = 0; i < n; i++){
    if(i == n-1){
      if(a[i] > maxi)
        count++;
      continue;
    }
    if(a[i] > maxi and a[i] > a[i+1])
      count++;
    maxi = max(maxi, a[i]);
  }
  cout << count << endl;
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