//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
//vector<int>a[2000];
bool prime(int n){
	for(int i=2; i*i <= n; i++){
		if(n%i == 0)
			return true;
	}
return false;
}
void solve(){
	int x, k;
	cin >> x >> k;
	if(k == 1){
		if(x-2 >= 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}else if(k == 2){
		if(x < 4){
			cout << 0 << endl;
			return;
		}
		if(prime(x))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}else{
		ll n = x;
		ll fact = 0;
		while(n%2 == 0) fact++, n/=2;
		for(int i = 3; i*i <= n; i+=2){
			while(n%i == 0)fact++, n/=i;
		}
		if(n > 2) fact++;
		if(fact >= k)
			cout << 1 << endl;
		else
			cout << 0 << endl;
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
