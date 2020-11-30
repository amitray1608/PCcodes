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
  for(auto &i : a)
    cin >> i.first >> i.second;
  auto cmp = [&](const pair<int, int> &x, const pair<int, int> &y) {
    if(x.first == y.first)
      return x.second < y.second;
    return x.first < y.first;
  };
  sort(a.begin(), a.end(), cmp);
  int maxi = 0, curr = 0, start = a[0].first, end = a[0].second;
  for(int i = 1; i < n; i++) {
    if(
  }
  cout << count << endl;
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
