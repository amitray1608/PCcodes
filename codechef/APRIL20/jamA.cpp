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
	int a[n][n];
	int sum = 0, rcount = 0, ccount = 0;
	for(int i = 0; i < n; i++){
		set<int>s;
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(i == j)
			sum += a[i][j];

			s.insert(a[i][j]);
		}
		if((int)s.size() != n)
			rcount++;
		s.clear();
	}
	cout << sum <<  " ";
	for(int i = 0; i < n; i++){
		set<int>s;
		for(int j = 0; j < n; j++){
			s.insert(a[j][i]);
		}
		if((int)s.size() != n)
			ccount++;
		s.clear();
	}
	cout << rcount << " " << ccount << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 1;
		cin >> t;
		while(t--){
			cout << "Case #" << tt++ << ": ";
			solve();
		}
	return 0;
}	
