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
	bool flag = true;

		bool vis[2*n+1];
		memset(vis, false, sizeof vis);
		for(int i : a)
			vis[i] = true;
		int b[2*n]={0}, k = 0;
		for(int i = 0; i < n; i++){
			b[2*i] = a[k];
			vis[a[k]] = true;
			for(int j = 1; j<=2*n; j++){
				if(!vis[j] && j > a[k]){
					b[2*i+1] = j;
					vis[j] = true;
					break;
				}
			 }
			k++;
		}
		
		for(int i = 0; i < n; i++)
			if(a[i] != min(b[2*i], b[2*i+1]))
				flag = false;
		if(!flag)
			cout << -1;
		else
			for(int i : b)
				cout << i << " ";
			
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
