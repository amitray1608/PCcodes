//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
		ll n,s,k;
		cin >> n >> s >> k;
		ll aa[k];
		for(ll i = 0; i < k; i++)
			cin >> aa[i];
		map<ll, ll> check;
		for(ll i = 0; i<k; i++)
			check[aa[i]]++;
		ll front=0, back=0 ,a=s, b=s;
		while(check[a]==1)
		{
			if(a == n)
			{
				front=1e18;
				break;
			}
			front++;
			a++;
		}
		while(check[b] == 1){
			if(b == 1){
				back = 1e18;
				break;
			}
			back++;
			b--;
		}
		cout << min(front,back) << endl;
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
