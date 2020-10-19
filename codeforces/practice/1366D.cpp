//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 10000001;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll prime[siz];

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (ll i = 0; i < static_cast<ll>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef RAY
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void seive(){
  prime[0] = prime[1] = 1; prime[2] = 2;
  for(ll i = 4; i < siz; i+=2) prime[i] = 2;
  for(ll i = 3; i*i <= siz; i+= 2){
    if(!prime[i]){
      prime[i] = i;
      for(ll j = i*i; j < siz; j += (2*i)){
        prime[j] = i;
      }
    }
  }
}

void solve(){
  ll n;
  cin >> n;
  memset(prime, 0, sizeof prime);
  seive();
  // for(ll i = 0; i < n; i++)
  //   cout << prime[i] << ' ';
  vector<pair<ll, ll>>p(n, {-1, -1});
  for(ll i = 0; i < n; i++){
    ll x;
    cin >> x;
    set<ll> div;
    while(x > 1){
      div.insert(prime[x]);
      x /= prime[x];
    }
    // cout << "ok";
  //   debug(div);
    vector<ll>v;
    for(auto pp : div) v.push_back(pp);
    if(v.size() < 2){
        continue;
    }
    ll pd = 1;
    for(ll &pp : v) pd *= pp;
      p[i].first = v[0];
      p[i].second = pd/v[0];
  }
  // debug(p);
  for(auto i : p)
      cout << i.first << ' ';
  cout << endl;
  for(auto i : p)
      cout << i.second << ' ';
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  