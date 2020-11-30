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
  for(int i = 0; i < n; i++)
    cin >> a[i].first >> a[i].second;
  auto cmp = [&](const pair<int, int> &x, const pair<int, int> &y) {
    return x.second < y.second;
  };
  sort(a.begin(), a.end(), cmp);
//  for(int i = 0; i < n; i++)
//    cout << a[i].first << ' '  << a[i].second << endl;
  int start = 0, count = 0;
  for(int i = 0; i < n; i++) {
    if(a[i].first >= start)
      count++, start = a[i].second;
  }
  cout << count;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //  cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
