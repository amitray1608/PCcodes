//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

bool isprime(int n){
	if(n == 2 || n == 3)
		return true;
	for(int i = 2; i*i < n; i++)
		if(n%i == 0)
			return false;
	return true;
}

void solve(){
	int n;
	cin >> n;
	int i = n+1;
	while(true){
		if(!isprime(i)){
			if(!isprime(i-n)){
				cout << i << " " << (i -n) << endl;
				return;
			}
		}
		i++;
	}
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
	
