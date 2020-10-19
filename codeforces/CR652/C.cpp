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
  ll n, k;
  cin >> n >> k;
  vector<ll>v(n);
  for(ll i = 0; i < n; i++) cin >> v[i];
  vector<ll>w(k);
  for(ll i = 0; i < k; i++) cin >> w[i];
  sort(v.begin(), v.end());
  sort(w.begin(), w.end());
  // reverse(v.begin(), v.end());  
  stack<ll>st;
  for(ll i : v) st.push(i);
  ll ans = 0;
  ll mn[k], mx[k];
  for (ll i = 0; i < k; i++) {
    mn[i] = LONG_MAX;
    mx[i] = LONG_MIN;
  }
  ll cnt = k;
  ll j = 0;
  for (ll i = 0; i < k; i++) {
    ll count = w[i];
    unordered_set<ll> dist;
    vector<ll> temp;
    ll maxi = LONG_MIN, mini = LONG_MAX;
    while(j < n and (ll)dist.size() != count && (ll)st.size() > 0){
      ll prev_size = dist.size();
      ll ele = st.top();
      dist.insert(st.top());  
      st.pop();
      ll new_size = dist.size();
      if(prev_size == new_size){
        temp.push_back(ele); 
      }else{
        maxi = max(maxi, ele);
        mini = min(mini, ele);
      }
    }
    ll diff = 0;
    if(dist.size() != count){
      diff = count - dist.size();
    }

    for(j = temp.size()-1 - diff ; j >= 0; j--){
       st.push(temp[j]);
    }

    ans+= (maxi + mini);
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
    solve();
  }
  return 0;
}  