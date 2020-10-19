//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(base) cout << #base << " = " << base << endl;

int digits(int n){
    int d = 0;
    while(n){
        d++;
        n >>= 2;
    }
    return d;
}
ll bits(ll n){
	ll ans = 0;
	while(n){
		ans += (n&1);
		n = n>>1;
	}
	return ans;
}
ll modexpo(ll base, ll expo){  
    ll ans = 1;
    while (expo > 0) {
        if (expo & 1)  
            ans = (ans*base) % MOD;  
        expo = expo>>1; 
        base = (base*base) % MOD;  
    }  
    return ans;  
}  
void solve(){
      int n;
      cin >> n;
      ll a[n];        
      for(ll &i : a) cin >> i;
      ll count = 0, ans = 1;
      ll maxi  = *max_element(a, a+n);
      ll big = digits(maxi);      
      bool flag = true;
      for(int i = 1; i < n; i++){
        int curr = a[i-1], nxt = a[i],ii = 0,  new_n = 0;
        while(curr  || nxt ){
          int andd = curr & 1;
          int ands = nxt & 1;
          if(andd && ands){
			ans = ans *2;
			ans %= MOD; 
          }
          else if(andd && !ands){
			  ans = 0;
			  break;
          }
          nxt = nxt>>1;
          curr = curr>>1;
        }
	}

        //for(int i = 1; i<n; i++){
			//count += bits(a[i-1] & a[i]);
		//}
        //ll ans	 = modexpo(2, count);
		cout << ans << endl;
    //   if(flag)
    //     cout << count << endl;
    //   else
    //     cout << 0 << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
