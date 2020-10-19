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
	int a[n];
	for(int &i : a) cin >> i;
	int fre[n] = {0};
	for(int i = 0; i < n; i++){
		int x = (a[i]+i)%n;
		if(x < 0)
			x = x+n;
		fre[x]++;
	}
	for(int i = 0; i < n; i++){
		if(fre[i] > 1){
			cout << "NO" << endl;
			return;
		}	
	}
	cout << "YES" << endl;
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
	
