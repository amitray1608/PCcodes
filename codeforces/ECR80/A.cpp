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
		ll n,d;
		cin >> n >> d;
		if(d <= n) 
			cout<<"YES"<<endl;
		else
		{
			ll left = d/((n/2)+1);
			left += n/2;
			if(d%(n/2+1)) 
				left += 1;
			if(left <= n) 
                cout << "YES" << endl;
			else 
                cout << "NO" << endl;
		}
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
