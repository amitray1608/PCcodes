//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll MODinv(ll x) {
	ll m = MOD, u = 1, v = 0;
	while (m) {
		ll t = x / m;
		x -= t * m; swap(x, m);
		u -= t * v; swap(u, v);
	}
	u %= MOD;
	if (u < 0) u += MOD;
	return u;
}

void solve(){
    ll n;
    string s;
    cin >> n >> s;
    int exceed[n+1], okay[n+1];
    memset(okay, 0, sizeof okay);
    memset(exceed, 0, sizeof exceed);
    unordered_map<ll,ll> check;
    exceed[0] = 1, okay[0] = 0;
	char open = '(', close = ')';
    ll ans = 0, count = 0;
	ll total = (n*(n+1))/2;
    for(int i = 0; i < n; i++){
        // if(s[i] == close){
        //     okay[i] = exceed[i-1];
        //     if(s[i-1] == open){
        //         if(i-2 >= 0)
        //             exceed[i] = exceed[i-2]+1;
		// 		else
        //             exceed[i] = 1;
        //     }
        // }
        if((s[i] == close)){
            ll curr = (check[total] + 1LL );
            check[total]= (check[total] + 1LL) ;
            count += check[total];
            check[total]--;
            check[total+2] = curr;
            total++;
        }
        else if(s[i] == open)    
            check[total] = (check[total] + 1LL) , total--;           
        else
            check[total]++;
        ans += count;

    }
    total = ((n*(n+1))/2);
     ll ag = __gcd(ans,total);
	total/=ag;
	ans/=ag;
    cout << ans << endl;
		
        ll q = MODinv(total);
        ll change = ((ans % MOD) * (q % MOD)) % MOD;
          
        cout << change << endl;
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
/*
6
5
((())
8
)**(*(*)
9
(*()*)*)*
8
(*(*)*))
7
***((()
6
))))((
4
866666673
10
277777780
30
666666672
20
555555560
1
35714286
25
190476193
*/
