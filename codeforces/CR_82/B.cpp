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
	ll n,g,b;
    cin >> n >> g >>b;
    if(g >= n){
        cout << n << endl;
        return;
    }
    ll GD = (n+1)/2;
    ll days = GD/g, total = 0;
    if(GD%g == 0){
        total = days*(g+b);
        total -= b;
        if(total < n){
            total += n-total;
        }
    } 
    else{
        total = days*(g+b);
        total += GD%g;
        if(total < n){
            total += n-total;
        }
    }
    cout << total << endl;
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
