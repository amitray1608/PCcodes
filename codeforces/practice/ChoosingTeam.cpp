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
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	int count = 0;
	for(int i = 2; i < n; i+=3){
		if(5-a[i] >= k)
			count++;
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
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
