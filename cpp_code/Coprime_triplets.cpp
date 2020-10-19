//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e5 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
bool prime[siz];
void seive(){
	
	for(int i = 2; i <= siz; i++){
		if(prime[i]){
			for(int p = i*i; i<siz; i += p)
				prime[p] = false;
		}
	}
	
}


void solve(){
	memset(prime, true, sizeof prime);
	seive();
	int n;
	cin >> n;
	vector<int>v(n);
	
	for(int i = 1; i<=n; i++) cin >> v[i];
	
	int count = 0, od[n] = {0}, ev[n] = {0}, _prime[n] ={0};

	for(int i = 1; i <= n; i++){
		if(prime[v[i]){
		 _prime[i] = prime[i-1]+1; 
		 continue; 
		} 
		
		else if(v[i]&1) od[i] += od[i-1]+1;
		else ev[i] += ev[i-1]+1;
	}
		
		for(int j = 3; j < n; j++){
				if(prime[j] >= 1){
					count += j
				}
		}
		
	}
	cout << count << endl;
}

int main(){
	#ifndef RAY
	//	freopen("input.txt", "r", stdin);
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
