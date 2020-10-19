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
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	vector<int>a(n);
    for(int &i : a) cin >> i;
	int maxi = 0, sum = a[0]-1;
	for(int i = 1; i < n; i++){
		sum += a[i]-1;
		sum %= h;
		if(sum >= l && sum <= r)
			maxi++;
	}	
	cout << maxi << endl;
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
