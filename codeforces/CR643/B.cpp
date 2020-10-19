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
	int n, e;
	cin >> n;
	int a[n+1]={0};
	for (int j = 0; j < n; j++) {
		cin >> e;
		a[e - 1]++;
	}
	int count = 0, x = 0;
	for (int j = 0; j < n; j++) {
		int i = (j+1);
		count += a[j] / i;
		a[j] %= i;
		x += a[j];
		a[j] = 0;
		count += x / i;
		x %= i;
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
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}	
