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
	int i = 0;
	while(a[i] < 0)
		i++;
	if(i == n){
		cout << 0 << endl;
		return;
	}
	int best = 0, sum = 0, maxi = -50;
	for(; i < n; i++){
		sum += a[i];
		maxi = max(maxi, a[i]);
		if(sum < 0){
			sum = 0;
			maxi = -50;
		}
		if(maxi != -50 && sum-maxi > best)
				best = sum-maxi;
	}
	cout << best << endl;
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
