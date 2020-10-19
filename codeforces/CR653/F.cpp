#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>  
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef unsigned long long ull;

const int MOD =  998244353; //   1000000009 , 1000000023 ,1000000007
const ll INF = ll(1e18);
const ld PI = 4*atan((ld)1);

using namespace __gnu_pbds;
template<typename T, class cmp = std::less<T>>
using Tree = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ll gcd(ll a , ll b){
  if(a==0)return b;
  return gcd(b%a,a);
}
bool isbal(string s , ll l , ll r){
  ll pos = 0;
  for(ll i=l ; i<=r ; i++){
    if(s[i]=='(')pos++;
    else pos--;
    if(pos<0)return false;
  }
  if(pos==0)return true;
  return false;
}
int main() {
  
#ifdef AVI  
  freopen("input.txt" , "r" , stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  
  ll tt;
  //cin >> tt;
  tt = 1;
  while(tt--){
    ll n , k;
    cin >> n >> k;
    vector<pair<ll , pll>>ar(n);
    for(auto &x:ar)cin >> x.first >> x.second.first >> x.second.second;
    sort(ar.begin() , ar.end());
    ll res = 0 ;
    multiset<ll>br , bob , alice;
    for(auto &x:ar){
      if(!x.second.first && !x.second.second)continue;
      if(x.second.first && x.second.second)br.insert(x.first);
      else if(x.second.first && (!x.second.second))bob.insert(x.first);
      else alice.insert(x.first);
      //if(min(bob.size() , alice.size()) + br.size() >= k)break;
    }
    deque<ll>brf , bobf , alicef;
    ll req = k - min(bob.size() , alice.size());
    req = max(ll(0) , req);

    for(auto &x:br)brf.push_back(x);
    for(auto &x:alice)alicef.push_back(x);
    for(auto &x:bob)bobf.push_back(x);
    if(min(bob.size() , alice.size()) + br.size() < k){
      cout << "-1\n";
      continue;
    }
    //ll res = 0;
    for(ll i=0 ; i<k ; i++){
      if(i<req){res += brf[0] , brf.pop_front();continue;}
      if(!brf.size()){
        res += bobf[0] + alicef[0];
        bobf.pop_front();
        alicef.pop_front();
        continue;
      }
      if(bobf[0] + alicef[0] < brf[0]){
        res += bobf[0] + alicef[0];
        bobf.pop_front();
        alicef.pop_front();
      }
      else {
        res += brf[0];
        brf.pop_front();
      }
    }
    cout << res << '\n';
  }
  

}

/*
9 3
1 1 0
1 0 1
2 1 0
2 0 1
2 1 0
2 0 1
8 1 1
10 1 1
11 1 1
*/