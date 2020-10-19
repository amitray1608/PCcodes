//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  
  int n, m;
  cin >> n >> m;
  map<string , string> belong;
  for(int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    belong[a] = b;    
  }
  map<string , int> chef, country;
  for(int i = 0; i < m; i++) {
    string s;
    cin >> s;
    chef[s]++;
    country[belong[s]]++;
  }
  int maxi = 0;
  string chefans;
  for(auto i : chef) {
    if(i.second > maxi) {
      maxi = i.second;
      chefans = i.first;
    }
    if(i.second == maxi and maxi != 0) {
      chefans = min(chefans, i.first);
    }
  }
  string countryans;
  maxi = 0;
  for(auto i : country) {
    if(i.second > maxi) {
      maxi = i.second;
      countryans = i.first;
    }
    if(i.second == maxi and maxi != 0) {
      countryans = min(countryans, i.first);
    }
  }
  cout << countryans << endl << chefans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  