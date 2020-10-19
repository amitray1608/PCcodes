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
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	bool flag = 0;
	if(a[0] == a[1] && a[2] != a[1])
		flag = 1;
	else if(a[0] != a[1] && a[1] == a[2]) 
		flag = 1;
	
	if(flag)
		cout << "YES\n";
	else
		cout <<"NO\n";
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
