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
	int n, m, k;
	cin >> n >> m >> k;
	ll a = n/k;
	if(a >= m)
		cout << m << endl;
	else{
		m = m-a;
		int e = m/(k-1);
		int f = m%(k-1);
		if(f == 0)
			cout << a-e << endl;
		else
			cout << a-e-1 << endl;
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
