#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  vector<pair<int, int>> x, y;
  for(int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    x.push_back({u, v});
    y.push_back({u, v});
  }
  auto compx = [&](const pair<int, int>&a, const pair<int, int>&b) {
    if(a.first != b.first)
      return a.first < b.first;
    return a.second < b.second;
  };
  auto compy = [&](const pair<int, int>&a, const pair<int, int>&b) {
    if(a.second != b.second)
      return a.second < b.second;
    return a.first < b.first;
  };
  sort(x.begin(), x.end(), compx);
  sort(y.begin(), y.end(), compy);
 /*
  for(auto i : x)
    cout << i.first << ' '  << i.second << endl;
  for(auto i : y)
    cout << i.first << ' '  << i.second << endl;
*/
  ll maxi = 0;
  for(int i = 0; i < n-1; i++) {
    maxi = max(maxi,(ll) abs(x[i].first - x[n-1].first) + abs(x[i].second - x[n-1].second)); 
  }
  for(int i = 0; i < n-1; i++) {
    maxi = max(maxi, (ll)abs(y[i].first - y[n-1].first) + abs(y[i].second - y[n-1].second)); 
  }
  cout << maxi << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
