#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for(auto &i : a) cin >> i.first >> i.second;
  auto cmp = [&](const pair<int, int>&x, const pair<int, int>&y) {
    return x.second < y.second;
  };
  sort(a.begin(), a.end(), cmp);
  int pre[n] = {0};
  for(int i = 0; i < n; i++) {
    
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
