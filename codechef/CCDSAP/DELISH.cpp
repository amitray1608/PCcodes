//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
#define deb(x) cout << #x << " = " << x << endl;
ll leftdp[1000004][2],rightdp[1000004][2];
void solve(){
	int n;
	cin >> n;
	ll a[n+1];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	leftdp[0][0] = a[0];
	leftdp[0][1] = a[0];

	for(int i = 1; i < n; i++){
	    leftdp[i][0] = max(leftdp[i-1][0],0) + a[i];
	    leftdp[i][1] = min(leftdp[i-1][1],0) + a[i];	
	}


	rightdp[n-1][0] = a[n-1];
	rightdp[n-1][1] = a[n-1];
	for(int i = n-2; i >= 0; i--){
	    rightdp[i][0] = max(rightdp[i+1][0],0) + a[i];
	    rightdp[i][1] = min(rightdp[i+1][1],0) + a[i];	
	}

	long long int ans = 0;
	for(int i = 0; i < n-1; i++){
	   ans = max(ans,abs(leftdp[i][0] - rightdp[i+1][1]));
	   ans = max(ans,abs(leftdp[i][1] - rightdp[i+1][0]));
	}
	cout << ans << endl;
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
