//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	ll n,k;
	cin >> n >> k;
	ll a[n];
	for(ll &i : a) cin >> i;
	ll sum = 0, curr = 0, mini = 0, maxi = INT_MIN;
	map<ll, ll> check;
	for(ll i=0; i < n/2; i++){
		//mini = max(mini, 1 + min(a[i], a[n-i-1]));
		//maxi = min(maxi, k + max(a[i], a[n-i-1]));
        ll tmp = a[i] + a[n-i-1]; 
        check[tmp]++;
		if ( maxi < check[tmp] ){
			maxi = check[tmp] ;
			sum = tmp ;
		}
	}
	//maxi = INT_MIN;
	//for(auto &i : check){
		//if(i.second > maxi){
			//maxi = i.second;
			//sum = i.first;
		//}
	//}
	ll count = 0, j = n-1;
	for (ll i = 0; i < j; i++, j--){
		if ((a[i] + a[j]) != sum){
			ll p = sum - a[i] ;
			ll q = sum - a[j];
			if((p > k) && (q > k))
			count += 2;
			else
			count++ ;
		}
	}
	count = min(count , n/2);
	cout << count << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}	
