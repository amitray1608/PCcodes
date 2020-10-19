//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll power (ll a, ll b) {
    ll ans = 1ll;
    while(b) {
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b >>= 1;
    }
    return ans;
    }
bool isPerfectSquare(double x){   

  double sr = sqrt(x); 
  
  return ((sr - floor(sr)) == 0); 
} 

void solve(){
		int n;
		cin >> n;
		int num[n+1][10] = {0};
	bool flag = 0;
	for(int nn = 1; nn < n; nn++){
		for(int i = 1; i <10 ; i++)
			num[nn][i] = i;

	}
	 for(int i : num)cout << i;
	 cout << endl;
}


int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		cout << fixed << setprecision(12);
		while(t--){
			solve();
		}
	return 0;
}
