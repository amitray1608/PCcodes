//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  ll n;
  cin >> n;
  vector<ll>a(n), b(n);
  map<ll, ll>check, checka, checkb;
  for(ll &i : a) cin >> i, check[i]++, checka[i]++;
  for(ll &i : b) cin >> i, check[i]++, checkb[i]++;
  ll mini = LONG_MAX;
  for(auto &i : check){
    mini = min(mini, i.first);
    if(i.second&1){
      cout << -1 << endl;
      return;
    } else if(i.second != 0){
      i.second /= 2;
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if(a == b){
    cout << 0 << endl;
    return;
  }
  for(ll &i : a){
    check[i]--;
  }
  vector<ll> AA, BB;
  for(auto i : check){
    if(i.second > 0) {
      ll x = i.second;
      while(x--)
        BB.push_back(i.first);
    }else if(i.second < 0) {
        ll x = abs(i.second);
        while(x--)
          AA.push_back(i.first);
    }
  }
  sort(BB.begin(), BB.end());
  sort(AA.begin(), AA.end());
  ll i = 0, j = (ll)BB.size()-1;  
  ll ans = 0;
  while(i < (ll)BB.size() and j >= 0){
    ans += min(2*mini, min(BB[i], AA[j])); 
    i++;
    j--; 
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
    cout << "Ans:" << endl;
    solve();
  }
  return 0;
}  


/*
6
10
1 1 1 1 2 3 3 4 5 6
2 2 2 4 5 5 5 6 6 6
7
1 2 3 4 4 5 5
1 2 2 2 3 5 5
5
5 2 4 2 1
1 5 2 2 4
7
1 3 4 5 3 4 5
1 6 7 8 6 7 8
6 
1 1 1 2 3 2
1 2 3 2 4 4
8
1 1 1 2 2 3 3 3
2 2 1 3 3 3 2 2

2
6
2 2 2 2 3 3 
3 3 3 3 2 2
7
1 1 3 3 5 5 7
2 2 4 4 6 6 7

1
13
2 2 3 3 3 3 4 4 4 4 4 5 5
2 2 2 2 2 2 3 3 4 4 4 4 4

1
5
3 4 8 8 4
3 6 9 9 6
*/

