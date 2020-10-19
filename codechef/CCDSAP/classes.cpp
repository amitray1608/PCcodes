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
	int n;
	cin >> n;
	int a[2*n+1];
	//for(int &i : a) cin >> i;
	for(int i = 0; i < 2*n; i++) cin >> a[i];
	sort(a, a+(2*n));
	//for(int i =0; i< 2*n; i++) cout << a[i] << " ";
	//cout << endl;
	cout << abs(a[(2*n)/2-1]-a[(2*n)/2]) << endl;
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
