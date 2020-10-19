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
	int count = 0,cc = 0, a[n];
	for(int i =0; i < n; i++){
		cin >> a[i];
		if(~a[i]&1)
			count++;
		else
			cc++;
	}
	if(~count&1 && ~cc&1){
		cout << "YES" << endl;
		return;
	}
		sort(a, a+n);
		for(int i = 1; i < n; i++){
			if(a[i] - a[i-1] == 1){
				cc--;
				count--;
				if(cc %2 == 0 &&  count%2 == 0)
					break;
				i++;
			}
		}
		if(cc%2 == 0 && count%2 == 0)
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
