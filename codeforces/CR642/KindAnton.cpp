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
	int a[n], b[n];
	for(int &i : a) cin >> i;
	for(int &i : b) cin >> i;
	int neg = 0, pos = 0, flag = 1;
	for(int i = 0; i < n; i++){
		if(a[i] < b[i] && pos == 0)
			flag = false;
		if(a[i] > b[i] && neg == 0)
			flag = false;
		if(a[i] == -1)
			neg = 1;
		if(a[i] == 1)
			pos = 1;
	}
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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
	
