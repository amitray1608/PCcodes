//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll power(ll x, ll y,  ll m); 
  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
ll modInverse(ll a, ll m) 
{ 
    if (__gcd(a, m) != 1) 
        return -1;
  
    else { 
            return power(a, m - 2, m); 
    } 
} 
  
// To compute x^y under modulo m 
ll modDivide(ll a, ll b, ll m) 
{ 
    a = a % m; 
    ll inv = modInverse(b, m); 
    if (inv == -1) return -1;
    
		return (inv * a) % m; 
} 
ll power(ll x,  ll y,  ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y / 2, m) % m; 
    p = (p * p) % m; 
  
    return (y % 2 == 0) ? p : (x * p) % m; 
} 

ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
ll findlcm(ll arr[], ll n) 
{ 
    ll ans = arr[0]; 
 
    for (ll i = 1; i < n; i++) 
        ans = modDivide(((arr[i] * ans)), (gcd(arr[i], ans)), MOD); 
  
    return ans; 
} 
void solve(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll &i : a) cin >> i;
	
	ll lc = findlcm(a, n), ans = 0;
	for(ll i = 0; i < n; i++)
		ans += modDivide(lc ,a[i], MOD), ans = ans%MOD;
		
	cout <<  ans%MOD<< endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
