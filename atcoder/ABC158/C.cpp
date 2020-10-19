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
	int a, b;
	cin >> a >> b;
	double A = 0.08, B = 0.1;
	double ans = 0;
	bool flag = 0;
	for(int i = 1; i <= 1002; i++){
		if(floor(i*A) == (double)a && floor(i*B) == (double)b){
			ans = i;
			flag = 1;
			break;
		}
	}
	if(flag)
		cout << (int)ans;
	else
		cout << -1 << endl;
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
