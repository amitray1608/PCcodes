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
	ll n;
	cin >> n;
	vector<ll>a;
	for(int i = 1; i <= n; i *= 2){
		a.push_back(i);
		n-=i;
	}
	if(n > 0)
		a.push_back(n);
	sort(a.begin(), a.end());
	cout << a.size() - 1 << endl;
	for(int i = 1; i < (int)a.size(); i++)
		cout << a[i] - a[i-1] << " ";
	cout << endl;
	
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
