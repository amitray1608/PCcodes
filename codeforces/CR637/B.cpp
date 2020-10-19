//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(maxi) cout << #maxi << " = " << maxi << endl;

void solve(){
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i<n; i++)
		cin >> a[i];
	vector<int> p(n, 0);
	for(int i = 1; i < n-1; i++)
		p[i] = (a[i] > a[i-1]) && (a[i] > a[i+1]);
	vector<int> pref(n);
	for(int i=1; i < n; i++)
		pref[i] += p[i] + pref[i-1];
    int t = -1, l = -1;
	for(int i = 0; i + k - 1 < n; i++){
		int maxi = pref[i+k-1];
		if(i != 0)
			maxi -= pref[i-1];
		if(p[i])
			maxi--;
		if(p[i+k-1])
			maxi--;
		if((t == -1ll && l == -1ll) || maxi > t)
			t = maxi, l = i;
	}
	cout << t+1 << ' ' << l+1 << endl;	
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
	
