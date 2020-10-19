//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 998244353;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
 
void solve(){
	int n,k;
	cin >> n >> k;
	int a[n];
    for(int &i : a) cin >> i;
	vector<int> pos;
	ll maxi = 0;
	for(int i=0; i<n; i++){
		if(a[i] > n-k){	 
            pos.push_back(i);
                maxi = (maxi + a[i]);
        }
	}
	ll count = 1;
	for(int i = 0; i < (int)pos.size()-1; i++)
	 count = (count % MOD * (pos[i+1] - pos[i])) % MOD;
	
    cout << maxi << " " << count%MOD;
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
