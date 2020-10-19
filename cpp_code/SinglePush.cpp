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
	int l=0, r=0, k=0;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++)  cin >> b[i];
	bool flag = true, x = false;
	int l = 0, r = 0, count = 0;
	for(int i = 0; i < n; i++){
		if(a[i] != b[i] && !x){
			
			if(a[i+1] == b[i+1]) x = true;  
			if(a[i])
		}
	}
}

int main(){
	#ifndef RAY
		freopen("input.txt", "r", stdin);
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
	
