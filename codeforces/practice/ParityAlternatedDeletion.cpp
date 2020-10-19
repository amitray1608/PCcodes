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
	int odd[n], even[n];
	long sum = 0, e = 0, o = 0;
	for(int i = 0; i<n; i++){
		int ii;
		 cin >> ii;
			if(ii&1) 
				odd[o++] = ii;
			else
				even[e++] = ii; 
	}
	sort(even, even+e);
	sort(odd, odd+o);
	//o--, e--;
	
	if(o >= e){
		for(int i = 0; i<o-e-1; i++) sum += odd[i];
	}else{
		for(int i = 0; i<e-o-1; i++) sum += even[i];
	}
	cout << sum << endl;
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
