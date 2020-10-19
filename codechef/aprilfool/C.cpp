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
	 ll n;cin>>n;
    ll c = n%10;
	n = n/10;
    ll b=n%10;
    n = n/10;
    ll a=n%10;
    n = n/10;
    ll d = (a^b);
    if(d==c)
		cout<<"Exclusive";
    else
		cout<<"Inclusive";
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
