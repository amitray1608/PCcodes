//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
#define INF  1e18;
void solve(){
    ll n;
    cin >> n;
    ll a[n], b[n], left[n]; 
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
        if(i > 0) 
            left[i] = max(0LL, a[i]-b[i-1]);
    }
    ll suf[n], pre[n], p, ans = INF;
    left[0] = max(0LL, a[0]-b[n-1]);
    suf[n-1] = left[n-1];
    for(int i = n-2; i >= 0; i--){
        suf[i] = suf[i]+suf[i+1];
    }
    pre[0] = left[0];
    for(int i=1; i<n; i++){
        pre[i] = pre[i-1]+left[i];
    }
    for(int i=0; i<n; i++){
        if(i == 0){
            p = a[i]+suf[i+1];
        }else if(i == n-1){
            p = a[i]+pre[i-1];
        }else{
            p = a[i] + suf[i+1] + pre[i-1];
        }
        ans = min(p, ans);
    }
    cout << ans << endl;
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
	
