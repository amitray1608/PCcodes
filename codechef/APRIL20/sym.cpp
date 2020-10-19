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
	char c[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cin >> c[i][j];
	}
	bool flag = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			if(c[i][j] != c[i][n-j-1])
				flag = false;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			if(c[n-j-1][i] != c[j][i])
				flag = false;
	}
	if(flag)
		cout << "YES";
	else
		cout << "NO";
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
