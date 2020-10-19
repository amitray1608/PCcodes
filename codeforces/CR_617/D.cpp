//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll check(ll n , ll a  , ll b){
	ll val=n/(a+b);
	if(n % (a+b) == 0)
		val--;
	n -= (val)*(a+b);
    if(n <= a){
		return 0;
    }
	else{
		n -= a;
		ll times = n/a;
		if(n%a != 0)
			times++;
		
        return times;
	}
}
void solve(){
        ll n, a, b, tmp;
		cin >> n >> a >> b >> tmp;
		ll mons[n];
		for(ll &i : mons) 
            cin >> i;
		ll left[n];
		ll count = 0;
		vector<ll>aa;
		for(ll i=0; i<n; i++){
			left[i] = check(mons[i], a, b);
			if(left[i] == 0)
				count++;
			else aa.push_back(left[i]);
		}
		sort(aa.begin(), aa.end());
		ll len = aa.size();
		for(ll i=0; i<len; i++){
            if(aa[i] > tmp) break;
			else{
				count++;
				tmp -= aa[i];
			}
		}
		cout << count << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
/*
3
6 2 3 3
7 10 50 12 1 8
1 1 100 99
100
7 4 2 1
1 3 5 4 2 7 6
*/
