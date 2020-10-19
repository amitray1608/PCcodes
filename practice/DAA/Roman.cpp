//Amit Kumar
//18BCS2059
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

ll RomantoInt(string s) {
  unordered_map<char, ll>c;
  c['I'] = 1;
  c['V'] = 5;
  c['X'] = 10;
  c['L'] = 50;
  c['C'] = 100;
  c['D'] = 500;
  c['M'] = 1000;
  ll ans = 0, p = 0;
  ll n = (ll)s.size();
  for(ll i = n-1; i >= 0; i--) {
    ll tmp = c[s[i]];
    if(tmp >= p)
      ans += tmp;
    else
      ans -= tmp;
    p = tmp;
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  ll n = RomantoInt(s);
  cout << n << endl;
 return 0;
}