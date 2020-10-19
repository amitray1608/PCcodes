#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n, X, Y;
  cin >> n >> X >> Y;
  vector<int> a(n), b(n);
  for(int &i : a) cin >> i;
  for(int &i : b) cin >> i;
  vector<pair<int, int>> both(n);
  for(int i = 0; i < n; i++) {
    both[i].first = a[i], both[i].second = b[i];
  }
  sort(both.begin(), both.end(), 
    [](const pair<int, int> &x,const pair<int, int> &y) {
      return abs(x.first - x.second) > abs(y.first - y.second);  
    }
  );
  int maxi = 0, counta = 0, countb = 0;
  for(int i = 0; i < n; i++) {
    if(both[i].first > both[i].second) {
      if(counta < X)
        counta++, maxi += both[i].first;
      else
        countb++, maxi += both[i].second;
    } else {
      if(countb < Y)
        countb++, maxi += both[i].second;
      else
        counta++, maxi += both[i].first;
    }
  }
  cout << maxi << endl;
  /*
  for(auto &i : both) {
    cout << i.first << ' ' << i.second << endl;
  }
  */
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
