//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll a[50005], b[50005], n, m, k;
ll forrow(ll x){
	ll count=0, p_sum[50005];
	memset(p_sum, 0, sizeof(p_sum));
	for(ll i=1; i<=n; i++) 
        p_sum[i]=a[i]+p_sum[i-1];
	for(ll i=1;i <=n-x+1; i++){
		if(p_sum[x+i-1] - p_sum[i-1] == x)
             count++;
	}
	return count;
}

ll forcol(ll x){
	ll count=0, p_sum[50005];
	memset(p_sum,0,sizeof(p_sum));
	for(ll i=1; i <= m; i++) 
		p_sum[i]=b[i]+p_sum[i-1];
	for(ll i=1; i <= m-x+1; i++){
		if(p_sum[x+i-1]-p_sum[i-1] == x)
			count++;
	}
	return count;
}


void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	ll count = 0;
	for(ll i=1; i*i <= k; i++){
		if(k%i==0){
			count += forrow(k/i) * forcol(i);
			if(i != k/i) 
				count += forrow(i)*forcol(k/i);
		}
	}
	cout<<count<<"\n";
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
	
