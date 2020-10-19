//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll bino[53][53];

void binomial_coeff(){
	
	bino[0][0] = 1;
	
	for(int i = 1; i<53; i++){
		bino[i][0] = 1;
		for(int j = 1; j<53; j++){
			bino[i][j] = bino[i-1][j-1]+bino[i-1][j];
		}
	}
}


void solve(){
	int n, k;
	cin >> n >> k;
	vector<int>v(n);
	
	for(int &i : v) cin >> i;
	sort(v.begin(), v.end());
	int x = v[k-1], count = 0, lcount = 0;
	for(int i = 0; i <n; i++){
		if(i<k && v[i] == x)
			count++;
		if(v[i] == x)
			lcount++;
	}
	
	cout << bino[lcount][count] << endl;
	
}

int main(){
	#ifndef RAY
		freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		binomial_coeff();
		while(t--){
			solve();
		}
	return 0;
}
	
