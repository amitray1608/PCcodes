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
	ll x,y,a,b;
	cin >> x >> y >> a >> b;
	//if(x > y){
		//swap(x, y);
	//}
	if(x == 0 && y == 0){
		cout << "0\n";
		return;
	}
	ll sum;
	if(b > 2*a){
		sum = (x+y)*a;;
		cout << sum <<endl;
	}else {
		sum =  min(x, y)*b + (max(x,y)-min(x,y))*a;
		cout << sum << endl;
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
