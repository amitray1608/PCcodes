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
		int n, p;
        cin >> n >> p;
         int a[n+1];
		bool flag = false;
		for(int i=1; i <= n; ++i){
			cin >> a[i];
			if(a[i] == p) 
                flag = 1;
		}
		if(flag){
			cout << 1 << endl;
			return;
		}
		sort(a+1, a+n+1);
		if(a[n] > p) 
            cout << 2 << endl;
		else 
            cout << (p + a[n]-1) / a[n] << endl;
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
