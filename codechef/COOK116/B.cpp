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
	int maxi = *max_element(a, a+n);
	int front = 0, back = 0, pos = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == maxi){ front = i; break;}
	}
	for(int i = n-1; i >= 0; i--){
		if(a[i] == maxi){ back = i; break;}
	}
		int d = back-front;
		cout << max(0, (n/2) - d) << endl;
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
