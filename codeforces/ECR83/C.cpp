//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll expo(ll base, ll p){
    ll res=1;
    while(p>0){
      if(p&1) res=(res*base);
      p/=2;
      base=(base*base);
    }
    return res;
}
void solve(){
          ll n,k;
          cin >> n >> k;
          ll a[n+1];
          for(int i = 1; i <= n; i++){
              cin >> a[i];
          }
          int freq[40];
          //memset(freq, 0, sizeof freq);
          for(int i = 0; i < 40 ; i++) 
			freq[i] = 0;
		map<ll, bool> check;
          int flag = 1;
          for(ll i = 1; i <= n; i++){
            if (a[i] == 0)
                continue;
            ll x = a[i];
            ll cur = 0;
            while (x) {
                if (x % k > 1) {
                    flag = false;
                    break;
                }
                if (x % k == 1) {
                    if (check[cur]) {
                        flag = false;
                        break;
                    }
                    check[cur] = true;
                }
                x /= k;
                cur++;
            }
            if (!flag)
                break;
          }
        //   for(int i = 0; i < 40; i++){
        //       if(freq[i] > 1) 
        //         flag = 0;
        //   }
          if(flag) 
            cout << "YES\n";
          else 
            cout << "NO\n";
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
