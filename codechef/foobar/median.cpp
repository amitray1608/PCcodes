//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
//okay lets brute.
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int>a;
	for(int i = 1; i < n+1; i++){ int x; cin >> x; a.push_back(x);}
	int mid;
	int count = 0;
	while(1){
		sort(a.begin(), a.end());
		n = a.size();
		mid = (n-1)/2;
		if(a[mid] == k)
			break;
		a.push_back(k);
		count++;
	}
	cout << count << endl;
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
