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
	bool flag = true;
	for(int i = 0; i < n; i++){
		if(a[i] == 1){
			for(int j = i+1; j <= min(n-1, i+5); j++){
				if(a[j] == 1)
					flag = false;
			}
		}
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
