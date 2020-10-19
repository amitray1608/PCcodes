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
  vector<pair<int, pair<int, int>>>a(n);
  int alicee = 0, bobb = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    if(a[i].second.first == 1)
      alicee++;
    if(a[i].second.second == 1)
      bobb++;
  }
  if(alicee < k or bobb < k){
    cout << -1 << endl;
    return;
  }
  
  sort(a.begin(), a.end());
  vector<int> alice, bob, both;
  for(int i = 0; i < n; i++) {
    if(a[i].second.first and a[i].second.second)
      both.push_back(a[i].first);
    else if(a[i].second.first)
      alice.push_back(a[i].first);
    else if(a[i].second.second)
      bob.push_back(a[i].first);
  }

  for(int i = 1; i < (int)alice.size(); i++) {
      alice[i] += alice[i-1];
  }
  for(int i = 1; i < (int)bob.size(); i++) {
      bob[i] += bob[i-1];
  }
  for(int i = 1; i < (int)both.size(); i++) {
      both[i] += both[i-1];
  }

  int ans = (int)1e14;
  for(int i = 0; i <=(int)both.size(); i++){
    if(i == 0) {
      if(min((int)alice.size(), (int)bob.size()) >= k)
        ans = min(ans, alice[k-1]+bob[k-1]);
      continue;
    }
    int sum = both[i-1];
    int rem = k-i;
    if(min((int)alice.size(), (int)bob.size()) >= rem) {
      if(rem - 1 >= 0){
        sum += (alice[rem-1] + bob[rem-1]);
      } 
      ans = min(ans, sum);
    }
  }
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