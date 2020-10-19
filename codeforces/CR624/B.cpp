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
	int n, m;
	cin >> n >> m;
	int a[n], b[m], vis[105] = {0};
	for(int &i : a) cin >> i;
	for(int &i : b) cin >> i, vis[i] = 1;
	bool flag = true;
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++)
		if(a[j] > a[j+1]){
			if(vis[j+1])
				swap(a[j], a[j+1]);
			else{
				flag = false;
				break;
			}
		}
	}
	if(flag)
		cout << "YES\n";
	else
		cout <<  "NO\n";
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
